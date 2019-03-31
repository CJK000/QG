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


//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes);//初始化栈
void DoinitStack(SqStack *s);
Status isEmptyStack(SqStack *s);//判断栈是否为空
void DoisEmptyStack(SqStack *s);
Status getTopStack(SqStack *s,ElemType *e); //得到栈顶元素
void DogetTopStack(SqStack *s);
Status clearStack(SqStack *s);//清空栈
void DoclearStack(SqStack *s);
Status destroyStack(SqStack *s);//销毁栈
void DodestroyStack(SqStack *s);
Status stackLength(SqStack *s,int *length);//检测栈长度
void DostackLength(SqStack *s);
Status pushStack(SqStack *s,ElemType data);//入栈
void DopushStack(SqStack *s);
Status popStack(SqStack *s,ElemType *data);//出栈
void DopopStack(SqStack *s);



void showmenu(void);
int getnumber(void);
void showmeun(void);

#endif // STACK_H_INCLUDED










