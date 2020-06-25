#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
void	ft_printf(const char *format, ...)
{
	va_list list;
	int i;

	va_start(list, format);
	ft_parse_all(format, list);
	va_end(list);
}

int main()
{
	ft_printf("%d", 3);
}
