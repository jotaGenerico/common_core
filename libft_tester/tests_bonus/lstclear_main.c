#include <stdio.h>
#include <stdlib.h> // Para malloc, free
#include <string.h> // Para strcmp, strdup
#include "libft.h"

// Contador para a função `del_for_test`
static int del_calls_count = 0;

// Função `del` de teste que conta as chamadas e libera o conteúdo
void del_for_test(void *content)
{
    if (content)
    {
        free(content); // Libera o strdup feito no teste
        del_calls_count++;
    }
}

// Função auxiliar para imprimir uma lista (para depuração)
void print_list_content(const char *label, t_list *list)
{
    printf("%s: [", label);
    while (list)
    {
        if (list->content)
            printf("'%s'", (char *)list->content);
        else
            printf("(NULL)");
        list = list->next;
        if (list)
            printf(" -> ");
    }
    printf("]\n");
}

// Função para rodar um teste específico
void run_lstclear_test(const char *test_name, char **initial_contents, size_t num_nodes, void (*del_func)(void *), int expected_del_calls)
{
    t_list *head = NULL;
    int     test_status = 1;

    printf("--- Teste: %s ---\n", test_name);

    // Constrói a lista
    for (size_t i = 0; i < num_nodes; i++)
    {
        t_list *new_node;
        if (initial_contents[i])
            new_node = ft_lstnew(strdup(initial_contents[i]));
        else
            new_node = ft_lstnew(NULL); // Para testar nós com conteúdo NULL

        if (!new_node)
        {
            fprintf(stderr, "Erro de alocacao para o teste '%s'!\n", test_name);
            // Tenta limpar o que já foi alocado para evitar vazamento no próprio teste
            ft_lstclear(&head, del_for_test);
            return;
        }
        ft_lstadd_back(&head, new_node);
    }

    printf("  Lista inicial: "); print_list_content("", head);

    del_calls_count = 0; // Resetar contador antes da chamada

    ft_lstclear(&head, del_func);

    // 1. Verificar se `head` se tornou NULL
    if (head == NULL)
    {
        printf("✅ OK: Ponteiro 'head' e NULL apos clear.\n");
    }
    else
    {
        printf("❌ FALHA: Ponteiro 'head' nao e NULL (%p).\n", (void *)head);
        test_status = 0;
    }

    // 2. Verificar o número de chamadas da função `del`
    if (del_calls_count == expected_del_calls)
    {
        printf("✅ OK: Funcao 'del' chamada %d vezes como esperado.\n", del_calls_count);
    }
    else
    {
        printf("❌ FALHA: Funcao 'del' esperava %d chamadas, mas teve %d.\n", expected_del_calls, del_calls_count);
        test_status = 0;
    }

    // Verificação de Valgrind: Se tudo estiver OK acima, o Valgrind deve reportar 0 vazamentos.

    if (test_status)
        printf("Resultado final do teste: ✅ OK\n\n");
    else
        printf("Resultado final do teste: ❌ FALHA\n\n");
}

int main(void)
{
    printf("=== Testando ft_lstclear ===\n\n");

    // Teste 1: Lista com 3 nós
    char *contents1[] = {"Node1", "Node2", "Node3"};
    run_lstclear_test("Lista com 3 nos", contents1, 3, del_for_test, 3);

    // Teste 2: Lista vazia
    char *contents2[] = {}; // Lista vazia
    run_lstclear_test("Lista vazia", contents2, 0, del_for_test, 0);

    // Teste 3: Lista com um único nó
    char *contents3[] = {"OnlyOne"};
    run_lstclear_test("Lista com um unico no", contents3, 1, del_for_test, 1);

    // Teste 4: Lista com nós e conteúdo NULL
    // A função `del` NÃO deve ser chamada para conteúdos NULL, apenas para os alocados.
    char *contents4[] = {"First", NULL, "Last"};
    run_lstclear_test("Lista com conteudo NULL", contents4, 3, del_for_test, 2); // 2 chamadas de del (para "First" e "Last")

    // Teste 5: Chamar com head = NULL (não deve fazer nada, e del não deve ser chamada)
    run_lstclear_test("Chamar com head = NULL", NULL, 0, del_for_test, 0);

    return (0);
}
