#include <stdio.h>  // Para printf
#include <stdlib.h> // Para free
#include <string.h> // Para strlen (apenas para exibição, pode ser removido se ft_strlen for usada)
#include "libft.h"  // Inclui as declarações das suas funções da Libft

int main(void)
{
    // --- Teste 1: ft_calloc ---
    char *buffer_calloc;
    size_t count = 5;
    size_t size = sizeof(int); // Alocará 5 * 4 = 20 bytes

    printf("--- Testando ft_calloc ---\n");
    buffer_calloc = (char *)ft_calloc(count, size);
    if (buffer_calloc == NULL)
    {
        printf("ERRO: ft_calloc falhou!\n");
        return 1;
    }
    printf("ft_calloc alocou %zu bytes. Conteudo inicial (primeiro byte): %d\n", count * size, buffer_calloc[0]);
    free(buffer_calloc); // Liberando a memória de ft_calloc
    printf("Memoria de ft_calloc liberada.\n");

    // --- Teste 2: ft_strdup ---
    char *original_str = "Minha string para duplicar com ft_strdup!";
    char *duplicada_str;

    printf("\n--- Testando ft_strdup ---\n");
    duplicada_str = ft_strdup(original_str);
    if (duplicada_str == NULL)
    {
        printf("ERRO: ft_strdup falhou!\n");
        return 1;
    }
    printf("ft_strdup duplicou: \"%s\"\n", duplicada_str);
    free(duplicada_str); // Liberando a memória de ft_strdup
    printf("Memoria de ft_strdup liberada.\n");

    // --- Teste 3: ft_substr ---
    char *full_str = "Isso e uma string longa para testar substring.";
    char *sub_str;

    printf("\n--- Testando ft_substr ---\n");
    sub_str = ft_substr(full_str, 5, 8); // Pega "e uma st"
    if (sub_str == NULL)
    {
        printf("ERRO: ft_substr falhou!\n");
        return 1;
    }
    printf("ft_substr: \"%s\" (do original \"%s\")\n", sub_str, full_str);
    free(sub_str); // Liberando a memória de ft_substr
    printf("Memoria de ft_substr liberada.\n");

    // --- Teste 4: ft_strjoin ---
    char *s1_join = "Parte Um ";
    char *s2_join = "Parte Dois";
    char *joined_str;

    printf("\n--- Testando ft_strjoin ---\n");
    joined_str = ft_strjoin(s1_join, s2_join);
    if (joined_str == NULL)
    {
        printf("ERRO: ft_strjoin falhou!\n");
        return 1;
    }
    printf("ft_strjoin: \"%s\"\n", joined_str);
    free(joined_str); // Liberando a memória de ft_strjoin
    printf("Memoria de ft_strjoin liberada.\n");

    // --- Teste 5: ft_itoa ---
    int num = -12345;
    char *itoa_str;

    printf("\n--- Testando ft_itoa ---\n");
    itoa_str = ft_itoa(num);
    if (itoa_str == NULL)
    {
        printf("ERRO: ft_itoa falhou!\n");
        return 1;
    }
    printf("ft_itoa de %d: \"%s\"\n", num, itoa_str);
    free(itoa_str); // Liberando a memória de ft_itoa
    printf("Memoria de ft_itoa liberada.\n");

    // --- Teste 6: ft_split ---
    char *split_str = " esta eh uma frase para separar ";
    char delimiter = ' ';
    char **words;
    int i;

    printf("\n--- Testando ft_split ---\n");
    words = ft_split(split_str, delimiter);
    if (words == NULL)
    {
        printf("ERRO: ft_split falhou!\n");
        return 1;
    }
    printf("ft_split de \"%s\" por '%c':\n", split_str, delimiter);
    i = 0;
    while (words[i] != NULL)
    {
        printf("  - \"%s\"\n", words[i]);
        free(words[i]); // Liberando cada string dentro do array
        i++;
    }
    free(words); // Liberando o array de ponteiros em si
    printf("Memoria de ft_split liberada.\n");

    printf("\nTodos os testes de alocacao/liberacao concluídos.\n");
    return 0;
}
