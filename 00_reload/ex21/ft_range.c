/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:54:17 by jose-cad          #+#    #+#             */
/*   Updated: 2025/07/09 09:54:20 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*range;

	if (min >= max)
		return (NULL);
	len = max - min;
	range = malloc(sizeof(int) * len);
	if (range == NULL)
		return (NULL);
	while (--len >= 0)
		range[len] = --max;
	return (range);
}
