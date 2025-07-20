#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	test_ft_tolower(void)
{
	int test_values[] = { 'A', 'Z', 'M', 'a', 'z', '0', '[', '{', -1, 200 };
	size_t i;

	printf("=== Testando ft_tolower ===\n");

	for (i = 0; i < sizeof(test_values) / sizeof(int); ++i)
	{
		int val = test_values[i];
		int ft = ft_tolower(val);
		int std = tolower(val);
		if (ft == std)
			printf("✅ ft_tolower(%3d '%c') = %3d '%c'\n", val, (val >= 32 && val <= 126 ? val : '.'), ft, (ft >= 32 && ft <= 126 ? ft : '.'));
		else
			printf("❌ ft_tolower(%3d '%c') = %3d, esperado: %3d\n", val, (val >= 32 && val <= 126 ? val : '.'), ft, std);
	}
	printf("\n");
}

int	main(void)
{
	test_ft_tolower();
	return 0;
}

