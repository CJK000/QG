#include "../../ͷ�ļ�/LQueue.h"
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
	printf("���г�ʼ�����\n");
	return ;
}



void DestoryLQueue(LQueue *Q)	//���ٶ���
{
	Node *p;
	if(Q->length == 0)
	{
		printf("�ӿ�\n");
		return ;
	}
	while(Q->length > 0)
	{
		p = Q->front;
		Q->front = p->next;
		free(p);
		Q->length --;
	}
	printf("�������ٳɹ�\n");
	return ;
}



Status IsEmptyLQueue(const LQueue *Q)	//�������Ƿ�Ϊ��
{
	return Q->length == 0 ? TRUE : FALSE;
}

void DoIsEmptyLQueue(const LQueue *Q)
{
	if(IsEmptyLQueue(Q) == TRUE)
	{
		printf("����Ϊ��\n");
		return ;
	}
	printf("���в�Ϊ��\n");
	return ;
}



Status GetHeadLQueue(LQueue *Q, void *e)	//�鿴��ͷԪ�� 
{
	int len;
	if(Q->length == 0)
	{
		printf("�ӿ�\n");
		return FALSE;
	}
	memcpy(&len,Q->front->data,INTLEN);
	memcpy(e,Q->front->data,len);
	return TRUE;
}

void DoGetHeadLQueue(LQueue *Q)
{
	int len,type;
	void *e;
	if(Q->length == 0)
	{
		printf("�ӿ�\n");
		return ;
	}
	memcpy(&type, Q->front->data + INTLEN, INTLEN);	//��͵͵��һ�¶�ͷԪ����ʲô���͵����ݣ���ΪҪ�����ڴ��void *e
	switch (type)
	{
		case INT :
			{
				int n;
				len = 3 * INTLEN;
				e = malloc(len);
				if(GetHeadLQueue(Q, e) == TRUE)
				{
					memcpy(&n, e + 2 * INTLEN , INTLEN);
					printf("��ͷԪ��Ϊ��");
					printf("%d\n",n);
				}
				break;
			}
		case FLOAT :
			{
				int n;
				len = 2 * INTLEN + sizeof(float);
				e = malloc(len);
				if(GetHeadLQueue(Q, e) == TRUE)
				{
					memcpy(&n, e + 2 * INTLEN , sizeof(float));
					printf("��ͷԪ��Ϊ��");
					printf("%f\n",n);
				}
				break;
			}
	} 
	free(e);
}


int LengthLQueue(LQueue *Q)		//ȷ�����еĳ��� 
{
	return Q->length;
}


void DoLengthLQueue(LQueue *Q)
{
	printf("���еĳ���Ϊ��%d\n",LengthLQueue(Q));
	return ;
}




