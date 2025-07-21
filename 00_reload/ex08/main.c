/* ************************************************************************** */void	ft_putchar(char c);
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forty-two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drown-ed <drown-ed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 8888/88/88 88:88:88 by drown-ed          #+#    #+#             */
/*   Updated: 8888/88/88 88:88:88 by drown-ed         ###   ########.SP       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);
void	ft_putchar(char c);

int	main(void)
{
	int	nbr;

	nbr = -42;
	ft_is_negative(nbr);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
