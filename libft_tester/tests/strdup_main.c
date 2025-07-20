#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void test_ft_strdup(void)
{
    // Removido o NULL explícito no final, pois strdup não deve ser chamado com NULL
    const char *tests[] = {
        "",
        "42 SP",
        "O rato roeu a roupa do rei de Roma",
        "A very very long string to duplicate...",
        "Último teste" // Adicionado um último teste válido para fechar o array
    };
    // Calcula o número de elementos no array
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t i = 0;

    printf("=== Testando ft_strdup ===\n");
    // Itera por todos os elementos do array
    for (i = 0; i < num_tests; i++)
    {
        char *std_res = strdup(tests[i]);
        char *ft_res = ft_strdup(tests[i]);

        printf("Teste: \"%s\"\n", tests[i]);

        // Verifica se ambas as alocações foram bem-sucedidas antes de comparar
        if (!std_res)
        {
            printf("❌ ERRO: strdup original retornou NULL para \"%s\" (problema no ambiente de teste ou memória)\n", tests[i]);
            // Libera a memória da sua função se ela alocou
            if (ft_res)
                free(ft_res);
            continue; // Pula para o próximo teste
        }
        if (!ft_res)
        {
            printf("❌ ERRO: ft_strdup retornou NULL para \"%s\"\n", tests[i]);
            // Libera a memória da função original
            if (std_res)
                free(std_res);
            continue; // Pula para o próximo teste
        }

        // Compara os conteúdos das strings duplicadas
        if (strcmp(std_res, ft_res) == 0)
            printf("✅ OK: \"%s\" duplicado corretamente como \"%s\"\n", tests[i], ft_res);
        else
            printf("❌ ERRO: ft_strdup(\"%s\") resultado diferente.\n    Esperado: \"%s\"\n    Obtido:   \"%s\"\n", tests[i], std_res, ft_res);

        // Libera a memória alocada por ambas as funções
        free(std_res);
        free(ft_res);
    }
    printf("\n");
}

int main(void)
{
    test_ft_strdup();
    return 0;
}
