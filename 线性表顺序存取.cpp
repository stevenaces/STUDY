#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 20

#define OK 	  1
#define ERROR 0
#define TRUE  1
#define FALSE 0

typedef int ElemType; 
typedef int Status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status GetElem(SqList *L, int i)	//���Ԫ�� 
{
	int e;
	if(L->length == 0 || i <1 || i>L->length)
	{
		puts("��ѯ���Ϸ���Ϊ�ձ�"); 
		return ERROR;
	}
	e = L->data[i-1];
	printf("��λ��Ԫ��Ϊ��%d\n",e);	 
	return OK;	
}
void InitList(SqList *&L)  
{  
    L = (SqList*)malloc(sizeof(SqList));  
    L->length=0;  
} 
Status ListInsert (SqList *L, int i, ElemType e)	//�� i ��λ�� ǰ�� 
{
	int k;
	if(L->length == MAXSIZE)	//���� 
	{
		return ERROR;
	}
	if(i<1 || i> L->length+1)	//����λ�ò��Ϸ� 
	{
		return ERROR;
	} 
	if(i<=L->length)	//����Ĳ��ڱ�β 
	{
		for(k=L->length-1; k>= i-1; k--)
		{
			L->data[k+1] = L->data[k];
		}
	}
	
	L->data[i-1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList *L, int i)
{
	int k,e;	
	if(L->length == 0)	//�Ƿ�Ϊ�ձ� 
	{
		puts("�˱�Ϊ�գ�����"); 
		return ERROR;
	}
	if(i> L->length || i<1) //ɾ��λ�ò��Ϸ� 
	{
		puts("ɾ��λ�ò��Ϸ�");
		return ERROR;
	}
	
	e = L->data[i-1];	
	
	if(i<L->length)	//Ԫ��ȡ���󣬺����Ԫ����ǰ�Ƹ��� 
	{
		for(k=i;k<=L->length;k++)
		{
			L->data[k-1] = L->data[k]; 
		}
	} 
	
	L->length--;
	printf("ɾ���ɹ�����ɾ����Ԫ��ֵΪ��%d\n",e);
	return OK; 
}

int insertFunction(SqList L)
{
	
	ElemType input;
	int index,result;
	puts("���������֣�");
	scanf("%d",&input);
	puts("����������λ�ã�");
	scanf("%d",&index); 
	
	result = ListInsert (&L, index, input);
	if(result == OK)
	{
		puts("����ɹ�");
		return 0; 
	}else
	{
		puts("����ʧ��");
		return 0;
	}
}

int checkFunction(SqList *L)
{
	int index;
	puts("��������Ҫ��ѯ��Ԫ��λ�ã�");
	scanf("%d",&index);
	
	GetElem(L, index);
	 
}
void Display(SqList *L)
{
	int len;
	len = L->length;
	if(len == 0)
	{
		puts("�˱�Ϊ�գ�����");
	}else
	{
	for(int i=0;i<len;i++)
		{
			printf("%d\t",L->data[i]);
		}
		printf("\n");	
	}	
}

void deleteFunction(SqList *L)
{
	int pos;
	puts("��������Ҫɾ����Ԫ��λ�ã�");
	scanf("%d",&pos);
	
	ListDelete(L, pos);
}
int main()
{
	SqList l1;
	SqList *L;
	L = &l1;
	ElemType e;
	
	int select,goOn=1;
	
	printf("˳���ʼ���� L \n");
	InitList(L);	

	while(goOn)
	{	
		puts("��ѡ����Ĳ�����1.����  2.��ѯ  3.ɾ��  4.��ʾ  0.�˳�");
		scanf("%d",&select);
		switch(select)
		{
			case 1: insertFunction(l1);break;
			case 2: checkFunction(L);break;
			case 3: deleteFunction(L);break;
			case 4: Display(L);break; 
			case 0: return 0;	
		}
		puts("�Ƿ���������� 1.�� 0.�˳�");
		scanf("%d",&goOn);		
	} 
	
	return 0;
} 

/* 
*	https://www.cnblogs.com/qyaizs/articles/2039101.html
*	https://www.cnblogs.com/wgang171412/p/5046235.html
*	https://www.cnblogs.com/xiang-little/p/5840809.html
*/ 
