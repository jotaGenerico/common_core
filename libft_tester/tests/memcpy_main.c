#include <stdio.h>
#include <string.h>   // Para memcpy e memcmp
#include <stdlib.h>   // Para malloc, free
#include "libft.h"    // Para ft_memcpy

// Função auxiliar para imprimir o conteúdo de um buffer em hexadecimal
void print_buffer(const char *label, const void *buf, size_t size)
{
    const unsigned char *bytes = (const unsigned char *)buf;
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++)
        printf("%02X ", bytes[i]);
    printf("\n");
}

// Função auxiliar para rodar um teste de ft_memcpy e verificar o resultado
void run_memcpy_test(const char *test_name, const void *src_data, size_t src_len, size_t copy_len)
{
    // Aloca memória dinamicamente para os buffers para evitar estouro de pilha
    // e para testar tamanhos variados.
    // +1 para o terminador nulo, se for uma string, mas memcpy não se importa.
    // Apenas garantimos que o buffer de destino seja grande o suficiente para a cópia.
    char *dest_std = (char *)malloc(copy_len + 5); // +5 para garantir que há espaço extra e ver se algo fora da cópia muda
    char *dest_ft = (char *)malloc(copy_len + 5);
    char *original_src_copy = (char *)malloc(src_len); // Copia da fonte para depuração

    if (!dest_std || !dest_ft || !original_src_copy)
    {
        printf("❌ ERRO: Falha na alocacao de memoria para o teste.\n\n");
        free(dest_std);
        free(dest_ft);
        free(original_src_copy);
        return;
    }

    // Garante que a cópia da fonte é segura
    memcpy(original_src_copy, src_data, src_len);

    // Inicializa os destinos com um valor conhecido para detectar mudanças indesejadas
    memset(dest_std, 0xFF, copy_len + 5);
    memset(dest_ft, 0xFF, copy_len + 5);

    printf("Teste: %s\n", test_name);
    printf("  Fonte: \"%.*s\" (len=%zu), Tamanho da copia (n): %zu\n", (int)src_len, (char *)src_data, src_len, copy_len);
    print_buffer("  Destino antes (std)", (unsigned char *)dest_std, copy_len + 5);
    print_buffer("  Destino antes (ft) ", (unsigned char *)dest_ft, copy_len + 5);


    // Executa ambas as funções
    void *ret_std = memcpy(dest_std, src_data, copy_len);
    void *ret_ft = ft_memcpy(dest_ft, src_data, copy_len);

    print_buffer("  Destino depois (std)", (unsigned char *)dest_std, copy_len + 5);
    print_buffer("  Destino depois (ft) ", (unsigned char *)dest_ft, copy_len + 5);

    // Compara os buffers e os valores de retorno
    if (memcmp(dest_std, dest_ft, copy_len + 5) == 0 && ret_std == dest_std && ret_ft == dest_ft)
    {
        printf("✅ OK: Buffers e retornos idênticos.\n\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Retornos: std=%p, ft=%p | Esperado dest: \"%.*s\", Obtido dest: \"%.*s\"\n",
               ret_std, ret_ft, (int)copy_len, dest_std, (int)copy_len, dest_ft);
        printf("\n");
    }

    free(dest_std);
    free(dest_ft);
    free(original_src_copy);
}

int main(void)
{
    printf("=== Testando ft_memcpy ===\n\n");

    // Teste 1: Copia básica
    run_memcpy_test("Copia basica", "1234567890", 10, 10);

    // Teste 2: Copia parcial
    run_memcpy_test("Copia parcial (5 bytes)", "abcdefghij", 10, 5);

    // Teste 3: Copia de 0 bytes
    run_memcpy_test("Copia 0 bytes", "some_string", 11, 0);

    // Teste 4: Copia de string vazia
    run_memcpy_test("Copia de string vazia", "", 0, 0);

    // Teste 5: Copia de string com nulls internos
    run_memcpy_test("Copia com null interno", "abc\0def", 7, 7);

    // Teste 6: Copia de um caracter
    run_memcpy_test("Copia de um caractere", "X", 1, 1);

    // Teste 7: Copia onde o destino e maior que a fonte
    char src_short[] = "ABC";
    char dest_large_std[10];
    char dest_large_ft[10];
    memset(dest_large_std, 'Z', 10); // Preenche para ver o que nao e copiado
    memset(dest_large_ft, 'Z', 10);

    // Isso é mais difícil de generalizar com run_memcpy_test devido aos tamanhos fixos.
    // Faremos um teste manual para clareza aqui.
    printf("Teste: Copia para destino maior\n");
    printf("  Fonte: \"%s\" (len=%zu), Destino grande (10 bytes), Copia: 3 bytes\n", src_short, strlen(src_short));

    char *ret_std = memcpy(dest_large_std, src_short, 3);
    char *ret_ft = ft_memcpy(dest_large_ft, src_short, 3);

    print_buffer("  Destino final (std)", (unsigned char *)dest_large_std, 10);
    print_buffer("  Destino final (ft) ", (unsigned char *)dest_large_ft, 10);

    if (memcmp(dest_large_std, dest_large_ft, 10) == 0 && ret_std == dest_large_std && ret_ft == dest_large_ft)
    {
        printf("✅ OK: Buffers e retornos idênticos.\n\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Retornos: std=%p, ft=%p | Esperado dest: \"%s\", Obtido dest: \"%s\"\n",
               ret_std, ret_ft, dest_large_std, dest_large_ft);
        printf("\n");
    }


    return 0;
}
