/* ************************************************************************** */
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

#include <stdio.h>

void	ft_putnbr(int n);
void	ft_square(int n);
void	ft_double(int n);
void	ft_foreach(int *tab, int length, void (*f)(int));

int	main(void)
{
	int	i;
	int	tab[5];
	int	length;

	i = 0;
	length = 5;
	while (i < length)
	{
		tab[i] = i + 1;
		i++;
	}
	ft_foreach(tab, length, &ft_putnbr);
	printf("\n");
	ft_foreach(tab, length, &ft_square);
	printf("\n");
	ft_foreach(tab, length, &ft_double);
	printf("\n");
	return (0);
}

void	ft_putnbr(int n)
{
	printf("%d\n", n);
}

void	ft_square(int n)
{
	printf("%d\n", n * n);
}

void	ft_double(int n)
{
	printf("%d\n", n * 2);
}
