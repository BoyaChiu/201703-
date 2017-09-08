#include <stdio.h>

int add()
{
	static int a = 0;
	a = a + 1;
	return a;
}

int main()
{
	int ret = add();
	printf("ret=%d\n",ret);

	int ret1 = add();
	printf("ret1=%d\n",ret1);
	
	return 0;
}
