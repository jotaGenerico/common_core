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

#include "libft.h"

char	*ft_strnstr(const char *base, const char *target, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*target == '\0')
		return ((char *)base);
	while (i < len && base[i])
	{
		j = 0;
		while (target[j] && (i + j) < len && base[i + j] == target[j])
			j++;
		if (target[j] == '\0')
			return ((char *)&base[i]);
		i++;
	}
	return (NULL);
}
