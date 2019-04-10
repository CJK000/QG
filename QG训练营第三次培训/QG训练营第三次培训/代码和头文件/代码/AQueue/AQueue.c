#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "../../头文件/AQueue.h"
#include <string.h>
#define INTLEN sizeof(int)




/*
	思路,结构中的数据域指针，为其开辟一个内存空间，该内存由以下三部分组成；
																		1、一个int型的长度，用来记录该数据的长度是多少 
																		2、一个int型的长度，用来记录该数据的类型是什么 :
																			1：int型  2：float型 
																		3、存放数据的真实值 
*/

//测试程序的数据类型全部以int来实现 

void InitAQueue(AQueue *Q)	//初始化队列 
{
		Q->front = 0;
		Q->rear = 0;
		Q->length = 0;
		printf("队列初始化成功\n");
		return ;
}



void DestoryAQueue(AQueue *Q)	//销毁队列 
{
	int i;
	if(Q->length == 0)
	{
		printf("队列为空\n");
		return ;
	}
	for(i = Q->front; i != Q->rear; i = (i+1) % MAXQUEUE)
	{
		free(Q->data[i]);
		Q->length --;
	}
	printf("队列成功销毁\n");
	return ;
}



Status IsFullAQueue(const AQueue *Q)	//检查队列是否已满
{
	if(Q->length == MAXQUEUE)
	{
		return TRUE;
	}
	return FALSE;
} 

void DoIsFullAQueue(const AQueue *Q)
{
	if(IsFullAQueue(Q) == TRUE)
	{
		printf("队列已满\n");
		return ;
	}
	printf("队列未满\n");
	return ;
}






Status IsEmptyAQueue(const AQueue *Q)	//检查队列是否为空
{
	if(Q->length == 0)
	{
		return TRUE;
	}
	return FALSE;
}

void DoIsEmptyAQueue(const AQueue *Q)
{
	if(IsEmptyAQueue(Q) == TRUE)
	{
		printf("队列为空\n");
		return ;
	}
	printf("队列不为空\n");
	return ; 
}

Status GetHeadAQueue(AQueue *Q, void *e)	// 查看队头元素
{
	int len;
	if(Q->length == 0)
	{
		return FALSE;
	}
	memcpy(&len,Q->data[Q->front],INTLEN);
	memcpy(e,Q->data[Q->front],len);
	return TRUE;
}

void DoGetHeadAQueue(AQueue *Q)
{
	void *e=NULL;
	int type;
	if(Q->length == 0)
	{
		printf("队空，无元素可查看\n");
	}
	memcpy(&type,Q->data[Q->front]+INTLEN,INTLEN);		//先偷偷看一眼存的是什么类型的数据，因为要先分配好内存 
	switch (type)
	{
		case INT :
			{
				int n;
				e = malloc(3*INTLEN);
				if(GetHeadAQueue(Q,e) == FALSE)
				{
					printf("队列没有元素\n");
					return ;
				}
				memcpy(&n,e+2*INTLEN,INTLEN);
				printf("%d\n",n);
				break;
			} 
		case FLOAT :
			{
				float n;
				e = malloc(2*INTLEN + sizeof(float));
				if(GetHeadAQueue(Q,e) == FALSE)
				{
					printf("队列没有元素\n");
					return ;
				}
				memcpy(&n,e+2*INTLEN,sizeof(float));
				printf("%f\n",n);
				break;
			}
	}
	free(e);
	return ;
}


int LengthAQueue(AQueue *Q)		// 确定队列长度
{
	return Q->length;
}

void DoLengthAQueue(AQueue *Q)
{
	int n;
	n=LengthAQueue(Q);
	printf("队列长度为：%d\n",n);
	return ;
}



Status EnAQueue(AQueue *Q, void *data)		//入队 
{
	int len;
	if(Q->length == MAXQUEUE)
	{
		return FALSE;
	}
	memcpy(&len,data,INTLEN);
	if((Q->data[Q->rear] = malloc(len)) == NULL)
	{
		printf("内存分配失败\n");
		exit (0); 
	}
	memcpy(Q->data[Q->rear],data,len);
	Q->rear = (Q->rear +1) % MAXQUEUE;
	Q->length ++;
	return TRUE;
} 

