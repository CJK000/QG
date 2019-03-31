#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack {
	ElemType *elem;
	int top;
	int size;
} SqStack;


//˳��ջ(���������)
Status initStack(SqStack *s,int sizes);//��ʼ��ջ
void DoinitStack(SqStack *s);
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
void DoisEmptyStack(SqStack *s);
Status getTopStack(SqStack *s,ElemType *e); //�õ�ջ��Ԫ��
void DogetTopStack(SqStack *s);
Status clearStack(SqStack *s);//���ջ
void DoclearStack(SqStack *s);
Status destroyStack(SqStack *s);//����ջ
void DodestroyStack(SqStack *s);
Status stackLength(SqStack *s,int *length);//���ջ����
void DostackLength(SqStack *s);
Status pushStack(SqStack *s,ElemType data);//��ջ
void DopushStack(SqStack *s);
Status popStack(SqStack *s,ElemType *data);//��ջ
void DopopStack(SqStack *s);



void showmenu(void);
int getnumber(void);
void showmeun(void);

#endif // STACK_H_INCLUDED










