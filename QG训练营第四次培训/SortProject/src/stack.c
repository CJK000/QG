
#include "../inc/stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
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
			printf("初始化失败\n");
			exit (0);
		}
	}
	else 
	{
		s->top = -1;
		return ERROR ;
	}
}


Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if(s->top == -1)
	{
		return SUCCESS;
	}
	return ERROR ;
}



Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if(s->top == -1)
	{
		printf("栈空\n");
		return ERROR;
	}
	*e = s->elem[s->top];
	return SUCCESS;
}


Status destroyStack(SqStack *s)  //销毁栈
{
	free(s->elem);
	s->elem = NULL;
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	*length = s->top + 1; 
	return SUCCESS;
} 


Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if(s->top == s->size - 1)
	{	
		return ERROR;			//栈满，无法入栈
	}
	s->top ++ ;
	s->elem[s->top] = data ;
	return SUCCESS;
}


Status popStack(SqStack *s,ElemType *data)   //出栈
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





















