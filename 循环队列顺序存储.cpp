#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 5
#define OK 	  1
#define ERROR 0
#define TRUE  1
#define FALSE 0

typedef int Status;
typedef int QElemType;

typedef struct Queue			//����˳��洢�ṹ�� 
{
	QElemType data[MAXSIZE];	//ѭ���������� 
	int front;					//��ͷ�α� 
	int rear;					//��β�α� 
}SqQueue,*pointQ;

Status EnQueue(SqQueue *Q);
Status DeQueue(SqQueue *Q);
void showMainFun(SqQueue *Q);
Status DestroyQueue(SqQueue *Q);
Status ClearQueue(SqQueue *Q);
Status QueueLenght(SqQueue *Q);

Status EnQueue(SqQueue *Q)		//��� 
{
	
	int flag = 1;
	QElemType e;
	pointQ point = Q;
	while(flag)
	{
		if((point->rear+1)%MAXSIZE == point->front)		//�ж϶����Ƿ����� 
		{
			puts("�˶���������");
			return ERROR;
		}else
		{			
			puts("���������Ԫ��ֵ��");
			scanf("%d",&e);
			point->data[point->rear] = e;
			printf("������ӵ�ֵΪ��%d\n",point->data[point->rear]); 
			point->rear = (point->rear+1)%MAXSIZE;		//��β�α�ָ��ѭ�����к�һλ�� 
			puts("��ӳɹ���");
		}
		puts("�Ƿ������ӣ� 1.��  0.��");
		scanf("%d",&flag);
	}
		
}

Status DeQueue(SqQueue *Q)		//���� 
{
	int flag = 1;
	pointQ point = Q;
	while(flag)
	{
		if((point->front) == (point->rear))		//�п� 
		{
			puts("����Ϊ�գ�");
			return ERROR;
		}else if((point->front+1)%MAXSIZE == point->rear)	//�ж��Ƿ�Ϊ��βԪ�� 
		{
			
			printf("�˴γ���Ϊ��%dԪ��ֵΪ��%d\n",point->front,point->data[point->front]);			
			puts("������Ϊ�գ�");
			return ERROR;
		}else									//�����ĳ��� 
		{
			printf("�˴γ���Ϊ��%dԪ��ֵΪ��%d\n",point->front,point->data[point->front]);
			point->front = (point->front+1)%MAXSIZE;		//��ͷ�α������һλ  
		}
		puts("�Ƿ�������ӣ� 1.��  0.��");
		scanf("%d",&flag);
	}
		
}

Status DestroyQueue(SqQueue *Q)			//���ٶ��У������⣩ 
{
	pointQ point = Q;
	free(point);
	puts("�˶������ٳɹ���"); 
	return OK;
}

Status ClearQueue(SqQueue *Q)			//��ն��� 
{
	pointQ point = Q;
	while((point->front) != (point->rear))		//ֱ�� ��ͷ�α�  ����  ��β�α� 
	{
		point->front = (point->front+1)%MAXSIZE;// ��ͷ�α������һλ 
	}
	puts("��������գ�"); 
}

Status QueueLenght(SqQueue *Q)			//��ȡ���г��� 
{
	int len;
	pointQ point = Q;
	len = (point->rear-point->front+MAXSIZE)%MAXSIZE;
	printf("��ʱ���еĳ���Ϊ��%d\n",len);
	return OK;
}

void showMainFun(SqQueue *Q)
{
	int select,flag = 1;
	while(flag)
	{
		puts("\t\t\t\t	1.���		\t\t\t\t"); 
		puts("\t\t\t\t	2.����		\t\t\t\t");
		puts("\t\t\t\t	3.���ٶ���		\t\t\t\t");
		puts("\t\t\t\t	4.��ն���		\t\t\t\t"); 
		puts("\t\t\t\t	5.��ǰ���г���		\t\t\t\t");
		puts("\t\t\t\t	0.�˳�			\t\t\t\t");
		scanf("%d",&select); 	
		switch(select)
		{
			case 1: EnQueue(Q);break;
			case 2: DeQueue(Q);break;
			case 3: DestroyQueue(Q);break; 
			case 4: ClearQueue(Q);break;
			case 5: QueueLenght(Q);break;			
			case 0: flag = 0;break;
		}
	}
} 
int main()
{
	SqQueue queue;		//����һ���� queue 
	queue.front = 0;
	queue.rear  = 0;
	pointQ pQ = &queue;
	showMainFun(pQ);
	
} 
