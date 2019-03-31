#include"../head/SqStack.h"
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

void DoinitStack(SqStack *s)
{
	int sizes;
	printf("������ջ�Ĵ�С��");
	scanf("%d",&sizes);
	if(initStack(s, sizes) == SUCCESS)
	{
		printf("��ʼ��ջ�ɹ�\n\n");
		return ;
	}
	else 
	{
		printf("ջ�Ѵ��ڣ������\n\n");
		return ;
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

void DoisEmptyStack(SqStack *s)
{
	if(s->elem==NULL)
	{
		printf("ջδ��ʼ��\n");	
		return ;
	} 
	if(isEmptyStack(s)==SUCCESS)
	{
		printf("ջΪ��\n");
		return ;
	}
	else
	{
		printf("ջ��Ϊ��\n");
	}
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

void DogetTopStack(SqStack *s)
{
	ElemType e;
	if(s->elem==NULL)
	{
		printf("ջδ��ʼ��\n");	
		return ;
	} 
	if(getTopStack(s,&e)==SUCCESS)
	{
		printf("ջ��Ԫ��Ϊ:%d\n",e);
		return ;
	}
}

Status clearStack(SqStack *s)   //���ջ
{
	s->top  = -1;
	return SUCCESS;
}

void DoclearStack(SqStack *s)
{
	if(s->elem==NULL)
	{
		printf("ջδ��ʼ��\n");	
		return ;
	} 
	if(clearStack(s) == SUCCESS)
	{
		printf("���ջ�ɹ�\n");
	}
}

Status destroyStack(SqStack *s)  //����ջ
{
	free(s->elem);
	s->elem = NULL;
	return SUCCESS;
}

void DodestroyStack(SqStack *s)
{
	if(s->elem == NULL)
	{
		printf("ջδ��ʼ��\n");	
		return ;
	} 
	if(destroyStack(s) == SUCCESS )
	{
		printf("����ջ�ɹ�\n");
		return ;
	}
}

Status stackLength(SqStack *s,int *length)   //���ջ����
{
	*length = s->top + 1; 
	return SUCCESS;
} 

void DostackLength(SqStack *s){
	int len;
	if(s->elem == NULL)
	{
		printf("ջδ��ʼ��\n");	
		return ;
	} 
	if(stackLength(s, &len) == SUCCESS)
	{
		printf("ջ�ĳ���Ϊ%d",len);
		return ;
	}
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

void DopushStack(SqStack *s)
{
	int data ;
	if(s->elem == NULL)
	{
		printf("ջδ��ʼ��\n");	
		return ;
	} 
	printf("������Ҫ��ջ��Ԫ�أ�");
	scanf("%d",&data);
	if(pushStack(s, data) == SUCCESS)
	{
		printf("��ջ�ɹ�\n");
		return ;
	}
	else 
	{
		printf("ջ�����޷���ջ\n");	
		return ;
	}
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

void DopopStack(SqStack *s)
{
	int data ;
	if(s->elem == NULL)
	{
		printf("ջδ��ʼ��\n");	
		return ;
	}
	if(popStack(s,&data) == SUCCESS)
	{
		printf("��ջ�ɹ�����ջԪ��Ϊ%d",data);
		return ;
	}
	else
	{
		printf("ջ�գ���ջʧ��\n");
		return ;
	}
}

void showmenu(void){
	int i=70;
	while(i--)putchar('*');
	putchar('\n');
	
	printf("1����ʼ��ջ\n");
	printf("2���ж�ջ�Ƿ�Ϊ��\n");
	printf("3���õ�ջ��Ԫ��\n");
	printf("4�����ջ\n");
	printf("5������ջ\n");
	printf("6�����ջ����\n");
	printf("7����ջ\n");
	printf("8����ջ\n");
	printf("-1���˳�����\n");
	i=70;
	while(i--)putchar('*');
	putchar('\n');
	printf("���������ֽ�����ع��ܣ�");
}





int getnumber(void){							//��ȡһ�������� 
	int n;
	char a[5];
	while(1){
		scanf("%4s",a);
		if(strcmp(a,"-1")==0){
			printf("�����ѹر�\n");
			exit (0);
		}
		if(strlen(a)==1&&'0'<=a[0]&&a[0]<='9'){	//�����������ֵĴ�С�����޸� 
			n=a[0]-'0';
			system("cls");//����
			return n;
		}
		else{
			while(getchar()!='\n');				//�Ե�������ʣ�µ������ַ�
			printf("�����������������\n");
			return getnumber();
		}
	}
	
}

