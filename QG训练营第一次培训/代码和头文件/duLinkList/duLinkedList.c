#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	DuLinkedList p,p1;
	p=*L;
	if(p==NULL){
		p=(DuLinkedList)malloc(sizeof(DuLNode));
		p->next=NULL;
		p->prior=NULL;
		(*L)=p;
		return SUCCESS;
	}
	if((*L)->next!=NULL){
		p=(*L)->next;
	}
	while(p!=NULL){
		p1=p;
		p=p->next;
		free(p1);
	}
	return SUCCESS;
}
void DoInitList_DuL(DuLinkedList *head){
	if(InitList_DuL(head)==SUCCESS){
		printf("Successfully initialize an empty linked list\n");
	}
	
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p;
	p=*L;
	while(p!=NULL){
		*L=p->next;
		free(p);
		p=*L;
	}
}

void DoDestroyList_DuL(DuLinkedList *L){
	DestroyList_DuL(L);
	printf("Finish destroy the linked list\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p->prior==NULL){
		q->next=p->next;
		if(p->next!=NULL){
			p->next->prior=q;
		}
		p->next=q;
		q->prior=p;
		return SUCCESS;
	}
	q->next=p;
	q->prior=p->prior;
	p->prior->next=q;
	p->prior=q;
	return SUCCESS;
}

void DoInsertBeforeList_DuL(DuLNode *p){
	DuLNode *q;
	if(p==NULL){
		printf("This is a null list.Please initialize a list.\n");
		return ;
	}
	q=(DuLNode *)malloc(sizeof(DuLNode));
	printf("Please enter the data of insert:");
	scanf("%d",&q->data);
	if(p->next==NULL){
		if(InsertBeforeList_DuL(p,q)==SUCCESS){
			printf("Successfully insert.\n");
			return ;
		}	
	}
	else {
		p=p->next;
		if(InsertBeforeList_DuL(p,q)==SUCCESS){
			printf("Successfully insert.\n");
			return ;
		}
	}
}
/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	q->next=p->next;
	q->prior=p;
	if(p->next!=NULL){
		p->next->prior=q;
	}
	p->next=q;
	return SUCCESS;
}


void DoInsertAfterList_DuL(DuLNode *p){
	DuLNode *q;
	if(p==NULL){
		printf("This is a null list.Please initialize a list.\n");
		return ;
	}
	q=(DuLNode *)malloc(sizeof(DuLNode));
	printf("Please enter the data of insert:");
	scanf("%d",&q->data);
	while(p->next){
		p=p->next;
	}
	if(InsertAfterList_DuL(p,q)==SUCCESS){
		printf("Successfully insert.\n");
		return ;
	}
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p->next==NULL){
		return ERROR;
	}
	p->next->data=*e;
	return SUCCESS;
}


void DoDeleteList_DuL(DuLNode *p){
	ElemType e,del;
	if(p==NULL){
		printf("This is a null list.Please initialize a list.\n");
		return ;
	}
	if(p->next==NULL){
		printf("There is no data in the list.\n");
		return ;
	}
	printf("Please enter the new data:");
	scanf("%d",&e);
	printf("Please enter the node's data before the node being deleted:");
	scanf("%d",&del);
	while(p->next){
		if(p->data==del){
			break;
		}
		p=p->next;
	}
	if(p->next!=NULL){
		if(DeleteList_DuL(p,&e)==SUCCESS){
			printf("Successfully delete.\n");
			return ;
		}
	}
	printf("Can't find the data.Failed to delete.\n");
	return ;
	
}


 
/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	if(L==NULL){
		printf("This is a null list.Please initialize a list.\n");
		return ;
	}
	if(L->next==NULL){
		printf("There is no data in the list.\n");
		return ;
	}
	L=L->next;
	while(L){
		(*visit)(L->data);
		L=L->next;
	}
	printf("NULL");
	return ;
	
}

void DoTraverseList_DuL(DuLinkedList L){
	void visit(ElemType e);
	void (*p)(ElemType e);
	p=visit;
	if(L==NULL){
		printf("This is a null list.Please initialize a list.\n");
		return ;
	}
	if(L->next==NULL){
		printf("There is no data in the list.\n");
		return ;
	}
	TraverseList_DuL(L,p);
	return ;
	
}

void visit(ElemType e){
	printf("%d->",e);
	return ;
}


void ShowMenu(void){
	int i=70;
	while(i--){
		putchar('*');
	}
	putchar(10);
	printf("Please enter number to choose function:\n");
	printf("0:initialize an empty linked list with only the head node.\n");
	printf("1:Destroy the linked list.\n");
	printf("2:Insert a node in the front.\n");
	printf("3:Insert a node in the end.\n");
	printf("4:Delete the first node after the node p and assign its value to e.\n");
	printf("5:Show all data of list.\n");
	printf("-1:exit the pragram.\n");
	i=70;
	while(i--){
		putchar('*');
	}
	putchar(10);
}


int GetNumber(int *n){
	char a[4];
	while(1){
		scanf("%3s",a);
		if(strcmp(a,"-1")==0){
			printf("pragram has exited.\n");
			exit (0);
		}
		if(strlen(a)==1&&'0'<=a[0]&&a[0]<='5'){
			*n=a[0]-'0';
			putchar(10);
			return *n;
		}
		else{
			while(getchar()!='\n');
			printf("enter error,please enter again:\n");
			return GetNumber(n);
		}
	}
}
