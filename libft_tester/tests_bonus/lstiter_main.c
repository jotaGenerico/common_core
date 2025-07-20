#include <stdio.h>
#include <stdlib.h> // Para malloc, free
#include <string.h> // Para strcmp, strdup
#include "libft.h"

// Variáveis globais para rastrear as chamadas da função de iteração
static int iter_calls_count = 0;
static char *iter_last_content_processed = NULL;

// Função de iteração de teste: imprime e atualiza contadores
void	f_iter_test(void *content)
{
	iter_calls_count++;
	if (content)
		iter_last_content_processed = (char *)content; // Apenas para fins de depuração/verificação
	// printf("  [f_iter_test] Conteudo: '%s'\n", (char *)content); // Descomente para depurar
}

// Função de iteração que simula a modificação do conteúdo
// (Note: ft_lstiter não deve modificar o conteúdo, mas a função f pode tentar)
void    f_modify_content(void *content)
{
    char *str = (char *)content;
    if (str && strlen(str) > 0)
    {
        str[0] = 'M'; // Modifica o primeiro caractere
    }
    iter_calls_count++;
}


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

// Função auxiliar para rodar um teste de ft_lstiter e verificar o resultado
void run_lstiter_test(const char *test_name, char **initial_contents, size_t num_nodes, void (*f_ptr)(void *), int expected_calls)
{
    t_list *head = NULL;
    t_list *original_head_copy = NULL; // Para garantir que a lista original não mude
    int     test_status = 1;

    printf("--- Teste: %s ---\n", test_name);

    // Constrói a lista e uma cópia para verificação
    for (size_t i = 0; i < num_nodes; i++)
    {
        ft_lstadd_back(&head, ft_lstnew(strdup(initial_contents[i])));
        ft_lstadd_back(&original_head_copy, ft_lstnew(strdup(initial_contents[i])));
    }

    // Resetar contadores antes de cada execução de teste
    iter_calls_count = 0;
    iter_last_content_processed = NULL;

    printf("  Chamando ft_lstiter...\n");
    ft_lstiter(head, f_ptr);
    printf("  ft_lstiter concluida.\n");

    // 1. Verificar o número de chamadas da função 'f'
    if (iter_calls_count == expected_calls)
    {
        printf("✅ OK: Funcao 'f' chamada %d vezes como esperado.\n", iter_calls_count);
    }
    else
    {
        printf("❌ FALHA: Funcao 'f' esperava %d chamadas, mas teve %d.\n", expected_calls, iter_calls_count);
        test_status = 0;
    }

    // 2. Verificar se a lista original NÃO foi modificada por ft_lstiter (apenas por f)
    // ft_lstiter não deve modificar a estrutura da lista, mas f_ptr pode modificar o conteúdo.
    // Se o f_ptr modifica o conteúdo (como f_modify_content), a comparação abaixo falhará.
    // Apenas verifique se a estrutura da lista permanece a mesma.
    printf("  Verificando se a lista original nao foi modificada (estrutura).\n");
    t_list *current_original = head;
    t_list *current_copy = original_head_copy;
    int structural_match = 1;
    while (current_original || current_copy)
    {
        if ((current_original && !current_copy) || (!current_original && current_copy) ||
            (current_original && current_copy && (current_original->content == NULL) != (current_copy->content == NULL)))
        {
            structural_match = 0; // Estrutura (ou content NULL) difere
            break;
        }
        current_original = current_original ? current_original->next : NULL;
        current_copy = current_copy ? current_copy->next : NULL;
    }

    if (structural_match)
        printf("✅ OK: Estrutura da lista original nao foi alterada.\n");
    else
    {
        printf("❌ FALHA: Estrutura da lista original foi alterada!\n");
        test_status = 0;
    }


    if (test_status)
        printf("Resultado final do teste: ✅ OK\n\n");
    else
        printf("Resultado final do teste: ❌ FALHA\n\n");

    // Libera a memória
    free_list(&head);
    free_list(&original_head_copy); // Libera a cópia também
}

int main(void)
{
    printf("=== Testando ft_lstiter ===\n\n");

    // Teste 1: Lista com múltiplos nós, função 'f_iter_test'
    char *contents1[] = {"Node A", "Node B", "Node C"};
    run_lstiter_test("Multiplos nos (f_iter_test)", contents1, 3, f_iter_test, 3);

    // Teste 2: Lista vazia
    char *contents2[] = {};
    run_lstiter_test("Lista vazia", contents2, 0, f_iter_test, 0);

    // Teste 3: Lista com um único nó
    char *contents3[] = {"Single Node"};
    run_lstiter_test("Unico no", contents3, 1, f_iter_test, 1);

    // Teste 4: Lista com conteúdo NULL
    t_list *head_null_content = ft_lstnew(strdup("First"));
    ft_lstadd_back(&head_null_content, ft_lstnew(NULL)); // Conteúdo NULL
    ft_lstadd_back(&head_null_content, ft_lstnew(strdup("Last")));

    iter_calls_count = 0; // Reset
    printf("--- Teste: Lista com Conteudo NULL (f_iter_test) ---\n");
    ft_lstiter(head_null_content, f_iter_test);
    if (iter_calls_count == 3)
        printf("✅ OK: Funcao 'f' chamada 3 vezes para lista com NULL content.\n\n");
    else
        printf("❌ FALHA: Funcao 'f' esperava 3 chamadas, mas teve %d.\n\n", iter_calls_count);
    free_list(&head_null_content);

    // Teste 5: Usando uma função 'f' que modifica o conteúdo (para verificar efeitos colaterais)
    // A estrutura deve permanecer, o conteúdo DEVE ser modificado.
    char *contents5[] = {"apple", "banana"};
    printf("--- Teste: Funcao 'f' que modifica conteudo (f_modify_content) ---\n");
    t_list *mod_head = ft_lstnew(strdup(contents5[0]));
    ft_lstadd_back(&mod_head, ft_lstnew(strdup(contents5[1])));

    iter_calls_count = 0; // Reset
    ft_lstiter(mod_head, f_modify_content);

    if (iter_calls_count == 2)
        printf("✅ OK: Funcao 'f' chamada 2 vezes.\n");
    else
        printf("❌ FALHA: Funcao 'f' esperava 2 chamadas, mas teve %d.\n", iter_calls_count);

    // Verifica se os conteúdos foram modificados como esperado por f_modify_content
    printf("  Verificando conteudos modificados:\n");
    if (mod_head && strcmp((char*)mod_head->content, "Mpple") == 0 &&
        mod_head->next && strcmp((char*)mod_head->next->content, "Manana") == 0)
    {
        printf("✅ OK: Conteudos modificados corretamente por f_modify_content.\n");
    }
    else
    {
        printf("❌ FALHA: Conteudos nao modificados como esperado por f_modify_content.\n");
    }
    printf("\n");
    free_list(&mod_head);

    return 0;
}
