#!/bin/bash

# Diretórios onde estão os binários
BIN_DIRS=("tests" "tests_bonus")

# Cores pra enfeitar
GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
RESET="\033[0m"

# Arrays para armazenar resultados
declare -a passed_tests=()
declare -a failed_tests=()
total_tests=0

# Cabeçalho
echo -e "${YELLOW}==> Rodando testes com Valgrind (modo parsing elegante)${RESET}\n"

# Loop por todos os diretórios
for dir in "${BIN_DIRS[@]}"; do
    if [ ! -d "$dir" ]; then
        echo -e "${RED}❌ Diretório não encontrado: $dir${RESET}"
        continue
    fi

    for bin in "$dir"/test_*; do
        # Só executa se for um executável
        if [ -x "$bin" ]; then
            echo -e "🔍 Testando ${YELLOW}$bin${RESET}..."
            ((total_tests++))

            # Executa valgrind e filtra erros reais
			output=$(valgrind --leak-check=full --error-exitcode=42 --quiet \
				--track-origins=yes --log-fd=1 "$bin" 2>&1 | tr -d '\0')


            # Verifica resultado (exitcode 42 se erro real de memória)
            if [ $? -eq 42 ]; then
                echo -e "   ${RED}❌ ERRO detectado${RESET}"
                echo "$output" | grep -E "Invalid read|Invalid write|definitely lost"
                failed_tests+=("$bin")
            else
                echo -e "   ${GREEN}✅ OK (sem vazamentos ou acessos inválidos)${RESET}"
                passed_tests+=("$bin")
            fi

            echo    # linha extra por higiene
        fi
    done
done

# Imprime o resumo final
echo -e "\n📊 Resumo dos testes:"
echo -e "   ✅ Passaram: ${#passed_tests[@]}"
echo -e "   ❌ Falharam: ${#failed_tests[@]}"
echo -e "   🔥 Total:    $total_tests"

# Lista as funções que passaram
echo -e "\n✅ Funções aprovadas:"
for test in "${passed_tests[@]}"; do
    echo -e "   ${GREEN}→ $(basename "$test")${RESET}"
done

# Lista as funções que falharam
if [ ${#failed_tests[@]} -gt 0 ]; then
    echo -e "\n❌ Funções com falha:"
    for test in "${failed_tests[@]}"; do
        echo -e "   ${RED}→ $(basename "$test")${RESET}"
    done
fi
