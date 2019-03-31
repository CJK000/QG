#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../head/LinkStack.h"

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	if(s->top == NULL)
	{
		if((s->top = (LinkStackPtr)malloc(sizeof(StackNode))) == NULL)
		{
			printf("内存分配失败\n");
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
		printf("栈初始化成功\n");
		return ;
	}
	else
	{
		printf("栈已存在，无需初始化\n");
		return ;
	}
}



Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
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
		printf("栈不存在，请先初始化\n");
		return ;
	}
	if(isEmptyLStack(s) == SUCCESS)
	{
		printf("栈为空\n");
		return ;
	}
	else
	{
		printf("栈不为空\n");
		return ;
	}
}



Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
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
		printf("栈不存在，请先初始化\n");
		return ;
	}
	if(getTopLStack(s,&e) == SUCCESS)
	{
		printf("栈顶元素为：%d",e);
		return ;
	}
	else
	{
		printf("栈空，没有元素\n");
		return ;
	}
}



Status clearLStack(LinkStack *s)   //清空栈
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
		printf("栈不存在，请先初始化\n");
		return ;
	}
	if(clearLStack(s) == SUCCESS)
	{
		printf("栈已清空\n");
		return ;
	}
	else
	{
		printf("这是一个空栈\n");
	}
}


Status destroyLStack(LinkStack *s)   //销毁栈
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
		printf("栈不存在，请先初始化\n");
		return ;
	}
	if(destroyLStack(s) == SUCCESS)
	{
		printf("栈已销毁\n");
		return ;
	}
}


Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	*length = s->count;
	return SUCCESS;
}

void DoLStackLength(LinkStack *s)
{
	int length;
	if(s->top == NULL)
	{
		printf("栈不存在，请先初始化\n");
		return ;
	}
	if(LStackLength(s,&length) == SUCCESS)
	{
		printf("栈的长度为：%d",length);
	}
}

Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(p == NULL)
	{
		printf("内存分配失败\n");
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
		printf("栈不存在，请先初始化\n");
		return ;
	}
	printf("请输入要入栈的元素：");
	scanf("%d",&data);
	if(pushLStack(s,data) == SUCCESS)
	{
		printf("元素入栈成功\n");
		return ;
	}
}


Status popLStack(LinkStack *s,ElemType *data)   //出栈
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
		printf("栈不存在，请先初始化\n");
		return ;
	}
	if(popLStack(s,&data) == SUCCESS)
	{
		printf("出栈元素为：%d",data);
		return ;
	}
	else 
	{
		printf("栈空，没有元素可以出栈\n");
		return ;
	}
}



void showmenu(void){
	int i=70;
	while(i--)putchar('*');
	putchar('\n');
	printf("1：初始化栈\n");
	printf("2：判断栈是否为空\n");
	printf("3：得到栈顶元素\n");
	printf("4：清空栈\n");
	printf("5：销毁栈\n");
	printf("6：检测栈长度\n");
	printf("7：入栈\n");
	printf("8：出栈\n");
	printf("-1：退出程序\n");
	i=70;
	while(i--)putchar('*');
	putchar('\n');
	printf("请输入数字进入相关功能：");
}




int getnumber(void){							//读取一个操作数 
	int n;
	char a[5];
	while(1){
		scanf("%4s",a);
		if(strcmp(a,"-1")==0){
			printf("程序已关闭\n");
			exit (0);
		}
		if(strcmp(a,"861")==0){
			return 861;
		}
		if(strlen(a)==1&&'0'<=a[0]&&a[0]<='9'){	//根据所需数字的大小进行修改 
			n=a[0]-'0';
			system("cls");//清屏
			return n;
		}
		else{
			while(getchar()!='\n');				//吃掉缓冲区剩下的所有字符
			printf("输入错误，请重新输入\n");
			return getnumber();
		}
	}
	
}

