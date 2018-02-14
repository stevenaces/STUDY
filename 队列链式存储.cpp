#include<stdio.h>
#include<malloc.h>

#define OK 	  1
#define ERROR 0
#define TRUE  1
#define FALSE 0

typedef int QElemType;
typedef int Status;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front,rear;
}LinkQueue;

void showMainFun(LinkQueue *Q);
Status EnQueue(LinkQueue *Q);
Status DeQueue(LinkQueue *Q);
//Status ClearQueue(LinkQueue *Q);

Status EnQueue(LinkQueue *Q)		//��� 
{
	LinkQueue *point = Q;
	QueuePtr pNew;					//��Ԫ�ؽ�� 
	QElemType e;
	int flag = 1;
	
	while(flag)
	{
		pNew = (QueuePtr)malloc(sizeof(QNode));		//���ٶ�Ԫ�ؽ��ռ� 
		puts("���������Ԫ��ֵ��");
		scanf("%d",&e);
		pNew->data = e;
		pNew->next = NULL;							//Ԫ�ؽ��ָ����Ϊ�� 
		
		point->front->data++;						//�ӽڵ����� 1 
		point->rear->next = pNew;					//�������ɵ����Ԫ����ǰһ����Ԫ�� ������ 
		point->rear = pNew;							//����βָ��ָ��������ӵĽ�� 
		printf("��ӳɹ���Ԫ��ֵΪ��%d\n",point->rear->data);
		puts("�Ƿ������ӣ� 1.��  0.��");
		scanf("%d",&flag);
	}	
}

Status DeQueue(LinkQueue *Q)		//���� 
{
	LinkQueue *point = Q;
	QueuePtr temp = point->front;	//����һ����ʱ ��Ԫ��ָ����� 
	int flag = 1;
	
	while(flag)
	{
		
		if(temp == (point->rear))	//�п� 
		{
			puts("�˶���Ϊ�գ�");
			return ERROR; 
		}else if((temp->next) == (point->rear)) //�ж��Ƿ�ֻ��һ���ӽ����������ȥͷ��㣩 
		{
			printf("����Ԫ��Ϊ��%d\n",point->rear->data);
			free(point->rear);
			point->rear = temp;
			point->front->data = 0; 
			puts("���ӳɹ����˶�����Ϊ�գ�");
			return ERROR; 
		}else					//���� 
		{
			temp = temp->next;	//����ʱָ��ָ���һ���ӽ��Ԫ�� 
			printf("����Ԫ��Ϊ��%d\n",temp->data);
			point->front->next = temp->next;	//��ͷ����ָ����ָ����Ӻ��µĵ�һ���ӽ��Ԫ�� 
			free(temp);			//�ͷŸոճ��ӵĶ�Ԫ���ڴ�ռ� 
			point->front->data--;//�ӽ��Ԫ�ؼ� 1  
			temp = point->front;//��ʱ�������ָ��ͷ��㣬Ϊ��һ�γ�����׼�� 
			puts("���ӳɹ���");			
		}
		puts("�Ƿ�������ӣ� 1.��  0.��");
		scanf("%d",&flag);
	}	
}

//Status ClearQueue(LinkQueue *Q)
//{
//	LinkQueue *point = Q;
//	QueuePtr temp = point->front;
//	
//	if(point->front == point->rear)
//	{
//		puts("���б���Ϊ�գ�");
//		return ERROR;
//	}
//	while((temp->next) !=NULL)
//	{
//		temp = temp->next;
//		if(temp->next )
//		free(point->rear);
//		point->rear = 
//	}
//}

void showMainFun(LinkQueue *Q)
{
	int select,flag = 1;
	while(flag)
	{
		puts("\t\t\t\t	1.���		\t\t\t\t"); 
		puts("\t\t\t\t	2.����		\t\t\t\t");
//		puts("\t\t\t\t	3.���ٶ���		\t\t\t\t");
//		puts("\t\t\t\t	4.��ն���		\t\t\t\t"); 
//		puts("\t\t\t\t	5.��ǰ���г���		\t\t\t\t");
		puts("\t\t\t\t	0.�˳�			\t\t\t\t");
		scanf("%d",&select); 	
		switch(select)
		{
			case 1: EnQueue(Q);break;
			case 2: DeQueue(Q);break;
//			case 3: DestroyQueue(Q);break; 
//			case 4: ClearQueue(Q);break;
//			case 5: QueueLenght(Q);break;			
			case 0: flag = 0;break;
		}
	}
}

int main()
{
	QNode qNode;
	qNode.data = 0;
	qNode.next = NULL;
	LinkQueue link;
	link.front = link.rear = &qNode;
	showMainFun(&link);
	
}
