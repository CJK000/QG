#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/fun_time.h"
#include <time.h>


void timeTestType1(int n, void (*foo)(int *a, int n))				//测试插入排序、非递归快排、桶排序 
{
	FILE *fp;
	int *a, *b, i;
	if((fp = fopen("testnumber.txt","r")) == NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	i = n;
	a = b = (int *)malloc(sizeof(int) * n);
	while(i --)					//读取测试数据 
	{
		fscanf(fp, "%d", b);
		b ++;
		if(feof(fp) == EOF)	break;	//如果文件被读完则结束 
	
	}
	if(i > 0)					//判断测试数据是否足够 
	{
		printf("测试数据不足\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	clock_t start = clock();	//开始计时 
	(*foo)(a, n); 				//执行排序算法 
	clock_t diff = clock() - start;
	
	fclose(fp);
	free(a);
}



void time3TestType1(void (*foo)(int *a, int n))				//测试插入排序、非递归快排、桶排序 
{
	int n,i;
	clock_t start, diff;
	
	n = 10000;
	start = clock();	//开始计时 
	timeTestType1(n, foo);				//测试插入排序、非递归快排、桶排序 
	diff = clock() - start;
	printf("\t排序%ld个数据用时：%dms\n",n,diff);
	
	n = 50000;
	start = clock();	//开始计时 
	timeTestType1(n, foo);				//测试插入排序、非递归快排、桶排序 
	diff = clock() - start;
	printf("\t排序%ld个数据用时：%dms\n",n,diff);
	
	n = 200000;
	start = clock();	//开始计时 
	timeTestType1(n, foo);				//测试插入排序、非递归快排、桶排序 
	diff = clock() - start;
	printf("\t排序%ld个数据用时：%dms\n",n,diff);
	
	n = 1000;
	diff = 0;
	start = clock();	//开始计时 
	while(n --)
	{
		i = 100;
		while(i --)
		{
			timeTestType1(n, foo);				//测试插入排序、非递归快排、桶排序 
		}
	}
	diff = clock() - start;
	printf("\t排序%d*%d个数据用时：%ldms\n",100, 1000, diff);
}






void timeTestQuickSort_Recursion(void)				//测试递归版快排 
{
	FILE *fp;
	int *a, *b, i, n;
	if((fp = fopen("testnumber.txt","r")) == NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	printf("请输入要进行测试的数据量：");
	GetNumber(&n);
	i = n;
	a = b = (int *)malloc(sizeof(int) * n);
	while(i --)					//读取测试数据 
	{
		fscanf(fp, "%d", b);
		b ++;
		if(feof(fp) == EOF) break;	//如果文件被读完则结束 
	}
	if(i > 0)					//判断测试数据是否足够 
	{
		printf("测试数据不足\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	 QuickSort_Recursion(a, 0, n - 1); 				//执行排序算法 
	
	for(i = 0; i < n; i ++)		//输出排序结果 
	{
		printf("%4d ",a[i]);
	}
	putchar('\n');
	
	fclose(fp);
	free(a);
}




void timeTestCountSort(void)				//测试计数排序 
{
	FILE *fp;
	int *a, *b, i, n, max;
	if((fp = fopen("testnumber.txt","r")) == NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	printf("请输入要进行测试的数据量：");
	GetNumber(&n);
	i = n;
	a = b = (int *)malloc(sizeof(int) * n);
	while(i --)					//读取测试数据 
	{
		fscanf(fp, "%d", b);
		b ++;
		if(feof(fp) == EOF) break;	//如果文件被读完则结束 
	}
	if(i > 0)					//判断测试数据是否足够 
	{
		printf("测试数据不足\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	max = a[0];					//找到数组中最大的数 
	for(i = 0; i < n; i++)
	{
		if(a[i] > max) max = a[i];
	}
	
	CountSort(a, n, max); 				//执行排序算法 
	
	for(i = 0; i < n; i ++)		//输出排序结果 
	{
		printf("%4d ",a[i]);
	}
	putchar('\n');
	
	fclose(fp);
	free(a);
}





void timeTestMergeArray(void)				//测试归并排序 
{
	FILE *fp;
	int *a, *b, i, n;
	if((fp = fopen("testnumber.txt","r")) == NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	printf("请输入要进行测试的数据量：");
	GetNumber(&n);
	i = n;
	a = b = (int *)malloc(sizeof(int) * n);
	while(i --)					//读取测试数据 
	{
		fscanf(fp, "%d", b);
		b ++;
		if(feof(fp) == EOF) break;	//如果文件被读完则结束 
	}
	if(i > 0)					//判断测试数据是否足够 
	{
		printf("测试数据不足\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	b = (int *)malloc(sizeof(int) * n);
	MergeArray(a, 0, n/2, n - 1, b); 				//执行排序算法 
	
	for(i = 0; i < n; i ++)		//输出排序结果 
	{
		printf("%4d ",a[i]);
	}
	putchar('\n');
	
	fclose(fp);
	free(a);
	free(b);
}



















void timemenu(void)
{
	int i = 70;
	while(i --)putchar('*');
	putchar('\n');
	
	
	printf("1、插入排序\n");
	printf("2、归并排序\n");
	printf("3、快速排序（递归版）\n");
	printf("4、快速排序（非递归版）\n");
	printf("5、计数排序\n");
	printf("6、基数计数排序\n");
	printf("-1、退出程序\n");
	
	
	i = 70;
	while(i --)putchar('*');
	putchar('\n');
	
	printf("请选择要测试的排序：\n");
	
	return ;
}















