#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef struct Elem{
	char Symbol;
	int Number;
	int Type;		//1��ʾ���� ��0��ʾ���� 
} ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s,int *length);//���ջ����
Status pushLStack(LinkStack *s,ElemType data);//��ջ
Status popLStack(LinkStack *s,ElemType *data);//��ջ





#endif // STACK_H_INCLUDED
