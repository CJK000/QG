#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/fun.h"


//读取测试数据并测试排序函数的程序
int main(){				
	int n;
	menu();
	GetNumber(&n);
	while(1)
	{
		switch (n)
		{
			case 1 : TestType1(insertSort); break;
			case 2 : TestMergeArray(); break;
			case 3 : TestQuickSort_Recursion(); break;
			case 4 : TestType1(QuickSort); break;
			case 5 : TestCountSort(); break;
			case 6 : TestType1(RadixCountSort);break;
			case 7 : TestColorSort(); break;
			case 8 : TestFindNumber();break;
			case -1 : exit(0);
			default : printf("无此选项\n");
		}
		printf("输入任意字符继续：");
		getchar();
		system("cls");
		menu();
		GetNumber(&n);
	}
}



// 大数据量和大量小数组的排序测试程序

// 这个代码好像问题还很大 
// 这个代码好像问题还很大 
// 这个代码好像问题还很大 

/*
int main()
{
	printf("插入排序：\n");
	time3TestType1(insertSort);				//测试插入排序
	printf("非递归快速排序：\n");
	time3TestType1(QuickSort);				//非递归快排
	printf("桶排序：\n");
	time3TestType1(RadixCountSort);			//桶排序 
	getchar();
} 
*/













/*
//写函数时用来测试的，师兄请忽略这个
//写函数时用来测试的，师兄请忽略这个
//写函数时用来测试的，师兄请忽略这个
//写函数时用来测试的，师兄请忽略这个 

//简单测试函数  


int main(){
	int a[5]={8,4,5,3,1};
//	int a[10]={236,415,328,180,324,454,895,856,637,694};
//	int a[7]={1,2,1,0,2,0,0};
	int i;
//	insertSort(a,5);				//插入排序 
//	int temp[5];					
//	MergeArray(a,0,2,4,temp);		//归并排序 
//	QuickSort_Recursion(a, 0, 4);	//快速排序（递归） 
//	QuickSort(a,5);			//快排（非递归）
//	CountSort(a, 5, 8);
//	RadixCountSort(a,10);		//基数计数排序—桶排序 
//	ColorSort(a,7);
	FindNumber(a, 5);
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n请输入任意字符结束程序：");
	getchar();
	return 0;

} 


*/
