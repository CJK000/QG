#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/fun.h"


//��ȡ�������ݲ������������ĳ���
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
			default : printf("�޴�ѡ��\n");
		}
		printf("���������ַ�������");
		getchar();
		system("cls");
		menu();
		GetNumber(&n);
	}
}



// ���������ʹ���С�����������Գ���

// �������������⻹�ܴ� 
// �������������⻹�ܴ� 
// �������������⻹�ܴ� 

/*
int main()
{
	printf("��������\n");
	time3TestType1(insertSort);				//���Բ�������
	printf("�ǵݹ��������\n");
	time3TestType1(QuickSort);				//�ǵݹ����
	printf("Ͱ����\n");
	time3TestType1(RadixCountSort);			//Ͱ���� 
	getchar();
} 
*/













/*
//д����ʱ�������Եģ�ʦ����������
//д����ʱ�������Եģ�ʦ����������
//д����ʱ�������Եģ�ʦ����������
//д����ʱ�������Եģ�ʦ���������� 

//�򵥲��Ժ���  


int main(){
	int a[5]={8,4,5,3,1};
//	int a[10]={236,415,328,180,324,454,895,856,637,694};
//	int a[7]={1,2,1,0,2,0,0};
	int i;
//	insertSort(a,5);				//�������� 
//	int temp[5];					
//	MergeArray(a,0,2,4,temp);		//�鲢���� 
//	QuickSort_Recursion(a, 0, 4);	//�������򣨵ݹ飩 
//	QuickSort(a,5);			//���ţ��ǵݹ飩
//	CountSort(a, 5, 8);
//	RadixCountSort(a,10);		//������������Ͱ���� 
//	ColorSort(a,7);
	FindNumber(a, 5);
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n�����������ַ���������");
	getchar();
	return 0;

} 


*/
