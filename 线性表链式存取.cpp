#include<stdio.h>
#include<malloc.h>
#include<time.h>

#define OK 	  1
#define ERROR 0
#define TRUE  1
#define FALSE 0

typedef int ElemType; 
typedef int Status; 

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

void createLinkList(Node *pH);
int showLinkList(Node *pHead);
void insertLinkList(Node *pHead);
int deleteLinkList(Node *pHead);
void showMainFun(Node *pHead);
void getElemLinkList(Node *pHead);
void checkElemLinkList(Node *pHead);

void createLinkList(Node *pH)
{
	int flag = 0, count = 0;
	
	Node *pNew,*pNew2,*point;
	point = pH;

	pNew = (Node*)malloc(sizeof(Node));
	puts("请输入结点数值：");
	scanf("%d",&pNew->data);
	pNew->next = NULL;	
	
	point->next = pNew;		//把结点连接到已经创建的结点后面 
	point = pNew;			//更新操作结点指针 指向最新创建的结点 	
	(pH->data)++;			//结点数加一	
	
	puts("是否继续添加？ 1.是 0.否");
	scanf("%d",&flag);
	
	while(flag)
	{		
		pNew2 = (Node*)malloc(sizeof(Node));	//创建结点		
		puts("请输入结点数值：");
		scanf("%d",&pNew2->data);
		pNew2->next = NULL;
		             
		point->next = pNew2; 	//把结点连接到已经创建的结点后面 
		point = pNew2;			//更新操作结点指针 指向最新创建的结点 
		(pH->data)++;			//链表总结点数加一	
		
		puts("是否继续添加？ 1.是 0.否");
		scanf("%d",&flag);
	}
	puts("创建成功！");
	printf("增加的结点数为：%d个\n",pH->data);
	
	
	
}

int showLinkList(Node *pHead)
{
	int i = 1;
	
	Node *point;
	point = pHead;
	
	if((point->next == NULL) && (point->data == 0))
	{
		puts("此链表为空!");
		return ERROR;
	}else
	{
		while(point != NULL)
		{
			if(i == 1)
			{
				printf("此链表的长度为：%d，数据如下：\n",point->data);
				point = point->next;
				i++;
				continue;
			}
			printf("%d\t",point->data);
			point = point->next;
		}
		printf("\n");	
	}
	return OK;	
}

void insertLinkList(Node *pHead)
{
	Node *point,*pNew;
	int pos, flag=1;
	
	while(flag)
	{
		point = pHead;		//每次插入前操作指针指向的是头结点 
		
		pNew = (Node*)malloc(sizeof(Node));
		puts("请输入插入的位置（在此位置前面插入，若用此方法创建链表请输入：1）");
		scanf("%d",&pos);
		
		if((point->data == 0 ) && (pos == 1))	//此链表为空表的情况 进行插入操作 
		{
			puts("请输入结点值：");
			scanf("%d",&pNew->data);
			pNew->next = NULL;
			
			point->next = pNew;			
			point = pNew;		
			(pHead->data)++;
			puts("插入成功！");
//			printf("此时链表的长度为：%d\n",pHead->data);
		}else if((pos > pHead->data) || (pos<0))	//插入的位置不合法 
		{
			puts("插入位置不合法！");
		}else										//正常的在某个元素的前面插入 
		{
			for(int i=1;i < pos; i++)
			{
				point = point->next;
			}
			puts("请输入结点值：");
			scanf("%d",&pNew->data);
			pNew->next = NULL;	
					
			pNew->next = point->next;			
			point->next = pNew;		
			(pHead->data)++;
			puts("插入成功！");
//			printf("此时链表的长度为：%d\n",pHead->data);
		}
		
		puts("是否继续插入？ 1.是  0.否");
		scanf("%d",&flag); 
		
	}
}

