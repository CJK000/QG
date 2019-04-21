#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	if(s->top == NULL)
	{
		if((s->top = (LinkStackPtr)malloc(sizeof(StackNode))) == NULL)
		{
			printf("�ڴ����ʧ��\n");
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



Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if(s->count == 0)
	{
		return SUCCESS;
	}
	return ERROR;
}



Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(p == NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit (0);
	}
	p->data = data;
	p->next = s->top->next;
	s->top->next = p;
	s->count ++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)   //��ջ
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


