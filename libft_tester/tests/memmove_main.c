#include <stdio.h>
#include <string.h>   // Para memmove e memcmp (melhor que strcmp para buffers genéricos)
#include "libft.h"    // Para ft_memmove

// Função auxiliar para imprimir buffers (como em memset_main)
void print_buffer_hex(const char *label, const void *buf, size_t size)
{
    const unsigned char *bytes = (const unsigned char *)buf;
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++)
        printf("%02X ", bytes[i]);
    printf("\n");
}

// Função auxiliar para rodar um teste de ft_memmove e verificar o resultado
void run_memmove_test(const char *test_name, char *src_orig, char *dst_orig, size_t src_len, size_t n_bytes)
{
    // Crias cópias separadas para std e ft, e para src e dst
    char    src_std[src_len + 1];
    char    dst_std[src_len + 1]; // Garante que dst é grande o suficiente
    char    src_ft[src_len + 1];
    char    dst_ft[src_len + 1];

    // Inicializa src e dst para cada teste
    memset(src_std, 0, sizeof(src_std));
    memset(dst_std, 0, sizeof(dst_std));
    memset(src_ft, 0, sizeof(src_ft));
    memset(dst_ft, 0, sizeof(dst_ft));

    strncpy(src_std, src_orig, src_len);
    strncpy(src_ft, src_orig, src_len);
    strncpy(dst_std, dst_orig, src_len); // dst_orig pode ter lixo, entao copiar o que importa
    strncpy(dst_ft, dst_orig, src_len);

    printf("Teste: %s\n", test_name);
    printf("  Src: \"%s\" (len=%zu), Dst: \"%s\", N_bytes: %zu\n", src_orig, src_len, dst_orig, n_bytes);
    printf("  Estado inicial (dest):\n");
    print_buffer_hex("    std_dst", dst_std, src_len + 1);
    print_buffer_hex("    ft_dst ", dst_ft, src_len + 1);

    // Executa ambas as funções
    void *ret_std = memmove(dst_std, src_std, n_bytes);
    void *ret_ft = ft_memmove(dst_ft, src_ft, n_bytes);

    printf("  Estado final (dest):\n");
    print_buffer_hex("    std_dst", dst_std, src_len + 1);
    print_buffer_hex("    ft_dst ", dst_ft, src_len + 1);

    // Compara os buffers finais e os valores de retorno
    // Usa memcmp pois os buffers podem ter nulos internos ou não serem strings terminadas
    if (memcmp(dst_std, dst_ft, src_len + 1) == 0 && ret_std == dst_std && ret_ft == dst_ft)
    {
        printf("✅ OK\n\n");
    }
    else
    {
        printf("❌ FALHA!\n");
        printf("  Retornos: std=%p, ft=%p | Esperado dst: \"%s\", Obtido dst: \"%s\"\n",
               ret_std, ret_ft, dst_std, dst_ft);
        printf("\n");
    }
}


void test_ft_memmove(void)
{
    printf("=== Testando ft_memmove ===\n\n");

    char s1_orig[] = "abcdefghij";
    char d1_orig[] = "ABCDEFGHIJ"; // Destino inicial com outros caracteres

    // Teste 1: Sem sobreposição (destino < source)
    run_memmove_test("Sem sobreposicao (Dst < Src)", s1_orig, d1_orig, strlen(s1_orig), 5); // move "abcde" de s1_orig para d1_orig

    // Teste 2: Sem sobreposição (source < destino)
    char s2_orig[] = "abcdefghij";
    char d2_orig[20] = "XXXXXXXXXX"; // Destino maior para garantir espaço
    memmove(d2_orig + 5, s2_orig, 5); // Prepara um cenário onde src < dst
    run_memmove_test("Sem sobreposicao (Src < Dst)", s2_orig, d2_orig, strlen(s2_orig), 5);

    // Teste 3: Sobreposição: Destino sobrepõe Source (move para trás)
    char overlap_back_std[20] = "abcdefghij";
    char overlap_back_ft[20] = "abcdefghij";
    memmove(overlap_back_std, overlap_back_std + 3, 7); // move "defghij" para o início
    ft_memmove(overlap_back_ft, overlap_back_ft + 3, 7);
    run_memmove_test("Sobreposicao: Dst sobrepoe Src", overlap_back_std, overlap_back_ft, 10, 7);

    // Teste 4: Sobreposição: Source sobrepõe Destino (move para frente)
    char overlap_front_std[20] = "abcdefghij";
    char overlap_front_ft[20] = "abcdefghij";
    memmove(overlap_front_std + 3, overlap_front_std, 7); // move "abcdefg" para a posição 3
    ft_memmove(overlap_front_ft + 3, overlap_front_ft, 7);
    run_memmove_test("Sobreposicao: Src sobrepoe Dst", overlap_front_std, overlap_front_ft, 10, 7);

    // Teste 5: Len 0
    char s5_orig[] = "abc";
    char d5_orig[] = "xyz";
    run_memmove_test("Len 0", s5_orig, d5_orig, strlen(s5_orig), 0);

    // Teste 6: Strings iguais (copia para si mesma)
    char self_move_std[20] = "abcdefghij";
    char self_move_ft[20] = "abcdefghij";
    memmove(self_move_std, self_move_std, 10);
    ft_memmove(self_move_ft, self_move_ft, 10);
    run_memmove_test("Copia para si mesma", self_move_std, self_move_ft, 10, 10);

    // Teste 7: Move para o mesmo local, com sobreposicao trivial
    char same_pos_std[20] = "abcdefghij";
    char same_pos_ft[20] = "abcdefghij";
    memmove(same_pos_std + 2, same_pos_std + 2, 5);
    ft_memmove(same_pos_ft + 2, same_pos_ft + 2, 5);
    run_memmove_test("Move para mesmo local", same_pos_std, same_pos_ft, 10, 5);
}

int	main(void)
{
	test_ft_memmove();
	return (0);
}
