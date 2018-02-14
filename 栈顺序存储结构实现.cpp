#include <stdio.h>

#define MAXSIZE 100
#define OK 	  1
#define ERROR 0
#define TRUE  1
#define FALSE 0


typedef int SElemType;
typedef int Status;

typedef struct
{
	SElemType data[MAXSIZE];
	int top;				//栈顶的游标 
}SqStack;

Status Push(SqStack *stHead);
Status Pop(SqStack *stHead);
void showMainFun(SqStack *stHead);

Status Push(SqStack *stHead)
{
	int flag = 1,count1=0,count2;	
	SElemType element;
	SqStack *point = stHead;
	
	while(flag)
	{
		if(point->top == (MAXSIZE-1))
		{
			puts("此栈以满！"); 
			return ERROR;
		}else
		{
			puts("请输入你要压入的元素值：");
			scanf("%d",&element);
			point->top++;						//栈顶游标向上移一个单位 
			point->data[point->top] = element;	//将元素值压入栈 
			count1++;							//此次压栈统计 
		}
		puts("是否继续压栈？ 1.是 0.否");
		scanf("%d",&flag);
	}
	count2 = point->top;						//栈内总数统计 
	count2++;
	printf("\n此次压栈数为：%d，栈内总数为:%d\n",count1,count2);	
	return OK;
}

Status Pop(SqStack *stHead)
{
	int flag = 1;
	SElemType element;
	SqStack *point = stHead;
	while(flag)
	{
		if(point->top == -1)		//栈判空 
		{
			puts("此栈已为空！");
			return ERROR; 
		}else if(point->top == 0)	//栈内只剩一个元素 
		{
			printf("栈顶元素为：%d\n",point->data[point->top]);
			point->top--; 
			return OK;				//弹栈自动结束 
		}else						//普通情况 
		{
			printf("栈顶元素为：%d\n",point->data[point->top]);
			point->top--; 
		}
		puts("是否继续弹栈？ 1.是 0.否");
		scanf("%d",&flag);
	}
	return OK;
}

void showMainFun(SqStack *stHead)
{
	int select,flag = 1;
	SqStack *point = stHead;
	while(flag)
	{
		puts("\t\t\t\t	1.压栈		\t\t\t\t"); 
		puts("\t\t\t\t	2.弹栈		\t\t\t\t"); 
		puts("\t\t\t\t	0.退出			\t\t\t\t");
		scanf("%d",&select); 	
		switch(select)
		{
			case 1: Push(point);break;
			case 2: Pop(point);break; 			
			case 0: flag = 0;break;
		}		
	}
		
}

int main()
{
	SqStack st;		//创建一个栈 
	st.top = -1;	//栈顶游标指向 -1，此时栈内没有数值 
	SqStack *stPoint = &st; 
	showMainFun(stPoint);
//	Push(stPoint);
//	Pop(stPoint);
}
