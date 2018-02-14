#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 5
#define OK 	  1
#define ERROR 0
#define TRUE  1
#define FALSE 0

typedef int Status;
typedef int QElemType;

typedef struct Queue			//队列顺序存储结构体 
{
	QElemType data[MAXSIZE];	//循环队列数组 
	int front;					//队头游标 
	int rear;					//队尾游标 
}SqQueue,*pointQ;

Status EnQueue(SqQueue *Q);
Status DeQueue(SqQueue *Q);
void showMainFun(SqQueue *Q);
Status DestroyQueue(SqQueue *Q);
Status ClearQueue(SqQueue *Q);
Status QueueLenght(SqQueue *Q);

Status EnQueue(SqQueue *Q)		//入队 
{
	
	int flag = 1;
	QElemType e;
	pointQ point = Q;
	while(flag)
	{
		if((point->rear+1)%MAXSIZE == point->front)		//判断队列是否已满 
		{
			puts("此队列已满！");
			return ERROR;
		}else
		{			
			puts("请输入入队元素值：");
			scanf("%d",&e);
			point->data[point->rear] = e;
			printf("本次入队的值为：%d\n",point->data[point->rear]); 
			point->rear = (point->rear+1)%MAXSIZE;		//队尾游标指向循环队列后一位置 
			puts("入队成功！");
		}
		puts("是否继续入队？ 1.是  0.否");
		scanf("%d",&flag);
	}
		
}

Status DeQueue(SqQueue *Q)		//出队 
{
	int flag = 1;
	pointQ point = Q;
	while(flag)
	{
		if((point->front) == (point->rear))		//判空 
		{
			puts("队列为空！");
			return ERROR;
		}else if((point->front+1)%MAXSIZE == point->rear)	//判断是否为队尾元素 
		{
			
			printf("此次出队为第%d元素值为：%d\n",point->front,point->data[point->front]);			
			puts("队列已为空！");
			return ERROR;
		}else									//正常的出队 
		{
			printf("此次出队为第%d元素值为：%d\n",point->front,point->data[point->front]);
			point->front = (point->front+1)%MAXSIZE;		//队头游标向后移一位  
		}
		puts("是否继续出队？ 1.是  0.否");
		scanf("%d",&flag);
	}
		
}

Status DestroyQueue(SqQueue *Q)			//销毁队列（有问题） 
{
	pointQ point = Q;
	free(point);
	puts("此队列销毁成功！"); 
	return OK;
}

Status ClearQueue(SqQueue *Q)			//清空队列 
{
	pointQ point = Q;
	while((point->front) != (point->rear))		//直到 队头游标  等于  队尾游标 
	{
		point->front = (point->front+1)%MAXSIZE;// 队头游标向后移一位 
	}
	puts("队列已清空！"); 
}

Status QueueLenght(SqQueue *Q)			//获取队列长度 
{
	int len;
	pointQ point = Q;
	len = (point->rear-point->front+MAXSIZE)%MAXSIZE;
	printf("此时队列的长度为：%d\n",len);
	return OK;
}

void showMainFun(SqQueue *Q)
{
	int select,flag = 1;
	while(flag)
	{
		puts("\t\t\t\t	1.入队		\t\t\t\t"); 
		puts("\t\t\t\t	2.出队		\t\t\t\t");
		puts("\t\t\t\t	3.销毁队列		\t\t\t\t");
		puts("\t\t\t\t	4.清空队列		\t\t\t\t"); 
		puts("\t\t\t\t	5.当前队列长度		\t\t\t\t");
		puts("\t\t\t\t	0.退出			\t\t\t\t");
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
	SqQueue queue;		//定义一队列 queue 
	queue.front = 0;
	queue.rear  = 0;
	pointQ pQ = &queue;
	showMainFun(pQ);
	
} 
