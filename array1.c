#include <stdio.h>

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i,sum=0;
	for(i=0;i<10;i++)
		sum += a[i];
			

	printf("sum=%d\n",sum);
	return 0;
}
