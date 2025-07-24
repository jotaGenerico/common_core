/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:01:55 by jose-cad          #+#    #+#             */
/*   Updated: 2025/07/21 11:01:59 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dsize == 0)
		return (src_len);
	if ((src_len + 1) < dsize)
		ft_memcpy(dest, src, src_len + 1);
	else
	{
		ft_memcpy(dest, src, dsize - 1);
		dest[dsize - 1] = '\0';
	}
	return (src_len);
}
