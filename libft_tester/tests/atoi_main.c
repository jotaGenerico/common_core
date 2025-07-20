#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void test_ft_atoi(void)
{
    const char *tests[] = {
        "42",
        "   -42",
        "4193 with words",
        "words and 987",
        "+123",
        "  +0",
        "-2147483648",  // INT_MIN
        "2147483647",   // INT_MAX
        "9223372036854775807", // overflow?
        "",
        "  \t\n\r\v\f-56",
        NULL
    };
    int i = 0;

    printf("=== Testando ft_atoi ===\n");
    while (tests[i])
    {
        int std = atoi(tests[i]);
        int ft = ft_atoi(tests[i]);
        if (std == ft)
            printf("OK: ft_atoi(\"%s\") == %d\n", tests[i], ft);
        else
            printf("❌ ERRO: ft_atoi(\"%s\") == %d | esperado: %d\n", tests[i], ft, std);
        i++;
    }
    printf("\n");
}

int main(void)
{
    test_ft_atoi();
    return 0;
}

