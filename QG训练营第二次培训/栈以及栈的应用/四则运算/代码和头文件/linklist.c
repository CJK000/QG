#include"linklist.h"



//链表

void InsertNode (LinkStackPtr head, ElemType newnode)
{
	LinkStackPtr p = head, q;
	while(p->next != NULL)
	{
		p = p->next;
	}
	q = (LinkStackPtr)malloc(sizeof(StackNode));
	q->data = newnode;
	q->next = NULL ;
	p->next = q;
}


ElemType GetNode (LinkStackPtr head)
{
	LinkStackPtr p;
	ElemType elem;
	p = head->next;
	elem = p->data;
	head->next = p->next;
	free(p);
	return elem;
} 

Status isEmptyLinkList(LinkStackPtr head)		//判断链表是否为空
{
	if(head->next == NULL)
	{
		return SUCCESS;
	}
	else 
	{
		return ERROR;
	}
}




