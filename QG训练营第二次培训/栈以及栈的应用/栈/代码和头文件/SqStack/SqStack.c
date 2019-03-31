#include"../head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
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
			printf("初始化失败\n");
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
	printf("请输入栈的大小：");
	scanf("%d",&sizes);
	if(initStack(s, sizes) == SUCCESS)
	{
		printf("初始化栈成功\n\n");
		return ;
	}
	else 
	{
		printf("栈已存在，已清空\n\n");
		return ;
	}
}

Status isEmptyStack(SqStack *s)   //判断栈是否为空
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
		printf("栈未初始化\n");	
		return ;
	} 
	if(isEmptyStack(s)==SUCCESS)
	{
		printf("栈为空\n");
		return ;
	}
	else
	{
		printf("栈不为空\n");
	}
}

Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if(s->top == -1)
	{
		printf("栈空\n");
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
		printf("栈未初始化\n");	
		return ;
	} 
	if(getTopStack(s,&e)==SUCCESS)
	{
		printf("栈顶元素为:%d\n",e);
		return ;
	}
}

Status clearStack(SqStack *s)   //清空栈
{
	s->top  = -1;
	return SUCCESS;
}

void DoclearStack(SqStack *s)
{
	if(s->elem==NULL)
	{
		printf("栈未初始化\n");	
		return ;
	} 
	if(clearStack(s) == SUCCESS)
	{
		printf("清空栈成功\n");
	}
}

Status destroyStack(SqStack *s)  //销毁栈
{
	free(s->elem);
	s->elem = NULL;
	return SUCCESS;
}

void DodestroyStack(SqStack *s)
{
	if(s->elem == NULL)
	{
		printf("栈未初始化\n");	
		return ;
	} 
	if(destroyStack(s) == SUCCESS )
	{
		printf("销毁栈成功\n");
		return ;
	}
}

Status stackLength(SqStack *s,int *length)   //检测栈长度
{
	*length = s->top + 1; 
	return SUCCESS;
} 

void DostackLength(SqStack *s){
	int len;
	if(s->elem == NULL)
	{
		printf("栈未初始化\n");	
		return ;
	} 
	if(stackLength(s, &len) == SUCCESS)
	{
		printf("栈的长度为%d",len);
		return ;
	}
}

Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if(s->top == s->size - 1)
	{	
		return ERROR;			//栈满，无法入栈
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
		printf("栈未初始化\n");	
		return ;
	} 
	printf("请输入要入栈的元素：");
	scanf("%d",&data);
	if(pushStack(s, data) == SUCCESS)
	{
		printf("入栈成功\n");
		return ;
	}
	else 
	{
		printf("栈满，无法入栈\n");	
		return ;
	}
}

Status popStack(SqStack *s,ElemType *data)   //出栈
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
		printf("栈未初始化\n");	
		return ;
	}
	if(popStack(s,&data) == SUCCESS)
	{
		printf("出栈成功，出栈元素为%d",data);
		return ;
	}
	else
	{
		printf("栈空，出栈失败\n");
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

