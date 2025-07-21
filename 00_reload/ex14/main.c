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

int ft_sqrt(int nb);

int main(void)
{
    clock_t start, end;
    double  time_taken;
    int     nbr, square;

    nbr = 9;
    start = clock();
    square = ft_sqrt(nbr);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("square: %d\n", square);
    printf("execuçao: %f\n", time_taken);

    return (0);
}
