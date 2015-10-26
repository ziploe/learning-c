// inorder, preorder, postorder
/************binary search tree**********************/
#include<stdio.h>
#include<stdlib.h>

struct node {
	int number;
	struct node *leftPtr;
	struct node *rightPtr;
}
typedef struct node Node;
typedef struct node* NodePtr;

/**********functons************************/
void insertInstruction(void);
void insert(NodePtr *nodePPtr,int value);
void printInstruction(void);
void inorderPrint(NodePtr nodePtr);
void preorderPrint(NodePtr nodePtr);
void postorderPrint(NodePtr nodePtr);
/**************main function begin*****************/
int mian (void)
{
	int element,insertChoice,printChoice;
	NodePtr rootNodePtr=NULL;
	insertInstruction();
	scanf("%d",&insertChoice);
	while(insertChoice!=-1){
		puts("enter the number to insert\n");
		scanf("%d",element);
		insert(&rootNodePtr,element);
		insertInstruction();
		scanf("%d",&insertChoice);
	}// binary tree build done

	void printInstruction(void);
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
			void printInstruction(void);
			break;
		}
	}
	puts("function end\n");
	return 0;
}

/**********insertInstruction**********************/
void insertInstruction(void)
{
	printf("enter -1 to end insert, enter other number to start insert function");
}

/*******************printInstruction****************/
void printInstruction(void)
{
	printf("choice your choice\n"
		"	1 mean inorderprint\n"
		"	2 mean preorderprint\n"
		"	3 mean postorderprint\n"
		"	3 to end\n"
}
/**************insertfunction*********************/
void insert(NodePtr *nodePPtr,int value)
{
	NodePtr newPtr;
	NodePtr currentPtr;
	//newPtr=(NodePtr)malloc(sizeof(Node));
	currentPtr=(*nodePPtr);
	if((*nodePPtr)==NULL){
		newPtr=(NodePtr)malloc(sizeof(Node));			
		if(newPtr!=NULL){
			newPtr->number=value;						// creat a node and insert the value if the node is NULL
			newPtr->leftPtr=NULL;						
			newPtr->rightPtr=NULL;
			currentPtr=newPtr;
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
}//end function

/****************inorderPrint function********************/
void inorderPrint(NodePtr nodePtr)
{
	NodePtr currentPtr=nodePtr;
	if(currentPtr->leftPtr==NULL){					// if the node is the leaf node,print the value
		printf("%d",currentPtr->number);			
	}
	else{
		currentPtr=currentPtr->leftPtr;
		inorderPrint(currentPtr);			//if not ,½øÈëµü´ú
	}
	inorderPrint(currentPtr->rightPtr);
	return;
}