void DoEnAQueue(AQueue *Q)
{
	void *data;
	int type;
	char ch;
	printf("请选择要存的数据类型：1、int型，2、float型：");
	GetNumber(&type); 
	while(type != 1 && type != 2)
	{
		GetNumber(&type);
	}
	switch (type)
	{
		case INT :
			{
				int n;
				n=3*INTLEN;
				data = malloc(n);
				memcpy(data,&n,INTLEN);
				memcpy(data+INTLEN,&type,INTLEN);
				printf("请输入要存的数据：");
				scanf("%d",&n);
				ch = getchar();
				if(ch != '\n')
				{
					do
					{
						if(ch != '\n')
						{
							while(ch != '\n')ch = getchar();
						}
						printf("输入错误，请重新输入：");
						scanf("%d",&n);
						ch = getchar();
					}while(ch != '\n');
				}
				memcpy(data + 2 * INTLEN,&n,INTLEN);
				break;
			}
		case FLOAT :
			{
				float n;
				n=2*INTLEN + sizeof(float);
				data = malloc(n);
				memcpy(data,&n,INTLEN);
				memcpy(data+INTLEN,&type,INTLEN);
				printf("请输入要存的数据：");
				scanf("%f",&n);
				ch = getchar();
				if(ch != '\n')
				{
					do
					{
						if(ch != '\n')
						{
							while(ch != '\n')ch = getchar();
						}
						printf("输入错误，请重新输入：");
						scanf("%f",&n);
						ch = getchar();
					}while(ch != '\n');
				}
				memcpy(data + 2 * INTLEN,&n,sizeof(float));
				break;
			}
	}
	if(EnAQueue(Q,data) == TRUE) 
	{
		printf("入队成功\n");
		return ;
	}
	printf("入队失败\n");
	return ;
}




Status DeAQueue(AQueue *Q)			//出队 
{
	if(Q->length == 0)
	{
		printf("队空\n");
		return ;
	}
	printf("出队的元素是：");
	DoGetHeadAQueue(Q);					//因为这个出队的函数只有一个参数，不知道要把数据干嘛，那就看一下然后就把它删掉好了；
	free(Q->data[Q->front]);
	Q->front = (Q->front +1) % MAXQUEUE;
	Q->length --;
}





void ClearAQueue(AQueue *Q)				//清空队列 
{
	int i;
	if(Q->length == 0)
	{
		printf("队列为空\n");
		return ;
	}
	for(i = Q->front; i != Q->rear; i = (i+1) % MAXQUEUE)
	{
		free(Q->data[i]);
		Q->length --;
	}
	printf("队列成功清空\n");
	return ;
}



Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))	//遍历函数操作
{
	int i,cnt;
	i = Q->front;
	cnt = Q->length;
	while(cnt--)
	{
		(*foo)(Q->data[i]);
		i = (i + 1) % MAXQUEUE;
	}
	return TRUE;
} 

void DoTraverseAQueue(const AQueue *Q)
{
	if(Q->length == 0)
	{
		printf("队空，无操作\n");
		return ;
	}
	if(TraverseAQueue(Q,APrint) == TRUE)
	{
		printf("遍历结束\n");
		return ;
	}
} 

void APrint(void *q)		//显示一个数据 
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
	i=70;
	while(i--)
	{
		putchar('*');
	}
	putchar('\n');
	printf("1：初始化队列\n");
	printf("2：销毁队列\n");
	printf("3：检查队列是否已满\n");
	printf("4：检查队列是否为空\n");
	printf("5：查看队头元素\n");
	printf("6：确定队列长度\n"); 
	printf("7：元素入队\n");
	printf("8：元素出队\n");
	printf("9：遍历函数操作\n");
	i=70;
	while(i--)
	{
		putchar('*');
	}
	putchar('\n');
}



void GetNumber(int *n)
{
	char a[4];
	printf("请出入一个操作数：");
	scanf("%3s",a);
	if(strcmp(a, "-1") == 0)
	{
		getchar();
		*n = -1;
		return ;
	}
	if(strlen(a) == 1 && a[0] >= '1' && a[0] <= '9')
	{
		*n = a[0] - '0';
		getchar();
		system("cls");
		return ;
	}
	else 
	{
		while(getchar() != '\n');
		printf("输入出错，请重新输入\n");
		GetNumber(n);
		return ;
	}
	
}









