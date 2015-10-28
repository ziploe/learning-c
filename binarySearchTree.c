/************binary search tree**********************/
/*********insert the number and save in a binary tree*****/
/********and choose your way to print****************/
#include<stdio.h>
#include<stdlib.h>

struct node {
	int number;
	struct node *leftPtr;
	struct node *rightPtr;
};
typedef struct node Node;
typedef struct node* NodePtr;

/**********functons************************/
//void insertInstruction(void);
void insert(NodePtr nodePtr,int value);
void printInstruction(void);
void inorderPrint(NodePtr nodePtr);
void preorderPrint(NodePtr nodePtr);
void postorderPrint(NodePtr nodePtr);
/**************old main function begin*****************/
/*int main (void)
{
	int element,insertChoice,printChoice;
	NodePtr rootNodePtr=NULL;
	insertInstruction();
	scanf("%d",&insertChoice);
	while(insertChoice!=-1){
		puts("enter the number to insert\n");
		scanf("%d",&element);
		if(rootNodePtr==NULL){
			rootNodePtr=(NodePtr)malloc(sizeof(Node));
			rootNodePtr->number=element;
			rootNodePtr->leftPtr=NULL;
			rootNodePtr->rightPtr=NULL;
		}
		else{
			insert(rootNodePtr,element);
			insertInstruction();
		}
		insertInstruction();
		scanf("%d",&insertChoice);
	}// binary tree build done

	printInstruction();
	scanf("%d",&printChoice);
	while(printChoice!=4){
		switch(printChoice){
		case 1:
			inorderPrint(rootNodePtr);
			break;
		case 2:
			preorderPrint(rootNodePtr);
			break;
		case 3:
			postorderPrint(rootNodePtr);
			break;
		default:
			puts("invalid choice\n");
			printInstruction();
			break;
		}
		printInstruction();
		scanf("%d",&printChoice);
	}
	puts("function end\n");
	return 0;
}		//end main function
*/

/**************new main function*****************/
int main(void)
{
	int element,printChoice;
	NodePtr rootNodePtr=NULL;
	puts("enter a number to insert or enter a non-number to stop insert function\n");
	printf("?:");
	while(scanf("%d",&element)){
		if(rootNodePtr==NULL){
			rootNodePtr=(NodePtr)malloc(sizeof(Node));
			rootNodePtr->number=element;
			rootNodePtr->leftPtr=NULL;
			rootNodePtr->rightPtr=NULL;
		}
		else{
			insert(rootNodePtr,element);	
		}
		printf("?:");
	}
	getchar();					//第77行 scanf("%d",&i);是告诉电脑，你从输入流输入一个东西，
	printInstruction();				//如果他是整形（%d）判断，那么他将传递过来的地址
	scanf("%d",&printChoice);			//（&i是对i取地址）接收，否则将被继续放在缓存中。
							//92行输入非数字就会进入死循环！ 因为它一直被放在缓存中
	while(printChoice!=4){
		switch(printChoice){
		case 1:												
			inorderPrint(rootNodePtr);
			break;
		case 2:
			preorderPrint(rootNodePtr);
			break;
		case 3:
			postorderPrint(rootNodePtr);
			break;
		default:
			puts("invalid choice\n");
			//printInstruction();
			break;
		}
		fflush(stdin);					// to clean the date in the cache
		printInstruction();
		scanf("%d",&printChoice);
	}
	puts("function end\n");
	return 0;
}		//end main function

/**********insertInstruction**********************/
void insertInstruction(void)
{
	printf("enter -1 to end insert,\n enter other number to start insert function：");
	return;
}

