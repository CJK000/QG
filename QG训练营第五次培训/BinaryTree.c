#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include <string.h> 
#include "LQueue.h"
#include"LinkStack.h"


Status InitBiTree(BiTree *T)	//����ն�����T
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
		printf("��������ɹ�\n");
		return ;
	}
	printf("���Ѵ���\n");
}



Status DestroyBiTree(BiTree *T)		//�ݻٶ�����T
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
		printf("�������Ѵݻ�\n");
		return ;
	}
	printf("����һ�ſ���\n");
}



Status CreateBiTree(BiTree *T, char* definition)		//���������T
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
	printf("�����һ�Žڵ���С��10000���������ַ�'#'�������(��AB#D##C##)��\n");
	scanf("%s",definition);
	getchar();
	if(CreateBiTree(T, definition) == SUCCESS)
	{
		printf("�����ɹ�\n");
		return ;
	}
	else
	{
		printf("����һ�ŷǷ�����������������\n");
		return ;
	}
}




void Traverse(BiTree T, Status foo(BiTree T, Status (*visit)(TElemType e)))		//���Ա������ĺ��� 
{
	if((*foo)(T, visit) == SUCCESS)
	{
		printf("�������\n");
		return ; 
	}
	else
	{
		printf("����һ�ſ���\n");
		return ;
	}
}


Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))		//�������������T
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



Status PrePreOrderTraverse(BiTree T, Status (*visit)(TElemType e))		//�������������T���ǵݹ飩
{
	
	LinkStack s;
	s.top = NULL;
	BiTree p = T;
	if(T == NULL)
	{
		return ERROR;
	}
	initLStack(&s);		//��ʼ��ջ
	while(p != NULL)
	{
		(*visit)(p->data);
		pushLStack(&s,p);	//��ջ
		p = p->lchild; 
	}
	while(isEmptyLStack(&s) == ERROR)
	{
		popLStack(&s,&p);	//��ջ
		p = p->rchild;
		while(p != NULL)
		{
			(*visit)(p->data);
			pushLStack(&s,p);//��ջ
			p = p->lchild;
		}
	}
	return SUCCESS;
} 


Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//������������� 
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



//��ûʵ�� 
Status CirInOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//��������ǵݹ��
{
	LinkStack s;
	s.top = NULL;
	BiTree p = T;
	if(T == NULL)
	{
		return ERROR;
	}
	initLStack(&s);		//��ʼ��ջ
	while(p != NULL)
	{
		pushLStack(&s,p);	//��ջ
		p = p->lchild; 
	}
	while(isEmptyLStack(&s) == ERROR)
	{
		popLStack(&s,&p);	//��ջ
		(*visit)(p->data);
		p = p->rchild;
		while(p != NULL)
		{
			pushLStack(&s,p);//��ջ
			p = p->lchild;
		}
	}
	return SUCCESS;
} 



Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//������������� 
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



Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))	//��α��� 
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
	if(p->lchild == NULL)	//���ʽֻ��һ������ 
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



Status Enter(char *s)		//��ȡǰ׺���ʽ��ת���������������ʹ�õĽṹ 
{
	char ch;
	int i;
	printf("������һ��ǰ׺���ʽ��\n");
	ch = getchar();
	if(ch == ' ' || ch == '\n')			//������һЩû������Ŀհ����� 
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
		printf("����������������룺\n");
	}
	if(CreateBiTree(&T, s) == ERROR)	//����ǰ׺���ʽ������
	{
		printf("����������˳�\n");
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
	printf("1������ն�����\n");
	printf("2���ݻٶ�����\n");
	printf("3��������������������\n");
	printf("4���������������\n");
	printf("5������������������ǵݹ飩\n");
	printf("6���������������\n");
	printf("7������������������ǵݹ飩\n");
	printf("8���������������\n");
	printf("9������δʵ�֣�����������������ǵݹ飩\n");
	printf("10���������������\n");
	printf("11���Թ������ǰ׺���ʽ��������ֵ\n");
	printf("-1���˳�����\n");
	
	i = 70;
	while(i--)putchar('*');
	putchar('\n');
}








void GetNumber(int *n)
{
	int a;
	char ch;
	printf("�����һ����������");
	scanf("%d",&a);
	ch = getchar();
	while(ch != '\n')
	{
		while(ch != '\n')
		{
			ch = getchar();
		}
		printf("����������������룺");
		scanf("%d",&a);
		ch = getchar();
	}
	*n = a;
}



















