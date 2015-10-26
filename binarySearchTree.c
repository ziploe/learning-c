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
void inorderPrint(NodePtr rootNodePtr);
void preorderPrint(NodePtr rootNodePtr);
void postorderPrint(NodePtr rootNodePtr);
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

/**************insertfunction*********************/
void insert(NodePtr *nodePPtr,int value)
{
	NodePtr newPtr;
	newPtr=(NodePtr)malloc(sizeof(Node));
	if(newPtr!=NULL){
		newPtr->number=value;
		newPtr->leftPtr=NULL;						//
		newPtr->rightPtr=NULL;
		if((*nodePPtr)==NULL){
			(*nodePPtr)=newPtr;
		}
		else if( (*nodePPtr)->number==value){
			puts("not inserted, because of repetition");
		}
		else if(value<(*nodePPtr)->number){
			insert(&(*nodePPtr)->leftPtr,value);
		}
		else{
			insert(&(*nodePPtr)->rightPtr,value);
		}
	}
	else{
		puts("insert failed, momory available");
	}
}//end function