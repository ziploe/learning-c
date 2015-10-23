#include<stdio.h>
#include<string.h>

struct card{
	char *face;			// attention!!! "*" has always been forgot 
	char *suit;
};
typedef struct card Card;
void function (Card *a);
							//	问题描述 如何把一个字符串数组中的元素赋予结构体中的
int main(void)
{
	Card deck[52],acard;
	char *Ptr="hello";
	char *string[]={"along","side"};
	deck[10].face="king";
	acard.face = "king";
	function(deck);
	printf("%s\n",deck[9].face);
	printf("%s\n",deck[10].face);
	//strcpy(deck[7].face,string[0]);
	deck[7].face=Ptr;
	deck[2].face=string[0];
	printf("%s\n",deck[7].face);
	printf("%s\n",deck[2].face);
	return 0;
}
void function(Card*a)
{
	a[9].face="ten";
}