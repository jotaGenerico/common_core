#include <stdio.h>
#include <string.h>   // Para strlcat original (Linux) e strcmp, memset, strncpy
#include "libft.h"    // Para sua ft_strlcat

// DECLARAÇÃO ESSENCIAL: Prototipagem de strlcat da libc
// Essa função é uma extensão BSD e pode não ser declarada por padrão
// em ambientes específicos (como a 42), levando a erros de "implicit declaration" com -Werror.
size_t strlcat(char *dst, const char *src, size_t size);

// Função auxiliar para rodar um único teste de strlcat e imprimir o resultado formatado
void run_strlcat_test(const char *test_name, const char *initial_dst, const char *src, size_t size)
{
    char    dst_ft[100];  // Buffer para o resultado da sua função
    char    dst_std[100]; // Buffer para o resultado da função original

    // Garante que os buffers são limpos e copiados para cada teste,
    // e que há um null terminator no final.
    memset(dst_ft, 0, sizeof(dst_ft));
    memset(dst_std, 0, sizeof(dst_std));
    strncpy(dst_ft, initial_dst, sizeof(dst_ft) - 1);
    strncpy(dst_std, initial_dst, sizeof(dst_std) - 1);
    dst_ft[sizeof(dst_ft) - 1] = '\0';
    dst_std[sizeof(dst_std) - 1] = '\0';

    // Chama ambas as funções e guarda os retornos
    size_t  ret_ft = ft_strlcat(dst_ft, src, size);
    size_t  ret_std = strlcat(dst_std, src, size);

    printf("Teste: %s\n", test_name);
    printf("  Entrada: dst=\"%s\" src=\"%s\" size=%zu\n", initial_dst, src, size);
    printf("  ft_strlcat -> dst: \"%s\", retorno: %zu\n", dst_ft, ret_ft);
    printf("  strlcat    -> dst: \"%s\", retorno: %zu\n", dst_std, ret_std);

    // Compara o retorno e o conteúdo final do buffer
    if (ret_ft == ret_std && strcmp(dst_ft, dst_std) == 0)
    {
        printf("✅ OK\n\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Esperado (ret): %zu, Obtido (ft_ret): %zu\n", ret_std, ret_ft);
        printf("  Esperado (dst): \"%s\", Obtido (ft_dst): \"%s\"\n", dst_std, dst_ft);
        printf("\n");
    }
}

void	test_ft_strlcat(void)
{
	printf("=== Testando ft_strlcat ===\n");

	// Teste 1: Concatenação normal, espaço suficiente
	run_strlcat_test("Espaco suficiente", "42", "sp", 20);

	// Teste 2: Size menor que strlen(dst). Não deve adicionar nada.
    // strlcat ainda calcula o tamanho total que *deveria* ter copiado.
	run_strlcat_test("Size menor que strlen(dst)", "1234", "XXXX", 2);

	// Teste 3: Size zero. Não deve adicionar nada.
	run_strlcat_test("Size zero", "abc", "def", 0);

	// Teste 4: src vazio. Deve apenas retornar strlen(dst).
	run_strlcat_test("Src vazio", "Hello", "", 10);

    // Teste 5: dst vazio. Deve se comportar como strlcpy.
    run_strlcat_test("Dst vazio", "", "World", 10);

    // Teste 6: Size exato para o null-terminator (dst + 1)
    // strlcat não adiciona chars, apenas o null, e retorna strlen(dst) + strlen(src)
    run_strlcat_test("Size para apenas null", "abc", "de", 4);

    // Teste 7: Size exato para concatenar src inteiro + null
    run_strlcat_test("Size exato para src completo", "abc", "def", 7);

    // Teste 8: src maior que o espaço disponível (size permite apenas parte do src)
    run_strlcat_test("Src maior que espaco", "Hello", "world", 8);

    // Teste 9: DST muito longo para size
    run_strlcat_test("DST muito longo para size", "abcdefghijklmnopqrstuvwxyz", "123", 5);

    // Teste 10: DST e SRC vazios
    run_strlcat_test("DST e SRC vazios", "", "", 10);

	printf("\n");
}

int	main(void)
{
	test_ft_strlcat();
	return 0;
}
