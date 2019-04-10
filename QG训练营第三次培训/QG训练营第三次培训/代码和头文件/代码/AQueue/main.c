#include <stdio.h>
#include <stdlib.h>
#include "../../Í·ÎÄ¼þ/AQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	AQueue Q;
	Q.length = 0;
	int n;
	ShowMenu();
	GetNumber(&n);
	while(1)
	{
		switch (n)
		{
			case 1 : InitAQueue(&Q);break;
			case 2 : DestoryAQueue(&Q);break;
			case 3 : DoIsFullAQueue(&Q);break;
			case 4 : DoIsEmptyAQueue(&Q);break;
			case 5 : DoGetHeadAQueue(&Q);break; 
			case 6 : DoLengthAQueue(&Q);break;
			case 7 : DoEnAQueue(&Q);break;
			case 8 : DeAQueue(&Q);break;
			case 9 : DoTraverseAQueue(&Q);break;
			case -1: exit(0);
		}
		putchar('\n');
		ShowMenu();
		GetNumber(&n);
		
	}
	
	
	
	
	
	
	return 0;
}