int deleteLinkList(Node *pHead)
{
	Node *point = pHead;
	int pos,value;
//	if(!showLinkList(pHead))
//	{
//		return ERROR;
//	}
	puts("请输入删除元素的位置：");
	scanf("%d",&pos);
	
	if(point->data == 0)						//链表为空表的情况 
	{
		puts("此表为空！");		
		
	}else if((pos == 1)&&(pHead->data == 1))	//删除情况为：此链表除头结点外只有一个结点 
	{
		value = point->next->data;
		point->next = NULL;
		
		(pHead->data)--;
		puts("删除成功！");
		printf("删除的结点值为：%d\n",value);
		return value; 
	}else										//正常的删除情况 
	{
		for(int i = 1; i < pos;i++)
		{
			point = point->next;
		}
		if((point->next->next) == NULL)			//在正常的删除情况中：删除的是链表最后的一个结点 
		{
			value = point->next->data;
			point->next = NULL;
			
			(pHead->data)--;
			puts("删除成功！");
			printf("删除的结点值为：%d\n",value);
			return value;
		}else									//删除的是链表的中间结点 
		{
			value = point->next->data;
			point->next = point->next->next;
			(pHead->data)--;
			puts("删除成功！");
			printf("删除的结点值为：%d\n",value);
			return value;
		}
	}
}

void getElemLinkList(Node *pHead)
{
	Node *point = pHead;
	int pos;
	
	if(pHead->data == 0)
	{
		puts("此表为空！");
	}else
	{
		puts("请输入你要查询的结点位置：");
		scanf("%d",&pos);
		if((pos>pHead->data)&&(pos<0))
		{
			puts("查询位置不合法！");
		}else
		{
			for(int i=1; i<=pos; i++)
			{
				point = point->next;
			}
			printf("你查询位置元素值为：%d\n",point->data);
		}
	}
}

void checkElemLinkList(Node *pHead)
{
	Node *point = pHead;
	int value, i=0;
	if(pHead->data == 0)
	{
		puts("此表为空！");
	}else
	{
		puts("请输入你要查询的结点的值：");
		scanf("%d",&value);
		point = point->next;
		while(1)
		{
			i++;
			if(point->data == value)	//如果查询到则输出位置返回 
			{
				printf("查询到该值位于链表第 %d 结点\n",i);
				break;
			}
			if((point->next == NULL)&&(point->data != value))	//没有查询到，&&两边条件不能互换位置，必须先判地址在判值！ 
			{
				puts("没有与查询值相等的元素结点");
				break;
			}
			point = point->next;
		} 
	}
}

void showMainFun(Node *pHead)
{
	int select,flag = 1;
	Node *point = pHead;
	while(flag)
	{
		puts("\t\t\t\t	1.创建链表		\t\t\t\t"); 
		puts("\t\t\t\t	2.插入结点		\t\t\t\t"); 
		puts("\t\t\t\t	3.删除某个结点	\t\t\t\t"); 
		puts("\t\t\t\t	4.查询单个结点	\t\t\t\t"); 
		puts("\t\t\t\t	5.根据结点值查询	\t\t\t\t");
		puts("\t\t\t\t	6.显示链表		\t\t\t\t");
		puts("\t\t\t\t	0.退出			\t\t\t\t");
		scanf("%d",&select); 	
		switch(select)
		{
			case 1: createLinkList(point);break;
			case 2: insertLinkList(point);break; 			
			case 3: deleteLinkList(point);break; 
			case 4: getElemLinkList(point);break;
			case 5: checkElemLinkList(point);break;
			case 6: showLinkList(point);break;
			case 0: flag = 0;break;
		}		
	}
		
}

int main()
{
	Node node;		//定义元结点 
	node.data = 0;	//元结点此数据为链表的长度 
	Node *pLinkListH;
	pLinkListH = &node;
	pLinkListH->next = NULL;
	
	showMainFun(pLinkListH);	
	return 0;
}

/* 
*	https://www.cnblogs.com/qyaizs/articles/2039101.html
*	https://www.cnblogs.com/wgang171412/p/5046235.html
*	https://www.cnblogs.com/xiang-little/p/5840809.html
*/ 