/*******************printInstruction****************/
void printInstruction(void)
{
	printf("\nchoice your choice\n"
		"	1 mean inorderprint\n"
		"	2 mean preorderprint\n"
		"	3 mean postorderprint\n"
		"	4 to end\n");
	return ;
}
/**************old eorr insertfunction*********************/
/*void insert(NodePtr nodePtr,int value)
{
	NodePtr newPtr;
	NodePtr currentPtr;
	//newPtr=(NodePtr)malloc(sizeof(Node));
	currentPtr=nodePtr;
	if( currentPtr->number==value){
		puts("not inserted, because of repetition");		
	}
	else if(value<currentPtr->number){
		if(currentPtr->leftPtr==NULL){
			newPtr=(NodePtr)malloc(sizeof(Node));			
			if(newPtr!=NULL){
				newPtr->number=value;						// creat a node and insert the value if the node is NULL
				newPtr->leftPtr=NULL;						
				newPtr->rightPtr=NULL;
				currentPtr->leftPtr=newPtr;
			}
			else{
				puts("insert failed, momory available");
			}
		}//end if leftPtr==NULL
		else{
			currentPtr=currentPtr->leftPtr;
			insert(currentPtr,value);
		}
	}
	else{			//value>currentPtr->number
		if(currentPtr->rightPtr==NULL){
			newPtr=(NodePtr)malloc(sizeof(Node));			
			if(newPtr!=NULL){
				newPtr->number=value;		// creat a node and insert the value if the node is NULL
				newPtr->leftPtr=NULL;						
				newPtr->rightPtr=NULL;
				currentPtr->rightPtr=newPtr;
			}
			else{
				puts("insert failed, momory available");
			}
		}//end if leftPtr==NULL
		else{
			currentPtr=currentPtr->rightPtr;
			insert(currentPtr,value);
		}
	}
	return;
}*/

/****************new insert function***********************/
void insert(NodePtr nodePtr,int value)
{
	NodePtr newPtr,prePtr;
	NodePtr currentPtr=nodePtr;
	while(currentPtr!=NULL && currentPtr->number!=value){
		prePtr=currentPtr;
		if(value<currentPtr->number){	
			currentPtr=currentPtr->leftPtr;
		}
		else{
			currentPtr=currentPtr->rightPtr;
		}
	}//end while
	if(currentPtr==NULL){
		newPtr=(NodePtr)malloc(sizeof(Node));
		if(newPtr!=NULL){
			newPtr->number=value;
			newPtr->leftPtr=NULL;
			newPtr->rightPtr=NULL;
			if(value<prePtr->number){
				prePtr->leftPtr=newPtr;
			}
			else{
				prePtr->rightPtr=newPtr;
			}	
		}
		else{
			puts("insert failed, momory available");
		}
	}
	else{
		puts("not inserted, because of repetition");
	}
	return ;
}


/*

	if(currentPtr==NULL){
		newPtr=(NodePtr)malloc(sizeof(Node));			
		if(newPtr!=NULL){
			newPtr->number=value;						// creat a node and insert the value if the node is NULL
			newPtr->leftPtr=NULL;						
			newPtr->rightPtr=NULL;
			currentPtr=newPtr;
			puts("first node used");
		}
		else{
			puts("insert failed, momory available");
		}
	}
	else if( currentPtr->number==value){
		puts("not inserted, because of repetition");		
	}
	else if(value<currentPtr->number){
		insert(&(currentPtr->leftPtr),value);
	}
	else{
		insert(&(currentPtr->rightPtr),value);
	}
	return;
}//end function


/****************old inorderPrint function********************/
/*void inorderPrint(NodePtr nodePtr)
{
	NodePtr currentPtr=nodePtr;
	if(currentPtr->leftPtr==NULL){					
		printf("%d\t",currentPtr->number);
		if(currentPtr->rightPtr!=NULL){
			inorderPrint(currentPtr->rightPtr);
		}

	}
	else{
		inorderPrint(currentPtr->leftPtr);			
		printf("%d\t",currentPtr->number);
	}
	return;
}*/

/************new inorderPrint function******************/
void inorderPrint(NodePtr nodePtr){
	NodePtr currentPtr=nodePtr;
	if(currentPtr!=NULL){
		inorderPrint(currentPtr->leftPtr);
		printf("%d\t",currentPtr->number);
		inorderPrint(currentPtr->rightPtr);
	}
}

/****************preorderPrint function***********************/
void preorderPrint(NodePtr nodePtr){
	NodePtr currentPtr=nodePtr;
	if(currentPtr!=NULL){
		printf("%d\t",currentPtr->number);
		preorderPrint(currentPtr->leftPtr);
		preorderPrint(currentPtr->rightPtr);

	}
	return ;
}
/****************postorderPrint function***********************/
void postorderPrint(NodePtr nodePtr){
	NodePtr currentPtr=nodePtr;
	if(currentPtr!=NULL){
		postorderPrint(currentPtr->leftPtr);
		postorderPrint(currentPtr->rightPtr);
		printf("%d\t",currentPtr->number);
	}
	return ;
}
