#include <stdio.h>
#include <string.h>   // Para memset e memcmp
#include "libft.h"

// Função auxiliar para imprimir o conteúdo de um buffer em hexadecimal
void print_buffer(const char *label, const void *buf, size_t size)
{
    const unsigned char *bytes = (const unsigned char *)buf;
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++)
        printf("%02X ", bytes[i]);
    printf("\n");
}

// Função auxiliar para rodar um teste de ft_memset e verificar o resultado
void run_memset_test(const char *test_name, int c, size_t len, const char *initial_state)
{
    char std_buf[20]; // Buffer para a função original
    char ft_buf[20];  // Buffer para sua função

    printf("Teste: %s\n", test_name);
    printf("  Char para preencher: '%c' (0x%02X), Tamanho: %zu\n", (char)c, c, len);

    // Inicializa ambos os buffers com um estado conhecido
    // Garante que o buffer é grande o suficiente para o len
    memset(std_buf, 0x00, sizeof(std_buf));
    memset(ft_buf, 0x00, sizeof(ft_buf));
    if (initial_state) // Se houver estado inicial, copia
    {
        strncpy(std_buf, initial_state, sizeof(std_buf) - 1);
        strncpy(ft_buf, initial_state, sizeof(ft_buf) - 1);
    }

    printf("  Antes   (std): "); print_buffer("", std_buf, sizeof(std_buf));
    printf("  Antes   (ft_): "); print_buffer("", ft_buf, sizeof(ft_buf));

    // Chama ambas as funções
    void *ret_std = memset(std_buf, c, len);
    void *ret_ft = ft_memset(ft_buf, c, len);

    printf("  Depois  (std): "); print_buffer("", std_buf, sizeof(std_buf));
    printf("  Depois  (ft_): "); print_buffer("", ft_buf, sizeof(ft_buf));

    // Compara os buffers e os retornos
    if (memcmp(std_buf, ft_buf, sizeof(std_buf)) == 0 && ret_std == std_buf && ret_ft == ft_buf)
    {
        printf("✅ OK: Buffers e retornos idênticos.\n\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Diferença nos buffers ou retornos.\n");
        printf("  std_buf: %p, ft_buf: %p\n", (void*)std_buf, (void*)ft_buf);
        printf("  ret_std: %p, ret_ft: %p\n", ret_std, ret_ft);
        printf("\n");
    }
}

int main(void)
{
    printf("=== Testando ft_memset ===\n\n");

    // Teste 1: Preencher com 'A' em 5 bytes
    run_memset_test("Preencher 'A' (5 bytes)", 'A', 5, "ABCDEFGHIJ");

    // Teste 2: Preencher com 0 (nulos) em 10 bytes
    run_memset_test("Preencher com 0 (10 bytes)", 0, 10, "1234567890");

    // Teste 3: Preencher com um byte diferente (0xFF) em 3 bytes
    run_memset_test("Preencher 0xFF (3 bytes)", 0xFF, 3, "ABCDEF");

    // Teste 4: Preencher buffer vazio (len 0)
    run_memset_test("Len 0", 'Z', 0, "TEST");

    // Teste 5: Preencher todo o buffer (tamanho 20)
    run_memset_test("Preencher tudo (20 bytes)", 'X', 20, "abcdefghijklmnopqrst");

    // Teste 6: Preencher com um caractere especial
    run_memset_test("Preencher com caractere especial", '*', 7, "12345678");

    return 0;
}
