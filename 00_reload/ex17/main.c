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
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*str1, *str2;
	char	*str3, *str4;

	str1 = "confia no processo";
	str2 = "confia no processo";
	str3 = "processo";
	str4 = "";

	printf("minha iguais: %d\n", ft_strcmp(str1, str2));
	printf("lib iguais: %d\n", strcmp(str1, str2));

	printf("minha maior: %d\n", ft_strcmp(str1, str3));
	printf("lib maior: %d\n", strcmp(str1, str3));

	printf("minha menor: %d\n", ft_strcmp(str3, str2));
	printf("lib menor: %d\n", strcmp(str3, str2));

	printf("minha vazia: %d\n", ft_strcmp(str1, str4));
	printf("lib vazia: %d\n", strcmp(str1, str4));

	printf("minha vazia: %d\n", ft_strcmp(str4, str2));
	printf("lib vazia: %d\n", strcmp(str4, str2));

	return (0);
}
