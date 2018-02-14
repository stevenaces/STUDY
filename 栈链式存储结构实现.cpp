#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
#define OK 	  1
#define ERROR 0
#define TRUE  1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct StackNode		//��ջÿ��ջԪ�ؽ��ṹ�� 
{
	SElemType data;				//������� 
	struct StackNode *next;		//���ָ�� 
}StackNode,*LinkStackPtr;

typedef struct LinkStack		//ջ����־�ṹ�� 
{
	LinkStackPtr top;			//����һ��ջԪ�ؽ���ָ�� 
//	StackNode *top;				//����һ�书��һ�� 
	int count;					//ͳ��ջԪ�ظ��� 
}LinkStack;

Status linkListPush(LinkStack *point);
Status linkListPop(LinkStack *point);
void showMainFun(LinkStack *point); 

Status linkListPush(LinkStack *point)		//ѹջ 
{
	int flag = 1;
	SElemType e;
	LinkStackPtr pNew;			//����һ��ջԪ�ؽ������ָ�룻 
	
	while(flag)
	{
		pNew = (LinkStackPtr)malloc(sizeof(StackNode));		//ΪջԪ�ؽ�㿪���ڴ�ռ� 
		puts("������ѹջ��Ԫ��ֵ��");
		scanf("%d",&e);
		if(point->count == 0)		//ջΪ�յ�һ��ѹջ����� 
		{
			pNew->next = NULL;		//����һ��ջԪ�ص�ָ�����ÿգ� 
			pNew->data = e;			//����һ��ջԪ�ص�������ֵ 
			point->top = pNew;		//����һ��ջԪ�ص��׵�ַ���� ջ���ṹ�� �б�־ջ����ָ�� 
			point->count++;			//ջԪ�ؼ� 1 
		}else
		{
			pNew->data = e;				//����һ��ջԪ�ص�������ֵ 
			pNew->next = point->top;	//��֮ǰ��ջ��Ԫ�� ջ��ָ�� �������ڵ� ջԪ�ؽ��ָ����ʹ֮�������� 
			point->top = pNew;			//������ջԪ�ص��׵�ַ���� ջ���ṹ�� �б�־ջ����ָ�� 
			point->count++;				//ջԪ�ؼ� 1
		}
		puts("ѹջ�ɹ���");
		puts("�ǹ�����ѹջ�� 1.��  0.��");
		scanf("%d",&flag);
	}		
}

Status linkListPop(LinkStack *point)		//��ջ 
{
	int flag = 1;
	LinkStackPtr pCurrent; 
	while(flag)
	{
		if(point->count == 0)			//ջΪ�� 
		{
			puts("��ջ��Ϊ�գ�");
			return ERROR;
		}
		else if(point->top->next == NULL)	//���һ������ջ����� 
		{
			printf("������ջ��Ԫ��Ϊ��%d\n",point->top->data);	 
			puts("��ջ��Ϊ�գ�");
			pCurrent   = point->top;//Ϊ�ͷ�ջԪ����׼��
			point->top = NULL;		//ջ���ṹ�� �б�־ջ����ָ���ÿ� 
			point->count = 0;		//ջ���ṹ�� ��ջԪ��ͳ���� 0 
			free(pCurrent); 		//�ͷ�ջԪ��ռ�õ��ڴ�ռ� 
			return OK;				//��ջ�Զ����� 
		}else if(point->top == NULL)//ջ������Ϊ�գ�û����ջ����� 
		{
			puts("��ջ��Ϊ�գ�");
		}else
		{
			printf("������ջ��Ԫ��Ϊ��%d\n",point->top->data);	
			pCurrent   = point->top;		//Ϊ�ͷ�ջԪ����׼�� 		
			point->top = point->top->next;	//ջԪ�ؽ�����һջԪ���׵�ַ���� ջ���ṹ�� �б�־ջ����ָ�� 
			point->count--;					//ջԪ�ظ����� 1 
			free(pCurrent); 				//�ͷ�ջԪ��ռ�õ��ڴ�ռ� 
		}
		puts("��ջ�ɹ���");
		puts("�ǹ�������ջ�� 1.��  0.��");
		scanf("%d",&flag);
	}	
}

void showMainFun(LinkStack *point)
{
	int select,flag = 1;
	while(flag)
	{
		puts("\t\t\t\t	1.ѹջ		\t\t\t\t"); 
		puts("\t\t\t\t	2.��ջ		\t\t\t\t"); 
		puts("\t\t\t\t	0.�˳�			\t\t\t\t");
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
	LinkStack test,*point;		//����һ�� ջ����־�ṹ�� ���� �ʹ�����ָ�� 
	test.count = 0;				//ջ����־�ṹ�� ����  ������0 
	test.top   = NULL;			//ջ����־�ṹ�� ����  ��־ջ��ָ���ÿ� 
	point = &test;				//ջ����־�ṹ�� ����  ���׵�ַ����  ջ����־�ṹ��ָ�� 
	showMainFun(point);
	
	return 0;
}
