#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// Função auxiliar para imprimir resultados e comparar
void compare_strtrim_result(const char *test_name, const char *s1, const char *set, const char *expected_str)
{
    char *result_ft = ft_strtrim(s1, set);

    // Assegura que ambos os ponteiros não são NULL e compara
    if ((result_ft == NULL && expected_str != NULL) || (result_ft != NULL && expected_str == NULL))
    {
        printf("❌ %s (s1=\"%s\", set=\"%s\"): Ponteiro incorreto (esperado: %s, obtido: %s)\n",
               test_name, s1, set, expected_str ? expected_str : "NULL", result_ft ? result_ft : "NULL");
    }
    else if (strcmp(result_ft ? result_ft : "", expected_str ? expected_str : "") == 0)
    {
        printf("✅ OK: %s (s1=\"%s\", set=\"%s\") -> \"%s\"\n",
               test_name, s1, set, result_ft);
    }
    else
    {
        printf("❌ ERRO: %s (s1=\"%s\", set=\"%s\")\n", test_name, s1, set);
        printf("    Esperado: \"%s\"\n", expected_str ? expected_str : "NULL");
        printf("    Obtido:   \"%s\"\n", result_ft ? result_ft : "NULL");
    }
    free(result_ft); // Libere a memória alocada
}

void test_ft_strtrim(void)
{
    printf("=== Testando ft_strtrim ===\n");

    compare_strtrim_result("Espacos padrao", "   Hello World   ", " ", "Hello World");
    compare_strtrim_result("Caracteres abc", "abcHelloabc", "abc", "Hello");
    compare_strtrim_result("Mix de caracteres", "xyzHello Worldzyx", "xyz ", "Hello World");
    compare_strtrim_result("Set vazio", "NoTrim", "", "NoTrim");
    compare_strtrim_result("String vazia", "", " ", "");
    compare_strtrim_result("Apenas chars do set", "   ", " ", "");
    compare_strtrim_result("Apenas chars do set com mix", "aaaaabbbbaaaa", "ab", "");
    compare_strtrim_result("Sem trim", "NoTrimAtAll", " ", "NoTrimAtAll");
    compare_strtrim_result("Trim de um lado", "  Hello", " ", "Hello");
    compare_strtrim_result("Trim do outro lado", "Hello  ", " ", "Hello");

    printf("\n");
}

int main(void)
{
    test_ft_strtrim();
    return 0;
}
