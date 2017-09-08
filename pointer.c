#include <stdio.h>

int main()
{
	int i = 10;
	int *p = &i;
//	*p = 20;

	printf("i=%d\n",*(&i));

	printf("i=%d\n",*p);
	return 0;
}
