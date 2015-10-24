#include<stdio.h>
#include<stdlib.h>

struct node{
	char character;
	struct node *prePtr;
	struct node *nextPtr;
};
typedef struct node Node;

void insert(Node **headPPtr,char value);
void delet(Node **headPPtr,char value);
void print(Node headnode);
void instruction(void);

int main(void)
{
	Node *headPtr=NULL;
	int choice;
	char element;
	instruction();
	scanf("%d",&choice);
	getchar();
	//choice=getchar();
	while(choice!=3){
		switch(choice){
		case 1:
			printf("enter the character to insert\n");
			//getchar();
			scanf("%c",&element);
			getchar();
			//element=getchar();
			insert(&headPtr,element);
			//print(*headPtr);
			break;
		case 2:
			if(headPtr==NULL){
				printf("error! no element inside\n");
			}
			else{
				printf("enter the character to delete\n");
				scanf("%c",&element);
				getchar();
				//element=getchar();
				delet(&headPtr,element);
			}
			break;
		default:
			printf("unvalid value\n");			
			break;
		}//end switch
		print(*headPtr);
		instruction();
		scanf("%d",&choice);
		getchar();
		//choice=getchar();
	}//end while
	return 0;
}//end main

// functions
void instruction(void){
	printf("choice your choice from '1','2','3'\n'1'to insert\t'2'to delete\t'3'to end\n");
}

void insert(Node** headPPtr,char value)
{
	Node *newPtr,*currentPtr;
	newPtr=(Node*)malloc(sizeof(Node));
	//scanf("%c",&value);			//changed
	puts("in insert function");
	if(newPtr!=NULL){
		newPtr->character=value;
		//newPtr->prePtr=NULL;
		newPtr->nextPtr=NULL;
		//currentPtr=hnode;
		//if(hnode==NULL){			//if element is the first one be insert		！！！！这里hnode 没有被初始化！！！
		if(*headPPtr==NULL){
			*headPPtr=newPtr;
		}
		else{currentPtr=*headPPtr;	//changed
			if(newPtr->character<currentPtr->character ){
				newPtr->nextPtr=currentPtr;
				//currentPtr->prePtr=newPtr;
				*headPPtr=newPtr;
			}
			else{
				while(newPtr->character>currentPtr->character && currentPtr->nextPtr!=NULL){
					currentPtr=currentPtr->nextPtr;
				}
				if(currentPtr->nextPtr==NULL){
					currentPtr->nextPtr=newPtr;
					//newPtr->prePtr=currentPtr;
				}
				else
				{
					newPtr->nextPtr=currentPtr->nextPtr;
					currentPtr->nextPtr=newPtr;
					//newPtr->prePtr=currentPtr;				
					//currentPtr->nextPtr->prePtr=newPtr;
				}//end else 
			}//end else in else if
		}//end else in if if
	}//end if
	else{
		printf("no memory avaliable");
	}
	return;
}//end insert function

// delete function begin
void delet(Node **headPPtr,char value)
{
	Node *currentPtr=*headPPtr,*temPtr;
	if (currentPtr->nextPtr==NULL && currentPtr->character==value){
		currentPtr=NULL;
	}
	else{
		while(currentPtr->character<value && currentPtr->nextPtr!=NULL){
			currentPtr=currentPtr->nextPtr;
		}
		if(currentPtr->nextPtr==NULL){
		printf("element not found");
		}
		else if(currentPtr->nextPtr->character==value)
		{
			temPtr=currentPtr->nextPtr;
			currentPtr->nextPtr=temPtr->nextPtr;
			printf("element %c deleted successfully",value);
			free(temPtr);

		}
		else{
		printf("element not found");
		}
	}
	return;
}//end delete function

//print function begin
void print(Node headnode)
{

	Node *currentPtr=&headnode;
	while(currentPtr!=NULL){
		printf("%s\n%c\n","the list contains:",currentPtr->character);
		currentPtr=currentPtr->nextPtr;
	}
	return;
}



//有一个为NULL的指向结构体的指针，可以用这个指针的所指结构体内部的元素和别的值去比较吗？
/*int main(void)
{
	Node *tryPtr=NULL;
	if(tryPtr->character!='a'){
		printf("可以进行比较！");				//事实证明这么做是错误的
	}
	else
		puts("not so");
	return 0;
}*/