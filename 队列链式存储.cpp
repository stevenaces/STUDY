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

Status EnQueue(LinkQueue *Q)		//入队 
{
	LinkQueue *point = Q;
	QueuePtr pNew;					//队元素结点 
	QElemType e;
	int flag = 1;
	
	while(flag)
	{
		pNew = (QueuePtr)malloc(sizeof(QNode));		//开辟队元素结点空间 
		puts("请输入入队元素值：");
		scanf("%d",&e);
		pNew->data = e;
		pNew->next = NULL;							//元素结点指针域为空 
		
		point->front->data++;						//队节点数加 1 
		point->rear->next = pNew;					//将新生成的入队元素与前一个队元素 链起来 
		point->rear = pNew;							//将队尾指针指向最新入队的结点 
		printf("入队成功，元素值为：%d\n",point->rear->data);
		puts("是否继续入队？ 1.是  0.否");
		scanf("%d",&flag);
	}	
}

Status DeQueue(LinkQueue *Q)		//出队 
{
	LinkQueue *point = Q;
	QueuePtr temp = point->front;	//定义一个临时 队元素指针变量 
	int flag = 1;
	
	while(flag)
	{
		
		if(temp == (point->rear))	//判空 
		{
			puts("此队列为空！");
			return ERROR; 
		}else if((temp->next) == (point->rear)) //判断是否只有一个队结点的情况（除去头结点） 
		{
			printf("出队元素为：%d\n",point->rear->data);
			free(point->rear);
			point->rear = temp;
			point->front->data = 0; 
			puts("出队成功！此队列已为空！");
			return ERROR; 
		}else					//出队 
		{
			temp = temp->next;	//将临时指针指向第一个队结点元素 
			printf("出队元素为：%d\n",temp->data);
			point->front->next = temp->next;	//将头结点的指针域指向出队后新的第一个队结点元素 
			free(temp);			//释放刚刚出队的队元素内存空间 
			point->front->data--;//队结点元素减 1  
			temp = point->front;//临时结点重新指向头结点，为下一次出队做准备 
			puts("出队成功！");			
		}
		puts("是否继续出队？ 1.是  0.否");
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
//		puts("队列本来为空！");
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
		puts("\t\t\t\t	1.入队		\t\t\t\t"); 
		puts("\t\t\t\t	2.出队		\t\t\t\t");
//		puts("\t\t\t\t	3.销毁队列		\t\t\t\t");
//		puts("\t\t\t\t	4.清空队列		\t\t\t\t"); 
//		puts("\t\t\t\t	5.当前队列长度		\t\t\t\t");
		puts("\t\t\t\t	0.退出			\t\t\t\t");
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
