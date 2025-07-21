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
#include <time.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	int	nbr;
	int	fatorial;
	clock_t start, end;
	double time_taken;

	nbr = 5;
	start = clock();
	fatorial = ft_iterative_factorial(nbr);
	end = clock();
	time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("fatorial de %d: %d\n", nbr, fatorial);
	printf("execuçao: %f segundos\n", time_taken);
	return (0);
}


