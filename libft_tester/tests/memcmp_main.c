#include <stdio.h>
#include <string.h>
#include "libft.h"

void print_cmp(int std, int ft, const char *desc)
{
	if ((std == 0 && ft == 0) || (std < 0 && ft < 0) || (std > 0 && ft > 0))
		printf("✅ ft_memcmp %s: esperado=%d, obtido=%d\n", desc, std, ft);
	else
		printf("❌ ft_memcmp %s: esperado=%d, obtido=%d\n", desc, std, ft);
}

void test_ft_memcmp(void)
{
	printf("=== Testando ft_memcmp ===\n");

	const char *a = "abcdef";
	const char *b = "abcdeF";
	const char *c = "abcdefg";
	const char *d = "abcdeg";

	// Igualdade total
	print_cmp(memcmp(a, a, 6), ft_memcmp(a, a, 6), "igualdade total");

	// Igualdade parcial (até o 5º byte)
	print_cmp(memcmp(a, b, 5), ft_memcmp(a, b, 5), "igualdade parcial");

	// Diferença no último byte
	print_cmp(memcmp(a, b, 6), ft_memcmp(a, b, 6), "diferença no último byte");

	// Diferença em strings diferentes
	print_cmp(memcmp(a, c, 6), ft_memcmp(a, c, 6), "com string maior (c)");

	print_cmp(memcmp(c, d, 7), ft_memcmp(c, d, 7), "strings diferentes com n maior");

	// Comparar com n = 0 (sempre 0)
	print_cmp(memcmp(a, b, 0), ft_memcmp(a, b, 0), "n = 0 (sempre 0)");

	printf("\n");
}

int main(void)
{
	test_ft_memcmp();
	return 0;
}

