#include "libft.h"

static int	ft_word_count(char const *s, char c);
static int	ft_word_len(char const *s, char c);
static void	*ft_free_all(char **tab, int i);

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		while (*s == c)
			s++;
		res[i] = ft_substr(s, 0, ft_word_len(s, c));
		if (!res[i])
			return (ft_free_all(res, i));
		s += ft_word_len(s, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}

static int	ft_word_count(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	*ft_free_all(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

// int	main(void)
// {
// 	print_split_result("hello world test", ' ');
// 	print_split_result("   multiple   spaces   ", ' ');
// 	print_split_result(",,,,,start,end,,,", ',');
// 	print_split_result("one", ',');
// 	print_split_result("", ',');
// 	print_split_result(",,,,,", ',');
// 	print_split_result("a b c d e", ' ');
// 	return (0);
// }
