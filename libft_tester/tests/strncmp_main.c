#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_ft_strncmp(void)
{
	struct {
		const char *s1;
		const char *s2;
		size_t n;
	} tests[] = {
		{"banana", "banana", 6},
		{"banana", "banaba", 6},
		{"banana", "banaba", 3},
		{"abc", "abd", 3},
		{"abc", "abcd", 10},
		{"abcd", "abc", 10},
		{"", "", 1},
		{"abc", "", 1},
		{"", "abc", 1},
		{"42sp", "42SP", 4},
		{"\200", "\0", 1},   // testes com valores não ASCII
	};

	size_t i;
	printf("=== Testando ft_strncmp ===\n");
	for (i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
	{
		const char *s1 = tests[i].s1;
		const char *s2 = tests[i].s2;
		size_t n = tests[i].n;

		int std = strncmp(s1, s2, n);
		int ft = ft_strncmp(s1, s2, n);

		if ((std == 0 && ft == 0) || (std < 0 && ft < 0) || (std > 0 && ft > 0))
			printf("✅ ft_strncmp(\"%s\", \"%s\", %zu) == %d\n", s1, s2, n, ft);
		else
			printf("❌ ft_strncmp(\"%s\", \"%s\", %zu) == %d | esperado: %d\n", s1, s2, n, ft, std);
	}
	printf("\n");
}

int	main(void)
{
	test_ft_strncmp();
	return (0);
}

