#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "stack.h"
#include "fun.h"
#include "linklist.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackNode listhead, *head;
	LinkStack stack;
	stack.count = 0;
	stack.top = NULL;
	initLStack(&stack);
	listhead.next = NULL;
	head = &listhead;
	Nifix2Postfix(head);
	Compute(head);
	
	
	
	return 0;
}
