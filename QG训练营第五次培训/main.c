#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	BiTree T = NULL;
	do
	{
		ShowMenu();
		GetNumber(&n);
		switch (n)
		{
			case 1 : DoInitBiTree(&T);break;
			case 2 : DoDestroyBiTree(&T);break;
			case 3 : DoCreateBiTree(&T); break;
			case 4 : Traverse(T, PreOrderTraverse); break;
			case 5 : Traverse(T,  PrePreOrderTraverse); break;
			case 6 : Traverse(T, InOrderTraverse); break;
			case 7 : Traverse(T,  CirInOrderTraverse); break;
			case 8 : Traverse(T, PostOrderTraverse); break;
			case 9 : printf("抱歉，这个还没写出来，先玩一下其他功能吧！\n"); break;
			case 10 : Traverse(T,  LevelOrderTraverse); break;
			case 11 : Calcultator();break;
			case -1 : exit(0); break;
		}
		printf("输入回车继续\n");
		while(getchar()!='\n');
		system("cls");
	}while(1);
	
	return 0;
}
