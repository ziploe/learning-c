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
	//student1.number=1;			  //int ������ô��ֵ
	//strcpy(student1.name,a);		 //��6�ж�Ӧ  ����
	//strcpy(student1.name,"wang"); //��6�ж�Ӧ  ���� //�μ�http://www.360doc.com/content/14/1125/23/6496277_428086465.shtml
	//student1.name="wang";		   //��6�ж�Ӧ  ������ Ϊʲôchar��������ô ��ֵ��ֻ��������ʱ��ֵ���� ֮��strcpy ��ֵ
	//student1.name="wang";		  //��7�ж�Ӧ  ����
	student1={1,"wang"};		 //��6�ж�Ӧ  ������
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
	printf("location %p value %d \n",&a,a);			//	һ����������Ӧһ����ַ
	printf("location %p value %d \n",&b,b);
	//int *Ptr,*Ptr2;								  //Ϊ����������һ��Ҫ������ǰ�棿
	Ptr=(int*)malloc(sizeof(int)); 
	//Ptr2=(int*)malloc(sizeof(int));				//Ptr2 Ҳ������һ����ַ
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
