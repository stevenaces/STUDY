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

Status GetElem(SqList *L, int i)	//获得元素 
{
	int e;
	if(L->length == 0 || i <1 || i>L->length)
	{
		puts("查询不合法或为空表"); 
		return ERROR;
	}
	e = L->data[i-1];
	printf("该位置元素为：%d\n",e);	 
	return OK;	
}
void InitList(SqList *&L)  
{  
    L = (SqList*)malloc(sizeof(SqList));  
    L->length=0;  
} 
Status ListInsert (SqList *L, int i, ElemType e)	//第 i 个位置 前插 
{
	int k;
	if(L->length == MAXSIZE)	//表满 
	{
		return ERROR;
	}
	if(i<1 || i> L->length+1)	//插入位置不合法 
	{
		return ERROR;
	} 
	if(i<=L->length)	//插入的不在表尾 
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
	if(L->length == 0)	//是否为空表 
	{
		puts("此表为空！！！"); 
		return ERROR;
	}
	if(i> L->length || i<1) //删除位置不合法 
	{
		puts("删除位置不合法");
		return ERROR;
	}
	
	e = L->data[i-1];	
	
	if(i<L->length)	//元素取出后，后面的元素往前移覆盖 
	{
		for(k=i;k<=L->length;k++)
		{
			L->data[k-1] = L->data[k]; 
		}
	} 
	
	L->length--;
	printf("删除成功，被删除的元素值为：%d\n",e);
	return OK; 
}

int insertFunction(SqList L)
{
	
	ElemType input;
	int index,result;
	puts("请输入数字：");
	scanf("%d",&input);
	puts("请输入插入的位置：");
	scanf("%d",&index); 
	
	result = ListInsert (&L, index, input);
	if(result == OK)
	{
		puts("插入成功");
		return 0; 
	}else
	{
		puts("插入失败");
		return 0;
	}
}

int checkFunction(SqList *L)
{
	int index;
	puts("请输入你要查询的元素位置：");
	scanf("%d",&index);
	
	GetElem(L, index);
	 
}
void Display(SqList *L)
{
	int len;
	len = L->length;
	if(len == 0)
	{
		puts("此表为空！！！");
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
	puts("请输入你要删除的元素位置：");
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
	
	printf("顺序初始化： L \n");
	InitList(L);	

	while(goOn)
	{	
		puts("请选择你的操作：1.插入  2.查询  3.删除  4.显示  0.退出");
		scanf("%d",&select);
		switch(select)
		{
			case 1: insertFunction(l1);break;
			case 2: checkFunction(L);break;
			case 3: deleteFunction(L);break;
			case 4: Display(L);break; 
			case 0: return 0;	
		}
		puts("是否继续操作？ 1.是 0.退出");
		scanf("%d",&goOn);		
	} 
	
	return 0;
} 

/* 
*	https://www.cnblogs.com/qyaizs/articles/2039101.html
*	https://www.cnblogs.com/wgang171412/p/5046235.html
*	https://www.cnblogs.com/xiang-little/p/5840809.html
*/ 
