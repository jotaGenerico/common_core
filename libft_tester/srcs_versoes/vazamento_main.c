#include <stdio.h>  // Para printf
#include <stdlib.h> // Para free
#include <string.h> // Para strlen (se você não tiver uma ft_strlen)
#include "libft.h"  // Inclui as declarações das suas funções ft_calloc, ft_strdup, etc.

int main(void)
{
    // --- Teste do ft_calloc ---
    char *buffer_calloc;
    size_t count = 5; // Número de elementos
    size_t size = sizeof(int); // Tamanho de cada elemento (total 5 * 4 = 20 bytes)

    printf("Testando ft_calloc...\n");
    buffer_calloc = (char *)ft_calloc(count, size); // Aloca memoria com ft_calloc
    if (buffer_calloc == NULL)
    {
        printf("ft_calloc falhou!\n");
        return 1;
    }
    printf("ft_calloc alocou %zu bytes. Conteudo inicial (primeiro byte): %d\n", count * size, buffer_calloc[0]);
    // Verifique se ft_calloc zerou a memória (deve ser 0)

    // --- IMPORTANTE: VAMOS LIBERAR ESTE PARA NÃO VAZAR AQUI ---
    free(buffer_calloc);
    printf("Memoria do ft_calloc liberada.\n");

    // --- Teste do ft_strdup (que usa malloc internamente) ---
    char *original_str = "Isso e uma string para duplicar.";
    char *duplicada_str;

    printf("\nTestando ft_strdup...\n");
    duplicada_str = ft_strdup(original_str); // Duplica a string com ft_strdup
    if (duplicada_str == NULL)
    {
        printf("ft_strdup falhou!\n");
        return 1;
    }
    printf("ft_strdup duplicou: \"%s\"\n", duplicada_str);

    // --- IMPORTANTE: INTENCIONALMENTE NAO VAMOS LIBERAR ESTA MEMORIA AGORA ---
    // free(duplicada_str); // Se você descomentar esta linha, Valgrind nao detectara vazamento aqui.
    printf("Memoria do ft_strdup nao sera liberada neste teste para causar um vazamento.\n");


    // --- Outra alocacao para mostrar vazamento claro ---
    int *vazamento_int = (int *)ft_calloc(1, sizeof(int));
    if (vazamento_int == NULL)
    {
        printf("Falha na segunda alocacao (vazamento_int).\n");
        return 1;
    }
    *vazamento_int = 42;
    printf("Variavel 'vazamento_int' alocada e nao sera liberada. Conteudo: %d\n", *vazamento_int);
    // free(vazamento_int); // Esta linha deve ser descomentada para corrigir o vazamento

    printf("\nFim do programa de teste.\n");

    return 0;
}
