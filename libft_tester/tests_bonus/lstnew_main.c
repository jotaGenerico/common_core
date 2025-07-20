#include <stdio.h>
#include <stdlib.h> // Para malloc, free
#include <string.h> // Para strcmp, strdup
#include "libft.h"

// Função auxiliar para rodar um teste de ft_lstnew e verificar o resultado
void run_lstnew_test(const char *test_name, void *content, int expected_to_be_null)
{
    t_list  *node;
    int     test_status = 1; // 1 para OK, 0 para FALHA

    printf("Teste: %s\n", test_name);

    node = ft_lstnew(content);

    if (expected_to_be_null)
    {
        if (node == NULL)
        {
            printf("✅ OK: Retornou NULL como esperado.\n\n");
        }
        else
        {
            printf("❌ FALHA: Esperava NULL, mas obteve %p.\n", (void *)node);
            printf("  Node->content: %p, Node->next: %p\n", node->content, (void *)node->next);
            test_status = 0;
            // Tenta liberar o que foi alocado indevidamente, se possível
            if (node->content && node->content == content) // Se o conteúdo for o mesmo ponteiro que passamos
                ; // Não libera, pois o ponteiro é do teste e não foi duplicado pela sua função.
            else if (node->content) // Se sua ft_lstnew alocar e duplicar o conteúdo, você precisaria liberar.
                free(node->content); // Cuidado aqui, depende da sua implementação.
            free(node);
        }
    }
    else // Espera um nó válido
    {
        if (node == NULL)
        {
            printf("❌ FALHA: Retornou NULL inesperadamente.\n\n");
            test_status = 0;
        }
        else
        {
            printf("  Nó alocado em: %p\n", (void *)node);
            // Verifica o conteúdo
            if (node->content == content) // ft_lstnew não deve duplicar o content
            {
                printf("✅ OK: Conteúdo do nó corresponde ao esperado (%p).\n", node->content);
            }
            else
            {
                printf("❌ FALHA: Conteúdo do nó está incorreto.\n");
                printf("  Esperado content: %p, Obtido content: %p\n", content, node->content);
                test_status = 0;
            }

            // Verifica o ponteiro next
            if (node->next == NULL)
            {
                printf("✅ OK: Ponteiro 'next' é NULL.\n");
            }
            else
            {
                printf("❌ FALHA: Ponteiro 'next' deveria ser NULL.\n");
                printf("  Obtido next: %p\n", (void *)node->next);
                test_status = 0;
            }
            // Libera o nó (e seu conteúdo, se aplicável, no caso de strdup)
            // Lembre-se: ft_lstnew NÃO DEVE DUPLICAR o conteúdo.
            // O teste passa um ponteiro para uma string literal ou strdup'd.
            if (content) // Se content não for NULL
            {
                // Se o content foi duplicado *pelo teste* (ex: strdup), o teste deve liberá-lo.
                // Se ft_lstnew duplicasse, seria preciso liberar node->content.
                // Mas, por padrão, ft_lstnew apenas armazena o ponteiro 'content'.
                // Então, se passamos strdup("string"), o strdup precisa ser liberado.
                // No nosso caso, passamos literais ou strdup'd explicitamente no main.
            }
            free(node);
        }
    }

    if (test_status)
        printf("\n");
    else
        printf("\n");
}

int main(void)
{
    printf("=== Testando ft_lstnew ===\n\n");

    // Teste 1: Conteúdo normal (string literal)
    run_lstnew_test("Conteudo normal (string literal)", "Teste de conteudo", 0);

    // Teste 2: Conteúdo nulo
    run_lstnew_test("Conteudo NULL", NULL, 0); // ft_lstnew deve criar o nó, content = NULL

    // Teste 3: Conteúdo de um inteiro (void pointer)
    int num = 42;
    run_lstnew_test("Conteudo int (via void*)", &num, 0);

    // Teste 4: Conteúdo alocado dinamicamente (precisa ser liberado pelo teste)
    char *dyn_content = strdup("Conteudo alocado dinamicamente");
    if (dyn_content)
    {
        run_lstnew_test("Conteudo dinamico", dyn_content, 0);
        free(dyn_content); // Libera o conteúdo alocado pelo strdup no teste
    }
    else
    {
        printf("❌ ERRO: Falha na alocacao de dyn_content para o teste.\n\n");
    }

    // Teste 5: String vazia como conteúdo
    run_lstnew_test("String vazia", "", 0);

    return 0;
}
