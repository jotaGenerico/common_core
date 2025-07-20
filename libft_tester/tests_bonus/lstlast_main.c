#include <stdio.h>
#include <stdlib.h> // Para malloc, free
#include <string.h> // Para strcmp, strdup
#include "libft.h"

// Função auxiliar para liberar a memória de uma lista para evitar vazamentos no teste
void free_list(t_list **head)
{
    t_list *current;
    t_list *next;

    if (!head || !*head)
        return;

    current = *head;
    while (current)
    {
        next = current->next;
        free(current->content); // Libera o conteúdo se for alocado dinamicamente
        free(current);
        current = next;
    }
    *head = NULL;
}

// Função auxiliar para rodar um teste de ft_lstlast e verificar o resultado
void run_lstlast_test(const char *test_name, t_list **head, t_list *expected_last_node, const char *expected_content)
{
    t_list *ft_last;
    int     test_status = 1;

    printf("Teste: %s\n", test_name);

    ft_last = ft_lstlast(*head);

    // 1. Verifica se o ponteiro retornado é o esperado
    if (ft_last == expected_last_node)
    {
        printf("✅ OK: Ponteiro do ultimo no corresponde ao esperado.\n");
    }
    else
    {
        printf("❌ FALHA: Ponteiro do ultimo no NAO corresponde.\n");
        printf("  Esperado ponteiro: %p\n", (void *)expected_last_node);
        printf("  Obtido ponteiro:   %p\n", (void *)ft_last);
        test_status = 0;
    }

    // 2. Se o ponteiro não for NULL, verifica o conteúdo
    if (ft_last != NULL)
    {
        if (ft_last->content && expected_content && strcmp((char *)ft_last->content, expected_content) == 0)
        {
            printf("✅ OK: Conteudo do ultimo no corresponde ao esperado ('%s').\n", (char *)ft_last->content);
        }
        else if (!ft_last->content && !expected_content)
        {
             printf("✅ OK: Conteudo do ultimo no é NULL como esperado.\n");
        }
        else
        {
            printf("❌ FALHA: Conteudo do ultimo no esta incorreto.\n");
            printf("  Esperado conteudo: '%s'\n", expected_content ? expected_content : "NULL");
            printf("  Obtido conteudo:   '%s'\n", ft_last->content ? (char *)ft_last->content : "NULL");
            test_status = 0;
        }
    }
    else // ft_last é NULL
    {
        if (expected_last_node != NULL) // Se esperávamos um nó e obtivemos NULL
        {
             printf("❌ FALHA: ft_lstlast retornou NULL inesperadamente.\n");
             test_status = 0;
        }
    }

    if (test_status)
        printf("\n");
    else
        printf("\n");
}

int main(void)
{
    t_list *head = NULL;
    t_list *node1;
    t_list *node2;
    t_list *node3;
    t_list *node_null_content;

    printf("=== Testando ft_lstlast ===\n\n");

    // Teste 1: Lista vazia
    run_lstlast_test("Lista vazia", &head, NULL, NULL);

    // Teste 2: Lista com um único nó
    node1 = ft_lstnew(strdup("Primeiro"));
    ft_lstadd_back(&head, node1);
    run_lstlast_test("Lista com um no", &head, node1, "Primeiro");
    free_list(&head); // Limpa para o próximo teste

    // Teste 3: Lista com múltiplos nós
    node1 = ft_lstnew(strdup("A"));
    node2 = ft_lstnew(strdup("B"));
    node3 = ft_lstnew(strdup("C"));
    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);
    run_lstlast_test("Lista com multiplos nos", &head, node3, "C");
    free_list(&head); // Limpa para o próximo teste

    // Teste 4: Lista com nós e conteúdo NULL
    node1 = ft_lstnew(strdup("Um"));
    node_null_content = ft_lstnew(NULL); // Nó com conteúdo NULL
    node2 = ft_lstnew(strdup("Dois"));
    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node_null_content);
    ft_lstadd_back(&head, node2);
    run_lstlast_test("Lista com conteudo NULL", &head, node2, "Dois");
    free_list(&head);

    return 0;
}
