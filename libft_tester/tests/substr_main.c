#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcmp
#include "libft.h"

// Função auxiliar para imprimir resultados e comparar
void compare_substr_result(const char *test_name, const char *s, unsigned int start, size_t len, const char *expected_str)
{
    char *result_ft = ft_substr(s, start, len);

    // ft_substr deve retornar NULL se s for NULL ou se a alocação falhar (mas não para offset > strlen)
    // No seu caso, ft_substr("42 is the answer", 20, 5) deve retornar uma string vazia "", não NULL
    if ((result_ft == NULL && expected_str != NULL) || (result_ft != NULL && expected_str == NULL))
    {
        printf("❌ %s (s=\"%s\", start=%u, len=%zu): Ponteiro incorreto (esperado: %s, obtido: %s)\n",
               test_name, s, start, len, expected_str ? expected_str : "NULL", result_ft ? result_ft : "NULL");
    }
    else if (strcmp(result_ft ? result_ft : "", expected_str ? expected_str : "") == 0) // Compara strings, lida com NULL como ""
    {
        printf("✅ OK: %s (s=\"%s\", start=%u, len=%zu) -> \"%s\"\n",
               test_name, s, start, len, result_ft);
    }
    else
    {
        printf("❌ ERRO: %s (s=\"%s\", start=%u, len=%zu)\n", test_name, s, start, len);
        printf("    Esperado: \"%s\"\n", expected_str ? expected_str : "NULL");
        printf("    Obtido:   \"%s\"\n", result_ft ? result_ft : "NULL");
    }
    free(result_ft); // Libere a memória alocada pela sua ft_substr
}

void test_ft_substr(void)
{
    printf("=== Testando ft_substr ===\n");

    compare_substr_result("Substring no meio", "42 is the answer", 3, 2, "is");
    compare_substr_result("Substring do inicio", "42 is the answer", 0, 5, "42 is");
    compare_substr_result("Offset fora dos limites", "42 is the answer", 20, 5, "");
    compare_substr_result("String vazia", "", 0, 10, "");
    compare_substr_result("Len maior que o restante", "short", 2, 100, "ort");
    compare_substr_result("Substring de 1 caractere", "abc", 1, 1, "b");
    compare_substr_result("String de 1 caractere", "a", 0, 1, "a");
    compare_substr_result("Offset exato no fim", "end", 2, 1, "d");
    compare_substr_result("Offset no fim, len 0", "end", 3, 0, "");
    compare_substr_result("Offset no fim, len > 0", "end", 3, 5, "");


    printf("\n");
}

int main(void)
{
    test_ft_substr();
    return 0;
}
