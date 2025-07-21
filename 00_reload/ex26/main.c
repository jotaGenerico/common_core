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

int	ft_is_upper(char *str);
int	ft_count_if(char **tab, int length, int (*f)(char*));

int	main(void)
{
	int		length = 3;
	char	*tab[] = {"Ola", "MUNDO", "123", NULL};
	int		count;

	count = ft_count_if(tab, length, &ft_is_upper);
	printf("quantidade de strings capitalizadas: %d\n", count);
	return (0);
}

int	ft_is_upper(char *str)
{
	return (*str >= 'A' && *str <= 'Z');
}
