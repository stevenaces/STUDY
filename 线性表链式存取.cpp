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
	puts("����������ֵ��");
	scanf("%d",&pNew->data);
	pNew->next = NULL;	
	
	point->next = pNew;		//�ѽ�����ӵ��Ѿ������Ľ����� 
	point = pNew;			//���²������ָ�� ָ�����´����Ľ�� 	
	(pH->data)++;			//�������һ	
	
	puts("�Ƿ������ӣ� 1.�� 0.��");
	scanf("%d",&flag);
	
	while(flag)
	{		
		pNew2 = (Node*)malloc(sizeof(Node));	//�������		
		puts("����������ֵ��");
		scanf("%d",&pNew2->data);
		pNew2->next = NULL;
		             
		point->next = pNew2; 	//�ѽ�����ӵ��Ѿ������Ľ����� 
		point = pNew2;			//���²������ָ�� ָ�����´����Ľ�� 
		(pH->data)++;			//�����ܽ������һ	
		
		puts("�Ƿ������ӣ� 1.�� 0.��");
		scanf("%d",&flag);
	}
	puts("�����ɹ���");
	printf("���ӵĽ����Ϊ��%d��\n",pH->data);
	
	
	
}

int showLinkList(Node *pHead)
{
	int i = 1;
	
	Node *point;
	point = pHead;
	
	if((point->next == NULL) && (point->data == 0))
	{
		puts("������Ϊ��!");
		return ERROR;
	}else
	{
		while(point != NULL)
		{
			if(i == 1)
			{
				printf("������ĳ���Ϊ��%d���������£�\n",point->data);
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
		point = pHead;		//ÿ�β���ǰ����ָ��ָ�����ͷ��� 
		
		pNew = (Node*)malloc(sizeof(Node));
		puts("����������λ�ã��ڴ�λ��ǰ����룬���ô˷����������������룺1��");
		scanf("%d",&pos);
		
		if((point->data == 0 ) && (pos == 1))	//������Ϊ�ձ����� ���в������ 
		{
			puts("��������ֵ��");
			scanf("%d",&pNew->data);
			pNew->next = NULL;
			
			point->next = pNew;			
			point = pNew;		
			(pHead->data)++;
			puts("����ɹ���");
//			printf("��ʱ����ĳ���Ϊ��%d\n",pHead->data);
		}else if((pos > pHead->data) || (pos<0))	//�����λ�ò��Ϸ� 
		{
			puts("����λ�ò��Ϸ���");
		}else										//��������ĳ��Ԫ�ص�ǰ����� 
		{
			for(int i=1;i < pos; i++)
			{
				point = point->next;
			}
			puts("��������ֵ��");
			scanf("%d",&pNew->data);
			pNew->next = NULL;	
					
			pNew->next = point->next;			
			point->next = pNew;		
			(pHead->data)++;
			puts("����ɹ���");
//			printf("��ʱ����ĳ���Ϊ��%d\n",pHead->data);
		}
		
		puts("�Ƿ�������룿 1.��  0.��");
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
	puts("������ɾ��Ԫ�ص�λ�ã�");
	scanf("%d",&pos);
	
	if(point->data == 0)						//����Ϊ�ձ����� 
	{
		puts("�˱�Ϊ�գ�");		
		
	}else if((pos == 1)&&(pHead->data == 1))	//ɾ�����Ϊ���������ͷ�����ֻ��һ����� 
	{
		value = point->next->data;
		point->next = NULL;
		
		(pHead->data)--;
		puts("ɾ���ɹ���");
		printf("ɾ���Ľ��ֵΪ��%d\n",value);
		return value; 
	}else										//������ɾ����� 
	{
		for(int i = 1; i < pos;i++)
		{
			point = point->next;
		}
		if((point->next->next) == NULL)			//��������ɾ������У�ɾ��������������һ����� 
		{
			value = point->next->data;
			point->next = NULL;
			
			(pHead->data)--;
			puts("ɾ���ɹ���");
			printf("ɾ���Ľ��ֵΪ��%d\n",value);
			return value;
		}else									//ɾ������������м��� 
		{
			value = point->next->data;
			point->next = point->next->next;
			(pHead->data)--;
			puts("ɾ���ɹ���");
			printf("ɾ���Ľ��ֵΪ��%d\n",value);
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
		puts("�˱�Ϊ�գ�");
	}else
	{
		puts("��������Ҫ��ѯ�Ľ��λ�ã�");
		scanf("%d",&pos);
		if((pos>pHead->data)&&(pos<0))
		{
			puts("��ѯλ�ò��Ϸ���");
		}else
		{
			for(int i=1; i<=pos; i++)
			{
				point = point->next;
			}
			printf("���ѯλ��Ԫ��ֵΪ��%d\n",point->data);
		}
	}
}

void checkElemLinkList(Node *pHead)
{
	Node *point = pHead;
	int value, i=0;
	if(pHead->data == 0)
	{
		puts("�˱�Ϊ�գ�");
	}else
	{
		puts("��������Ҫ��ѯ�Ľ���ֵ��");
		scanf("%d",&value);
		point = point->next;
		while(1)
		{
			i++;
			if(point->data == value)	//�����ѯ�������λ�÷��� 
			{
				printf("��ѯ����ֵλ������� %d ���\n",i);
				break;
			}
			if((point->next == NULL)&&(point->data != value))	//û�в�ѯ����&&�����������ܻ���λ�ã��������е�ַ����ֵ�� 
			{
				puts("û�����ѯֵ��ȵ�Ԫ�ؽ��");
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
		puts("\t\t\t\t	1.��������		\t\t\t\t"); 
		puts("\t\t\t\t	2.������		\t\t\t\t"); 
		puts("\t\t\t\t	3.ɾ��ĳ�����	\t\t\t\t"); 
		puts("\t\t\t\t	4.��ѯ�������	\t\t\t\t"); 
		puts("\t\t\t\t	5.���ݽ��ֵ��ѯ	\t\t\t\t");
		puts("\t\t\t\t	6.��ʾ����		\t\t\t\t");
		puts("\t\t\t\t	0.�˳�			\t\t\t\t");
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
	Node node;		//����Ԫ��� 
	node.data = 0;	//Ԫ��������Ϊ����ĳ��� 
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

