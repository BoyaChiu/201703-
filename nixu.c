#include <stdio.h>

void nixu(int *p, int len)
{
	if(NULL == p)
		return;
	int *q = p + len -1;

	int temp;
	while(p < q)
	{
		temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}


}



int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a) / sizeof(a[0]);
	nixu(a,len);

	int i;
	for(i=0;i<len;i++)
		printf("%d ",a[i]);

	printf("\n");

	return 0;
}

