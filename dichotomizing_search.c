/*#include<stdio.h>
int main(void)
{
	int a[]={0,1,2,3,4,5};
	printf("%d\na[%d]",a[3],3);
	return 0;
}*/
/*#include<stdio.h>
#include<string.h>
#define SIZE 100
//����һ�ζ���
int *half_function(int c[],int keynumber1,int low1,int max1)
{
	static int d[4];				
	int middle=(low1+max1)/2;    //�ҵ��м�����
	d[0]=0;d[1]=low1;d[2]=max1;d[3]=middle;//d[]={���ж��Ƿ��ҵ�������һ�����������һ���������м�����}
	//printf("%d",d[2]);
	if (keynumber1==c[middle]){				// ������ҵ��������м���������Ӧ������Ԫ��
		d[0]=1;
		d[3]=middle;
	}
	else if(keynumber1<c[middle]){				//������ҵ���С���м���������Ӧ������Ԫ��
		d[2]=middle;}
	else
		d[1]=middle;
	return d;
}
//���ַ���������Ԫ��
int main(void)
{
	int a[SIZE];
	int low=0,max=SIZE-1,keynumber,i;
	int b[4]={0,low,max,0};//b[0]�����ж��Ƿ��ҵ�Ԫ�� �ҵ�ʱ��ֵ1  
	int *p = NULL;
	for (i=0;i<SIZE;i++){					//���鸳ֵ
		a[i]=2*i;
	}
	printf("enter the element you want to find\n");
	scanf_s("%d",&keynumber);
	while(b[2]-b[1]>1){						//�����������ȥ��һ����������һʱ����ѭ��
		if(b[0]==1)
			printf("element was found a[%d]",b[3]);	// Ԫ����a[b[3]]���λ�ñ��ҵ�
		else
		{
			p = half_function(a,keynumber,low,max); //���û�ҵ� �ٽ���һ�ζ��ַ�
			for(i=0;i<4;i++)
				b[i]=p[i];							//��p[]����b[]
		}
	}
	return 0;
}*/
/*int *half_function(int c[],int keynumber1,int low1,int max1)
{
	
	int middle=(low1+max1)/2;
	int d[4]={0,low1,max1,middle};
	if (keynumber1==c[middle]){
		d[0]=1;
		d[3]=middle;
	}
	else if(keynumber1<c[middle]){
		d[2]=middle;}
	else
		d[1]=middle;
	return d[4];
}*/
#include<stdio.h>
#include<string.h>
#define SIZE 100
int *half_function(int c[],int keynumber1,int low1,int max1)
{
	static int d[4];
	int middle=(low1+max1)/2;
	d[0]=0;d[1]=low1;d[2]=max1;d[3]=middle;
	//printf("%d",d[2]);
	if (keynumber1==c[middle]){
		d[0]=1;
		d[1]=middle;
		d[2]=middle;
		d[3]=middle;
	}
	else if(keynumber1<c[middle]){
		d[2]=middle;}
	else
		d[1]=middle+1;
	return d;
}
int main(void)
{
	int a[SIZE];
	int low=0,max=SIZE-1,keynumber,i;
	int b[4]={0,low,max,0};
	int *p = NULL;
	for (i=0;i<SIZE;i++){
		a[i]=2*i;
	}
	printf("enter the element you want to find\n");
	scanf("%d",&keynumber);
	while(b[2]-b[1]>=1){
		
		p = half_function(a,keynumber,b[1],b[2]);
		for(i=0;i<4;i++)
			b[i]=p[i];
		if(b[0]==1)
			printf("element was found b[%d]",b[3]);
		
	}
	return 0;
}
