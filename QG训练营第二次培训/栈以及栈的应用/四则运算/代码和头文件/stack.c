#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

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


Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
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



Status clearLStack(LinkStack *s)   //���ջ
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


Status destroyLStack(LinkStack *s)   //����ջ
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

Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
	*length = s->count;
	return SUCCESS;
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











