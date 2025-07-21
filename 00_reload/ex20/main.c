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

#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src);

int	main(int argc, char **argv)
{
	char	*copia;

	if (argc == 2)
	{
		copia = ft_strdup(argv[1]);
		if (copia != NULL)
		{
			printf("copia: %s\n", copia);
			free(copia);
			return (0);
		}
	}
	else
		return (1);
}
