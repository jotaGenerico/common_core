#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

int main(void)
{
    // Cria ou abre um arquivo para escrita
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        // Verifica se houve erro ao abrir o arquivo
        perror("Error opening file");
        return 1;
    }

    // String a ser escrita no arquivo
    char *str = "Hello, World!\n";

    // Chama a função para escrever a string no arquivo
    ft_putendl_fd(str, fd);

    // Fecha o arquivo
    close(fd);

    return 0;
}
