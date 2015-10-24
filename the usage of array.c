#include<stdio.h>

void change(int* Ptr);

int main (void)
{
	int i[52];
	i[50]=50;
	printf("i[%d] is %d",50,i[50]);
	change(i);
	printf("i[%d] is %d",50,i[50]);
	return 0;
}
void change(int* Ptr)
{
	Ptr[50]=49;
}