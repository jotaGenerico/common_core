#include <stdio.h>
#include <string.h>   // Para strlcpy original e strcmp, memset
#include "libft.h"    // Para sua ft_strlcpy

// DECLARAÇÃO ESSENCIAL: Prototipagem de strlcpy da libc
// Esta função é uma extensão BSD e pode não ser declarada por padrão
// em ambientes específicos (como a 42), levando a erros de "implicit declaration" com -Werror.
size_t strlcpy(char *dst, const char *src, size_t size);

// Função auxiliar para rodar um único teste de strlcpy e imprimir o resultado formatado
void run_strlcpy_test(const char *test_name, const char *src, size_t size, const char *expected_dst_content)
{
    char    dst_ft[100];  // Buffer para o resultado da sua função
    char    dst_std[100]; // Buffer para o resultado da função original

    // Garante que os buffers são limpos para cada teste
    memset(dst_ft, 0, sizeof(dst_ft));
    memset(dst_std, 0, sizeof(dst_std));

    // Chama ambas as funções e guarda os retornos
    size_t  ret_ft = ft_strlcpy(dst_ft, src, size);
    size_t  ret_std = strlcpy(dst_std, src, size);

    printf("Teste: %s\n", test_name);
    printf("  Entrada: src=\"%s\" size=%zu\n", src, size);
    printf("  ft_strlcpy -> dst: \"%s\", retorno: %zu\n", dst_ft, ret_ft);
    printf("  strlcpy    -> dst: \"%s\", retorno: %zu\n", dst_std, ret_std);

    // Compara o retorno e o conteúdo final do buffer
    // Lida com casos onde expected_dst_content pode ser NULL (embora para strlcpy, esperamos "" ou algo)
    if (ret_ft == ret_std && strcmp(dst_ft, expected_dst_content ? expected_dst_content : "") == 0)
    {
        printf("✅ OK\n\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Esperado (ret): %zu, Obtido (ft_ret): %zu\n", ret_std, ret_ft);
        printf("  Esperado (dst): \"%s\", Obtido (ft_dst): \"%s\"\n", expected_dst_content ? expected_dst_content : "NULL", dst_ft);
        printf("\n");
    }
}

void	test_ft_strlcpy(void)
{
	printf("=== Testando ft_strlcpy ===\n");

	// Teste 1: Espaço suficiente
	run_strlcpy_test("Espaco suficiente", "piscine42", 10, "piscine42"); // size 10 para 9 chars + null

	// Teste 2: Size 0. Não copia nada, retorna strlen(src).
	run_strlcpy_test("Size zero", "piscine42", 0, ""); // dst deve ser vazio, retorno strlen("piscine42") = 9

	// Teste 3: Truncamento. Copia size-1 chars + null.
	run_strlcpy_test("Truncamento", "piscine42", 5, "pisc"); // size 5 copia 4 chars + null

    // Teste 4: Src vazio
    run_strlcpy_test("Src vazio", "", 10, "");

    // Teste 5: Size menor que strlen(src) mas nao 0
    run_strlcpy_test("Size menor que src", "longstring", 3, "lo"); // size 3 copia 'l', 'o', '\0'

    // Teste 6: Size exatamente strlen(src)
    run_strlcpy_test("Size == strlen(src)", "abc", 3, "ab"); // size 3 copia 'a', 'b', '\0' (cabe 2 chars + null)

    // Teste 7: Size exatamente strlen(src) + 1
    run_strlcpy_test("Size == strlen(src) + 1", "abc", 4, "abc"); // size 4 copia 'a', 'b', 'c', '\0'


	printf("\n");
}

int	main(void)
{
	test_ft_strlcpy();
	return 0;
}
