#include <stdio.h>
#include <ctype.h> // Para a função isalpha original
#include "libft.h" // Para a sua função ft_isalpha

int	main(void)
{
	int	values[] = { 'a', 'Z', '0', '[', '~', '\n', -1, 127, 200 };
	int	i;

	printf("=== Testando ft_isalpha vs isalpha ===\n");
	for (i = 0; i < (int)(sizeof(values) / sizeof(int)); i++)
	{
		int val = values[i];
		int std = isalpha(val);   // Resultado da função original
		int ft = ft_isalpha(val); // Resultado da sua função

		// Verifica se ambos são verdadeiros OU se ambos são falsos
		if ((std != 0 && ft != 0) || (std == 0 && ft == 0))
		{
			printf("✅ OK: Char='%c' (%3d) | ft_isalpha: %d | isalpha: %d\n",
				(val >= 32 && val <= 126 ? val : '.'), val, ft, std);
		}
		else
		{
			printf("❌ ERRO: Char='%c' (%3d) | ft_isalpha: %d | esperado: %d (da original)\n",
				(val >= 32 && val <= 126 ? val : '.'), val, ft, std);
		}
	}
	return (0);
}
