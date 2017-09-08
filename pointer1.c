#include <stdio.h>

int main()
{
	int i = 10;
	int *px,*py;
	px = py = &i;

	printf("%p\n",px);
	px++;
	printf("%p\n",px);

	return 0;
}
