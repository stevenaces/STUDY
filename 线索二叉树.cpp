#include<stdio.h>
#include<malloc.h>

//#define Link 	0	//��ʾָ�����Һ��ӵ�ָ�� 
//#define Thread 	1	//��ʾָ��ǰ�����ߺ�̵����� 

typedef char TElement;
typedef int Status;

typedef enum 
{ 
	Link,Thread
}PointerTag;

typedef struct BiThrNode
{
	TElement data;
	struct BiThrNode *lchild,*rchild;	
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;

void CreateBiTree(BiThrTree *T);
void PreOrderTraverse(BiThrTree T);
void InOrderTraverse(BiThrTree T);
void PostOrderTraverse(BiThrTree T);
void InThreading(BiThrTree p);

BiThrTree pre; 

void PreOrderTraverse(BiThrTree T)		//ǰ����� 
{
	if(T==NULL)
		return;
	printf("%c ",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiThrTree T)		//������� 
{
	if(T==NULL)
		return;	
	InOrderTraverse(T->lchild);
	printf("%c ",T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiThrTree T)	//������� 
{
	if(T==NULL)
		return;	
	PostOrderTraverse(T->lchild);	
	PostOrderTraverse(T->rchild);
	printf("%c ",T->data);
}

void CreateBiThrTree(BiThrTree *T)
{
	TElement e;
	char ch;		//���ڽ�������һ���ַ���Ļس��ַ� 
	puts("����������˽ڵ��Ԫ��ֵ��");
	scanf("%c",&e);
	ch = getchar();//���ջس��ַ� 
	if(e == '#')
	{
		*T = NULL;
	}else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode)); //�ѿ��ٵĿռ�ĵ�ַ ���� ָ��˽ڵ�� ָ�� 
		(*T)->data = e;
		CreateBiThrTree(&(*T)->lchild);	//�� �¿��ٵĽ�� �����ӵĵ�ַ��  ������㺯������ 
		CreateBiThrTree(&(*T)->rchild);	//�� �¿��ٵĽ�� ���ֺ��ӵĵ�ַ��  ������㺯������ 
	}
}

void InThreading(BiThrTree p) 
{
	if(p)
	{
		InThreading(p->lchild);
		if(!p->lchild) 
		{
			p->LTag = Thread; 
			p->lchild = pre; 
		}
		if(!pre->rchild) 
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}

int main()
{
		
	BiThrTree testT;			//������ָ����ڵ��ָ�� 
//	InitBiTree(&testT);
	CreateBiThrTree(&testT);	//�� ָ����ڵ�ָ��ĵ�ַ ���������������������ĺ��� 
	puts("ǰ�������"); 
	PreOrderTraverse(testT);
	puts("\n���������");
	InThreading(testT);
	puts("\n�������ɹ���"); 
	InOrderTraverse(testT);
	puts("\n���������");
	PostOrderTraverse(testT);
} 
