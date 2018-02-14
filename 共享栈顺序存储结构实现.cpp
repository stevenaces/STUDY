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
	int top1;		//1号栈的栈顶游标 
	int top2; 		//2号栈的栈顶游标 
}SqDoubleStack;		//此结构体类型名 

Status Push(SqDoubleStack *stHead, int stackNumber);
Status Pop(SqDoubleStack *stHead, int stackNumber);
void showMainFun(SqDoubleStack *stHead);

Status Push(SqDoubleStack *stHead, int stackNumber)
{
	int flag = 1;
	SqDoubleStack *point = stHead;
	SElemType element;
	while(flag)
	{
		if((point->top1+1) == (point->top2))	//判断此栈是否已满 
		{
			puts("此栈已满！");
			return ERROR;
		}else if(stackNumber == 1)				//压1号栈 
		{
			puts("请输入你要压栈的元素值：");
			scanf("%d",&element); 
			point->top1++;
			point->data[point->top1] = element;		
		}else									//压2号栈 
		{
			puts("请输入你要压栈的元素值：");
			scanf("%d",&element); 
			point->top2--;
			point->data[point->top2] = element;			
		}
		puts("是否继续压栈？ 1.是  0.否");
		scanf("%d",&flag);
	}	
}

Status Pop(SqDoubleStack *stHead, int stackNumber)
{
	int flag = 1;
	SqDoubleStack *point = stHead;
	SElemType element;
	if(stackNumber == 1)				//	判断弹1号栈 
	{
		while(flag)
		{
			if(point->top1 == -1)
			{
				puts("此栈已为空！");
				return ERROR; 
			}else if(point->top1 == 0)
			{
				printf("栈顶元素为：%d\n",point->data[point->top1]);
				point->top1--; 
				return OK;
			}else
			{
				printf("栈顶元素为：%d\n",point->data[point->top1]);
				point->top1--; 
			}
			puts("是否继续弹此栈(1号栈)？ 1.是 0.否");
			scanf("%d",&flag);
		}
		return OK;
	}else							//判断弹2号栈 
	{
		while(flag)
		{
			if(point->top2 == MAXSIZE)
			{
				puts("此栈已为空！");
				return ERROR; 
			}else if(point->top2 == (MAXSIZE-1))
			{
				printf("栈顶元素为：%d\n",point->data[point->top2]);
				point->top2++; 
				return OK;
			}else
			{
				printf("栈顶元素为：%d\n",point->data[point->top2]);
				point->top2++; 
			}
			puts("是否继续弹此栈(2号栈)？ 1.是 0.否");
			scanf("%d",&flag);
		}
		return OK;
	}
}

void showMainFun(SqDoubleStack *stHead)
{
	int select,flag = 1;
	SqDoubleStack *point = stHead;
	while(flag)
	{
		puts("\t\t\t\t	1.压栈(1号栈)		\t\t\t\t"); 
		puts("\t\t\t\t	2.压栈(2号栈)		\t\t\t\t");
		puts("\t\t\t\t	3.弹栈(1号栈)		\t\t\t\t");
		puts("\t\t\t\t	4.弹栈(2号栈)		\t\t\t\t"); 
		puts("\t\t\t\t	0.退出			\t\t\t\t");
		scanf("%d",&select); 	
		switch(select)
		{
			case 1: Push(point, 1);break;
			case 2: Push(point, 2);break;
			case 3: Pop(point, 1);break; 
			case 4: Pop(point, 2);break;			
			case 0: flag = 0;break;
		}		
	}
		
}

int main()
{
	SqDoubleStack dst;		//创建一个栈 
	dst.top1 = -1;			//1号栈栈顶游标为-1 
	dst.top2 = MAXSIZE;		//2号栈栈顶游标为MAXSIZE 
	SqDoubleStack *dstPoint = &dst;
	showMainFun(dstPoint);
	
}
