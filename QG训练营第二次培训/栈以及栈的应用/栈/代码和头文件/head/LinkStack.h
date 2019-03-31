#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

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
void DoinitLStack(LinkStack *s);
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
void DoisEmptyLStack(LinkStack *s);
Status getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
void DogetTopLStack(LinkStack *s);
Status clearLStack(LinkStack *s);//���ջ
void DoclearLStack(LinkStack *s);
Status destroyLStack(LinkStack *s);//����ջ
void DodestroyLStack(LinkStack *s);
Status LStackLength(LinkStack *s,int *length);//���ջ����
void DoLStackLength(LinkStack *s);
Status pushLStack(LinkStack *s,ElemType data);//��ջ
void DopushLStack(LinkStack *s);
Status popLStack(LinkStack *s,ElemType *data);//��ջ
void DopopLStack(LinkStack *s);


void showmenu(void);
int getnumber(void);




#endif // STACK_H_INCLUDED
