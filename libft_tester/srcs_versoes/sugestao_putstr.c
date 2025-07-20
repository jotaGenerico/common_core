#include "libft.h"

static ssize_t	ft_write_all(int fd, const char *buf, size_t len)
{
	ssize_t	total_written = 0;
	ssize_t	written;

	while (len > 0)
	{
		written = write(fd, buf + total_written, len);
		if (written <= 0)
			return (written); // erro ou fim inesperado
		total_written += written;
		len -= written;
	}
	return (total_written);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_write_all(fd, s, ft_strlen(s));
}

// Como funciona:
//
// ft_write_all tenta escrever toda a string, mesmo se write escrever só parte dela numa chamada.
//
// Retorna total escrito ou erro se ocorrer.
//
// ft_putstr_fd chama essa função com a string e seu tamanho.
