#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_ft_strrchr(void)
{
	const char *tests[] = {
		"banana",
		"42 São Paulo",
		"abcabcabc",
		"",
		"xxxx",
		NULL
	};
	int chars[] = { 'a', '4', 'c', 'x', '\0' };
	size_t i, j;

	printf("=== Testando ft_strrchr ===\n");

	for (i = 0; i < sizeof(tests) / sizeof(char *); i++)
	{
		for (j = 0; j < sizeof(chars) / sizeof(int); j++)
		{
			const char *str = tests[i];
			int ch = chars[j];

			if (str == NULL)
			{
				printf("🛑 Skipping NULL string (não vamos invocar o demônio com ponteiro NULL)\n");
				continue;
			}

			char *std = strrchr(str, ch);
			char *ft = ft_strrchr(str, ch);

			if (std == ft)
				printf("✅ ft_strrchr(\"%s\", '%c') == %s\n", str, (char)ch, ft ? ft : "NULL");
			else if (std && ft && strcmp(std, ft) == 0)
				printf("✅ ft_strrchr(\"%s\", '%c') -> conteúdo igual: \"%s\"\n", str, (char)ch, ft);
			else
				printf("❌ ft_strrchr(\"%s\", '%c') = %s | esperado: %s\n",
					str, (char)ch,
					ft ? ft : "NULL",
					std ? std : "NULL");
		}
	}
	printf("\n");
}

int	main(void)
{
	test_ft_strrchr();
	return (0);
}

