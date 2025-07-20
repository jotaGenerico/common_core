#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int del_count = 0;

void del_test(void *content)
{
    if (content)
    {
        free(content);
        del_count++;
    }
}

void print_node(t_list *node)
{
    if (!node)
        printf("NULL");
    else if (!node->content)
        printf("(node sem conteúdo)");
    else
        printf("%s", (char *)node->content);
}

int main(void)
{
    // Teste 1: Nó NULL
    printf("\nTeste 1: Nó NULL\n");
    del_count = 0;
    ft_lstdelone(NULL, del_test);
    if (del_count == 0)
        printf("✅ Passou: Não deletou nada com nó NULL\n");
    else
        printf("❌ Falhou: Deletou algo com nó NULL\n");

    // Teste 2: Nó único
    printf("\nTeste 2: Nó único\n");
    del_count = 0;
    t_list *node = ft_lstnew(strdup("teste"));
    printf("Conteúdo antes: ");
    print_node(node);
    printf("\n");

    ft_lstdelone(node, del_test);

    if (del_count == 1)
        printf("✅ Passou: Deletou corretamente\n");
    else
        printf("❌ Falhou: Não deletou corretamente\n");

    // Teste 3: Del NULL
    printf("\nTeste 3: Del NULL\n");
    t_list *node2 = ft_lstnew(strdup("teste2"));
    ft_lstdelone(node2, NULL);
    printf("✅ Passou: Não crashou com del NULL\n");

    // Correção para evitar vazamento
    if (node2)
    {
        if (node2->content)
            free(node2->content);
        free(node2);
    }

    // Teste 4: Conteúdo NULL
    printf("\nTeste 4: Conteúdo NULL\n");
    del_count = 0;
    t_list *node3 = ft_lstnew(NULL);
    ft_lstdelone(node3, del_test);
    if (del_count == 0)
        printf("✅ Passou: Não tentou deletar conteúdo NULL\n");
    else
        printf("❌ Falhou: Tentou deletar conteúdo NULL\n");

    // Teste 5: Múltiplos nós (verificar se deleta apenas um)
    printf("\nTeste 5: Múltiplos nós\n");
    del_count = 0;
    t_list *node4 = ft_lstnew(strdup("primeiro"));
    t_list *node5 = ft_lstnew(strdup("segundo"));
    node4->next = node5;

    printf("Lista antes: ");
    print_node(node4);
    printf(" -> ");
    print_node(node5);
    printf("\n");

    ft_lstdelone(node4, del_test);

    if (del_count == 1)
        printf("✅ Passou: Deletou apenas um nó\n");
    else
        printf("❌ Falhou: Número incorreto de deleções\n");

    // Limpar o nó restante
    ft_lstdelone(node5, del_test);

    printf("\nTodos os testes concluídos!\n");
    return 0;
}
