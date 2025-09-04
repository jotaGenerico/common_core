/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:24:31 by jose-cad          #+#    #+#             */
/*   Updated: 2025/08/12 10:24:41 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_bin_digit(char c)
{
	return (c == '0' || c == '1');
}

unsigned int	ft_ato_bin(const char *str)
{
	unsigned int	result;
	int				i;

	if (!str)
		return (0);
	result = 0;
	i = 0;
	while (str[i])
	{
		if (!is_bin_digit(str[i]))
			return (0);
		result = result * 2 + (str[i] - '0');
		i++;
	}
	return (result);
}
