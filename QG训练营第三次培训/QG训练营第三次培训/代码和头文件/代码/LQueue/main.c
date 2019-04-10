#include <stdio.h>
#include <stdlib.h>
#include "../../头文件/LQueue.h"

int main()
{
	LQueue Q;
	int n;
	ShowMenu();
	GetNumber(&n);
	while(1)
	{
		switch (n)
		{
			case 1 : InitLQueue(&Q);break;
			case 2 : DestoryLQueue(&Q);break;
			case 3 : DoIsEmptyLQueue(&Q);break;
			case 4 : DoGetHeadLQueue(&Q);break;
			case 5 : DoLengthLQueue(&Q);break;
			case 6 : DoEnLQueue(&Q);break;
			case 7 : DeLQueue(&Q);break;
			case 8 : ClearLQueue(&Q);break;
			case 9 : DoTraverseLQueue(&Q);break;
			
			case -1: exit(0);
			default : printf("无此操作，请重新输入\n");
		}
		ShowMenu();
		GetNumber(&n);
	}
	return 0;
}
