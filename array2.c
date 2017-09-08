#include <stdio.h>

int main()
{
	int a[2][3];
	//a++;ERROR
	printf("%p %p\n",a,&a[0]);

	printf("%p %p\n",a[0],&a[0][0]);

	printf("%p %p\n",a[1],&a[1][0]);

	return 0;
}
