#include "ft_printf.h"
#include <limits.h>
// #include "./libft/libft.h"

int main(void)
{
int a;



	// printf("\"% s\"\n", "");
	// printf("\" % 1s\"\n", "");
	// printf("\"% 1s \"\n", "");
	// printf("\" % s \"\n", "");
	// printf("\" % s \"\n", "-");
	// printf("\" % s % s \"\n", "", "-");
	// printf("\" % s % s \"\n", " - ", "");
	// printf("\" % s % s % s % s \"\n", " - ", "", "4", "");
	// printf("\" % s % s % s % s % s \"\n", " - ", "", "4", "", "2 ");
    // printf("\n*************************************************************\n");
	// ft_printf("\"% s\"\n", "");
	// ft_printf("\" % 1s\"\n", "");
	// ft_printf("\"% 1s \"\n", "");
	// ft_printf("\" % s \"\n", "");
	// ft_printf("\" % s \"\n", "-");
	// ft_printf("\" % s % s \"\n", "", "-");
	// ft_printf("\" % s % s \"\n", " - ", "");
	// ft_printf("\" % s % s % s % s \"\n", " - ", "", "4", "");
	// ft_printf("\" % s % s % s % s % s \"\n", " - ", "", "4", "", "2 ");



	// printf("\"%-1c\"\n", '0');
	// printf("\" %-2c \"\n", '0');
	// printf("\" %-3c\"\n", '0' - 256);
	// printf("\"%-4c \"\n", '0' + 256);
	a = printf(" %d", 256);
	// printf("\" %-1c %-2c %-3c \"\n", ' ', ' ', ' ');
	// printf("\" %-1c %-2c %-3c \"\n", '1', '2', '3');
	// printf("\" %-1c %-2c %-3c \"\n", '2', '1', 0);
	// printf("\" %-1c %-2c %-3c \"\n", 0, '1', '2');
    printf("%d\n", a);
    printf("\n*************************************************************\n");
	// ft_printf("\"%-1c\"\n", '0');
	// ft_printf("\" %-2c \"\n", '0');
	// ft_printf("\" %-3c\"\n", '0' - 256);
	// ft_printf("\"%-4c \"\n", '0' + 256);
	a = ft_printf(" %d", 256);
	// ft_printf("\" %-1c %-2c %-3c \"\n", ' ', ' ', ' ');
	// ft_printf("\" %-1c %-2c %-3c \"\n", '1', '2', '3');
	// ft_printf("\" %-1c %-2c %-3c \"\n", '2', '1', 0);
	// ft_printf("\" %-1c %-2c %-3c \"\n", 0, '1', '2');
    printf("%d\n", a);

// a = printf("\" %n \"\n");
// printf("%d\n", a);

// a = printf("or\"% s\"", "hello");
// printf("%d\n", a);
// a = ft_printf("my\"% s\"", "hello");
// printf("%d\n", a);
// a = ft_printf("\" % 2.8u \"", 10);
// printf("%d\n", a);

// a = printf("\" %-1d \"\n", 0);
// printf("%d\n", a);
// a = ft_printf("\" %-1d \"\n", 0);
// printf("%d\n\n", a);
// a = printf("\" %-2d \"\n", -1);
// printf("%d\n", a);
// a = ft_printf("\" %-2d \"\n", -1);
// printf("%d\n\n", a);
// a = printf("\" %-3d \"\n", 1);
// printf("%d\n", a);
// a = ft_printf("\" %-3d \"\n", 1);
// printf("%d\n\n", a);
// a = printf("\" %-4d \"\n", 9);
// printf("%d\n", a);
// a = ft_printf("\" %-4d \"\n", 9);
// printf("%d\n\n", a);
// a = printf("\" %-1d \"\n", 10);
// printf("%d\n", a);
// a = ft_printf("\" %-1d \"\n", 10);
// printf("%d\n\n", a);
// a = printf("\" %-2d \"\n", 11);
// printf("%d\n", a);
// a = ft_printf("\" %-2d \"\n", 11);
// printf("%d\n\n", a);
// a = printf("\" %-3d \"\n", 15);
// printf("%d\n", a);
// a = ft_printf("\" %-3d \"\n", 15);
// printf("%d\n\n", a);
// a = printf("\" %-4d \"\n", 16);
// printf("%d\n", a);
// a = ft_printf("\" %-4d \"\n", 16);
// printf("%d\n\n", a);
// a = printf("\" %-5d \"\n", 17);
// printf("%d\n", a);
// a = ft_printf("\" %-5d \"\n", 17);
// printf("%d\n\n", a);
// a = printf("\" %-1d \"\n", 99);
// printf("%d\n", a);
// a = ft_printf("\" %-1d \"\n", 99);
// printf("%d\n\n", a);
// a = printf("\" %-2d \"\n", 100);
// printf("%d\n", a);
// a = ft_printf("\" %-2d \"\n", 100);
// printf("%d\n\n", a);
// a = printf("\" %-3d \"\n", 101);
// printf("%d\n", a);
// a = ft_printf("\" %-3d \"\n", 101);
// printf("%d\n\n", a);
// a = printf("\" %-1d \"\n", -9);
// printf("%d\n", a);
// a = ft_printf("\" %-1d \"\n", -9);
// printf("%d\n\n", a);
// a = printf("\" %-2d \"\n", -10);
// printf("%d\n", a);
// a = ft_printf("\" %-2d \"\n", -10);
// printf("%d\n\n", a);
// a = printf("\" %-3d \"\n", -11);
// printf("%d\n", a);
// a = ft_printf("\" %-3d \"\n", -11);
// printf("%d\n\n", a);
// a = printf("\" %-4d \"\n", -14);
// printf("%d\n", a);
// a = ft_printf("\" %-4d \"\n", -14);
// printf("%d\n\n", a);
// a = printf("\" %-5d \"\n", -15);
// printf("%d\n", a);
// a = ft_printf("\" %-5d \"\n", -15);
// printf("%d\n\n", a);
// a = printf("\" %-6d \"\n", -16);
// printf("%d\n", a);
// a = ft_printf("\" %-6d \"\n", -16);
// printf("%d\n\n", a);
// a = printf("\" %-1d \"\n", -99);
// printf("%d\n", a);
// a = ft_printf("\" %-1d \"\n", -99);
// printf("%d\n\n", a);
// a = printf("\" %-2d \"\n", -100);
// printf("%d\n", a);
// a = ft_printf("\" %-2d \"\n", -100);
// printf("%d\n\n", a);
// a = printf("\" %-3d \"\n", -101);
// printf("%d\n", a);
// a = ft_printf("\" %-3d \"\n", -101);
// printf("%d\n\n", a);
// a = printf("\" %-9d \"\n", INT_MAX);
// printf("%d\n", a);
// a = ft_printf("\" %-9d \"\n", INT_MAX);
// printf("%d\n\n", a);
// a = printf("\" %-10d \"\n", INT_MIN);
// printf("%d\n", a);
// a = ft_printf("\" %-10d \"\n", INT_MIN);
// printf("%d\n\n", a);
// a = printf("\" %-11d \"\n", LONG_MAX);
// printf("%d\n", a);
// a = ft_printf("\" %-11d \"\n", LONG_MAX);
// printf("%d\n\n", a);
// a = printf("\" %-12d \"\n", LONG_MIN);
// printf("%d\n", a);
// a = ft_printf("\" %-12d \"\n", LONG_MIN);
// printf("%d\n\n", a);
// a = printf("\" %-13d \"\n", UINT_MAX);
// printf("%d\n", a);
// a = ft_printf("\" %-13d \"\n", UINT_MAX);
// printf("%d\n\n", a);
// a = printf("\" %-14d \"\n", ULONG_MAX);
// printf("%d\n", a);
// a = ft_printf("\" %-14d \"\n", ULONG_MAX);
// printf("%d\n\n", a);
// a = printf("\" %-15d \"\n", 9223372036854775807LL);
// printf("%d\n", a);
// a = ft_printf("\" %-15d \"\n", 9223372036854775807LL);
// printf("%d\n\n", a);
// a = printf("\" %-9d %-10d %-11d %-12d %-13d %-14d %-15d\"\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// printf("%d\n", a);
// a = ft_printf("\" %-9d %-10d %-11d %-12d %-13d %-14d %-15d\"\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// printf("%d\n\n", a);
}
