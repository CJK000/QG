#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/fun.h"


void TestType1(void (*foo)(int *a, int n))				//测试插入排序、非递归快排、桶排序 
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
		if(feof(fp) == EOF)	break;	//如果文件被读完则结束 
	
	}
	if(i > 0)					//判断测试数据是否足够 
	{
		printf("测试数据不足\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	(*foo)(a, n); 				//执行排序算法 
	
	for(i = 0; i < n; i ++)		//输出排序结果 
	{
		printf("%4d ",a[i]);
	}
	putchar('\n');
	
	fclose(fp);
	free(a);
}



void TestQuickSort_Recursion(void)				//测试递归版快排 
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




void TestCountSort(void)				//测试计数排序 
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





void TestMergeArray(void)				//测试归并排序 
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





void TestColorSort(void)				//测试颜色排序 
{
	FILE *fp;
	int *a, *b, i, n, t;
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
		fscanf(fp, "%d", &t);
		*b = t % 3;
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
	
	ColorSort(a, n); 				//执行排序算法 
	
	for(i = 0; i < n; i ++)		//输出排序结果 
	{
		printf("%d ",a[i]);
	}
	putchar('\n');
	
	fclose(fp);
	free(a);
}






void TestFindNumber(void)				//测试寻找第K个最大/小数  
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
		if(feof(fp) == EOF)	break;	//如果文件被读完则结束 
	
	}
	if(i > 0)					//判断测试数据是否足够 
	{
		printf("测试数据不足\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	FindNumber(a, n); 				//执行排序算法 
	
	fclose(fp);
	free(a);
}


















void menu(void)
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
	printf("7、颜色排序\n");
	printf("8、在一个无序序列中找到第K大/小的数\n");
	printf("-1、退出程序\n");
	
	
	i = 70;
	while(i --)putchar('*');
	putchar('\n');
	
	printf("请选择要测试的排序：\n");
	
	return ;
}


void GetNumber(int *n)
{
	int a;
	scanf("%d",&a);
	char ch;
	ch = getchar();
	while(ch != '\n')
	{
		while(ch != '\n')ch = getchar();
		printf("输入出错，请重新输入：");
		scanf("%d",&a);
		ch = getchar();
	}
	*n = a;
	return ;
}
























