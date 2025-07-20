#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // Para strcmp
#include <fcntl.h>    // Para open, O_CREAT, O_WRONLY, O_TRUNC
#include <unistd.h>   // Para close, read, write
#include "libft.h"

// Função auxiliar para ler o conteúdo de um arquivo (reutilizada)
static char *read_file_content(const char *filename)
{
    int     fd;
    char    *buffer;
    ssize_t bytes_read;
    off_t   file_size;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        // perror("Erro ao abrir arquivo para leitura"); // Removido para não poluir a saída do teste
        return (NULL);
    }

    file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1)
    {
        // perror("Erro ao buscar tamanho do arquivo");
        close(fd);
        return (NULL);
    }
    lseek(fd, 0, SEEK_SET);

    buffer = (char *)malloc(file_size + 1);
    if (!buffer)
    {
        close(fd);
        // perror("Erro de alocacao de memoria");
        return (NULL);
    }

    bytes_read = read(fd, buffer, file_size);
    if (bytes_read == -1)
    {
        // perror("Erro ao ler arquivo");
        free(buffer);
        close(fd);
        return (NULL);
    }
    buffer[bytes_read] = '\0';

    close(fd);
    return (buffer);
}

// Função auxiliar para rodar um teste de ft_putchar_fd e verificar o resultado
void run_putchar_fd_test(const char *test_name, char char_to_write, const char *filename)
{
    int     fd;
    char    *read_data;
    char    expected_str[2]; // Para armazenar o caractere + null terminator
    int     test_status = 1;

    printf("Teste: %s\n", test_name);
    printf("  Escrevendo: '%c' (ASCII: %d) para \"%s\"\n", char_to_write, char_to_write, filename);

    // 1. Construir a string esperada
    expected_str[0] = char_to_write;
    expected_str[1] = '\0';

    // 2. Escrever no arquivo usando ft_putchar_fd
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Erro ao abrir/criar arquivo para escrita");
        printf("❌ FALHA: Nao foi possivel abrir o arquivo para escrita.\n\n");
        return;
    }
    ft_putchar_fd(char_to_write, fd);
    close(fd);

    // 3. Ler o conteúdo do arquivo
    read_data = read_file_content(filename);
    if (!read_data)
    {
        printf("❌ FALHA: Nao foi possivel ler o conteudo do arquivo.\n\n");
        return;
    }

    // 4. Comparar o conteúdo lido com a string esperada
    if (strcmp(read_data, expected_str) == 0)
    {
        printf("✅ OK: Conteudo do arquivo corresponde ao esperado.\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Esperado: \"%s\"\n", expected_str);
        printf("  Obtido:   \"%s\"\n", read_data);
        test_status = 0;
    }

    free(read_data);

    // 5. Limpar o arquivo de teste
    if (remove(filename) != 0)
    {
        perror("Aviso: Nao foi possivel remover o arquivo de teste");
    }

    if (test_status)
        printf("\n");
    else
        printf("\n");
}

void test_ft_putchar_fd(void)
{
    printf("=== Testando ft_putchar_fd ===\n");

    // Testes variados para ft_putchar_fd
    run_putchar_fd_test("Caractere normal", 'X', "putchar_fd_test1.txt");
    run_putchar_fd_test("Newline", '\n', "putchar_fd_test2.txt");
    run_putchar_fd_test("Digito", '5', "putchar_fd_test3.txt");
    run_putchar_fd_test("Espaco", ' ', "putchar_fd_test4.txt");
    run_putchar_fd_test("Caractere especial", '@', "putchar_fd_test5.txt");
    run_putchar_fd_test("Null terminator", '\0', "putchar_fd_test6.txt"); // Deve escrever um byte 0

    // Nota: Testar ft_putchar_fd para stdout (fd 1) exigiria captura de saída do terminal.
    printf("Verifique a saida do terminal para ft_putchar_fd(char, 1):\n");
    ft_putchar_fd('Y', 1);
    ft_putchar_fd('\n', 1); // Adiciona um newline para melhor visualização no terminal
    printf("\n");
}

int main(void)
{
    test_ft_putchar_fd();
    return 0;
}
