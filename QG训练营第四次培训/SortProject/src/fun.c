#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/fun.h"


void TestType1(void (*foo)(int *a, int n))				//���Բ������򡢷ǵݹ���š�Ͱ���� 
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
		if(feof(fp) == EOF)	break;	//����ļ������������ 
	
	}
	if(i > 0)					//�жϲ��������Ƿ��㹻 
	{
		printf("�������ݲ���\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	(*foo)(a, n); 				//ִ�������㷨 
	
	for(i = 0; i < n; i ++)		//��������� 
	{
		printf("%4d ",a[i]);
	}
	putchar('\n');
	
	fclose(fp);
	free(a);
}



void TestQuickSort_Recursion(void)				//���Եݹ����� 
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




void TestCountSort(void)				//���Լ������� 
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





void TestMergeArray(void)				//���Թ鲢���� 
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





void TestColorSort(void)				//������ɫ���� 
{
	FILE *fp;
	int *a, *b, i, n, t;
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
		fscanf(fp, "%d", &t);
		*b = t % 3;
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
	
	ColorSort(a, n); 				//ִ�������㷨 
	
	for(i = 0; i < n; i ++)		//��������� 
	{
		printf("%d ",a[i]);
	}
	putchar('\n');
	
	fclose(fp);
	free(a);
}






void TestFindNumber(void)				//����Ѱ�ҵ�K�����/С��  
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
		if(feof(fp) == EOF)	break;	//����ļ������������ 
	
	}
	if(i > 0)					//�жϲ��������Ƿ��㹻 
	{
		printf("�������ݲ���\n");
		fclose(fp);
		free(a);
		return ;
	}
	
	FindNumber(a, n); 				//ִ�������㷨 
	
	fclose(fp);
	free(a);
}


















void menu(void)
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
	printf("7����ɫ����\n");
	printf("8����һ�������������ҵ���K��/С����\n");
	printf("-1���˳�����\n");
	
	
	i = 70;
	while(i --)putchar('*');
	putchar('\n');
	
	printf("��ѡ��Ҫ���Ե�����\n");
	
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
		printf("����������������룺");
		scanf("%d",&a);
		ch = getchar();
	}
	*n = a;
	return ;
}
























