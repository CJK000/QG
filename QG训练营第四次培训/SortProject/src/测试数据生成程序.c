#include<stdio.h>
#include<stdlib.h>
#include<time.h>





int main(){
	FILE *fp;
	long long i;
	int a;
	if((fp = fopen("testnumber.txt","w")) == NULL)
	{
		printf("�����ļ�ʧ��\n");
		exit(0);
	}
	srand(time(0));
	printf("�����Ҫ���ɵ���������");
	scanf("%d",&i);
	char ch;
	ch = getchar();
	while(ch != '\n')
	{
		while(ch != '\n')ch = getchar();
		printf("����������������룺");
		scanf("%d",&i);
		ch = getchar();
	}
	while(i--)
	{
		a = rand() % 10000;
		fprintf(fp, "%d ",a);
	}
	printf("�����������ɣ����������ַ���������\n");
	getchar();
	
}





