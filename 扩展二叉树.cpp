#include<stdio.h>
#include<malloc.h>

typedef char TElement;
typedef int Status;

typedef struct BiTNode
{
	TElement data;
	struct BiTNode *lchild,*rchild;	
}BiTNode,*BiTree;

void CreateBiTree(BiTree *T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);

void PreOrderTraverse(BiTree T)		//ǰ����� 
{
	if(T==NULL)
		return;
	printf("%c ",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)		//������� 
{
	if(T==NULL)
		return;	
	InOrderTraverse(T->lchild);
	printf("%c ",T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)	//������� 
{
	if(T==NULL)
		return;	
	PostOrderTraverse(T->lchild);	
	PostOrderTraverse(T->rchild);
	printf("%c ",T->data);
}

void CreateBiTree(BiTree *T)
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
		*T = (BiTree)malloc(sizeof(BiTNode)); //�ѿ��ٵĿռ�ĵ�ַ ���� ָ��˽ڵ�� ָ�� 
		(*T)->data = e;
		CreateBiTree(&(*T)->lchild);	//�� �¿��ٵĽ�� �����ӵĵ�ַ��  ������㺯������ 
		CreateBiTree(&(*T)->rchild);	//�� �¿��ٵĽ�� ���ֺ��ӵĵ�ַ��  ������㺯������ 
	}
}

int main()
{
		
	BiTree testT;			//������ָ����ڵ��ָ�� 
//	InitBiTree(&testT);
	CreateBiTree(&testT);	//�� ָ����ڵ�ָ��ĵ�ַ ���������������������ĺ��� 
	puts("ǰ�������"); 
	PreOrderTraverse(testT);
	puts("\n���������");
	InOrderTraverse(testT);
	puts("\n���������");
	PostOrderTraverse(testT);
} 
