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

// Função auxiliar para imprimir o conteúdo da lista
void print_list_content(const char *label, t_list *list)
{
	printf("  %s: [", label);
	if (!list)
	{
		printf("Lista Vazia]\n");
		return;
	}
	while (list)
	{
		printf("\"%s\"", list->content ? (char *)list->content : "(NULL)");
		list = list->next;
		if (list)
			printf(" -> ");
	}
	printf("]\n");
}

// Função para rodar um teste específico para ft_lstadd_back
void run_lstadd_back_test(const char *test_name, t_list **head_ptr, t_list *new_node_to_add, const char *expected_last_content, int expected_size_after)
{
	printf("--- Teste: %s ---\n", test_name);
	print_list_content("Estado inicial", *head_ptr);

	int old_size = ft_lstsize(*head_ptr);

	ft_lstadd_back(head_ptr, new_node_to_add);

	print_list_content("Estado final", *head_ptr);
	int current_size = ft_lstsize(*head_ptr);
	t_list *last_node = ft_lstlast(*head_ptr);

	int test_ok = 1;

	// Verifica aumento de tamanho
	if (new_node_to_add)
	{
		if (current_size != old_size + 1)
		{
			printf("  ❌ Erro de tamanho: Esperado %d, Obtido %d\n", old_size + 1, current_size);
			test_ok = 0;
		}
	}
	else
	{
		if (current_size != old_size)
		{
			printf("  ❌ Erro de tamanho (NULL node): Esperado %d, Obtido %d\n", old_size, current_size);
			test_ok = 0;
		}
	}

	// Verifica ponteiro do último nó e conteúdo
	if (new_node_to_add)
	{
		if (last_node != new_node_to_add)
		{
			printf("  ❌ Erro de ultimo no (ponteiro): Esperado %p, Obtido %p\n", (void *)new_node_to_add, (void *)last_node);
			test_ok = 0;
		}
		if (strcmp(expected_last_content, "(NULL)") == 0)
		{
			if (last_node->content != NULL)
			{
				printf("  ❌ Erro de conteudo do ultimo no: Esperado (NULL), Obtido \"%s\"\n", (char *)last_node->content);
				test_ok = 0;
			}
		}
		else
		{
			if (!last_node || !last_node->content || strcmp((char *)last_node->content, expected_last_content) != 0)
			{
				printf("  ❌ Erro de conteudo do ultimo no: Esperado \"%s\", Obtido \"%s\"\n",
					   expected_last_content,
					   last_node && last_node->content ? (char *)last_node->content : "(NULL)");
				test_ok = 0;
			}
		}
	}

	// Verifica tamanho final esperado
	if (current_size != expected_size_after)
	{
		printf("  ❌ Erro de tamanho final: Esperado %d, Obtido %d\n", expected_size_after, current_size);
		test_ok = 0;
	}

	test_ok ? printf("✅ OK\n\n") : printf("❌ FALHA!\n\n");
}

int main(void)
{
	printf("=== Testando ft_lstadd_back ===\n\n");

	t_list *head = NULL;
	t_list *node1, *node2, *node3, *node_null_content, *node_empty_content;

	// Teste 1: Adicionar à lista vazia
	node1 = ft_lstnew(strdup("Primeiro"));
	if (!node1)
		return (perror("Falha ao alocar node1"), 1);
	run_lstadd_back_test("Adicionar a lista vazia", &head, node1, "Primeiro", 1);

	// Teste 2: Adicionar com 1 elemento
	node2 = ft_lstnew(strdup("Segundo"));
	if (!node2)
		return (free_list(&head), perror("Falha ao alocar node2"), 1);
	run_lstadd_back_test("Adicionar a lista com 1 elemento", &head, node2, "Segundo", 2);

	// Teste 3: Adicionar com múltiplos elementos
	node3 = ft_lstnew(strdup("Terceiro"));
	if (!node3)
		return (free_list(&head), perror("Falha ao alocar node3"), 1);
	run_lstadd_back_test("Adicionar a lista com multiplos elementos", &head, node3, "Terceiro", 3);

	// Teste 4: Adicionar nó com content NULL
	node_null_content = ft_lstnew(NULL);
	if (!node_null_content)
		return (free_list(&head), perror("Falha ao alocar node_null_content"), 1);
	run_lstadd_back_test("Adicionar no com content NULL", &head, node_null_content, "(NULL)", 4);

	// Teste 5: Adicionar nó com content vazio
	node_empty_content = ft_lstnew(strdup(""));
	if (!node_empty_content)
		return (free_list(&head), perror("Falha ao alocar node_empty_content"), 1);
	run_lstadd_back_test("Adicionar no com content vazio", &head, node_empty_content, "", 5);

	// Teste 6: Adicionar NULL (não deve mudar nada)
	run_lstadd_back_test("Tentar adicionar um NULL como novo no (ignorado pela 42)", &head, NULL, "", 5);

	// Limpeza final
	free_list(&head);
	printf("Todos os testes para ft_lstadd_back concluidos.\n");

	return 0;
}
