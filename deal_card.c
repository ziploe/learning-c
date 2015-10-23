#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
	char *face;
	char *suit;
};
typedef struct card Card;

void creatCard (Card* const Ptr);
void shuffleCard (Card * const Ptr);
void printCard (const Card* const Ptr);
//char* suit[]={"heart","spade","diamond","club"};
//char* face[]={"one","two","three","four","five","six","seven","eight","nine","ten","J","Q","K"};

int main (void)
{
	Card deck[52];
	srand(time(NULL));
	//const char* suit[]={"heart","spade","diamond","club"};
	//const char* face[]={"one","two","three","four","five","six","seven","eight","nine","ten","J","Q","K"};
	printf("now creat the deck\n");	
	creatCard(deck);
	printCard(deck);
	//printf("%s",deck[1].face);
	//printf("%10s\t%s\t%10s%s",deck[4].face,"of",deck[4].suit,".");		//so far it is correct
	shuffleCard(deck);
	printCard(deck);
	return 0;
}

void creatCard(Card* const Ptr)
{
	char* suit[]={"heart","spade","diamond","club"};
	char* face[]={"one","two","three","four","five","six","seven","eight","nine","ten","J","Q","K"};
	int i=0;
	for (i=0;i<52;i++){ 
		Ptr[i].suit=suit[i/13];
		Ptr[i].face=face[i%13];
	}//end for
	printf("creat succeed\n");
	return ;
}//end function
void printCard (const Card * const Ptr)
{
	int i;
	printf("print called\n");
	for (i=0;i<52;i++){
		//printf("now in for loop");
		if(i%4==0){
			printf("\n");
		}//end if
		printf("%7s%s%-8s%s",Ptr[i].face," of ",Ptr[i].suit,".");			//这句话出问题了！！！  shit!!原来创建一副牌的时候没从0开始从i=1开始了。。。
		//printf("%10s\t%s\t%10s%s",Ptr[0].face,"of",Ptr[0].suit,".");
		
	}//end for
	printf("\n");
	return ;
}//end function
void shuffleCard (Card * const Ptr)
{
	Card tempcard;
	int j=0,k;
	for(j;j<52;j++){
		k=rand()%52;
		tempcard=Ptr[k];
		Ptr[k]=Ptr[j];
		Ptr[j]=tempcard;
	}//end for
	return;
}//end shuffleCard
//哈哈哈哈哈哈哈哈哈哈哈哈！！！！！！！ finally!!