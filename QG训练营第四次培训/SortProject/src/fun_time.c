#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/fun_time.h"
#include <time.h>


void timeTestType1(int n, void (*foo)(int *a, int n))				//���Բ������򡢷ǵݹ���š�Ͱ���� 
{
	FILE *fp;
	int *a, *b, i;
	if((fp = fopen("testnumber.txt","r")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	i = n;
	a = b = (int *)malloc(sizeof(int) * n);
	while(i --)					//��ȡ�������� 
	{
		fscanf(fp, "%d", b);
		b ++;
		if(feof(fp) == EOF)	break;	//����ļ������������ 
	
	}
	if(i > 0)					//�жϲ��������Ƿ��㹻 
	{
		printf("�������ݲ���\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	clock_t start = clock();	//��ʼ��ʱ 
	(*foo)(a, n); 				//ִ�������㷨 
	clock_t diff = clock() - start;
	
	fclose(fp);
	free(a);
}



void time3TestType1(void (*foo)(int *a, int n))				//���Բ������򡢷ǵݹ���š�Ͱ���� 
{
	int n,i;
	clock_t start, diff;
	
	n = 10000;
	start = clock();	//��ʼ��ʱ 
	timeTestType1(n, foo);				//���Բ������򡢷ǵݹ���š�Ͱ���� 
	diff = clock() - start;
	printf("\t����%ld��������ʱ��%dms\n",n,diff);
	
	n = 50000;
	start = clock();	//��ʼ��ʱ 
	timeTestType1(n, foo);				//���Բ������򡢷ǵݹ���š�Ͱ���� 
	diff = clock() - start;
	printf("\t����%ld��������ʱ��%dms\n",n,diff);
	
	n = 200000;
	start = clock();	//��ʼ��ʱ 
	timeTestType1(n, foo);				//���Բ������򡢷ǵݹ���š�Ͱ���� 
	diff = clock() - start;
	printf("\t����%ld��������ʱ��%dms\n",n,diff);
	
	n = 1000;
	diff = 0;
	start = clock();	//��ʼ��ʱ 
	while(n --)
	{
		i = 100;
		while(i --)
		{
			timeTestType1(n, foo);				//���Բ������򡢷ǵݹ���š�Ͱ���� 
		}
	}
	diff = clock() - start;
	printf("\t����%d*%d��������ʱ��%ldms\n",100, 1000, diff);
}






void timeTestQuickSort_Recursion(void)				//���Եݹ����� 
{
	FILE *fp;
	int *a, *b, i, n;
	if((fp = fopen("testnumber.txt","r")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	printf("������Ҫ���в��Ե���������");
	GetNumber(&n);
	i = n;
	a = b = (int *)malloc(sizeof(int) * n);
	while(i --)					//��ȡ�������� 
	{
		fscanf(fp, "%d", b);
		b ++;
		if(feof(fp) == EOF) break;	//����ļ������������ 
	}
	if(i > 0)					//�жϲ��������Ƿ��㹻 
	{
		printf("�������ݲ���\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	 QuickSort_Recursion(a, 0, n - 1); 				//ִ�������㷨 
	
	for(i = 0; i < n; i ++)		//��������� 
	{
		printf("%4d ",a[i]);
	}
	putchar('\n');
	
	fclose(fp);
	free(a);
}




void timeTestCountSort(void)				//���Լ������� 
{
	FILE *fp;
	int *a, *b, i, n, max;
	if((fp = fopen("testnumber.txt","r")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	printf("������Ҫ���в��Ե���������");
	GetNumber(&n);
	i = n;
	a = b = (int *)malloc(sizeof(int) * n);
	while(i --)					//��ȡ�������� 
	{
		fscanf(fp, "%d", b);
		b ++;
		if(feof(fp) == EOF) break;	//����ļ������������ 
	}
	if(i > 0)					//�жϲ��������Ƿ��㹻 
	{
		printf("�������ݲ���\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	max = a[0];					//�ҵ������������� 
	for(i = 0; i < n; i++)
	{
		if(a[i] > max) max = a[i];
	}
	
	CountSort(a, n, max); 				//ִ�������㷨 
	
	for(i = 0; i < n; i ++)		//��������� 
	{
		printf("%4d ",a[i]);
	}
	putchar('\n');
	
	fclose(fp);
	free(a);
}





void timeTestMergeArray(void)				//���Թ鲢���� 
{
	FILE *fp;
	int *a, *b, i, n;
	if((fp = fopen("testnumber.txt","r")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	printf("������Ҫ���в��Ե���������");
	GetNumber(&n);
	i = n;
	a = b = (int *)malloc(sizeof(int) * n);
	while(i --)					//��ȡ�������� 
	{
		fscanf(fp, "%d", b);
		b ++;
		if(feof(fp) == EOF) break;	//����ļ������������ 
	}
	if(i > 0)					//�жϲ��������Ƿ��㹻 
	{
		printf("�������ݲ���\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	b = (int *)malloc(sizeof(int) * n);
	MergeArray(a, 0, n/2, n - 1, b); 				//ִ�������㷨 
	
	for(i = 0; i < n; i ++)		//��������� 
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
	
	
	printf("1����������\n");
	printf("2���鲢����\n");
	printf("3���������򣨵ݹ�棩\n");
	printf("4���������򣨷ǵݹ�棩\n");
	printf("5����������\n");
	printf("6��������������\n");
	printf("-1���˳�����\n");
	
	
	i = 70;
	while(i --)putchar('*');
	putchar('\n');
	
	printf("��ѡ��Ҫ���Ե�����\n");
	
	return ;
}















