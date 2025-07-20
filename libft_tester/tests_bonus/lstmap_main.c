#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// Contador para a função `del`, para verificar se foi chamada
static int del_calls = 0;

void	del_for_test(void *content)
{
	if (content)
	{
		free(content);
		del_calls++;
	}
}

// Função de mapeamento que incrementa caracteres
// Retorna uma nova string alocada dinamicamente ou NULL em caso de falha
void	*f_increment_char(void *content)
{
	char	*str;
	size_t	len;
	char	*new_content;

	if (!content) // Handle NULL content gracefully
		return (NULL);

	str = (char *)content;
	len = strlen(str);
	new_content = (char *)malloc(len + 1);
	if (!new_content)
		return (NULL);

	for (size_t i = 0; i < len; i++)
		new_content[i] = str[i] + 1;
	new_content[len] = '\0';
	return (new_content);
}

// Função de mapeamento que sempre retorna NULL (para testar a função del)
void *f_returns_null(void *content)
{
    (void)content; // content não é usado, mas para evitar warnings
    return (NULL);
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

// Função auxiliar para comparar duas listas
int compare_lists(t_list *l1, t_list *l2)
{
    while (l1 && l2)
    {
        if (l1->content == NULL || l2->content == NULL) // Se um dos conteúdos for NULL
        {
            if (l1->content != l2->content) // Eles devem ser ambos NULL para serem iguais
                return (0);
        }
        else if (strcmp((char *)l1->content, (char *)l2->content) != 0)
        {
            return (0); // Conteúdo difere
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return (l1 == NULL && l2 == NULL); // Ambos devem terminar juntos
}

// Função auxiliar para liberar a memória de uma lista (duplicada para clareza no teste)
void ft_free_list_for_test(t_list **lst)
{
    t_list *current;
    t_list *next;

    if (!lst || !*lst)
        return;

    current = *lst;
    while (current)
    {
        next = current->next;
        if (current->content) // Se o conteúdo foi alocado, libera
            free(current->content);
        free(current);
        current = next;
    }
    *lst = NULL;
}


// Rodar um caso de teste para ft_lstmap
void run_lstmap_test(const char *test_name, char **initial_contents, size_t num_nodes,
                     void *(*f_ptr)(void *), void (*del_ptr)(void *),
                     char **expected_contents, int expected_del_calls_delta,
                     int check_original_list_unchanged)
{
    t_list *original_lst = NULL;
    t_list *original_lst_copy = NULL; // Para verificar se a original não foi alterada
    t_list *mapped_lst;
    t_list *expected_lst = NULL;
    int test_status = 1;

    printf("--- Teste: %s ---\n", test_name);

    // Crie a lista original
    for (size_t i = 0; i < num_nodes; i++)
    {
        ft_lstadd_back(&original_lst, ft_lstnew(strdup(initial_contents[i])));
        if (check_original_list_unchanged)
            ft_lstadd_back(&original_lst_copy, ft_lstnew(strdup(initial_contents[i]))); // Cópia para verificação
    }

    // Crie a lista esperada
    for (size_t i = 0; i < num_nodes; i++)
    {
        if (expected_contents[i])
            ft_lstadd_back(&expected_lst, ft_lstnew(strdup(expected_contents[i])));
        else
            ft_lstadd_back(&expected_lst, ft_lstnew(NULL)); // Para casos onde content é NULL
    }

    printf("  Lista original (antes): "); print_list_content("", original_lst);

    int initial_del_calls = del_calls;
    mapped_lst = ft_lstmap(original_lst, f_ptr, del_ptr);
    int final_del_calls = del_calls;

    printf("  Lista mapeada (obtida): "); print_list_content("", mapped_lst);
    printf("  Lista esperada:         "); print_list_content("", expected_lst);

    // 1. Verificar se a lista mapeada está correta
    if (compare_lists(mapped_lst, expected_lst))
    {
        printf("✅ OK: Lista mapeada corresponde ao esperado.\n");
    }
    else
    {
        printf("❌ FALHA: Lista mapeada nao corresponde ao esperado.\n");
        test_status = 0;
    }

    // 2. Verificar se a lista original NÃO foi modificada
    if (check_original_list_unchanged && !compare_lists(original_lst, original_lst_copy))
    {
        printf("❌ FALHA: Lista original foi modificada inesperadamente!\n");
        printf("  Original (depois): "); print_list_content("", original_lst);
        printf("  Copia original:    "); print_list_content("", original_lst_copy);
        test_status = 0;
    }
    else if (check_original_list_unchanged)
    {
         printf("✅ OK: Lista original NAO foi modificada.\n");
    }

    // 3. Verificar chamadas da função `del` (se relevante)
    if (expected_del_calls_delta != -1) // -1 indica que não estamos verificando del_calls neste teste
    {
        if ((final_del_calls - initial_del_calls) == expected_del_calls_delta)
        {
            printf("✅ OK: Funcao 'del' chamada %d vezes como esperado.\n", expected_del_calls_delta);
        }
        else
        {
            printf("❌ FALHA: Funcao 'del' esperava %d chamadas, mas teve %d.\n",
                   expected_del_calls_delta, (final_del_calls - initial_del_calls));
            test_status = 0;
        }
    }


    if (test_status)
        printf("Resultado final do teste: ✅ OK\n\n");
    else
        printf("Resultado final do teste: ❌ FALHA\n\n");

    // Libera a memória alocada pelo teste
    ft_lstclear(&original_lst, del_for_test); // Libera a lista original criada pelo teste
    ft_lstclear(&original_lst_copy, del_for_test); // Libera a cópia da lista original
    ft_lstclear(&mapped_lst, del_for_test);     // Libera a lista mapeada (seu ft_lstmap deve ter alocado o conteúdo)
    ft_lstclear(&expected_lst, del_for_test);   // Libera a lista esperada
}

int main(void)
{
    printf("=== Testando ft_lstmap ===\n\n");

    // Resetar contador de chamadas da função del
    del_calls = 0;

    // Teste 1: Mapeamento básico com incremento de caracteres
    char *initial1[] = {"abc", "def", "ghi"};
    char *expected1[] = {"bcd", "efg", "hij"};
    run_lstmap_test("Mapeamento basico", initial1, 3, f_increment_char, del_for_test, expected1, 0, 1);

    // Teste 2: Mapeamento de uma lista com um único nó
    char *initial2[] = {"X"};
    char *expected2[] = {"Y"};
    run_lstmap_test("Lista com um no", initial2, 1, f_increment_char, del_for_test, expected2, 0, 1);

    // Teste 3: Mapeamento de uma lista vazia
    char *initial3[] = {};
    char *expected3[] = {};
    run_lstmap_test("Lista vazia", initial3, 0, f_increment_char, del_for_test, expected3, 0, 1);

    // Teste 4: Mapeamento onde a função 'f' retorna NULL para alguns itens
    // Neste caso, o ft_lstmap deve descartar esses nós e chamar 'del' para seus conteúdos originais
    // E os nós previamente mapeados também devem ser liberados
    printf("--- Teste: Mapeamento onde 'f' retorna NULL ---\n");
    printf("  Atenção: Este teste verifica o comportamento de del quando f falha.\n");
    printf("  Se sua f_increment_char retornar NULL em algum caso, a del sera chamada.\n");
    printf("  A implementacao padrao de ft_lstmap deve limpar a lista parcialmente construida e retornar NULL\n");
    printf("  se *qualquer* chamada a 'f' retornar NULL.\n");

    del_calls = 0; // Reset calls for this specific test block

    t_list *fail_test_list = ft_lstnew(strdup("A"));
    ft_lstadd_back(&fail_test_list, ft_lstnew(strdup("B")));
    ft_lstadd_back(&fail_test_list, ft_lstnew(strdup("C")));

    t_list *result_list_fail = ft_lstmap(fail_test_list, f_returns_null, del_for_test);

    // Neste cenário, ft_lstmap deve retornar NULL
    if (result_list_fail == NULL)
    {
        printf("✅ OK: ft_lstmap retornou NULL quando 'f' retornou NULL.\n");
    }
    else
    {
        printf("❌ FALHA: ft_lstmap nao retornou NULL quando 'f' retornou NULL. Obtido: %p\n", (void*)result_list_fail);
        ft_lstclear(&result_list_fail, del_for_test); // Limpar se não for NULL
    }

    // Deve ter chamado del para todos os 3 conteúdos da lista original (se f_returns_null for chamada para todos)
    if (del_calls == 3) // Cada strdup para A, B, C deve ser liberado.
    {
        printf("✅ OK: 'del' foi chamado %d vezes como esperado (para limpar os conteudos da lista original).\n\n", del_calls);
    }
    else
    {
        printf("❌ FALHA: 'del' esperava ser chamado 3 vezes, mas foi %d.\n\n", del_calls);
    }
    ft_lstclear(&fail_test_list, del_for_test); // A lista original é liberada pelo teste aqui.


    // Teste 5: Conteúdo da lista original é NULL
    char *initial5[] = {"test", NULL, "final"};
    char *expected5[] = {"upsi", NULL, "gjobm"}; // 'test' -> 'upsi', NULL -> NULL, 'final' -> 'gjobm'
    del_calls = 0; // Reset counter
    run_lstmap_test("Conteudo NULL na lista original", initial5, 3, f_increment_char, del_for_test, expected5, 0, 1);


    return (0);
}
