/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:25:00 by jose-cad          #+#    #+#             */
/*   Updated: 2025/07/10 09:48:50 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_sort(int len, char **array);
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int	i;
	int	args;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			ft_putchar(argv[1][i++]);
		ft_putchar('\n');
		return (0);
	}
	ft_sort(argc, argv);
	args = 1;
	while (args < argc)
	{
		i = 0;
		while (argv[args][i])
			ft_putchar(argv[args][i++]);
		ft_putchar('\n');
		args++;
	}
	return (0);
}

void	ft_sort(int len, char **array)
{
	char	*temp;
	int		i;
	int		j;

	i = 2;
	while (i < len)
	{
		j = i;
		while (j > 1)
		{
			if (ft_strcmp(array[j], array[j - 1]) < 0)
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
			else
				break ;
			j--;
		}
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
