#include"fun.h"

void Nifix2Postfix(LinkStackPtr head)		//��׺ת��׺����׺���ʽ�������� 
{
	LinkStack stack;
	ElemType elem;
	stack.count = 0;
	stack.top = NULL;
	initLStack(&stack);
	char ch;
	int num;
	ch = getchar();
	while(ch != '\n')						//��һ���ַ� 
	{
		if(ch >= '0' && ch <= '9')			//�������������� 
		{
			num=0;
			do								//һֱ�������ַ�Ϊֹ�������ִ�ת�������� 
			{
				num = num*10 + ch - '0';
				ch = getchar();
			}while(ch >= '0' && ch <= '9');
			elem.Number = num;
			elem.Type = 1;
			InsertNode(head, elem);			//ֱ��������� 
			continue ;						//ֱ������ѭ�� 
		}
		else if(ch == '(')					//������ֱ����ջ 
		{
			elem.Symbol = ch;
			elem.Type = 0;
			pushLStack(&stack,elem);
		}
		else if(ch == ')')					//ջ��Ϊ������
		{
			popLStack(&stack,&elem);					//��ջ����������� 
			while(elem.Type == 0 && elem.Symbol != '(')	//ֱ������������ 
			{
				InsertNode(head, elem);					//��ջ���������� 
				popLStack(&stack,&elem);
			}
		}
		else if(ch == '*' || ch == '/')
		{
			if(isEmptyLStack(&stack) == SUCCESS)			//ջ����ֱ����ջ 
			{
				elem.Type = 0;
				elem.Symbol = ch;
				pushLStack(&stack,elem);
			}
			else											//ջ��Ϊ�� 
			{
				getTopLStack(&stack,&elem);					//�õ�ջ������� 
				while(elem.Symbol == '*' || elem.Symbol == '/')	//��������ȼ���ջ���������ͬ 
				{
					popLStack(&stack,&elem);				//��ջ����������� 
					InsertNode(head, elem);					//��ջ���������� 
					getTopLStack(&stack,&elem);				//�õ��µ�ջ��������� 
				}
				elem.Type = 0;								//�������ջ 
				elem.Symbol = ch;
				pushLStack(&stack,elem);
			}
		}
		else if(ch == '+' ||ch == '-')
		{
			if(isEmptyLStack(&stack) == SUCCESS)			//ջ��ֱ����ջ 
			{
				elem.Type = 0;
				elem.Symbol = ch;
				pushLStack(&stack,elem);
			}
			else											//ջ��Ϊ�� 
			{
				getTopLStack(&stack,&elem);					//�õ�ջ������� 
				if(elem.Symbol == '(')						//ջ�������Ϊ������ 
				{
					elem.Type = 0;
					elem.Symbol = ch;
					pushLStack(&stack,elem);				//�������ջ 
				}
				else
				{
					while(elem.Symbol != '(')				//���ȼ�С�ڵ���ջ������� 
					{
						popLStack(&stack,&elem);			//����ջ��Ԫ�� 
						InsertNode(head, elem);				//���ջ��Ԫ�� 
						if(isEmptyLStack(&stack) == SUCCESS) //���ջ��û��Ԫ��������ѭ�� 
						{
							break;
						}
						getTopLStack(&stack,&elem);			//�õ�ջ��Ԫ�� 
					}
					elem.Type = 0;							//�������ջ 
					elem.Symbol = ch;
					pushLStack(&stack,elem);
				}
			}
		}
		else												//���������ַ���ֱ��886 
		{
			printf("�������\n");
			exit (0);
		}
		ch = getchar();
	}
	while(isEmptyLStack(&stack) == ERROR)					//��ջ��ʣ����ַ�����ȫ������ 
	{
		popLStack(&stack,&elem);
		InsertNode(head, elem);
	}
	return ;
}

void Compute(LinkStackPtr head)				//�����׺���ʽ 
{
	LinkStackPtr p = head;
	LinkStack stack;
	ElemType elem,elem1,elem2;				//elem1������������elem2����Ҳ����� 
	elem.Type = 1;
	stack.count = 0;
	stack.top = NULL;
	initLStack(&stack);
	while(isEmptyLinkList(p) == ERROR)		//ѭ��ֱ����ź�׺���ʽ������Ϊ�� 
	{
		elem = GetNode(p);
		if(elem.Type == 1)					//������������ 
		{
			pushLStack(&stack,elem);		//��ջ 
		}
		else								//������������� 
		{
			if(popLStack(&stack,&elem2) == ERROR || elem2.Type ==0)	//��ջ�ж�һ��������Ϊ�Ҳ����� 
			{
				printf("��������\n");
				exit (0); 
			}
			if(popLStack(&stack,&elem1) == ERROR || elem1.Type ==0) //��ջ�ж�һ��������Ϊ�������  
			{
				printf("��������\n");
				exit (0); 
			}
			switch (elem.Symbol)									//���� 
			{
				case '+' : elem.Number = elem1.Number + elem2.Number;break;
				case '-' : elem.Number = elem1.Number - elem2.Number;break;
				case '*' : elem.Number = elem1.Number * elem2.Number;break;
				case '/' : elem.Number = elem1.Number / elem2.Number;break;
			}
			pushLStack(&stack,elem);								//��������ջ 
		}
	}
	printf("%d\n",elem.Number);										//���ջ�����һ������Ľ�� 
}

