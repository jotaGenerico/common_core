/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:37:32 by jose-cad          #+#    #+#             */
/*   Updated: 2025/08/12 10:37:38 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_atohex_ptr(const char *hex_str)
{
	unsigned long	num;
	int				i;

	num = 0;
	i = 0;
	if (hex_str[i] == '0' && (hex_str[i + 1] == 'x' || hex_str[i + 1] == 'X'))
		i += 2;
	while (hex_str[i])
	{
		num *= 16;
		if (hex_str[i] >= '0' && hex_str[i] <= '9')
			num += hex_str[i] - '0';
		else if (hex_str[i] >= 'a' && hex_str[i] <= 'f')
			num += hex_str[i] - 'a' + 10;
		else if (hex_str[i] >= 'A' && hex_str[i] <= 'F')
			num += hex_str[i] - 'A' + 10;
		i++;
	}
	return (num);
}
