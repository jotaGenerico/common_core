#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcmp
#include "libft.h"

// Função auxiliar para rodar um teste de ft_strjoin e imprimir o resultado
void run_strjoin_test(const char *test_name, const char *s1, const char *s2, const char *expected_result)
{
    char *result_ft = ft_strjoin(s1, s2);

    printf("Teste: %s\n", test_name);
    printf("  Entrada: s1=\"%s\", s2=\"%s\"\n", s1, s2);

    if (!result_ft)
    {
        printf("❌ FALHA: ft_strjoin retornou NULL.\n");
        return;
    }

    if (strcmp(result_ft, expected_result) == 0)
    {
        printf("✅ OK: Resultado: \"%s\"\n", result_ft);
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Esperado: \"%s\"\n", expected_result);
        printf("  Obtido:   \"%s\"\n", result_ft);
    }
    free(result_ft); // Libere a memória alocada pela ft_strjoin
    printf("\n");
}

void test_ft_strjoin(void)
{
    printf("=== Testando ft_strjoin ===\n");

    // Testes variados para ft_strjoin
    run_strjoin_test("Strings normais", "Hello, ", "World!", "Hello, World!");
    run_strjoin_test("Primeira string vazia", "", "World!", "World!");
    run_strjoin_test("Segunda string vazia", "Hello, ", "", "Hello, ");
    run_strjoin_test("Ambas as strings vazias", "", "", "");
    run_strjoin_test("String com numeros", "42", "sp", "42sp");
    run_strjoin_test("Strings longas", "Esta é uma string muito longa para ser a primeira parte.", "E esta é a segunda parte, também bem longa.", "Esta é uma string muito longa para ser a primeira parte.E esta é a segunda parte, também bem longa.");

    printf("\n");
}

int main(void)
{
    test_ft_strjoin();
    return 0;
}
