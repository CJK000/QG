#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	if(s->top == NULL)
	{
		if((s->top = (LinkStackPtr)malloc(sizeof(StackNode))) == NULL)
		{
			printf("内存分配失败\n");
			exit (0);
		}
		s->top->next = NULL;
		s->count = 0;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
} 



Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if(s->count == 0)
	{
		return SUCCESS;
	}
	return ERROR;
}


Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
	if(s->count == 0)
	{
		return ERROR;
	}
	else
	{
		*e = s->top->next->data;
		return SUCCESS;
	}
}



Status clearLStack(LinkStack *s)   //清空栈
{
	LinkStackPtr p,q;
	if(s->count == 0)
	{
		return ERROR;
	}
	else
	{
		q = p = s->top->next;
		while(p != NULL)
		{
			p = p->next;
			free(q);
			q = p;
		}
		s->top->next == NULL;
		s->count = 0;
		return SUCCESS;
	}
}


Status destroyLStack(LinkStack *s)   //销毁栈
{
	LinkStackPtr p,q;
	q= p = s->top->next;
	while(p != NULL)
	{
		p = p->next;
		free(q);
		q = p;	
	}
	free(s->top);
	s->top = NULL;
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	*length = s->count;
	return SUCCESS;
}


Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(p == NULL)
	{
		printf("内存分配失败\n");
		exit (0);
	}
	p->data = data;
	p->next = s->top->next;
	s->top->next = p;
	s->count ++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
	LinkStackPtr p;
	if(s->count != 0)
	{
		p=s->top->next;
		*data = p->data;
		s->top->next=p->next;
		free(p);
		s->count --;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}











