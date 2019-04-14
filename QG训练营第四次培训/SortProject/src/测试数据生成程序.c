#include<stdio.h>
#include<stdlib.h>
#include<time.h>





int main(){
	FILE *fp;
	long long i;
	int a;
	if((fp = fopen("testnumber.txt","w")) == NULL)
	{
		printf("创建文件失败\n");
		exit(0);
	}
	srand(time(0));
	printf("请出入要生成的数据量：");
	scanf("%d",&i);
	char ch;
	ch = getchar();
	while(ch != '\n')
	{
		while(ch != '\n')ch = getchar();
		printf("输入出错，请重新输入：");
		scanf("%d",&i);
		ch = getchar();
	}
	while(i--)
	{
		a = rand() % 10000;
		fprintf(fp, "%d ",a);
	}
	printf("随机数生成完成，输入任意字符结束程序\n");
	getchar();
	
}





