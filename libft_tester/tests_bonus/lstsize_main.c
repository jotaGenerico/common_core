#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// Função auxiliar para liberar a lista (usada para limpar após os testes)
void free_list(t_list **head)
{
    t_list *current = *head;
    t_list *next_node;
    while (current)
    {
        next_node = current->next;
        if (current->content)
            free(current->content);
        free(current);
        current = next_node;
    }
    *head = NULL;
}

// Função para testar ft_lstsize
void test_ft_lstsize(const char *test_name, t_list *head, int expected_size)
{
    int actual_size = ft_lstsize(head);
    printf("--- Teste: %s ---\n", test_name);
    printf("  Tamanho da lista: %d\n", actual_size);
    printf("  Tamanho esperado: %d\n", expected_size);

    if (actual_size == expected_size)
        printf("✅ OK\n\n");
    else
        printf("❌ FALHA: Tamanho incorreto.\n\n");
}

int main(void)
{
    printf("=== Testando ft_lstsize ===\n\n");

    t_list *head = NULL;
    t_list *node1, *node2, *node3, *node4; // node4 agora será usado

    // Teste 1: Lista vazia
    test_ft_lstsize("Lista vazia", head, 0);

    // Teste 2: Lista com 1 elemento
    node1 = ft_lstnew(strdup("Node 1"));
    if (!node1) { printf("Falha ao alocar node1\n"); return 1; }
    ft_lstadd_front(&head, node1);
    test_ft_lstsize("Lista com 1 elemento", head, 1);

    // Teste 3: Lista com 2 elementos
    node2 = ft_lstnew(strdup("Node 2"));
    if (!node2) { printf("Falha ao alocar node2\n"); free_list(&head); return 1; }
    ft_lstadd_front(&head, node2);
    test_ft_lstsize("Lista com 2 elementos", head, 2);

    // Teste 4: Lista com 3 elementos
    node3 = ft_lstnew(strdup("Node 3"));
    if (!node3) { printf("Falha ao alocar node3\n"); free_list(&head); return 1; }
    ft_lstadd_front(&head, node3);
    test_ft_lstsize("Lista com 3 elementos", head, 3);

    // Teste 5: Lista com 4 elementos (usando node4)
    node4 = ft_lstnew(strdup("Node 4")); // Aloca node4
    if (!node4) { printf("Falha ao alocar node4\n"); free_list(&head); return 1; }
    ft_lstadd_front(&head, node4); // Adiciona node4
    test_ft_lstsize("Lista com 4 elementos", head, 4); // Testa a lista com 4 elementos

    // Teste 6: Lista com NULL no meio (se ft_lstnew permite NULL content)
    t_list *node_null_content = ft_lstnew(NULL);
    if (!node_null_content) { printf("Falha ao alocar node_null_content\n"); free_list(&head); return 1; }
    ft_lstadd_front(&head, node_null_content);
    test_ft_lstsize("Lista com content NULL", head, 5); // Tamanho deve contar o nó, mesmo com content NULL

    // Limpeza final
    free_list(&head);
    printf("Todos os testes para ft_lstsize concluidos.\n");

    return 0;
}
