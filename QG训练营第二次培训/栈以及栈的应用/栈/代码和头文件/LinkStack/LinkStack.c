#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../head/LinkStack.h"

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	if(s->top == NULL)
	{
		if((s->top = (LinkStackPtr)malloc(sizeof(StackNode))) == NULL)
		{
			printf("�ڴ����ʧ��\n");
			exit (0);
		}
		s->top->next = NULL;
		s->count = 0;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
} 

void DoinitLStack(LinkStack *s)
{
	if(initLStack(s) == SUCCESS)
	{
		printf("ջ��ʼ���ɹ�\n");
		return ;
	}
	else
	{
		printf("ջ�Ѵ��ڣ������ʼ��\n");
		return ;
	}
}



Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if(s->count == 0)
	{
		return SUCCESS;
	}
	return ERROR;
}

void DoisEmptyLStack(LinkStack *s)
{
	if(s->top == NULL)
	{
		printf("ջ�����ڣ����ȳ�ʼ��\n");
		return ;
	}
	if(isEmptyLStack(s) == SUCCESS)
	{
		printf("ջΪ��\n");
		return ;
	}
	else
	{
		printf("ջ��Ϊ��\n");
		return ;
	}
}



Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
	if(s->count == 0)
	{
		return ERROR;
	}
	else
	{
		*e = s->top->next->data;
		return SUCCESS;
	}
}

void DogetTopLStack(LinkStack *s)
{
	ElemType e;
	if(s->top == NULL)
	{
		printf("ջ�����ڣ����ȳ�ʼ��\n");
		return ;
	}
	if(getTopLStack(s,&e) == SUCCESS)
	{
		printf("ջ��Ԫ��Ϊ��%d",e);
		return ;
	}
	else
	{
		printf("ջ�գ�û��Ԫ��\n");
		return ;
	}
}



Status clearLStack(LinkStack *s)   //���ջ
{
	LinkStackPtr p,q;
	if(s->count == 0)
	{
		return ERROR;
	}
	else
	{
		q = p = s->top->next;
		while(p != NULL)
		{
			p = p->next;
			free(q);
			q = p;
		}
		s->top->next == NULL;
		s->count = 0;
		return SUCCESS;
	}
}

void DoclearLStack(LinkStack *s)
{
	if(s->top == NULL)
	{
		printf("ջ�����ڣ����ȳ�ʼ��\n");
		return ;
	}
	if(clearLStack(s) == SUCCESS)
	{
		printf("ջ�����\n");
		return ;
	}
	else
	{
		printf("����һ����ջ\n");
	}
}


Status destroyLStack(LinkStack *s)   //����ջ
{
	LinkStackPtr p,q;
	q= p = s->top->next;
	while(p != NULL)
	{
		p = p->next;
		free(q);
		q = p;	
	}
	free(s->top);
	s->top = NULL;
	return SUCCESS;
}

void DodestroyLStack(LinkStack *s)
{
	if(s->top == NULL)
	{
		printf("ջ�����ڣ����ȳ�ʼ��\n");
		return ;
	}
	if(destroyLStack(s) == SUCCESS)
	{
		printf("ջ������\n");
		return ;
	}
}


Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
	*length = s->count;
	return SUCCESS;
}

void DoLStackLength(LinkStack *s)
{
	int length;
	if(s->top == NULL)
	{
		printf("ջ�����ڣ����ȳ�ʼ��\n");
		return ;
	}
	if(LStackLength(s,&length) == SUCCESS)
	{
		printf("ջ�ĳ���Ϊ��%d",length);
	}
}

Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(p == NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit (0);
	}
	p->data = data;
	p->next = s->top->next;
	s->top->next = p;
	s->count ++;
	return SUCCESS;
}

void DopushLStack(LinkStack *s)
{
	ElemType data;
	if(s->top == NULL)
	{
		printf("ջ�����ڣ����ȳ�ʼ��\n");
		return ;
	}
	printf("������Ҫ��ջ��Ԫ�أ�");
	scanf("%d",&data);
	if(pushLStack(s,data) == SUCCESS)
	{
		printf("Ԫ����ջ�ɹ�\n");
		return ;
	}
}


Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
	LinkStackPtr p;
	if(s->count != 0)
	{
		p=s->top->next;
		*data = p->data;
		s->top->next=p->next;
		free(p);
		s->count --;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

void DopopLStack(LinkStack *s)
{
	ElemType data;
	if(s->top == NULL)
	{
		printf("ջ�����ڣ����ȳ�ʼ��\n");
		return ;
	}
	if(popLStack(s,&data) == SUCCESS)
	{
		printf("��ջԪ��Ϊ��%d",data);
		return ;
	}
	else 
	{
		printf("ջ�գ�û��Ԫ�ؿ��Գ�ջ\n");
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
		if(strcmp(a,"861")==0){
			return 861;
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

