#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../head/linkedList.h"


int main(){
	LinkedList head=NULL;
	int n;
	ShowMenu();
	GetNumber(&n);
	while(1){
		switch (n){
			case 0:DoInitList(&head);break;
			case 1:DoDestroyList(&head);break;
			case 2:DoInsertList(&head);break;
			case 3:DoDeleteList(head);break;
			case 4:DoTraverseList(head);break;
			case 5:DoSearchList(head);break;
			case 6:DoReverseList(&head);break;
			case 7:DoIsLoopList(head);break;
			case 8:DoReverseEvenList(&head);break;
			case 9:DoFindMidNode(&head);break;		
		}
		putchar(10);
		putchar(10);
		ShowMenu();
		GetNumber(&n);
	}
	return 0;
}





