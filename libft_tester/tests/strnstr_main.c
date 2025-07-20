#include <stdio.h>
#include <string.h>
#include "libft.h"

void print_result(const char *desc, const char *result, const char *expected)
{
	if ((result == NULL && expected == NULL)
		|| (result && expected && strcmp(result, expected) == 0))
	{
		printf("✅ %s: \"%s\"\n", desc, result ? result : "NULL");
	}
	else
	{
		printf("❌ %s:\n", desc);
		printf("    Esperado: %s\n", expected ? expected : "NULL");
		printf("    Obtido:   %s\n", result ? result : "NULL");
	}
}

void test_ft_strnstr(void)
{
	const char *big = "42 is the answer to life, the universe and everything";

	printf("=== Testando ft_strnstr ===\n");

	// Substring encontrada no meio
	print_result("substring no meio",
		ft_strnstr(big, "answer", 50),
		"answer to life, the universe and everything");

	// Substring no começo
	print_result("substring no começo",
		ft_strnstr(big, "42", 50),
		"42 is the answer to life, the universe and everything");

	// Substring no fim
	print_result("substring no fim",
		ft_strnstr(big, "everything", 50),
		"everything");

	// Substring não encontrada
	print_result("substring não encontrada",
		ft_strnstr(big, "banana", 50),
		NULL);

	// Needle maior que n
	print_result("needle mais longa que n",
		ft_strnstr("foobar", "ooba", 2),
		NULL);

	// Needle vazia
	print_result("needle vazia",
		ft_strnstr(big, "", 50),
		big);

	// Haystack vazia, needle não
	print_result("haystack vazia",
		ft_strnstr("", "42", 10),
		NULL);

	// Haystack vazia, needle vazia
	print_result("haystack e needle vazias",
		ft_strnstr("", "", 10),
		"");

	// n == 0
	print_result("n == 0",
		ft_strnstr("banana", "banana", 0),
		NULL);

	printf("\n");
}

int main(void)
{
	test_ft_strnstr();
	return 0;
}
