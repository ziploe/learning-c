// inorder, preorder, postorder
/************binary search tree**********************/
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
void insertInstruction(void);
void insert(NodePtr nodePtr,int value);
void printInstruction(void);
void inorderPrint(NodePtr nodePtr);
void preorderPrint(NodePtr nodePtr);
void postorderPrint(NodePtr nodePtr);
/**************main function begin*****************/
int main (void)
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

/**********insertInstruction**********************/
void insertInstruction(void)
{
	printf("enter -1 to end insert,\n enter other number to start insert function");
	return;
}

/*******************printInstruction****************/
void printInstruction(void)
{
	printf("choice your choice\n"
		"	1 mean inorderprint\n"
		"	2 mean preorderprint\n"
		"	3 mean postorderprint\n"
		"	4 to end\n");
	return ;
}
/**************insertfunction*********************/
void insert(NodePtr nodePtr,int value)
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
				newPtr->number=value;						// creat a node and insert the value if the node is NULL
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


/****************inorderPrint function********************/
void inorderPrint(NodePtr nodePtr)
{
	NodePtr currentPtr=nodePtr;
	if(currentPtr->leftPtr==NULL){					
		printf("%d",currentPtr->number);
		if(currentPtr->rightPtr!=NULL){
			inorderPrint(currentPtr->rightPtr);
		}

	}
	else{
		inorderPrint(currentPtr->leftPtr);			
		printf("%d",currentPtr->number);
	}
	return;
}
void preorderPrint(NodePtr nodePtr){
	puts("p");
	return ;
}
void postorderPrint(NodePtr nodePtr){
	puts("s");
	return ;
}