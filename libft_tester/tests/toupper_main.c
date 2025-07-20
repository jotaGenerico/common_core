#include <stdio.h>
#include <ctype.h> // Para a função toupper original
#include "libft.h" // Para a sua função ft_toupper

int	main(void)
{
	int	values[] = {
		'a', 'z', 'A', 'Z', '0', '9', ' ', '\n', '\t',
		-1, 127, 200, 255, 64, 91, 96, 123
	};
	int	num_values = sizeof(values) / sizeof(int);
	int	i;

	printf("=== Testando ft_toupper vs toupper ===\n");
	for (i = 0; i < num_values; i++)
	{
		int val = values[i];
		int std_res = toupper(val);   // Resultado da função original
		int ft_res = ft_toupper(val); // Resultado da sua função

		// Verifica se ambos os resultados são iguais
		if (std_res == ft_res)
		{
			printf("✅ OK: Char='%c' (ASCII: %3d) -> ft_toupper: '%c' (%3d) | toupper: '%c' (%3d)\n",
				(val >= 32 && val <= 126 ? val : '.'), val,
				(ft_res >= 32 && ft_res <= 126 ? ft_res : '.'), ft_res,
				(std_res >= 32 && std_res <= 126 ? std_res : '.'), std_res);
		}
		else
		{
			printf("❌ ERRO: Char='%c' (ASCII: %3d) -> ft_toupper: '%c' (%3d) | esperado: '%c' (%3d) (da original)\n",
				(val >= 32 && val <= 126 ? val : '.'), val,
				(ft_res >= 32 && ft_res <= 126 ? ft_res : '.'), ft_res,
				(std_res >= 32 && std_res <= 126 ? std_res : '.'), std_res);
		}
	}
	return (0);
}
