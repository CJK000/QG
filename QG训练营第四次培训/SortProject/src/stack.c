
#include "../inc/stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
	
	if(s->elem == NULL)
	{
		if((s->elem = (ElemType *)malloc(sizeof(ElemType)*sizes))!=NULL)
		{
			s->top = -1;
			s->size=sizes;
			return SUCCESS;
		}
		else 
		{
			printf("��ʼ��ʧ��\n");
			exit (0);
		}
	}
	else 
	{
		s->top = -1;
		return ERROR ;
	}
}


Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if(s->top == -1)
	{
		return SUCCESS;
	}
	return ERROR ;
}



Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if(s->top == -1)
	{
		printf("ջ��\n");
		return ERROR;
	}
	*e = s->elem[s->top];
	return SUCCESS;
}


Status destroyStack(SqStack *s)  //����ջ
{
	free(s->elem);
	s->elem = NULL;
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)   //���ջ����
{
	*length = s->top + 1; 
	return SUCCESS;
} 


Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	if(s->top == s->size - 1)
	{	
		return ERROR;			//ջ�����޷���ջ
	}
	s->top ++ ;
	s->elem[s->top] = data ;
	return SUCCESS;
}


Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	if(s->top == -1)
	{
		return ERROR;
	}
	else 
	{
		*data = s->elem[s->top];
		s->top -- ;
		return SUCCESS;
	}
}





















