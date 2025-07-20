#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // Para strcmp, strlen
#include <fcntl.h>    // Para open, O_CREAT, O_WRONLY, O_TRUNC
#include <unistd.h>   // Para close, read, write
#include <limits.h>   // Para INT_MAX, INT_MIN
#include "libft.h"

// Função auxiliar para ler o conteúdo de um arquivo (reutilizada de putstr_fd_main.c)
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

// Função auxiliar para converter um int para string (usando sprintf, pois ft_itoa pode ser o que estamos testando)
// Ou você pode usar sua ft_itoa se ela já estiver 100% testada e funcionando.
static char *int_to_str_helper(int n)
{
    // Buffer grande o suficiente para qualquer int + null terminator
    // INT_MIN tem 11 dígitos + sinal + null = 13
    char *s = (char *)malloc(13);
    if (!s)
        return NULL;
    sprintf(s, "%d", n);
    return s;
}

// Função auxiliar para rodar um teste de ft_putnbr_fd e verificar o resultado
void run_putnbr_fd_test(const char *test_name, int n, const char *filename)
{
    int     fd;
    char    *read_data;
    char    *expected_str;
    int     test_status = 1;

    printf("Teste: %s\n", test_name);
    printf("  Escrevendo: %d para \"%s\"\n", n, filename);

    // 1. Escrever o número no arquivo usando ft_putnbr_fd
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Erro ao abrir/criar arquivo para escrita");
        printf("❌ FALHA: Nao foi possivel abrir o arquivo para escrita.\n\n");
        return;
    }
    ft_putnbr_fd(n, fd);
    close(fd);

    // 2. Gerar a string esperada
    expected_str = int_to_str_helper(n);
    if (!expected_str)
    {
        printf("❌ FALHA: Erro de alocacao para string esperada.\n\n");
        return;
    }

    // 3. Ler o conteúdo do arquivo
    read_data = read_file_content(filename);
    if (!read_data)
    {
        printf("❌ FALHA: Nao foi possivel ler o conteudo do arquivo.\n\n");
        free(expected_str);
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
    free(expected_str);

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

void test_ft_putnbr_fd(void)
{
    printf("=== Testando ft_putnbr_fd ===\n");

    // Testes variados para ft_putnbr_fd
    run_putnbr_fd_test("Zero", 0, "putnbr_fd_test_0.txt");
    run_putnbr_fd_test("Positivo pequeno", 42, "putnbr_fd_test_42.txt");
    run_putnbr_fd_test("Negativo pequeno", -123, "putnbr_fd_test_-123.txt");
    run_putnbr_fd_test("INT_MAX", INT_MAX, "putnbr_fd_test_INT_MAX.txt");
    run_putnbr_fd_test("INT_MIN", INT_MIN, "putnbr_fd_test_INT_MIN.txt");
    run_putnbr_fd_test("Numero com 1 digito", 7, "putnbr_fd_test_7.txt");
    run_putnbr_fd_test("Numero com multiplos zeros", 1000, "putnbr_fd_test_1000.txt");
    run_putnbr_fd_test("Numero com 0 no meio", 10203, "putnbr_fd_test_10203.txt");

    // Nota: Testar ft_putnbr_fd para stdout (fd 1) exigiria captura de saída do terminal.
    // O foco aqui é a funcionalidade de escrita em fd genérico.
    printf("Verifique a saida do terminal para ft_putnbr_fd(num, 1):\n");
    ft_putnbr_fd(98765, 1);
    ft_putnbr_fd('\n', 1); // Adiciona um newline para melhor visualização no terminal
    printf("\n");
}

int main(void)
{
    test_ft_putnbr_fd();
    return 0;
}
