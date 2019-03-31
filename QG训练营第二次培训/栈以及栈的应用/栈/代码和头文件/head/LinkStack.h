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



//链栈
Status initLStack(LinkStack *s);//初始化栈
void DoinitLStack(LinkStack *s);
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
void DoisEmptyLStack(LinkStack *s);
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
void DogetTopLStack(LinkStack *s);
Status clearLStack(LinkStack *s);//清空栈
void DoclearLStack(LinkStack *s);
Status destroyLStack(LinkStack *s);//销毁栈
void DodestroyLStack(LinkStack *s);
Status LStackLength(LinkStack *s,int *length);//检测栈长度
void DoLStackLength(LinkStack *s);
Status pushLStack(LinkStack *s,ElemType data);//入栈
void DopushLStack(LinkStack *s);
Status popLStack(LinkStack *s,ElemType *data);//出栈
void DopopLStack(LinkStack *s);


void showmenu(void);
int getnumber(void);




#endif // STACK_H_INCLUDED
