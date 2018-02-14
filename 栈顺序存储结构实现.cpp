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
	int top;				//ջ�����α� 
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
			puts("��ջ������"); 
			return ERROR;
		}else
		{
			puts("��������Ҫѹ���Ԫ��ֵ��");
			scanf("%d",&element);
			point->top++;						//ջ���α�������һ����λ 
			point->data[point->top] = element;	//��Ԫ��ֵѹ��ջ 
			count1++;							//�˴�ѹջͳ�� 
		}
		puts("�Ƿ����ѹջ�� 1.�� 0.��");
		scanf("%d",&flag);
	}
	count2 = point->top;						//ջ������ͳ�� 
	count2++;
	printf("\n�˴�ѹջ��Ϊ��%d��ջ������Ϊ:%d\n",count1,count2);	
	return OK;
}

Status Pop(SqStack *stHead)
{
	int flag = 1;
	SElemType element;
	SqStack *point = stHead;
	while(flag)
	{
		if(point->top == -1)		//ջ�п� 
		{
			puts("��ջ��Ϊ�գ�");
			return ERROR; 
		}else if(point->top == 0)	//ջ��ֻʣһ��Ԫ�� 
		{
			printf("ջ��Ԫ��Ϊ��%d\n",point->data[point->top]);
			point->top--; 
			return OK;				//��ջ�Զ����� 
		}else						//��ͨ��� 
		{
			printf("ջ��Ԫ��Ϊ��%d\n",point->data[point->top]);
			point->top--; 
		}
		puts("�Ƿ������ջ�� 1.�� 0.��");
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
		puts("\t\t\t\t	1.ѹջ		\t\t\t\t"); 
		puts("\t\t\t\t	2.��ջ		\t\t\t\t"); 
		puts("\t\t\t\t	0.�˳�			\t\t\t\t");
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
	SqStack st;		//����һ��ջ 
	st.top = -1;	//ջ���α�ָ�� -1����ʱջ��û����ֵ 
	SqStack *stPoint = &st; 
	showMainFun(stPoint);
//	Push(stPoint);
//	Pop(stPoint);
}
