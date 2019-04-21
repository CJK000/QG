#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include <string.h> 
#include "LQueue.h"
#include"LinkStack.h"


Status InitBiTree(BiTree *T)	//构造空二叉树T
{
	BiTree p = *T;
	if(p != NULL)
	{
		return ERROR;
	}
	p =NULL;
	return SUCCESS;
}

void DoInitBiTree(BiTree *T)
{
	if(InitBiTree(T) == SUCCESS)
	{
		printf("空树构造成功\n");
		return ;
	}
	printf("树已存在\n");
}



Status DestroyBiTree(BiTree *T)		//摧毁二叉树T
{
	BiTree p = *T;
	if(p == NULL)
	{
		return ERROR;
	}
	DestroyBiTree(&p->lchild);
	DestroyBiTree(&p->rchild);
	free(p);
	return SUCCESS;
}

void DoDestroyBiTree(BiTree *T)
{
	if(DestroyBiTree(T) == SUCCESS)
	{
		printf("二叉树已摧毁\n");
		return ;
	}
	printf("这是一颗空树\n");
}



Status CreateBiTree(BiTree *T, char* definition)		//构造二叉树T
{
	BiTree q = *T;
	int leaves, childs, len;
	int i;
	if(definition[0] == '\0')return ERROR;
	if(definition[0] == '#')
	{
		*T = NULL;
		return SUCCESS;
	}
	*T = q = (BiTree)malloc(sizeof(BiTNode));
	q->data = definition[0];
	CreateBiTree(&q->lchild, definition + 1);
	leaves = 0;
	childs = 0;
	len = strlen(definition);
	for(i = 1; i < len; i++)
	{
		if(definition[i] == '#')
		{
			leaves ++;
		}
		else
		{
			childs ++;
		}
		if(childs + 1 == leaves)
		{
			if(CreateBiTree(&q->rchild, definition + leaves + childs + 1) == ERROR)
			{
				return ERROR;
			}
			return SUCCESS;
		}
	}
	return ERROR;
}

void DoCreateBiTree(BiTree *T)
{
	char definition[10001]={0};
	printf("请出入一颗节点数小于10000的树，以字符'#'代表空树(如AB#D##C##)：\n");
	scanf("%s",definition);
	getchar();
	if(CreateBiTree(T, definition) == SUCCESS)
	{
		printf("种树成功\n");
		return ;
	}
	else
	{
		printf("这是一颗非法的树，请重新输入\n");
		return ;
	}
}




void Traverse(BiTree T, Status foo(BiTree T, Status (*visit)(TElemType e)))		//测试遍历树的函数 
{
	if((*foo)(T, visit) == SUCCESS)
	{
		printf("输出结束\n");
		return ; 
	}
	else
	{
		printf("这是一颗空树\n");
		return ;
	}
}


Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))		//先序遍历二叉树T
{
	if(T == NULL)
	{
		return ERROR;
	}
	(*visit)(T->data);
	PreOrderTraverse(T->lchild, visit);
	PreOrderTraverse(T->rchild, visit);
	return SUCCESS;
}

Status visit(TElemType e)
{
	printf("%c",e);
}



Status PrePreOrderTraverse(BiTree T, Status (*visit)(TElemType e))		//先序遍历二叉树T（非递归）
{
	
	LinkStack s;
	s.top = NULL;
	BiTree p = T;
	if(T == NULL)
	{
		return ERROR;
	}
	initLStack(&s);		//初始化栈
	while(p != NULL)
	{
		(*visit)(p->data);
		pushLStack(&s,p);	//入栈
		p = p->lchild; 
	}
	while(isEmptyLStack(&s) == ERROR)
	{
		popLStack(&s,&p);	//出栈
		p = p->rchild;
		while(p != NULL)
		{
			(*visit)(p->data);
			pushLStack(&s,p);//入栈
			p = p->lchild;
		}
	}
	return SUCCESS;
} 


Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//中序遍历二叉树 
{
	if(T == NULL)
	{
		return ERROR;
	}
	InOrderTraverse(T->lchild, visit);	
	(*visit)(T->data);
	InOrderTraverse(T->rchild, visit);
	return SUCCESS;
}



