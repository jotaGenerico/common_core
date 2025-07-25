/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:02:46 by jose-cad          #+#    #+#             */
/*   Updated: 2025/07/21 11:02:48 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last_position;
	unsigned char	uc;

	last_position = NULL;
	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			last_position = (char *)s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (last_position);
}
