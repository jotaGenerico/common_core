#include <stdio.h>
#include <string.h> // Para strcmp
#include "libft.h"

// Função que converte caracteres em maiúsculo se índice for par
void to_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

// Função que converte caracteres em minúsculo se índice for ímpar
void to_lower_odd(unsigned int i, char *c)
{
    if (i % 2 != 0 && *c >= 'A' && *c <= 'Z')
        *c = *c + 32;
}

// Função auxiliar para rodar um teste de ft_striteri e imprimir o resultado
void run_striteri_test(const char *test_name, char *str_to_modify, void (*f)(unsigned int, char*), const char *expected_result)
{
    char original_str[100]; // Buffer para guardar a string original para impressão

    // Copia a string original para não modificar o literal, pois ft_striteri modifica in-place
    strncpy(original_str, str_to_modify, sizeof(original_str) - 1);
    original_str[sizeof(original_str) - 1] = '\0';

    printf("Teste: %s\n", test_name);
    printf("  Original: \"%s\"\n", original_str);

    ft_striteri(str_to_modify, f); // Chama sua função

    printf("  Modificado: \"%s\"\n", str_to_modify);

    if (strcmp(str_to_modify, expected_result) == 0)
    {
        printf("✅ OK\n\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Esperado: \"%s\"\n", expected_result);
        printf("  Obtido:   \"%s\"\n", str_to_modify);
        printf("\n");
    }
}

void test_ft_striteri(void)
{
	printf("=== Testando ft_striteri ===\n");

    // Para evitar modificar literais de string (que são somente leitura),
    // usamos arrays de char para os testes.
    char test1_str[] = "abcdefg";
    run_striteri_test("Maiuscula em indice par", test1_str, to_upper_even, "AbCdEfG");

    char test2_str[] = "AbCdEfG";
    run_striteri_test("Minuscula em indice impar", test2_str, to_lower_odd, "AbcDefG");

    char test3_str[] = "";
    run_striteri_test("String vazia", test3_str, to_upper_even, "");

    char test4_str[] = "HELLO";
    run_striteri_test("Sem modificacao (todos maiusculos)", test4_str, to_upper_even, "HELLO");

    char test5_str[] = "world";
    run_striteri_test("Modificacao simples", test5_str, to_upper_even, "World");

    printf("\n");
}

int main(void)
{
	test_ft_striteri();
	return 0;
}
