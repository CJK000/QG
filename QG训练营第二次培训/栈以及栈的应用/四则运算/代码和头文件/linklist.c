#include"linklist.h"



//����

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

Status isEmptyLinkList(LinkStackPtr head)		//�ж������Ƿ�Ϊ��
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




