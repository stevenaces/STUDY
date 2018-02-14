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
	int top1;		//1��ջ��ջ���α� 
	int top2; 		//2��ջ��ջ���α� 
}SqDoubleStack;		//�˽ṹ�������� 

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
		if((point->top1+1) == (point->top2))	//�жϴ�ջ�Ƿ����� 
		{
			puts("��ջ������");
			return ERROR;
		}else if(stackNumber == 1)				//ѹ1��ջ 
		{
			puts("��������Ҫѹջ��Ԫ��ֵ��");
			scanf("%d",&element); 
			point->top1++;
			point->data[point->top1] = element;		
		}else									//ѹ2��ջ 
		{
			puts("��������Ҫѹջ��Ԫ��ֵ��");
			scanf("%d",&element); 
			point->top2--;
			point->data[point->top2] = element;			
		}
		puts("�Ƿ����ѹջ�� 1.��  0.��");
		scanf("%d",&flag);
	}	
}

Status Pop(SqDoubleStack *stHead, int stackNumber)
{
	int flag = 1;
	SqDoubleStack *point = stHead;
	SElemType element;
	if(stackNumber == 1)				//	�жϵ�1��ջ 
	{
		while(flag)
		{
			if(point->top1 == -1)
			{
				puts("��ջ��Ϊ�գ�");
				return ERROR; 
			}else if(point->top1 == 0)
			{
				printf("ջ��Ԫ��Ϊ��%d\n",point->data[point->top1]);
				point->top1--; 
				return OK;
			}else
			{
				printf("ջ��Ԫ��Ϊ��%d\n",point->data[point->top1]);
				point->top1--; 
			}
			puts("�Ƿ��������ջ(1��ջ)�� 1.�� 0.��");
			scanf("%d",&flag);
		}
		return OK;
	}else							//�жϵ�2��ջ 
	{
		while(flag)
		{
			if(point->top2 == MAXSIZE)
			{
				puts("��ջ��Ϊ�գ�");
				return ERROR; 
			}else if(point->top2 == (MAXSIZE-1))
			{
				printf("ջ��Ԫ��Ϊ��%d\n",point->data[point->top2]);
				point->top2++; 
				return OK;
			}else
			{
				printf("ջ��Ԫ��Ϊ��%d\n",point->data[point->top2]);
				point->top2++; 
			}
			puts("�Ƿ��������ջ(2��ջ)�� 1.�� 0.��");
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
		puts("\t\t\t\t	1.ѹջ(1��ջ)		\t\t\t\t"); 
		puts("\t\t\t\t	2.ѹջ(2��ջ)		\t\t\t\t");
		puts("\t\t\t\t	3.��ջ(1��ջ)		\t\t\t\t");
		puts("\t\t\t\t	4.��ջ(2��ջ)		\t\t\t\t"); 
		puts("\t\t\t\t	0.�˳�			\t\t\t\t");
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
	SqDoubleStack dst;		//����һ��ջ 
	dst.top1 = -1;			//1��ջջ���α�Ϊ-1 
	dst.top2 = MAXSIZE;		//2��ջջ���α�ΪMAXSIZE 
	SqDoubleStack *dstPoint = &dst;
	showMainFun(dstPoint);
	
}
