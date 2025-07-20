#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcmp
#include "libft.h"

// Função exemplo para passar para ft_strmapi
char to_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32); // converte para maiúsculo se índice par
	return (c);
}

// Nova função de mapeamento para testar outro cenário (ex: inverter case em impar)
char reverse_case_odd(unsigned int i, char c)
{
    if (i % 2 != 0) // Se o índice for ímpar
    {
        if (c >= 'a' && c <= 'z')
            return (c - 32); // Para maiúscula
        else if (c >= 'A' && c <= 'Z')
            return (c + 32); // Para minúscula
    }
    return (c);
}


// Função auxiliar para rodar um teste de ft_strmapi e imprimir o resultado
void run_strmapi_test(const char *test_name, const char *s, char (*f)(unsigned int, char), const char *expected_result)
{
    char *result_ft = ft_strmapi(s, f);

    printf("Teste: %s\n", test_name);
    printf("  Entrada: \"%s\"\n", s);
    printf("  Funcao de mapeamento: %s\n", test_name); // Simplificado para mostrar o nome do teste

    if (!result_ft)
    {
        printf("❌ FALHA: ft_strmapi retornou NULL.\n");
        return;
    }

    if (strcmp(result_ft, expected_result) == 0)
    {
        printf("✅ OK: Resultado: \"%s\"\n", result_ft);
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Esperado: \"%s\"\n", expected_result);
        printf("  Obtido:   \"%s\"\n", result_ft);
    }
    free(result_ft); // Libere a memória alocada pela ft_strmapi
    printf("\n");
}

void test_ft_strmapi(void)
{
	printf("=== Testando ft_strmapi ===\n");

    // Teste 1: Converter caracteres em índices pares para maiúsculas
	run_strmapi_test("Maiuscula em indice par", "abcdefg", to_upper_even, "AbCdEfG");

    // Teste 2: Inverter o case em índices ímpares
    run_strmapi_test("Inverter case em indice impar", "AbCdEfG", reverse_case_odd, "AdCbEfG");

    // Teste 3: String vazia
    run_strmapi_test("String vazia", "", to_upper_even, "");

    // Teste 4: String com um caractere
    run_strmapi_test("String de um caractere", "z", to_upper_even, "Z");

    // Teste 5: String que não deve ser modificada
    run_strmapi_test("Nao modificado", "12345", to_upper_even, "12345");
}

int main(void)
{
	test_ft_strmapi();
	return 0;
}
