#include <stdio.h>

int main()
{
	int a[10] = {23,6,65,43,89,234,15,90,7,1};
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		
		}
	}


	for(i=0;i<10;i++)
		printf("%d ",a[i]);

	printf("\n");
	return 0;
}
