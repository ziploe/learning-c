#include<stdio.h>
#include<stdlib.h>
//pointer must be initialized!!!
int main (void)
{
	int *a ;
	int *b;
	a=(int*)malloc(sizeof(int));
	b=(int*)malloc(sizeof(int));
	 *a=3; 
	 *b=4;
	 b= a;
	 printf("%d %d", *a, *b);
	 *a=6;
	printf("%d %d", *a, *b);
	return 0;
}