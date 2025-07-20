#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_ft_strchr(void)
{
	const char *tests[] = {
		"42 São Paulo",
		"banana",
		"", // String vazia
		"abcabcabc",
		"ultimo teste valido" // Removido o NULL explícito, adicionei um teste válido
	};
	// Calcula o número de elementos válidos no array
	size_t num_tests = sizeof(tests) / sizeof(tests[0]);

	int chars[] = { '4', 'a', '\0', 'x', 'c', 'S', 'P' }; // Adicionei 'S' e 'P' para mais variedade
	size_t num_chars = sizeof(chars) / sizeof(int);
	size_t i, j;

	printf("=== Testando ft_strchr ===\n");

	for (i = 0; i < num_tests; i++) // Loop agora vai até o número de testes válidos
	{
		for (j = 0; j < num_chars; j++)
		{
			const char *str = tests[i];
			int ch = chars[j];

			// strchr/ft_strchr não devem receber NULL como 'str'
			// O teste não precisa de uma verificação 'if (str == NULL)' aqui se o array não contiver NULLs.

			char *std = strchr(str, ch);
			char *ft = ft_strchr(str, ch);

			printf("ft_strchr(\"%s\", '%c'):\n", str, (char)ch);

			// Comparação mais explícita para cobrir todos os casos
			if (std == ft) // Ambos NULL ou ambos apontam para o mesmo local
			{
				printf("  ✅ OK: Ponteiros iguais (ambos %s)\n", ft ? "válidos" : "NULL");
			}
			else if (std != NULL && ft != NULL && strcmp(std, ft) == 0) // Ambos válidos e conteúdo igual
			{
				printf("  ✅ OK: Conteúdo igual (apontam para \"%s\")\n", ft);
			}
			else // Discrepância
			{
				printf("  ❌ ERRO:\n");
				printf("    Esperado: %s (ponteiro: %p)\n", std ? std : "NULL", (void *)std);
				printf("    Obtido:   %s (ponteiro: %p)\n", ft ? ft : "NULL", (void *)ft);
			}
			printf("\n"); // Nova linha para separar os resultados de cada sub-teste
		}
	}
	printf("\n");
}

int	main(void)
{
	test_ft_strchr();
	return (0);
}
