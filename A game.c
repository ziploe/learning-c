#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
int roll(void);
int main (void)
{
	int first_roll;
	int result;// 0 mean continue,1 mean won, 2 mean lost
	int sum,restroll,i=1;
	srand(time(NULL));
	sum=roll();
	//while(i==1){
	switch (sum){
		case'7':
		case'11':
			result=1;
			//break;
		case'2':
		case'3':
		case'12':
			result=2;
			//break;
		default:
			result=0;
			//break;
	//}
	}
	if (result!=0){
		if (result!=1)
			printf("You lost the game!\n");
		else
			printf("You win the game!\n");
	}
	else{
		first_roll=sum;
		printf("the first roll is %d\n ",first_roll);
		while(result==0){
			restroll=roll();
			if(restroll==7){
				result=1;
				printf("You lost the game!\n");
			}
			else if(restroll==first_roll){
				result=2;
				printf("You win the game!\n");
			}

		}
	}
	return 0;
}
int roll(void)
{
	int number1,number2,total;
	//srand(time(NULL));
	//void srand( unsigned int seed );
	//srand(unsigned int seed);
	number1=rand();
	number2=rand();
	number1=1+number1%6;
	number2=1+number2%6;
	//srand(GetTickCount());
	//number1=1+rand()%6;
	//number2=1+rand()%6;
	total=number1+number2;
	printf("the roll is %d + %d = %d \n",number1,number2,total);
	return total;
}
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int i,b;
	srand(time(NULL));
	i=rand();
	b=rand();
	printf("%d\n%d",i,b);
	return 0;
}*/
