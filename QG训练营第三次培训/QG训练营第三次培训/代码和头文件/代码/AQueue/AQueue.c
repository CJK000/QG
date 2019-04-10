#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "../../ͷ�ļ�/AQueue.h"
#include <string.h>
#define INTLEN sizeof(int)




/*
	˼·,�ṹ�е�������ָ�룬Ϊ�俪��һ���ڴ�ռ䣬���ڴ���������������ɣ�
																		1��һ��int�͵ĳ��ȣ�������¼�����ݵĳ����Ƕ��� 
																		2��һ��int�͵ĳ��ȣ�������¼�����ݵ�������ʲô :
																			1��int��  2��float�� 
																		3��������ݵ���ʵֵ 
*/

//���Գ������������ȫ����int��ʵ�� 

void InitAQueue(AQueue *Q)	//��ʼ������ 
{
		Q->front = 0;
		Q->rear = 0;
		Q->length = 0;
		printf("���г�ʼ���ɹ�\n");
		return ;
}



void DestoryAQueue(AQueue *Q)	//���ٶ��� 
{
	int i;
	if(Q->length == 0)
	{
		printf("����Ϊ��\n");
		return ;
	}
	for(i = Q->front; i != Q->rear; i = (i+1) % MAXQUEUE)
	{
		free(Q->data[i]);
		Q->length --;
	}
	printf("���гɹ�����\n");
	return ;
}



Status IsFullAQueue(const AQueue *Q)	//�������Ƿ�����
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
		printf("��������\n");
		return ;
	}
	printf("����δ��\n");
	return ;
}






Status IsEmptyAQueue(const AQueue *Q)	//�������Ƿ�Ϊ��
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
		printf("����Ϊ��\n");
		return ;
	}
	printf("���в�Ϊ��\n");
	return ; 
}

Status GetHeadAQueue(AQueue *Q, void *e)	// �鿴��ͷԪ��
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
		printf("�ӿգ���Ԫ�ؿɲ鿴\n");
	}
	memcpy(&type,Q->data[Q->front]+INTLEN,INTLEN);		//��͵͵��һ�۴����ʲô���͵����ݣ���ΪҪ�ȷ�����ڴ� 
	switch (type)
	{
		case INT :
			{
				int n;
				e = malloc(3*INTLEN);
				if(GetHeadAQueue(Q,e) == FALSE)
				{
					printf("����û��Ԫ��\n");
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
					printf("����û��Ԫ��\n");
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


int LengthAQueue(AQueue *Q)		// ȷ�����г���
{
	return Q->length;
}

void DoLengthAQueue(AQueue *Q)
{
	int n;
	n=LengthAQueue(Q);
	printf("���г���Ϊ��%d\n",n);
	return ;
}



Status EnAQueue(AQueue *Q, void *data)		//��� 
{
	int len;
	if(Q->length == MAXQUEUE)
	{
		return FALSE;
	}
	memcpy(&len,data,INTLEN);
	if((Q->data[Q->rear] = malloc(len)) == NULL)
	{
		printf("�ڴ����ʧ��\n");
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
	printf("��ѡ��Ҫ����������ͣ�1��int�ͣ�2��float�ͣ�");
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
				printf("������Ҫ������ݣ�");
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
				float n;
				n=2*INTLEN + sizeof(float);
				data = malloc(n);
				memcpy(data,&n,INTLEN);
				memcpy(data+INTLEN,&type,INTLEN);
				printf("������Ҫ������ݣ�");
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
						printf("����������������룺");
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
		printf("��ӳɹ�\n");
		return ;
	}
	printf("���ʧ��\n");
	return ;
}




Status DeAQueue(AQueue *Q)			//���� 
{
	if(Q->length == 0)
	{
		printf("�ӿ�\n");
		return ;
	}
	printf("���ӵ�Ԫ���ǣ�");
	DoGetHeadAQueue(Q);					//��Ϊ������ӵĺ���ֻ��һ����������֪��Ҫ�����ݸ���ǾͿ�һ��Ȼ��Ͱ���ɾ�����ˣ�
	free(Q->data[Q->front]);
	Q->front = (Q->front +1) % MAXQUEUE;
	Q->length --;
}





void ClearAQueue(AQueue *Q)				//��ն��� 
{
	int i;
	if(Q->length == 0)
	{
		printf("����Ϊ��\n");
		return ;
	}
	for(i = Q->front; i != Q->rear; i = (i+1) % MAXQUEUE)
	{
		free(Q->data[i]);
		Q->length --;
	}
	printf("���гɹ����\n");
	return ;
}



Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))	//������������
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
		printf("�ӿգ��޲���\n");
		return ;
	}
	if(TraverseAQueue(Q,APrint) == TRUE)
	{
		printf("��������\n");
		return ;
	}
} 

void APrint(void *q)		//��ʾһ������ 
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
	printf("1����ʼ������\n");
	printf("2�����ٶ���\n");
	printf("3���������Ƿ�����\n");
	printf("4���������Ƿ�Ϊ��\n");
	printf("5���鿴��ͷԪ��\n");
	printf("6��ȷ�����г���\n"); 
	printf("7��Ԫ�����\n");
	printf("8��Ԫ�س���\n");
	printf("9��������������\n");
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
	printf("�����һ����������");
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
		printf("�����������������\n");
		GetNumber(n);
		return ;
	}
	
}









