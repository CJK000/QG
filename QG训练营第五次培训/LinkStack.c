#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

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


