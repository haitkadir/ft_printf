#include "ft_printf.h"
// #include "./libft/libft.h"

int main(void)
{
    int a,b;
    // a = printf(" %-1d ", 0);
    // printf("\n%d\n", a);
    b = ft_printf("\"%.2d\"\n", -1);
    printf("%d\n", b);
    b = printf("\"\n%.2d\"\n", -1);
    printf("%d\n", b);

    // %[parameter][flags][width][.precision][length]type
}
