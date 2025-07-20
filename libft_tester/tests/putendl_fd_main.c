#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para write, dup2, close
#include <fcntl.h>  // Para open, O_CREAT, O_WRONLY
#include "libft.h"

// Função para comparar o conteúdo de um arquivo com uma string esperada
int check_file_content(const char *filepath, const char *expected_content)
{
    FILE *file = fopen(filepath, "r");
    if (!file)
    {
        perror("Erro ao abrir arquivo temporario para leitura");
        return 0;
    }

    char buffer[1024]; // Buffer para ler o conteúdo do arquivo
    size_t bytes_read = fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[bytes_read] = '\0'; // Garante que é uma string terminada em NULL

    fclose(file);

    if (strcmp(buffer, expected_content) == 0)
    {
        return 1; // Conteúdo corresponde
    }
    else
    {
        printf("  ❌ Conteudo inesperado no arquivo.\n");
        printf("    Esperado: \"%s\" (tamanho %zu)\n", expected_content, strlen(expected_content));
        printf("    Obtido:   \"%s\" (tamanho %zu)\n", buffer, bytes_read);
        return 0; // Conteúdo não corresponde
    }
}

// Função para rodar um teste específico para ft_putendl_fd
void run_putendl_fd_test(const char *test_name, const char *str_to_write, const char *expected_output)
{
    int original_stdout;
    int fd;
    int test_status = 1;
    const char *temp_filename = "putendl_fd_output.txt";

    printf("--- Teste: %s ---\n", test_name);
    printf("  String a escrever: \"%s\"\n", str_to_write ? str_to_write : "(NULL)");
    printf("  Saida esperada:    \"%s\"\n", expected_output);

    // 1. Redireciona stdout para um arquivo
    original_stdout = dup(STDOUT_FILENO); // Salva o stdout original
    fd = open(temp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("Erro ao criar arquivo temporario");
        test_status = 0;
    }
    if (dup2(fd, STDOUT_FILENO) < 0) // Redireciona stdout para o arquivo
    {
        perror("Erro ao redirecionar stdout");
        close(fd);
        test_status = 0;
    }
    close(fd); // O descritor original 'fd' pode ser fechado

    // 2. Chama ft_putendl_fd (agora escrevendo para o arquivo)
    if (test_status)
    {
        // === CORREÇÃO AQUI: CAST EXPLÍCITO ===
        ft_putendl_fd((char *)str_to_write, STDOUT_FILENO);
    }

    // 3. Restaura stdout
    dup2(original_stdout, STDOUT_FILENO); // Restaura o stdout original
    close(original_stdout);

    // 4. Verifica o conteúdo do arquivo
    if (test_status)
    {
        if (check_file_content(temp_filename, expected_output))
        {
            printf("✅ OK: Conteudo escrito corresponde ao esperado.\n");
        }
        else
        {
            test_status = 0; // check_file_content já imprime erro
        }
    }

    // 5. Remove o arquivo temporário
    remove(temp_filename);

    if (test_status)
        printf("Resultado final do teste: ✅ OK\n\n");
    else
        printf("Resultado final do teste: ❌ FALHA!\n\n");
}

int main(void)
{
    printf("=== Testando ft_putendl_fd ===\n\n");

    // Teste 1: String normal
    run_putendl_fd_test("String normal", "Hello, 42!", "Hello, 42!\n");

    // Teste 2: String vazia
    run_putendl_fd_test("String vazia", "", "\n");

    // Teste 3: String longa (para testar buffers)
    run_putendl_fd_test("String longa", "This is a very long string that should test the buffering capabilities of the write function. It must be written correctly to the file, including the newline at the end.", "This is a very long string that should test the buffering capabilities of the write function. It must be written correctly to the file, including the newline at the end.\n");

    // Teste 4: NULL como input (ft_putendl_fd(NULL, fd) deve escrever "(null)\n" ou só "\n" dependendo da especificação)
    // A 42 geralmente espera que ft_putendl_fd(NULL, fd) escreva apenas '\n'.
    // SE a sua ft_putendl_fd NÃO escrever nada para NULL, mude o expected_output para "".
    run_putendl_fd_test("Input NULL", NULL, "\n"); // Assumindo que para NULL escreve apenas newline. Ajuste se sua ft_putendl_fd não faz isso.

    return 0;
}
