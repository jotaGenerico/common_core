#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para memcmp
#include <limits.h> // Para SIZE_MAX (embora não seja comum testar overflow diretamente na 42)
#include "libft.h"

// Função auxiliar para rodar um teste de ft_calloc
void run_calloc_test(const char *test_name, size_t nmemb, size_t size, int expect_null)
{
    void    *arr_std = NULL;
    void    *arr_ft = NULL;
    int     test_status = 1; // 1 para OK, 0 para FALHA

    printf("Teste: %s\n", test_name);
    printf("  Alocando: nmemb=%zu, size=%zu (Total: %zu bytes)\n", nmemb, size, nmemb * size);

    arr_std = calloc(nmemb, size);
    arr_ft = ft_calloc(nmemb, size);

    if (expect_null)
    {
        if (arr_std == NULL && arr_ft == NULL)
        {
            printf("✅ OK: Ambos retornaram NULL como esperado.\n");
        }
        else
        {
            printf("❌ FALHA: Esperava NULL, mas obteve ft_calloc=%p, calloc=%p\n", arr_ft, arr_std);
            test_status = 0;
        }
    }
    else // Espera alocação bem-sucedida
    {
        if (!arr_std || !arr_ft)
        {
            printf("❌ FALHA: calloc original ou ft_calloc retornou NULL inesperadamente.\n");
            printf("  calloc: %p, ft_calloc: %p\n", arr_std, arr_ft);
            test_status = 0;
        }
        else
        {
            // Verifica se a memória está zerada
            if (memcmp(arr_std, arr_ft, nmemb * size) == 0)
            {
                printf("✅ OK: Memoria zerada corresponde.\n");
            }
            else
            {
                printf("❌ FALHA: Conteudo da memoria zerada difere.\n");
                printf("  Primeiros bytes (std): ");
                for (size_t i = 0; i < (nmemb * size > 16 ? 16 : nmemb * size); i++)
                    printf("%02X ", ((unsigned char *)arr_std)[i]);
                printf("\n");
                printf("  Primeiros bytes (ft):  ");
                for (size_t i = 0; i < (nmemb * size > 16 ? 16 : nmemb * size); i++)
                    printf("%02X ", ((unsigned char *)arr_ft)[i]);
                printf("\n");
                test_status = 0;
            }

            // Testar se é possível escrever na memória alocada
            if (nmemb * size > 0)
            {
                memset(arr_ft, 0xAA, nmemb * size); // Preenche ft_calloc com um padrão
                printf("  Escrita: Preenchido com 0xAA. Se nao segfaultou, esta OK para escrita.\n");
            }
        }
    }

    // Libera a memória
    free(arr_std);
    free(arr_ft);

    if (test_status)
        printf("\n");
    else
        printf("\n");
}

void test_ft_calloc(void)
{
    printf("=== Testando ft_calloc ===\n\n");

    // Teste 1: Alocação básica (como o seu original)
    run_calloc_test("Alocacao basica (5 ints)", 5, sizeof(int), 0);

    // Teste 2: Alocação de 1 byte
    run_calloc_test("Alocacao de 1 byte", 1, 1, 0);

    // Teste 3: Alocação de um tamanho maior
    run_calloc_test("Alocacao de 1000 chars", 1000, sizeof(char), 0);

    // Teste 4: nmemb = 0
    run_calloc_test("nmemb = 0", 0, sizeof(int), 0); // Deve retornar ponteiro válido, mas sem memória útil

    // Teste 5: size = 0
    run_calloc_test("size = 0", 10, 0, 0); // Deve retornar ponteiro válido, mas sem memória útil

    // Teste 6: nmemb = 0 e size = 0
    run_calloc_test("nmemb = 0, size = 0", 0, 0, 0); // Deve retornar ponteiro válido, mas sem memória útil

    // Teste 7: Alocação grande (para verificar estabilidade, cuidado com os limites da sua máquina)
    // Se nmemb * size for muito grande e causar overflow, calloc pode retornar NULL.
    // Não é comum para a 42 esperar testes de overflow explícitos para calloc.
    // Exemplo de um teste que pode falhar em máquinas com pouca RAM ou se o produto estourar SIZE_MAX
    // run_calloc_test("Alocacao muito grande (pode falhar)", 1024 * 1024, 1024, 0);

    // Teste 8: Outro tipo de dado
    run_calloc_test("Alocacao de 3 doubles", 3, sizeof(double), 0);
}

int main(void)
{
    test_ft_calloc();
    return 0;
}
