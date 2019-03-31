#include<stdio.h>
#include<stdlib.h>
#include"../head/LinkStack.h"

int main()
{
	int n;
	LinkStack s;
	s.top=NULL;
	s.count=0;
	showmenu();
	n=getnumber();
	while(1)
	{
		switch (n)
		{
			case 1:DoinitLStack(&s);break;
			case 2:DoisEmptyLStack(&s);break;
			case 3:DogetTopLStack(&s);break;
			case 4:DoclearLStack(&s);break;
			case 5:DodestroyLStack(&s);break;
			case 6:DoLStackLength(&s);break;
			case 7:DopushLStack(&s);break;
			case 8:DopopLStack(&s);break;
			case -1: exit (0);break;
		}
		putchar('\n');
		showmenu();
		n=getnumber();
	}
	
	
	
	return 0;
}
