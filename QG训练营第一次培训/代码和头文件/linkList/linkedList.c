#include "../head/linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	LinkedList p;
	p=*L;
	if(p==NULL){
		*L=(LinkedList)malloc(sizeof(LNode));
		(*L)->next=NULL;
		return SUCCESS;
	}
	while((*L)->next!=NULL){
		p=(*L)->next;
		(*L)=p->next;
		free(p);
	}
	return SUCCESS;
}

void DoInitList(LinkedList *head){
	if(InitList(head)==SUCCESS){
		printf("Successfully initialize an empty linked list\n");
	}
}



/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p;
	p=*L;
	while(p!=NULL){
		*L=p->next;
		free(p);
		p=*L;
	}
}

void DoDestroyList(LinkedList *L){
	DestroyList(L);
	printf("Finish destroy linked list\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	q->next=p->next;
	p->next=q;
	return SUCCESS;
}

void DoInsertList(LinkedList *head){
	LinkedList p;
	LNode *last;
	p=*head;
	if(p==NULL){
		printf("There is a null linked list.Please initialize one.\n");
		return ;
	}
	while(p->next){
		p=p->next;
	}
	last=(LNode*)malloc(sizeof(LNode));
	printf("Please enter the data of insert:");
	scanf("%d",&last->data);
	getchar();
	InsertList(p,last);
	printf("Successfully insert.\n");
}


/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e){
	p->next->data=*e;
	return SUCCESS;
}

void DoDeleteList(LNode *head){
	LNode *p;
	ElemType data1,data2;
	p=head;
	if(p==NULL){
		printf("There is a null linked list.Please initialize one.\n");
		return ;
	}
	if(p->next==NULL){
		printf("There is no data in linked list.\n");
		return ;
	}
	p=p->next;
	printf("Please enter the new data:");
	scanf("%d",&data2);
	printf("Please enter the node's data before the node deleted:");
	scanf("%d",&data1);
	while(p){
		if(p->data==data1){
			break;
		}
		p=p->next;
	}
	if(p==NULL){
		printf("Can't find the node.\n");
		return ;
	}
	if(p->next==NULL){
		printf("This is a incorrect location.\n");
		return ;
	}
	if(DeleteList(p,&data2)==SUCCESS){
		printf("Successfully delete.\n");
		return ;
	}
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	if(L==NULL){
		printf("There is a null linked list.Please initialize one.\n");
		return ;
	}
	if(L->next==NULL){
		printf("There is no data in linked list.\n");
		return ;
	}
	L=L->next;
	while(L!=NULL){
		(*visit)(L->data);
		L=L->next;
	}
	printf("NULL\n");
}

void DoTraverseList(LinkedList L){
	void (*p)(ElemType);
	p=_visit;
	if(L==NULL){
		printf("There is a null linked list.Please initialize one.\n");
		return ;
	}
	if(L->next==NULL){
		printf("There is no data in linked list.\n");
		return ;
	}
	TraverseList(L,p);
}

void _visit(ElemType e){
	printf("%d->",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e 
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if(L==NULL){
		printf("There is a null linked list.Please initialize one.\n");
		return ;
	}
	if(L->next==NULL){
		printf("There is no data in linked list.\n");
		return ;
	}
	L=L->next;
	while(L){
		if(L->data==e){
			printf("The data is in the list.\n ");
			return SUCCESS;
		}
		L=L->next;
	}
	printf("The data is not in the list.\n ");
	return ERROR;
}

void DoSearchList(LinkedList head){
	if(head==NULL){
		printf("This is a null linked list.Please initialize one.\n");
		return ;
	}
	if(head->next==NULL){
		printf("There is no data in linked list.\n");
		return ;
	}
	ElemType e;
	printf("Please enter a data to search:\n");
	scanf("%d",&e);
	SearchList(head,e);
}


/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LinkedList p1,p2,p3;
	if((*L)==NULL){
		printf("This is a null linked list.Please initialize one.\n");
		return ERROR;
	}
	if((*L)->next==NULL){
		printf("There is no data in linked list.\n");
		return SUCCESS;
	}
	p1=(*L)->next;
	p3=NULL;
	while(p1!=NULL){
		p2=p1;
		p1=p1->next;
		p2->next=p3;
		p3=p2;
	}
	(*L)->next=p2;
	printf("Reverse List successfully.\n");
	return SUCCESS;
}

void DoReverseList(LinkedList *head){
	ReverseList(head);
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList p;
	if(L==NULL){
		printf("This is a null linked list.Please initialize one.\n");
		return ERROR;
	}
	L=L->next;
	p=L;
	while(L!=NULL){
		L=L->next;
		if(L==NULL){
			return ERROR;
		}
		L=L->next;
		p=p->next;
		if(p==L){
			return SUCCESS;
		}
	}
	return ERROR;
}

void DoIsLoopList(LinkedList head){
	int bool;
	bool=IsLoopList(head);
	if(bool==1){
		printf("the linked list is looped.\n");
	}
	else {
		printf("the linked list is not looped.\n");
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish 
 */
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p1,p2,p3;	
	p1=(*L);
	if(p1==NULL){
		printf("This is a null linked list.Please initialize one.\n");
		return ;
	}
	if(p1->next==NULL||p1->next->next==NULL){
		printf("There is not enough data in linked list.\n");
		return p1;
	}
	p3=p1;
	p1=p1->next;
	p2=p1;
	p1=p1->next;
	(*L)->next=NULL;
	while(p1!=NULL){
		p3->next=p1;
		p2->next=p1->next;
		p1->next=p2;
		p3=p1=p2;
		if(p1->next==NULL){
			printf("Successfully reverse the nodes which value is an even number in the linked list.\n");
			return *L;
		}
		p1=p2=p1->next;
		if(p1->next==NULL){
			printf("Successfully reverse the nodes which value is an even number in the linked list.\n");
			return *L;
		}
		p1=p1->next;
	}
}

LNode* DoReverseEvenList(LinkedList *head){
	LinkedList newhead;
	if((*head)==NULL||(*head)->next==NULL){
		printf("There is not enough data in linked list.\n");
		return (*head);
	}
	newhead=ReverseEvenList(head);
	return newhead;
}



/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish 
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList p1,p2;
	int i;
	p1=p2=*L;
	while(p1){
		p2=p2->next;
		for(i=0;i<2;i++){
			p1=p1->next;
			if(p1==NULL){
				return p2;
			}
		}
	}
}

LNode* DoFindMidNode(LinkedList *head){
	LinkedList p;
	p=*head;
	if(*head==NULL){
		printf("This is a null linked list.Please initialize one.\n");
		return ;
	}
	if((*head)->next==NULL){
		printf("There is no data in linked list.Fail to insert.\n");
		return (*head);
	}
	p=FindMidNode(head);
	printf("The data of middle node is %d",p->data);
	return p;
	
}





void ShowMenu(void){
	int i=70;
	while(i--){
		putchar('*');
	}
	putchar(10);
	printf("Please enter number to choose function:\n");
	printf("0:initialize an empty linked list.\n");
	printf("1:Destroy linked list.\n");
	printf("2:Insert a node.\n");
	printf("3:delete the first node after the node p and assign its value to e.\n");
	printf("4:Show all the linked list's data.\n");
	printf("5:Search List.\n");
	printf("6:reverse the linked list.\n");
	printf("7:judge whether the linked list is looped.\n");
	printf("8:reverse the nodes which value is an even number in the linked list.\n");
	printf("9:find the middle node in the linked list.\n");
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
		if(strlen(a)==1&&'0'<=a[0]&&a[0]<='9'){
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
