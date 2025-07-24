/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:00:35 by jose-cad          #+#    #+#             */
/*   Updated: 2025/07/21 11:00:38 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*duplicate;

	len = ft_strlen(s) + 1;
	duplicate = malloc(sizeof(char) * len);
	if (duplicate == NULL)
		return (NULL);
	ft_memcpy(duplicate, s, len);
	return (duplicate);
}
