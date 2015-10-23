#include<stdio.h>
int pow(int x,int y);
int main(void)
{
	int a,b,sum;
	printf("this will caculate x to the power y,please enter the two number by order\n");
	scanf("%d%d",&a,&b);
	sum=pow(a,b);
	printf("the %d power of %d is %d\n",a,b,sum);
	return 0;
}

/*int pow (int x,int y)
{
	int power=1;
	for(int n=0;n<y;n++){     //为什么这个一编译就出错？
		power*=x;
	}
	return power;
}*/
int pow (int x,int y)
{
	int power=1;
	int n=0;
	for(n;n<y;n++){
		power*=x;
	}
	return power;
}