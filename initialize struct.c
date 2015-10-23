#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
	int number;
	//char name[10];
	char* name;
};
typedef struct student Student;

/*int main (void)
{
	//Student student1={1,"wang"},student2;
	Student student1,student2;
	char a[]="wang";
	//student1.number=1;			  //int 可以这么赋值
	//strcpy(student1.name,a);		 //与6行对应  可行
	//strcpy(student1.name,"wang"); //与6行对应  可行 //参见http://www.360doc.com/content/14/1125/23/6496277_428086465.shtml
	//student1.name="wang";		   //与6行对应  不可行 为什么char不可以这么 赋值？只能在声明时赋值或者 之后strcpy 赋值
	//student1.name="wang";		  //与7行对应  可行
	student1={1,"wang"};		 //与6行对应  不可行
	student2=student1;

	printf("%s\t%d\n",student1.name,student1.number);
	printf("%s\t%d",student2.name,student2.number);
	return 0;
}*/
int main (void)
{
	int a ,b;
	int *Ptr,*Ptr2;
	a=8;b=9;
	printf("location %p value %d \n",&a,a);
	printf("location %p value %d \n",&b,b);
	b=a;
	printf("location %p value %d \n",&a,a);			//	一个变量名对应一个地址
	printf("location %p value %d \n",&b,b);
	//int *Ptr,*Ptr2;								  //为何声明变量一定要放在最前面？
	Ptr=(int*)malloc(sizeof(int)); 
	//Ptr2=(int*)malloc(sizeof(int));				//Ptr2 也申请了一个地址
	Ptr2=Ptr;
	printf("%p\t%p\n",*Ptr,*Ptr2);
	if(Ptr!=NULL){
		*Ptr=9;
		printf("%d\t%d\n",*Ptr,*Ptr2);
		free(Ptr);
		printf("%d\t%d\n",*Ptr,*Ptr2);
	}
	return 0;
}
