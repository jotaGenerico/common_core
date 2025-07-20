#include "libft.h"

static ssize_t	ft_safe_write(int fd, const void *buf, size_t count)
{
	size_t		total_written;
	ssize_t		bytes_written;

	total_written = 0;
	while (total_written < count)
	{
		bytes_written = write(fd, (const char *)buf + total_written, count - total_written);
		if (bytes_written <= 0)
			return (-1);
		total_written += bytes_written;
	}
	return ((ssize_t)total_written);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (ft_safe_write(fd, s, len) == -1)
		return ;
	ft_safe_write(fd, "\n", 1);
}

// Explicação rápida:
//
// A função auxiliar ft_safe_write faz o loop até escrever tudo ou retornar erro.
//
// ft_putendl_fd usa essa função para escrever a string toda e depois o \n.
//
// Tudo simples, direto, e dentro do permitido (só usa write, tipos padrão e ft_strlen).
//
// Mantém o padrão de não imprimir erro ou sair, só tenta escrever o máximo possível.
