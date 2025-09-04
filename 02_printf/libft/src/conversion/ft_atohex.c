/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:26:03 by jose-cad          #+#    #+#             */
/*   Updated: 2025/08/12 10:26:09 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_atohex(const char *str)
{
	unsigned int	result;
	int				i;

	result = 0;
	i = 0;
	if (!str)
		return (0);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		i = 2;
	while (str[i])
	{
		result *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		else
			return (0);
		i++;
	}
	return (result);
}
