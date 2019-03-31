#include"fun.h"

void Nifix2Postfix(LinkStackPtr head)		//中缀转后缀，后缀表达式用链表存放 
{
	LinkStack stack;
	ElemType elem;
	stack.count = 0;
	stack.top = NULL;
	initLStack(&stack);
	char ch;
	int num;
	ch = getchar();
	while(ch != '\n')						//读一个字符 
	{
		if(ch >= '0' && ch <= '9')			//如果是数字则进入 
		{
			num=0;
			do								//一直读到是字符为止，将数字串转换成数字 
			{
				num = num*10 + ch - '0';
				ch = getchar();
			}while(ch >= '0' && ch <= '9');
			elem.Number = num;
			elem.Type = 1;
			InsertNode(head, elem);			//直接输出数字 
			continue ;						//直接跳出循环 
		}
		else if(ch == '(')					//“（”直接入栈 
		{
			elem.Symbol = ch;
			elem.Type = 0;
			pushLStack(&stack,elem);
		}
		else if(ch == ')')					//栈顶为“）”
		{
			popLStack(&stack,&elem);					//将栈顶运算符弹出 
			while(elem.Type == 0 && elem.Symbol != '(')	//直到遇到左括号 
			{
				InsertNode(head, elem);					//将栈顶运算符输出 
				popLStack(&stack,&elem);
			}
		}
		else if(ch == '*' || ch == '/')
		{
			if(isEmptyLStack(&stack) == SUCCESS)			//栈空则直接入栈 
			{
				elem.Type = 0;
				elem.Symbol = ch;
				pushLStack(&stack,elem);
			}
			else											//栈不为空 
			{
				getTopLStack(&stack,&elem);					//得到栈顶运算符 
				while(elem.Symbol == '*' || elem.Symbol == '/')	//运算符优先级与栈顶运算符相同 
				{
					popLStack(&stack,&elem);				//将栈顶运算符弹出 
					InsertNode(head, elem);					//将栈顶运算符输出 
					getTopLStack(&stack,&elem);				//得到新的栈顶的运算符 
				}
				elem.Type = 0;								//运算符入栈 
				elem.Symbol = ch;
				pushLStack(&stack,elem);
			}
		}
		else if(ch == '+' ||ch == '-')
		{
			if(isEmptyLStack(&stack) == SUCCESS)			//栈空直接入栈 
			{
				elem.Type = 0;
				elem.Symbol = ch;
				pushLStack(&stack,elem);
			}
			else											//栈不为空 
			{
				getTopLStack(&stack,&elem);					//得到栈顶运算符 
				if(elem.Symbol == '(')						//栈顶运算符为“）” 
				{
					elem.Type = 0;
					elem.Symbol = ch;
					pushLStack(&stack,elem);				//运算符入栈 
				}
				else
				{
					while(elem.Symbol != '(')				//优先级小于等于栈顶运算符 
					{
						popLStack(&stack,&elem);			//弹出栈顶元素 
						InsertNode(head, elem);				//输出栈顶元素 
						if(isEmptyLStack(&stack) == SUCCESS) //如果栈中没有元素则跳出循环 
						{
							break;
						}
						getTopLStack(&stack,&elem);			//得到栈顶元素 
					}
					elem.Type = 0;							//运算符入栈 
					elem.Symbol = ch;
					pushLStack(&stack,elem);
				}
			}
		}
		else												//读到其他字符，直接886 
		{
			printf("输入出错\n");
			exit (0);
		}
		ch = getchar();
	}
	while(isEmptyLStack(&stack) == ERROR)					//将栈中剩余的字符依次全部弹出 
	{
		popLStack(&stack,&elem);
		InsertNode(head, elem);
	}
	return ;
}

void Compute(LinkStackPtr head)				//计算后缀表达式 
{
	LinkStackPtr p = head;
	LinkStack stack;
	ElemType elem,elem1,elem2;				//elem1存放左操作数，elem2存放右操作数 
	elem.Type = 1;
	stack.count = 0;
	stack.top = NULL;
	initLStack(&stack);
	while(isEmptyLinkList(p) == ERROR)		//循环直到存放后缀表达式的链表为空 
	{
		elem = GetNode(p);
		if(elem.Type == 1)					//读到的是数字 
		{
			pushLStack(&stack,elem);		//入栈 
		}
		else								//读到的是运算符 
		{
			if(popLStack(&stack,&elem2) == ERROR || elem2.Type ==0)	//从栈中读一个数字作为右操作数 
			{
				printf("输入有误\n");
				exit (0); 
			}
			if(popLStack(&stack,&elem1) == ERROR || elem1.Type ==0) //从栈中读一个数字作为左操作数  
			{
				printf("输入有误\n");
				exit (0); 
			}
			switch (elem.Symbol)									//计算 
			{
				case '+' : elem.Number = elem1.Number + elem2.Number;break;
				case '-' : elem.Number = elem1.Number - elem2.Number;break;
				case '*' : elem.Number = elem1.Number * elem2.Number;break;
				case '/' : elem.Number = elem1.Number / elem2.Number;break;
			}
			pushLStack(&stack,elem);								//计算结果入栈 
		}
	}
	printf("%d\n",elem.Number);										//输出栈中最后一次运算的结果 
}

