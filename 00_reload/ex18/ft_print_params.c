/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:24:37 by jose-cad          #+#    #+#             */
/*   Updated: 2025/07/10 09:24:42 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	i;
	int	args;

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
