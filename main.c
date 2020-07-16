#include "ft_printf.h"
int	main()
{
	int a;
	a = 5;
	int *j;

	j = &a;
	printf("%*.12x\n", 20, 1000);
	ft_printf("%*.*x\n", 20, 12, 1000);
}
