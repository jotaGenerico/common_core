#include <unistd.h>

static void	ft_write_all(int fd, const void *buf, size_t count)
{
	ssize_t written;
	size_t	total;

	total = 0;
	while (total < count)
	{
		written = write(fd, (const char *)buf + total, count - total);
		if (written <= 0)
			break ;
		total += written;
	}
}

static void	ft_putint(int n, int fd)
{
	if (n > 9)
		ft_putint(n / 10, fd);
	ft_write_all(fd, &"0123456789"[n % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_write_all(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_write_all(fd, "-", 1);
		n = -n;
		ft_putint(n, fd);
	}
	else
		ft_putint(n, fd);
}

// Explicação rápida:
//
// ft_write_all tenta escrever tudo, repetindo se precisar.
//
// A lógica da impressão dos números não mudou, só substituímos write por ft_write_all.
//
// Continua simples e legível, fácil de entender e manter.
