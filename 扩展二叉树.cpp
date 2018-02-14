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

void PreOrderTraverse(BiTree T)		//前序遍历 
{
	if(T==NULL)
		return;
	printf("%c ",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)		//中序遍历 
{
	if(T==NULL)
		return;	
	InOrderTraverse(T->lchild);
	printf("%c ",T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)	//后序遍历 
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
	char ch;		//用于接收输入一个字符后的回车字符 
	puts("请输入该树此节点的元素值：");
	scanf("%c",&e);
	ch = getchar();//接收回车字符 
	if(e == '#')
	{
		*T = NULL;
	}else
	{
		*T = (BiTree)malloc(sizeof(BiTNode)); //把开辟的空间的地址 赋给 指向此节点的 指针 
		(*T)->data = e;
		CreateBiTree(&(*T)->lchild);	//把 新开辟的结点 的左孩子的地址给  创建结点函数参数 
		CreateBiTree(&(*T)->rchild);	//把 新开辟的结点 的又孩子的地址给  创建结点函数参数 
	}
}

int main()
{
		
	BiTree testT;			//二叉树指向根节点的指针 
//	InitBiTree(&testT);
	CreateBiTree(&testT);	//把 指向根节点指针的地址 做参数传给建立二叉树的函数 
	puts("前序遍历："); 
	PreOrderTraverse(testT);
	puts("\n中序遍历：");
	InOrderTraverse(testT);
	puts("\n后序遍历：");
	PostOrderTraverse(testT);
} 
