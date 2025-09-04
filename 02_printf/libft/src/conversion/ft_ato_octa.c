/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_octa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:24:57 by jose-cad          #+#    #+#             */
/*   Updated: 2025/08/12 10:25:03 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_octal_digit(char c)
{
	return (c >= '0' && c <= '7');
}

unsigned int	ft_ato_octa(const char *str)
{
	unsigned int	result;
	int				i;

	if (!str)
		return (0);
	result = 0;
	i = 0;
	while (str[i])
	{
		if (!is_octal_digit(str[i]))
			return (0);
		result = result * 8 + (str[i] - '0');
		i++;
	}
	return (result);
}
