#include <stdio.h>
#include <string.h> // Para memchr original e strlen
#include <stdint.h> // Para SIZE_MAX (CORREÇÃO AQUI!)
#include "libft.h"  // Para ft_memchr

// Estrutura para os casos de teste
typedef struct s_memchr_test
{
    const char *str;
    int         c;
    size_t      n;
} t_memchr_test;

void test_ft_memchr(void)
{
    // Casos de teste abrangentes
    t_memchr_test test_cases[] = {
        {"hello world", 'o', 11},           // Caractere no meio
        {"hello world", 'h', 11},           // Caractere no início
        {"hello world", 'd', 11},           // Caractere no fim
        {"hello world", 'z', 11},           // Caractere não encontrado
        {"hello world", '\0', 12},          // Caractere nulo (dentro dos limites)
        {"hello world", '\0', 5},           // Caractere nulo (fora dos limites, deve retornar NULL)
        {"", 'a', 0},                       // String vazia, n = 0
        {"", 'a', 1},                       // String vazia, n = 1 (deve retornar NULL)
        {"abcde", 'c', 3},                  // n limitado, encontra
        {"abcde", 'c', 2},                  // n limitado, não encontra
        {"aaaaa", 'a', 5},                  // Todos iguais
        {"aaaaa", 'b', 5},                  // Nenhum igual
        {"\0test", 't', 5},                 // Byte nulo antes
        {"\0test", '\0', 1},                // Byte nulo no início, n=1
        {"\0test", '\0', 5},                // Byte nulo no início, n=5
        {"test\0ing", 'i', 7},              // Byte nulo no meio, encontra depois
        {"test\0ing", 'i', 4},              // Byte nulo no meio, não encontra por causa do n
        {"12345", '3', SIZE_MAX},           // n muito grande (simular INT_MAX)
        {"abc", 'a', 0},                    // n = 0, deve retornar NULL
        {NULL, 0, 0}                        // Marcador de fim
    };

    int i = 0;

    printf("=== Testando ft_memchr ===\n\n");
    while (test_cases[i].str != NULL)
    {
        const char *str = test_cases[i].str;
        int c = test_cases[i].c;
        size_t n = test_cases[i].n;

        // Calcula um 'n' para display que reflita o que memchr realmente vê ou o tamanho da string.
        // Isso evita imprimir caracteres lixo se 'n' for muito grande ou menor que strlen.
        size_t display_n;
        if (n == 0)
            display_n = 0;
        else if (c == '\0' && n >= strlen(str) + 1)
            display_n = strlen(str) + 1; // Se buscar por NUL e n incluir o NUL terminator
        else if (n > strlen(str) && c != '\0')
            display_n = strlen(str); // Se n for maior que a string e não for NUL
        else
            display_n = n; // Caso contrário, usa o n fornecido

        const void *std_result = memchr(str, c, n);
        const void *ft_result = ft_memchr(str, c, n);

        printf("Testando: memchr(\"%.*s\", '%c', %zu)\n", (int)display_n, str, (char)c, n);
        printf("  Esperado: %p (offset %ld)\n", std_result, std_result ? (long)(std_result - (const void *)str) : -1L);
        printf("  Obtido:   %p (offset %ld)\n", ft_result, ft_result ? (long)(ft_result - (const void *)str) : -1L);

        if (std_result == ft_result)
        {
            printf("✅ OK\n\n");
        }
        else
        {
            printf("❌ FALHA!\n\n");
        }
        i++;
    }
    printf("\n");
}

int main(void)
{
    test_ft_memchr();
    return 0;
}
