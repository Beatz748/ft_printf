#include <stdio.h>
#include <unistd.h>

typedef struct ft_param
{
	int count;
	int flag;
}	ft_par;


void testing()
{
	ft_par listik;
	listik.count = 5;
	listik.flag = 0;
	printf("%d\n", listik.flag);
	printf("%d\n", listik.count);
}

int main()
{
	ft_printf("%c", 'A');
}
