#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>
#define INTLEN sizeof(int)


void InitLQueue(LQueue *Q)	//��ʼ������
{
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
	return ;
}




Status IsEmptyLQueue(const LQueue *Q)	//�������Ƿ�Ϊ��
{
	return Q->length == 0 ? SUCCESS : ERROR;
}


Status EnLQueue(LQueue *Q, LQType data)		//��Ӳ��� 
{
	Node *p;
	int len;
	if((p = (Node*)malloc(sizeof(Node))) == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return ERROR;
	}
	p->T = data;
	p->next = NULL;
	Q->length ++;
	if(Q->length == 1)
	{
		Q->front = Q->rear =p;
		return SUCCESS;
	}
	Q->rear->next = p;
	Q->rear = p;
	return SUCCESS;
}



Status DeLQueue(LQueue *Q, LQType *e)	//���� 
{
	Node *p;
	if(Q->length == 0)
	{
		return ERROR;
	}
	p = Q->front;
	*e = p->T;
	Q->front = Q->front->next;
	free(p);
	Q->length --;
	return SUCCESS;
}


