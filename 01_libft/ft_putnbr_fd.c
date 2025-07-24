/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:59:23 by jose-cad          #+#    #+#             */
/*   Updated: 2025/07/21 10:59:27 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putint(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putint(n, fd);
	}
	else
		ft_putint(n, fd);
}

static void	ft_putint(int n, int fd)
{
	if (n > 9)
		ft_putint(n / 10, fd);
	ft_putchar_fd("0123456789"[n % 10], fd);
}
