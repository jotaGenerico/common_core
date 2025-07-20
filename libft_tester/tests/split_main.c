#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcmp
#include "libft.h"

// Função auxiliar para liberar a memória de um array de strings
void free_split(char **split)
{
    int i = 0;
    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split); // Libera o array de ponteiros
}

// Função auxiliar para comparar dois arrays de strings
int compare_split_results(char **ft_res, const char **expected_res)
{
    int i = 0;
    while (expected_res[i] != NULL)
    {
        if (ft_res[i] == NULL || strcmp(ft_res[i], expected_res[i]) != 0)
            return (0); // Mismatch ou ft_res é mais curto
        i++;
    }
    // Verifica se ft_res não tem strings extras
    if (ft_res[i] != NULL)
        return (0); // ft_res é mais longo
    return (1); // Tudo corresponde
}

// Função auxiliar para imprimir arrays de strings (para depuração em caso de erro)
void print_split_debug(const char *label, char **split)
{
    int i = 0;
    printf("%s [\n", label);
    if (!split)
    {
        printf("  NULL\n");
        return;
    }
    while (split[i])
    {
        printf("  \"%s\",\n", split[i]);
        i++;
    }
    printf("]\n");
}


// Função para rodar um teste de ft_split
void run_split_test(const char *test_name, const char *s, char c, const char **expected_result)
{
    char **res_ft = ft_split(s, c);

    printf("Teste: %s\n", test_name);
    printf("  Entrada: \"%s\", delimitador: '%c'\n", s, c);

    if (compare_split_results(res_ft, expected_result))
    {
        printf("✅ OK\n\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        print_split_debug("  Obtido:", res_ft);
        // Construindo a string esperada para impressão
        int i = 0;
        printf("  Esperado: [\n");
        while (expected_result[i])
        {
            printf("    \"%s\",\n", expected_result[i]);
            i++;
        }
        printf("  ]\n\n");
    }
    free_split(res_ft);
}

void test_ft_split(void)
{
    printf("=== Testando ft_split ===\n");

    // Teste 1: Caso básico
    const char *exp1[] = {"Hello", "World", "from", "42", NULL};
    run_split_test("Caso basico", "Hello World from 42", ' ', exp1);

    // Teste 2: Multiplos delimitadores e nas bordas
    const char *exp2[] = {"abc", "def", "ghi", NULL};
    run_split_test("Multiplos delimitadores e bordas", "   abc   def   ghi   ", ' ', exp2);

    // Teste 3: String vazia
    const char *exp3[] = {NULL}; // ft_split("") deve retornar um array com apenas NULL
    run_split_test("String vazia", "", ' ', exp3);

    // Teste 4: Delimitador diferente
    const char *exp4[] = {"one", "two", "three", NULL};
    run_split_test("Delimitador diferente", "one;two;three", ';', exp4);

    // Teste 5: Apenas delimitadores
    const char *exp5[] = {NULL}; // ft_split(";;;;", ';') deve retornar um array com apenas NULL
    run_split_test("Apenas delimitadores", ";;;;", ';', exp5);

    // Teste 6: Nenhum delimitador
    const char *exp6[] = {"NoDelimiter", NULL};
    run_split_test("Nenhum delimitador", "NoDelimiter", ' ', exp6);

    // Teste 7: String com delimitadores no inicio e fim e no meio
    const char *exp7[] = {"a", "b", "c", NULL};
    run_split_test("Delimitadores inicio, fim e meio", " a b c ", ' ', exp7);

    // Teste 8: Outro tipo de delimitador (tab)
    const char *exp8[] = {"Hello", "World", NULL};
    run_split_test("Delimitador tab", "Hello\tWorld", '\t', exp8);

    // Teste 9: String com apenas um caractere
    const char *exp9[] = {"a", NULL};
    run_split_test("String de um caractere", "a", ' ', exp9);

    // Teste 10: Delimitador é o mesmo que o único caractere
    const char *exp10[] = {NULL};
    run_split_test("Delimitador = unico char", "a", 'a', exp10);

    printf("\n");
}

int main(void)
{
    test_ft_split();
    return 0;
}
