#include <stdio.h>
#include <strings.h> // Para bzero original
#include <string.h>  // Para memset, memcmp
#include <stdlib.h>  // Para malloc, free
#include "libft.h"   // Para ft_bzero

// Função auxiliar para imprimir o conteúdo de um buffer em hexadecimal
void print_buffer(const char *label, const unsigned char *buf, size_t size)
{
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++)
        printf("%02X ", buf[i]);
    printf("\n");
}

// Função auxiliar para rodar um teste de ft_bzero e verificar o resultado
void run_bzero_test(const char *test_name, size_t buf_size, size_t offset, size_t n_bytes)
{
    unsigned char *buf_std;
    unsigned char *buf_ft;
    int test_status = 1; // 1 para OK, 0 para FALHA

    // Aloca memória dinamicamente para não ter limites de stack para testes maiores
    buf_std = (unsigned char *)malloc(buf_size);
    buf_ft = (unsigned char *)malloc(buf_size);

    if (!buf_std || !buf_ft)
    {
        printf("❌ ERRO: Falha na alocacao de memoria para o teste '%s'.\n\n", test_name);
        free(buf_std); // free(NULL) é seguro
        free(buf_ft);
        return;
    }

    printf("Teste: %s\n", test_name);
    printf("  Tamanho do buffer: %zu, Offset: %zu, Bytes a zerar: %zu\n", buf_size, offset, n_bytes);

    // Preenche ambos os buffers com um padrão para garantir que 'bzero' os zere
    memset(buf_std, 0xAA, buf_size);
    memset(buf_ft, 0xAA, buf_size);

    printf("  Antes (std): "); print_buffer("", buf_std, buf_size);
    printf("  Antes (ft):  "); print_buffer("", buf_ft, buf_size);

    // Aplica bzero e ft_bzero
    bzero(buf_std + offset, n_bytes);
    ft_bzero(buf_ft + offset, n_bytes);

    printf("  Depois (std): "); print_buffer("", buf_std, buf_size);
    printf("  Depois (ft):  "); print_buffer("", buf_ft, buf_size);

    // Compara os buffers
    if (memcmp(buf_std, buf_ft, buf_size) == 0)
    {
        printf("✅ OK: Buffers idênticos após bzero.\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Conteudo dos buffers difere.\n");
        test_status = 0; // Marca falha
    }

    // Libera a memória
    free(buf_std);
    free(buf_ft);

    // Usa a variável test_status aqui para o warning sumir
    if (test_status)
        printf("Resultado final do teste: ✅ OK\n\n");
    else
        printf("Resultado final do teste: ❌ FALHA\n\n");
}

int main(void)
{
    printf("=== Testando ft_bzero ===\n\n");

    // Teste 1: Teste básico (como o seu original)
    run_bzero_test("Basico (4 bytes no meio)", 10, 3, 4);

    // Teste 2: Zerar o buffer inteiro
    run_bzero_test("Zerar buffer inteiro", 8, 0, 8);

    // Teste 3: Zerar 0 bytes
    run_bzero_test("Zerar 0 bytes (nao faz nada)", 5, 2, 0);

    // Teste 4: Zerar no início do buffer
    run_bzero_test("Zerar no inicio (3 bytes)", 7, 0, 3);

    // Teste 5: Zerar no final do buffer
    run_bzero_test("Zerar no final (3 bytes)", 7, 4, 3);

    // Teste 6: Zerar um buffer pequeno
    run_bzero_test("Zerar buffer pequeno (1 byte)", 1, 0, 1);

    // Teste 7: Buffer grande, zerar porções
    run_bzero_test("Buffer grande, zerar no meio", 50, 10, 20);

    // Teste 8: Offset grande com zero bytes a zerar (limite seguro)
    run_bzero_test("Offset grande, 0 bytes", 10, 9, 0);

    return 0;
}
