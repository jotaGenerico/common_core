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
        free(current->content); // Libera o conteúdo se foi strdup'd no teste
        free(current);
        current = next;
    }
    *head = NULL;
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
void run_lstadd_front_test(const char *test_name, t_list **current_head, t_list *new_node_to_add, const char *expected_new_head_content, int expected_size_after)
{
    t_list *old_head = *current_head; // Guarda o ponteiro da head antes da adição
    int     test_status = 1;

    printf("--- Teste: %s ---\n", test_name);
    printf("  Lista antes: "); print_list_content("", *current_head);
    printf("  Adicionando nó: '%s' (%p)\n", (new_node_to_add && new_node_to_add->content) ? (char *)new_node_to_add->content : "NULL", (void *)new_node_to_add);

    ft_lstadd_front(current_head, new_node_to_add);

    printf("  Lista depois: "); print_list_content("", *current_head);

    // 1. Verificar se a nova head é o nó adicionado
    if (*current_head == new_node_to_add)
    {
        printf("✅ OK: 'head' aponta para o novo nó.\n");
    }
    else
    {
        printf("❌ FALHA: 'head' nao aponta para o novo no. Esperado: %p, Obtido: %p\n", (void *)new_node_to_add, (void *)*current_head);
        test_status = 0;
    }

    // 2. Verificar se o 'next' do novo nó aponta para a antiga head
    if (new_node_to_add && new_node_to_add->next == old_head)
    {
        printf("✅ OK: 'next' do novo no aponta para a antiga 'head'.\n");
    }
    else if (!new_node_to_add && old_head == *current_head) // Caso new_node_to_add for NULL, head não deve mudar
    {
        printf("✅ OK: 'new_node' NULL, 'head' nao mudou como esperado.\n");
    }
    else
    {
        printf("❌ FALHA: 'next' do novo no nao aponta para a antiga 'head'. Esperado: %p, Obtido: %p\n", (void *)old_head, (new_node_to_add ? (void *)new_node_to_add->next : (void *)0));
        test_status = 0;
    }

    // 3. Verificar o conteúdo do novo nó na head (se o nó for válido)
    if (new_node_to_add && *current_head && (*current_head)->content && expected_new_head_content && strcmp((char *)(*current_head)->content, expected_new_head_content) == 0)
    {
        printf("✅ OK: Conteudo da nova 'head' corresponde ao esperado ('%s').\n", expected_new_head_content);
    }
    else if (new_node_to_add && *current_head && !(*current_head)->content && !expected_new_head_content)
    {
         printf("✅ OK: Conteudo da nova 'head' é NULL como esperado.\n");
    }
    else if (new_node_to_add) // Se new_node_to_add não é NULL mas a verificação de conteúdo falhou
    {
        printf("❌ FALHA: Conteudo da nova 'head' esta incorreto. Esperado: '%s', Obtido: '%s'\n",
               expected_new_head_content ? expected_new_head_content : "NULL",
               (*current_head && (*current_head)->content) ? (char *)(*current_head)->content : "NULL");
        test_status = 0;
    }

    // 4. Verificar o tamanho da lista (opcional, mas bom para lista encadeada)
    int current_size = ft_lstsize(*current_head);
    if (current_size == expected_size_after)
    {
        printf("✅ OK: Tamanho da lista (%d) corresponde ao esperado.\n", current_size);
    }
    else
    {
        printf("❌ FALHA: Tamanho da lista incorreto. Esperado: %d, Obtido: %d.\n", expected_size_after, current_size);
        test_status = 0;
    }


    if (test_status)
        printf("Resultado final do teste: ✅ OK\n\n");
    else
        printf("Resultado final do teste: ❌ FALHA\n\n");
}

int main(void)
{
    t_list *head = NULL;
    t_list *node1, *node2, *node3, *node_null_content;

    printf("=== Testando ft_lstadd_front ===\n\n");

    // Teste 1: Adicionar a uma lista vazia
    node1 = ft_lstnew(strdup("Primeiro"));
    if (!node1) { printf("Falha alocar node1\n"); return 1; }
    run_lstadd_front_test("Adicionar a lista vazia", &head, node1, "Primeiro", 1);
    // head agora é node1

    // Teste 2: Adicionar a uma lista com 1 nó
    node2 = ft_lstnew(strdup("Novo Primeiro"));
    if (!node2) { printf("Falha alocar node2\n"); free_list(&head); return 1; }
    run_lstadd_front_test("Adicionar a lista com 1 no", &head, node2, "Novo Primeiro", 2);
    // head agora é node2, node2->next é node1

    // Teste 3: Adicionar a uma lista com múltiplos nós
    node3 = ft_lstnew(strdup("Mais Um Primeiro"));
    if (!node3) { printf("Falha alocar node3\n"); free_list(&head); return 1; }
    run_lstadd_front_test("Adicionar a lista com multiplos nos", &head, node3, "Mais Um Primeiro", 3);
    // head agora é node3, node3->next é node2

    // Teste 4: Adicionar um nó com conteúdo NULL
    node_null_content = ft_lstnew(NULL); // ft_lstnew deve criar o nó com content=NULL
    if (!node_null_content) { printf("Falha alocar node_null_content\n"); free_list(&head); return 1; }
    run_lstadd_front_test("Adicionar no com conteudo NULL", &head, node_null_content, NULL, 4);

    // Teste 5: Adicionar NULL como nó (não deve mudar a lista nem causar crash)
    // IMPORTANT: A especificação da 42 para ft_lstadd_front NÃO especifica o comportamento
    // quando `new` é NULL. Muitas implementações simplesmente retornam.
    // Este teste assume que nada acontece. Se sua ft_lstadd_front abortar, reveja a espec.
    printf("\n--- Teste: Adicionar um no NULL (sem alocar) ---\n");
    t_list *head_before_null_add = head; // Guarda a head antes
    int size_before_null_add = ft_lstsize(head);

    ft_lstadd_front(&head, NULL); // Chamada com NULL

    if (head == head_before_null_add && ft_lstsize(head) == size_before_null_add)
    {
        printf("✅ OK: Adicionar no NULL nao alterou a lista.\n\n");
    }
    else
    {
        printf("❌ FALHA: Adicionar no NULL alterou a lista.\n\n");
    }


    // Libera toda a memória alocada pelos testes
    free_list(&head);

    return 0;
}
