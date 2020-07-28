#include "ft_printf.h"

int main()
{
	int a = 5;
	int b = 5;

	int x1 = ft_printf("%p|\n", NULL);
	int x2 = printf("%p|\n", NULL);
	printf("my : %d \norig %d", x1, x2);
}