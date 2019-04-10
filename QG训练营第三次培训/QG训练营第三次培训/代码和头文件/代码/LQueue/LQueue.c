#include "../../头文件/LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>
#define INTLEN sizeof(int)


void InitLQueue(LQueue *Q)	//初始化队列
{
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
	printf("队列初始化完成\n");
	return ;
}



void DestoryLQueue(LQueue *Q)	//销毁队列
{
	Node *p;
	if(Q->length == 0)
	{
		printf("队空\n");
		return ;
	}
	while(Q->length > 0)
	{
		p = Q->front;
		Q->front = p->next;
		free(p);
		Q->length --;
	}
	printf("队列销毁成功\n");
	return ;
}



Status IsEmptyLQueue(const LQueue *Q)	//检查队列是否为空
{
	return Q->length == 0 ? TRUE : FALSE;
}

void DoIsEmptyLQueue(const LQueue *Q)
{
	if(IsEmptyLQueue(Q) == TRUE)
	{
		printf("队列为空\n");
		return ;
	}
	printf("队列不为空\n");
	return ;
}



Status GetHeadLQueue(LQueue *Q, void *e)	//查看队头元素 
{
	int len;
	if(Q->length == 0)
	{
		printf("队空\n");
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
		printf("队空\n");
		return ;
	}
	memcpy(&type, Q->front->data + INTLEN, INTLEN);	//先偷偷看一下对头元素是什么类型的数据，因为要分配内存给void *e
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
					printf("队头元素为：");
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
					printf("队头元素为：");
					printf("%f\n",n);
				}
				break;
			}
	} 
	free(e);
}


int LengthLQueue(LQueue *Q)		//确定队列的长度 
{
	return Q->length;
}


void DoLengthLQueue(LQueue *Q)
{
	printf("队列的长度为：%d\n",LengthLQueue(Q));
	return ;
}




Status EnLQueue(LQueue *Q, void *data)		//入队操作 
{
	Node *p;
	int len;
	if((p = (Node*)malloc(sizeof(Node))) == NULL)
	{
		printf("内存分配失败\n");
		return FALSE;
	}
	memcpy(&len,data,INTLEN);
	if((p->data = malloc(len)) == NULL)
	{
		printf("内存分配失败\n");
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
	printf("请输入要入队的数据类型：1、int型，2、float型\n");
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
					printf("内存分配失败\n");
					exit(0);
				}
				memcpy(data,&n,n);
				memcpy(data + INTLEN, &type, INTLEN);
				printf("请输入要入队的数据：");
				scanf("%d",&n);
				ch = getchar();
				if(ch != '\n')
				{
					do
					{
						while(ch != '\n')ch = getchar();
						printf("输入出错，请重新输入：");
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
					printf("内存分配失败\n");
					exit(0);
				}
				memcpy(data,&n,n);
				memcpy(data + INTLEN, &type, INTLEN);
				printf("请输入要入队的数据：");
				scanf("%f",&x);
				ch = getchar();
				if(ch != '\n')
				{
					do
					{
						while(ch != '\n')ch = getchar();
						printf("输入出错，请重新输入：");
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
		printf("入队成功\n");
		return ;
	}
	printf("入队失败\n");
	return ;
}



Status DeLQueue(LQueue *Q)	//出队 
{
	Node *p;
	if(Q->length == 0)
	{
		printf("队空，无可出队元素\n");
		return FALSE;
	}
	DoGetHeadLQueue(Q);		//由于出队的函数只有一个参数，不知道要对数据做什么，那就看一眼就删掉吧
	p = Q->front;
	Q->front = Q->front->next;
	free(p);
	Q->length --;
	return TRUE;
}


void ClearLQueue(LQueue *Q)		//清空队列
{
	Node *p;
	if(Q->length == 0)
	{
		printf("队空\n");
		return ;
	} 
	while(Q->length >0)
	{
		p = Q->front;
		Q->front = Q->front->next;
		free(p);
		Q->length --;
	}
	printf("队列清空完成\n");
	return ;
}


Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))	//遍历函数操作
{
	int cnt;
	if(Q->length == 0)
	{
		printf("队空\n");
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
		printf("队空\n");
		return ;
	}
	if(TraverseLQueue(Q, LPrint) == TRUE)
	{
		printf("遍历结束\n");
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
	printf("1：初始化队列\n");
	printf("2：销毁队列\n");
	printf("3：检查队列是否为空\n");
	printf("4：查看队头元素\n");
	printf("5：确定队列长度\n"); 
	printf("6：元素入队\n");
	printf("7：元素出队\n");
	printf("8：清空队列\n");
	printf("9：遍历函数操作\n");
	printf("-1：退出程序\n");
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
	printf("请输入一个数字：");
	scanf("%d",&x);
	ch = getchar();
	if(ch != '\n')
	{
		while(ch != '\n')ch = getchar();
		printf("输入错误，请重新输入\n");
		GetNumber(&x);
	}
	*n = x ;
	system("cls");
	return ;
}





