#include <stdio.h>

int main()
{
	int a[6];
	int i;
	for(i=0;i<6;i++)
		printf("%p ",&a[i]);

	printf("\n");
	return 0;
}
