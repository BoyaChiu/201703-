#include <stdio.h>

struct student{
	int id;
	char name[20];
	float score;
	char sex;
};

int main()
{
	struct student stu = {1, "xiaoming",89.5, 'm'};

	printf("%d %s %.1f %c\n",stu.id, stu.name,stu.score, stu.sex);

	return ;
}
