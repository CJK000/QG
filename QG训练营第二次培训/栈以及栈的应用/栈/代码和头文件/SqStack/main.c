#include"../head/SqStack.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
	SqStack s;
	s.elem=NULL;
	int n;
	showmenu();
	n=getnumber();
	while (1) {
		switch (n){
			case 1 : DoinitStack(&s);break;
			case 2 : DoisEmptyStack(&s);break;
			case 3 : DogetTopStack(&s);break;
			case 4 : DoclearStack(&s);break;
			case 5 : DodestroyStack(&s);break;
			case 6 : DostackLength(&s);break;
			case 7 : DopushStack(&s);break;
			case 8 : DopopStack(&s);break;
		}
		putchar('\n');
		showmenu();
		n=getnumber();
	}
	
	
	return 0;
}
