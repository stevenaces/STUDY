#include<stdio.h>
#include<malloc.h>

//#define Link 	0	//表示指向左右孩子的指针 
//#define Thread 	1	//表示指向前驱或者后继的线索 

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

void PreOrderTraverse(BiThrTree T)		//前序遍历 
{
	if(T==NULL)
		return;
	printf("%c ",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiThrTree T)		//中序遍历 
{
	if(T==NULL)
		return;	
	InOrderTraverse(T->lchild);
	printf("%c ",T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiThrTree T)	//后序遍历 
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
	char ch;		//用于接收输入一个字符后的回车字符 
	puts("请输入该树此节点的元素值：");
	scanf("%c",&e);
	ch = getchar();//接收回车字符 
	if(e == '#')
	{
		*T = NULL;
	}else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode)); //把开辟的空间的地址 赋给 指向此节点的 指针 
		(*T)->data = e;
		CreateBiThrTree(&(*T)->lchild);	//把 新开辟的结点 的左孩子的地址给  创建结点函数参数 
		CreateBiThrTree(&(*T)->rchild);	//把 新开辟的结点 的又孩子的地址给  创建结点函数参数 
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
		
	BiThrTree testT;			//二叉树指向根节点的指针 
//	InitBiTree(&testT);
	CreateBiThrTree(&testT);	//把 指向根节点指针的地址 做参数传给建立二叉树的函数 
	puts("前序遍历："); 
	PreOrderTraverse(testT);
	puts("\n中序遍历：");
	InThreading(testT);
	puts("\n线索化成功！"); 
	InOrderTraverse(testT);
	puts("\n后序遍历：");
	PostOrderTraverse(testT);
} 