Status EnLQueue(LQueue *Q, void *data)		//��Ӳ��� 
{
	Node *p;
	int len;
	if((p = (Node*)malloc(sizeof(Node))) == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return FALSE;
	}
	memcpy(&len,data,INTLEN);
	if((p->data = malloc(len)) == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return FALSE;
	}
	memcpy(p->data,data,len);
	p->next = NULL;
	Q->length ++;
	if(Q->length == 1)
	{
		Q->front = Q->rear =p;
		return TRUE;
	}
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

void DoEnLQueue(LQueue *Q)
{
	int type;
	void *data;
	char ch;
	printf("������Ҫ��ӵ��������ͣ�1��int�ͣ�2��float��\n");
	GetNumber(&type);
	if(type != 1 && type != 2)
	{
		do
		{
			GetNumber(&type);
		}while(type != 1 && type != 2);
	}
	switch (type)
	{
		case INT :
			{
				int n;
				n = 3 * INTLEN;
				data = malloc(n);
				if(data == NULL)
				{
					printf("�ڴ����ʧ��\n");
					exit(0);
				}
				memcpy(data,&n,n);
				memcpy(data + INTLEN, &type, INTLEN);
				printf("������Ҫ��ӵ����ݣ�");
				scanf("%d",&n);
				ch = getchar();
				if(ch != '\n')
				{
					do
					{
						while(ch != '\n')ch = getchar();
						printf("����������������룺");
						scanf("%d",&n);
						ch = getchar();
					}while(ch != '\n');
				}
				memcpy(data + 2 * INTLEN,&n,INTLEN);
				break;
			}
		case FLOAT :
			{
				int n;
				float x;
				n = 2 * INTLEN + sizeof(float);
				data = malloc(n);
				if(data == NULL)
				{
					printf("�ڴ����ʧ��\n");
					exit(0);
				}
				memcpy(data,&n,n);
				memcpy(data + INTLEN, &type, INTLEN);
				printf("������Ҫ��ӵ����ݣ�");
				scanf("%f",&x);
				ch = getchar();
				if(ch != '\n')
				{
					do
					{
						while(ch != '\n')ch = getchar();
						printf("����������������룺");
						scanf("%f",&x);
						ch = getchar();
					}while(ch != '\n');
				}
				memcpy(data + 2 * INTLEN,&x,sizeof(float));
				break;
			}	
	}
	if(EnLQueue(Q, data) == TRUE)
	{
		printf("��ӳɹ�\n");
		return ;
	}
	printf("���ʧ��\n");
	return ;
}



Status DeLQueue(LQueue *Q)	//���� 
{
	Node *p;
	if(Q->length == 0)
	{
		printf("�ӿգ��޿ɳ���Ԫ��\n");
		return FALSE;
	}
	DoGetHeadLQueue(Q);		//���ڳ��ӵĺ���ֻ��һ����������֪��Ҫ��������ʲô���ǾͿ�һ�۾�ɾ����
	p = Q->front;
	Q->front = Q->front->next;
	free(p);
	Q->length --;
	return TRUE;
}


void ClearLQueue(LQueue *Q)		//��ն���
{
	Node *p;
	if(Q->length == 0)
	{
		printf("�ӿ�\n");
		return ;
	} 
	while(Q->length >0)
	{
		p = Q->front;
		Q->front = Q->front->next;
		free(p);
		Q->length --;
	}
	printf("����������\n");
	return ;
}


Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))	//������������
{
	int cnt;
	if(Q->length == 0)
	{
		printf("�ӿ�\n");
		return FALSE;
	}
	cnt = Q->length;
	while(cnt --)
	{
		(*foo)(Q->front->data);
	}
	return TRUE;
}

void DoTraverseLQueue(const LQueue *Q)
{
	if(Q->length == 0)
	{
		printf("�ӿ�\n");
		return ;
	}
	if(TraverseLQueue(Q, LPrint) == TRUE)
	{
		printf("��������\n");
		return ;
	}
}



void LPrint(void *q)
{
	int type ;
	memcpy(&type,q+INTLEN,INTLEN);
	switch (type)
	{
		case INT :
			{
				int n;
				memcpy(&n,q+2*INTLEN,INTLEN);
				printf("%d\n",n);
				break;
			}
		case FLOAT :
			{
				float n;
				memcpy(&n,q+2*INTLEN,sizeof(float));
				printf("%f\n",n);
				break;
			}
	}
	return ;
}


void ShowMenu(void)
{
	int i;
	putchar('\n');
	i=70;
	while(i--)
	{
		putchar('*');
	}
	putchar('\n');
	printf("1����ʼ������\n");
	printf("2�����ٶ���\n");
	printf("3���������Ƿ�Ϊ��\n");
	printf("4���鿴��ͷԪ��\n");
	printf("5��ȷ�����г���\n"); 
	printf("6��Ԫ�����\n");
	printf("7��Ԫ�س���\n");
	printf("8����ն���\n");
	printf("9��������������\n");
	printf("-1���˳�����\n");
	i=70;
	while(i--)
	{
		putchar('*');
	}
	putchar('\n');
}



void GetNumber(int *n)
{
	int x;
	char ch;
	printf("������һ�����֣�");
	scanf("%d",&x);
	ch = getchar();
	if(ch != '\n')
	{
		while(ch != '\n')ch = getchar();
		printf("�����������������\n");
		GetNumber(&x);
	}
	*n = x ;
	system("cls");
	return ;
}





