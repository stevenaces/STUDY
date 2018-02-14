#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
#define OK 	  1
#define ERROR 0
#define TRUE  1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct StackNode		//链栈每个栈元素结点结构体 
{
	SElemType data;				//结点数据 
	struct StackNode *next;		//结点指针 
}StackNode,*LinkStackPtr;

typedef struct LinkStack		//栈顶标志结构体 
{
	LinkStackPtr top;			//定义一个栈元素结点的指针 
//	StackNode *top;				//与上一句功能一样 
	int count;					//统计栈元素个数 
}LinkStack;

Status linkListPush(LinkStack *point);
Status linkListPop(LinkStack *point);
void showMainFun(LinkStack *point); 

Status linkListPush(LinkStack *point)		//压栈 
{
	int flag = 1;
	SElemType e;
	LinkStackPtr pNew;			//定义一个栈元素结点类型指针； 
	
	while(flag)
	{
		pNew = (LinkStackPtr)malloc(sizeof(StackNode));		//为栈元素结点开辟内存空间 
		puts("请输入压栈的元素值：");
		scanf("%d",&e);
		if(point->count == 0)		//栈为空第一次压栈的情况 
		{
			pNew->next = NULL;		//将第一个栈元素的指针域置空； 
			pNew->data = e;			//将第一个栈元素的数据域赋值 
			point->top = pNew;		//将第一个栈元素的首地址赋给 栈顶结构体 中标志栈顶的指针 
			point->count++;			//栈元素加 1 
		}else
		{
			pNew->data = e;				//将第一个栈元素的数据域赋值 
			pNew->next = point->top;	//将之前的栈顶元素 栈顶指针 赋给现在的 栈元素结点指针域，使之链接起来 
			point->top = pNew;			//将现在栈元素的首地址赋给 栈顶结构体 中标志栈顶的指针 
			point->count++;				//栈元素加 1
		}
		puts("压栈成功！");
		puts("是够继续压栈？ 1.是  0.否");
		scanf("%d",&flag);
	}		
}

Status linkListPop(LinkStack *point)		//出栈 
{
	int flag = 1;
	LinkStackPtr pCurrent; 
	while(flag)
	{
		if(point->count == 0)			//栈为空 
		{
			puts("此栈已为空！");
			return ERROR;
		}
		else if(point->top->next == NULL)	//最后一个弹出栈的情况 
		{
			printf("弹出的栈顶元素为：%d\n",point->top->data);	 
			puts("此栈已为空！");
			pCurrent   = point->top;//为释放栈元素做准备
			point->top = NULL;		//栈顶结构体 中标志栈顶的指针置空 
			point->count = 0;		//栈顶结构体 中栈元素统计置 0 
			free(pCurrent); 		//释放栈元素占用的内存空间 
			return OK;				//弹栈自动结束 
		}else if(point->top == NULL)//栈本来就为空，没有入栈的情况 
		{
			puts("此栈已为空！");
		}else
		{
			printf("弹出的栈顶元素为：%d\n",point->top->data);	
			pCurrent   = point->top;		//为释放栈元素做准备 		
			point->top = point->top->next;	//栈元素结点的下一栈元素首地址赋给 栈顶结构体 中标志栈顶的指针 
			point->count--;					//栈元素个数建 1 
			free(pCurrent); 				//释放栈元素占用的内存空间 
		}
		puts("弹栈成功！");
		puts("是够继续弹栈？ 1.是  0.否");
		scanf("%d",&flag);
	}	
}

void showMainFun(LinkStack *point)
{
	int select,flag = 1;
	while(flag)
	{
		puts("\t\t\t\t	1.压栈		\t\t\t\t"); 
		puts("\t\t\t\t	2.弹栈		\t\t\t\t"); 
		puts("\t\t\t\t	0.退出			\t\t\t\t");
		scanf("%d",&select); 	
		switch(select)
		{
			case 1: linkListPush(point);break;
			case 2: linkListPop(point);break; 			
			case 0: flag = 0;break;
		}		
	}
		
}

int main()
{
	LinkStack test,*point;		//定义一个 栈顶标志结构体 变量 和此类型指针 
	test.count = 0;				//栈顶标志结构体 变量  计数置0 
	test.top   = NULL;			//栈顶标志结构体 变量  标志栈顶指针置空 
	point = &test;				//栈顶标志结构体 变量  的首地址赋给  栈顶标志结构体指针 
	showMainFun(point);
	
	return 0;
}
