#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

void test_ft_itoa(void)
{
    int test_values[] = {0, 123, -123, INT_MAX, INT_MIN};
    size_t i;

    printf("=== Testando ft_itoa ===\n");
    for (i = 0; i < sizeof(test_values)/sizeof(int); ++i)
    {
        char std_buf[50];
        char *ft_res;
        int val = test_values[i];

        sprintf(std_buf, "%d", val);
        ft_res = ft_itoa(val);

        if (ft_res)
        {
            if (strcmp(std_buf, ft_res) == 0)
                printf("OK: ft_itoa(%d) == \"%s\"\n", val, ft_res);
            else
                printf("❌ ERRO: ft_itoa(%d) == \"%s\" | esperado: \"%s\"\n", val, ft_res, std_buf);
            free(ft_res);
        }
        else
            printf("❌ ERRO: ft_itoa(%d) retornou NULL\n", val);
    }
    printf("\n");
}

int main(void)
{
    test_ft_itoa();
    return 0;
}

