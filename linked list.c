#include<stdio.h>
#include<stdlib.h>

// compare mine with the book
struct node{
	char character;
	//struct node *prePtr;
	struct node *nextPtr;
};
typedef struct node Node;

void insert(Node **headPPtr,char value);
void delet(Node **headPPtr,char value);
int isEmpty(Node *headPPtr);		// add from the book
void print(Node headnode);			//differ from the book
void instruction(void);

int main(void)
{
	Node *headPtr=NULL;
	int choice;
	char element;
	instruction();
	printf("? ");
	scanf("%d",&choice);
	//getchar();
	//choice=getchar();
	while(choice!=3){
		switch(choice){
		case 1:
			printf("enter the character to insert\n");
			//scanf("%c",&element);			// mine
			scanf("\n%c",&element);		   //the book
			//getchar();
			insert(&headPtr,element);
			print(*headPtr);
			break;
		case 2:
			if(headPtr==NULL){
				printf("error! no element inside\n");
			}
			else{
				printf("enter the character to delete\n");
				//scanf("%c",&element);				//mine
				scanf("\n%c",&element);				//the book
				delet(&headPtr,element);
				if(headPtr!=NULL){
					print(*headPtr);
				}
				else{
					puts("list is empty");
				}
			}
			break;
		default:
			printf("unvalid value\n");	
			instruction();
			break;
		}//end switch
		printf("? ");
		scanf("%d",&choice);
		//scanf("%d",&choice);
		//getchar();
		//choice=getchar();
	}//end while
	printf("end of run.");
	return 0;
}//end main

// functions
void instruction(void){
	//printf("choice your choice from '1','2','3'\n'1'to insert\t'2'to delete\t'3'to end\n");			//mine
	printf("Enter your choice:\n"
		"	1 to insert an element into the list.\n"
		"	2 to delete an element from the list.\n"														//the book
		"	3 to end.\n");
}

//*********************my insert function*********************
/*void insert(Node** headPPtr,char value)
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
*/

//************* insert function from the book**********************
void insert(Node** headPPtr,char value)
{
	Node *newPtr,*prePtr,*currentPtr;
	if((newPtr=(Node*)malloc(sizeof(Node)))!=NULL){
		newPtr->character=value;
		newPtr->nextPtr=NULL;
		prePtr=NULL;
		currentPtr=*headPPtr;
		//---------loop to find the correct location in the list---------
		while(currentPtr!=NULL && value > currentPtr->character){
			prePtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}
		// ------insert new nood at the begining of list-------
		if(prePtr==NULL){
			newPtr->nextPtr=*headPPtr;
			*headPPtr=newPtr;
		}
		//-------insert now nood between prePtr and currentPtr------
		else{
			prePtr->nextPtr=newPtr;
			newPtr->nextPtr=currentPtr;
		}
	}//end first if
	else{
		printf("%c not insert, no memory available.\n");
	}
}//end insert function
			

// ***************** my delete function ***************************
void delet(Node **headPPtr,char value)
{
	Node *currentPtr=*headPPtr,*temPtr,*prePtr=NULL;								
	if ((*headPPtr)->character==value){
		temPtr=currentPtr;
		*headPPtr=(*headPPtr)->nextPtr;	
		puts("delete succeed");
		free(temPtr);
	}															
	else{
		while(currentPtr!=NULL && currentPtr->character!=value){				// finally this works! 
			prePtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}
		if(currentPtr==NULL){
			printf("element not found\n");
		}

		else{
			//in need of the Ptr before currentPtr
			temPtr=currentPtr;
			prePtr->nextPtr=currentPtr->nextPtr;
			puts("delete succeed");
			free(temPtr);
		}
	}
	return;
}//end delete function

// *********** another delete funcution****************
/*void delet(Node **headPPtr,char value){
	Node *prePtr=NULL;
	Node *currentPtr=*headPPtr,*temPtr;
	if((*headPPtr)->character==value){
		temPtr=*headPPtr;
		(*headPPtr)=(*headPPtr)->nextPtr;
		free(temPtr);
		puts("deleted");
	}
	else{
		while(currentPtr!=NULL && currentPtr->character!=value){
			prePtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}
		if(currentPtr!=NULL){
			temPtr=currentPtr;
			prePtr->nextPtr=currentPtr->nextPtr;
			free(temPtr);
			puts("deleted");
		}
		else{
			puts("not found");
		}
	}
return;
}*/

//***************print function begin*******************
void print(Node headnode)
{

	Node *currentPtr=&headnode;
	printf("the list contains:\n");
	while(currentPtr!=NULL){
		printf("%c\t",currentPtr->character);
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