//还没实现 
Status CirInOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//中序遍历非递归版
{
	LinkStack s;
	s.top = NULL;
	BiTree p = T;
	if(T == NULL)
	{
		return ERROR;
	}
	initLStack(&s);		//初始化栈
	while(p != NULL)
	{
		pushLStack(&s,p);	//入栈
		p = p->lchild; 
	}
	while(isEmptyLStack(&s) == ERROR)
	{
		popLStack(&s,&p);	//出栈
		(*visit)(p->data);
		p = p->rchild;
		while(p != NULL)
		{
			pushLStack(&s,p);//入栈
			p = p->lchild;
		}
	}
	return SUCCESS;
} 



Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//后序遍历二叉树 
{
	
	if(T == NULL)
	{
		return ERROR;
	}
	PostOrderTraverse(T->lchild, visit);
	PostOrderTraverse(T->rchild, visit);	
	(*visit)(T->data);
	return SUCCESS;
}



Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//层次遍历 
{
	BiTree t;
	LQueue Q;
	InitLQueue(&Q);
	if(T == NULL)
	{
		return ERROR;
	}
	(*visit)(T->data);
	EnLQueue(&Q, T);
	while(IsEmptyLQueue(&Q) == ERROR)
	{
		DeLQueue(&Q, &t);
		if(t->lchild != NULL)
		{
			(*visit)(t->lchild->data);
			EnLQueue(&Q, t->lchild);
		}
		if(t->rchild != NULL)
		{
			(*visit)(t->rchild->data);
			EnLQueue(&Q, t->rchild);
		}
	}
	return SUCCESS;
}



int Value(BiTree *T)
{
	int n, ln, rn;
	BiTree p = *T;
	if(p->lchild == NULL)	//表达式只有一个数字 
	{
		n = p->data;
		free(p);
		return n;
	}
	if(p->lchild->lchild != NULL)
	{
		Value(&p->lchild);
	}
	if(p->rchild->lchild != NULL)
	{
		Value(&p->rchild);
	}
	ln = (int)p->lchild->data;
	rn = (int)p->rchild->data;
	switch (p->data)
	{
		case '+' :
			{
				n = ln + rn;
				break;
			}
		case '-' :
			{
				n = ln - rn;
				break;
			}
		case '*' :
			{
				n = ln * rn;
				break;
			}
		case '/' :
			{
				n = ln / rn;
				break;
			}
	}
	p->data = (char)n;
	free(p->lchild);
	free(p->rchild);
	p->lchild = NULL;
	p->rchild = NULL;
	return n;
}



Status Enter(char *s)		//读取前缀表达式并转换成先序遍历可以使用的结构 
{
	char ch;
	int i;
	printf("请输入一个前缀表达式：\n");
	ch = getchar();
	if(ch == ' ' || ch == '\n')			//先跳过一些没有意义的空白输入 
	{
		while(ch == ' ' || ch == '\n')
		{
			ch = getchar();
		}
	}
	i = 0;
	while(ch != '\n')
	{
		switch (ch)
		{
			case '+' :
			case '-' :
			case '*' :
			case '/' : s[i++] = ch; break;
			case '1' :
			case '2' :
			case '3' :
			case '4' :
			case '5' :
			case '6' :
			case '7' :
			case '8' :
			case '9' :
			case '0' : s[i++] = ch - '0'; s[i++] = '#'; s[i++] = '#'; break;
			default : return ERROR;
		}
		ch = getchar();
	}
	return SUCCESS;
}




void Calcultator(void)
{
	BiTree T;
	int n;
	char s[1000]={};
	while(Enter(s) == ERROR)
	{
		printf("输入错误，请重新输入：\n");
	}
	if(CreateBiTree(&T, s) == ERROR)	//构造前缀表达式二叉树
	{
		printf("输入错误，已退出\n");
		return ;
	}
	n = Value(&T);
	printf("%d\n",n);
	return ;
}









void ShowMenu(void)
{
	int i;
	i = 70;
	while(i--)putchar('*');
	putchar('\n');
	printf("1、构造空二叉树\n");
	printf("2、摧毁二叉树\n");
	printf("3、以先序遍历构造二叉树\n");
	printf("4、先序遍历二叉树\n");
	printf("5、先序遍历二叉树（非递归）\n");
	printf("6、中序遍历二叉树\n");
	printf("7、中序遍历二叉树（非递归）\n");
	printf("8、后序遍历二叉树\n");
	printf("9、（尚未实现）后序遍历二叉树（非递归）\n");
	printf("10、层序遍历二叉树\n");
	printf("11、对构造出的前缀表达式二叉树求值\n");
	printf("-1、退出程序\n");
	
	i = 70;
	while(i--)putchar('*');
	putchar('\n');
}








void GetNumber(int *n)
{
	int a;
	char ch;
	printf("请出入一个操作数：");
	scanf("%d",&a);
	ch = getchar();
	while(ch != '\n')
	{
		while(ch != '\n')
		{
			ch = getchar();
		}
		printf("输入出错，请重新输入：");
		scanf("%d",&a);
		ch = getchar();
	}
	*n = a;
}



















