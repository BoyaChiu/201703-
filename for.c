#include <stdio.h>

int main()
{
	int i,sum = 0;
	i = 1;
	for(;;)
	{
		sum += i;
		i++;
		printf("i=%d\n",i);
	}
	printf("sum=%d\n",sum);


	return 0;
}
