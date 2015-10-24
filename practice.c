#include<stdio.h>

void doublee (int* Ptr);
	
int main(void)
{
	int a=9;	
	*&a=10;
	doublee(&a);			
	printf("%d",a);    
	return 0;
}
void doublee (int* i)
{
	*i=99;
}
/*#include<stdio.h>
#include<stdlib.h>
struct list {
	int num;
	struct list* nextPtr;
};
typedef struct list List;
typedef List *ListPtr;

void doubleElement(List* alist);
void adoble(List alist);

int main(void)
{
	ListPtr Ptr;
	Ptr=(ListPtr)malloc(sizeof(List));

	if(Ptr!=NULL){
		Ptr->num=9;
		Ptr->nextPtr=NULL;
		printf("the number is %d\n",Ptr->num);
		//doubleElement(Ptr);
		adoble(*Ptr);
		printf("then %c the number is %d\n",',',Ptr->num);
	}
	else
		printf("No memary available");
	free(Ptr);
	return 0;
}
void doubleElement(List* alist)
{
	alist->num=alist->num*alist->num;
}
void adoble(List alist)
{
	alist.num=alist.num+alist.num;
	printf("athe number is %d\n",alist.num);
}*/