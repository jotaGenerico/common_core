/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:50:16 by jose-cad          #+#    #+#             */
/*   Updated: 2025/07/21 10:50:21 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t	max_size;

	max_size = ~((size_t)0);
	if (nmemb != 0 && size != 0)
	{
		if (nmemb > max_size / size)
			return (NULL);
	}
	total_size = nmemb * size;
	if (total_size == 0)
		total_size = 1;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
