#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	int test_values[] = { -1, 0, 31, 32, 65, 90, 97, 122, 126, 127, 128 };
	size_t i;

	printf("=== Testando ft_isprint ===\n");
	for (i = 0; i < sizeof(test_values) / sizeof(int); ++i)
	{
		int val = test_values[i];
		int std = isprint(val);
		int ft = ft_isprint(val);
		if ((std && ft) || (!std && !ft))
			printf("✅ OK: ft_isprint(%3d '%c') == %d\n", val,
				(val >= 32 && val <= 126 ? val : '.'), ft);
		else
			printf("❌ ERRO: ft_isprint(%3d '%c') == %d | esperado: %d\n", val,
				(val >= 32 && val <= 126 ? val : '.'), ft, std);
	}
	return (0);
}
