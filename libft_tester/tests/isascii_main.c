#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void test_ft_isascii(void)
{
	int test_values[] = { -1, 0, 31, 32, 65, 127, 128, 255 };
	size_t i;

	printf("=== Testando ft_isascii ===\n");
	for (i = 0; i < sizeof(test_values)/sizeof(int); ++i)
	{
		int val = test_values[i];
		int std = isascii(val);
		int ft = ft_isascii(val);
		if ((std && ft) || (!std && !ft))
			printf("OK: ft_isascii(%3d) == %d\n", val, ft);
		else
			printf("❌ ERRO: ft_isascii(%3d) == %d | esperado: %d\n", val, ft, std);
	}
	printf("\n");
}

int main(void)
{
	test_ft_isascii();
	return 0;
}

