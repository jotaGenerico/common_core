#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	const char *tests[] = {
		"",
		"42",
		"liberdade",
		"essa é uma string mais longa com espaços",
		"\n\t\v",
		"😎",
	};
	size_t i;

	printf("=== Testando ft_strlen ===\n");
	for (i = 0; i < sizeof(tests) / sizeof(char *); ++i)
	{
		size_t std = strlen(tests[i]);
		size_t ft = ft_strlen(tests[i]);
		if (std == ft)
			printf("✅ OK: ft_strlen(\"%s\") == %zu\n", tests[i], ft);
		else
			printf("❌ ERRO: ft_strlen(\"%s\") == %zu | esperado: %zu\n", tests[i], ft, std);
	}
	return (0);
}
