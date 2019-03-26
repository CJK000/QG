#include<stdio.h>
#include<stdlib.h>
#include "../head/duLinkedList.h"


int main(){
	DuLinkedList head=NULL;
	int n;
	ShowMenu();
	GetNumber(&n);
	while(1){
		switch (n){
			case 0:DoInitList_DuL(&head);break;
			case 1:DoDestroyList_DuL(&head);break;
			case 2:DoInsertBeforeList_DuL(head);break;
			case 3:DoInsertAfterList_DuL(head);break;
			case 4:DoDeleteList_DuL(head);break;
			case 5:DoTraverseList_DuL(head);
		}
		putchar(10);
		putchar(10);
		ShowMenu();
		GetNumber(&n);
	
	}
	return 0;
}
