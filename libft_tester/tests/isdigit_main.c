#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void test_ft_isdigit(void)
{
	int test_values[] = { '0', '5', '9', 'a', ' ', '/', 127, -1, 200 };
	size_t i;

	printf("=== Testando ft_isdigit ===\n");
	for (i = 0; i < sizeof(test_values)/sizeof(int); ++i)
	{
		int val = test_values[i];
		int std = isdigit(val);
		int ft = ft_isdigit(val);
		if ((std && ft) || (!std && !ft))
			printf("OK: ft_isdigit(%3d '%c') == %d\n", val,
				(val >= 32 && val <= 126 ? val : '.'), ft);
		else
			printf("❌ ERRO: ft_isdigit(%3d '%c') == %d | esperado: %d\n", val,
				(val >= 32 && val <= 126 ? val : '.'), ft, std);
	}
	printf("\n");
}

int main(void)
{
	test_ft_isdigit();
	return 0;
}
