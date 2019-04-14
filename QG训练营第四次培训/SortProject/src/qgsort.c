#include "../inc/qgsort.h"
#include <stdio.h>
#include <stdlib.h>
#include "../inc/stack.h"

#define BIG 10				//��������������Ͱ������ 





void insertSort(int *a,int n)		//�������� 
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		if(a[i-1] > a[i])
		{
			t=a[i];
			for(j=i;j>0;j--)
			{
				if(a[j-1]>t)
				{
					a[j] = a[j-1];
				}
				else
				{
					break;
				}
			}
			a[j] = t;
		}
	}
}



void MergeArray(int *a,int begin,int mid,int end,int *temp)	//�鲢���򣨺ϲ����飩
{
	int i,j,k;
	if(begin == end) return ;
	MergeArray(a, begin, (begin + mid) / 2, mid, temp);
	MergeArray(a, mid + 1, (mid + end) / 2 , end, temp);
	k = begin;
	for(i = begin, j = mid +1; i <= mid && j <= end ;k ++)
	{
		if(a[i] < a[j])
		{
			temp[k] = a[i];
			i ++;
		}
		else 
		{
			temp[k] = a[j];
			j ++;
		}
	}
	while(i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while(j <= end)
	{
		temp[k] = a[j];
		k ++;
		j ++;
	}
	for(i = begin; i <=end; i++)
	{
		a[i] = temp[i];
	}
}





void QuickSort_Recursion(int *a, int begin, int end)	//�������� 
{
	if(begin >= end) return ;
	int t,t1,i,j;
	i = begin;
	j = i + 1;
	t=a[i];
	while(j < end)
	{
		j++;
		if(a[j] < t)
		{
			i++;
			t1 = a[i];
			a[i] = a[j];
			a[j] = t1;
		}
	}
	i ++;
	if(a[i] < t)
	{
		a[begin] = a[i];
		a[i] = t;
	}
	QuickSort_Recursion(a, begin, i - 1);
	QuickSort_Recursion(a, i + 1, end);
}





void QuickSort(int *a,int size)			//���ţ��ǵݹ飩
{
	SqStack s;
	s.elem = NULL;
	ElemType block;
	int t,t1,i,j;
	int *b;
	block.a = a;
	block.size =size;
	initStack(&s, size);
	pushStack(&s,block);
	while(isEmptyStack(&s) != SUCCESS)
	{
		popStack(&s,&block);
		b = block.a;
		size = block.size;
		if(size > 1)
		{
			i = 0;
			j = i + 1;
			t=b[i];
			while(j < size - 1)
			{
				j ++;
				if(b[j] < t)
				{
					i++;
					t1 = b[i];
					b[i] = b[j];
					b[j] = t1;
				}
			}
			i ++;
			if(b[i] < t)
			{
				b[0] = b[i];
				b[i] = t;
			}
		}
		if(i > 1)
		{
			block.a = b;
			block.size = i;
			pushStack(&s,block);
		}
		if(size - i > 1)
		{
			block.a = b + i;
			block.size = size - i;
			pushStack(&s,block);
		}
	}
} 




void CountSort(int *a, int size , int max)		//�������� 
{
	int *b,*c;
	b = (int*)malloc(sizeof(int) * (max + 1));
	c = (int*)malloc(sizeof(int)*size);
	int i;
	for(i = 0; i < max + 1; i ++)
	{
		b[i] = 0;
	}
	for(i = 0; i < size; i ++)
	{
		b[a[i]] ++;
	}
	if(size > 1)
	{
		for(i = 1; i <= max; i++)
		{
			b[i] = b[i - 1] + b[i];
		}
	}
	for(i = size -1; i >= 0; i --)
	{
		b[a[i]] --;
		c[b[a[i]]] = a[i];
	}
	for(i = 0;i < size; i ++)
	{
		a[i] = c[i];
	}
	free(b);
	free(c);
}




void RadixCountSort(int *a,int size)		// Ͱ���� 
{
	int max,i,con,j,h,t;
	int (*b)[size],k[BIG];
	int index = 1;
	int flag = 0;				//����Ƿ��������
	b = (int (*)[BIG])malloc(sizeof(int) * BIG * size);
	while(flag == 0)
	{
		for(i = 0; i < BIG; i++)					//�������Ͱ 
		{
			k[i] = 0;
		}
		for(i = 0; i < size; i++)					//��Ͱ 
		{
			b[a[i] / index % 10 ][k[a[i] / index % 10 ]] = a[i];
			k[a[i] / index % 10 ] ++;
		}
		
		
		index *= BIG;			//��ȡ��λ������һλ 
		
		
		h = 0;
		for(i = 0; i < BIG; i ++)			//������Ͱ�е������ռ����� 
		{
			for(j = 0; j < k[i]; j ++)
			{
				a[h] = b[i][j];
				h ++;
			}
		}
		
		flag = 1;
		for(i = 0;i < size; i++)		//�ж��Ƿ���Ҫ�������� 
		{
			if(a[i] / index > 0)
			{
				flag = 0;
				break;
			}
		}
	}
	free(b);
}





void ColorSort(int *a,int size)		//��ɫ����
{
	int *p0,*p2,*p;
	int t;
	p0 = a;
	p = p0 + 1;
	p2 = a + size - 1;
	while(p <= p2)
	{
		if(*p == 0)
		{
			t = *p;
			*p = *p0;
			*p0 = t;
			p0 ++;
			continue ;
		}
		if(*p == 2)
		{
			t = *p;
			*p = *p2;
			*p2 = t;
			p2 --;
			continue ;
		} 
		p ++;
	}
} 



void FindNumber(int *a, int size)				//Ѱ�ҵ�K�����/С�� 
{
	int n;
	printf("Ѱ�Ҵ���������1��Ѱ��С��������2��");
	GetNumber(&n);
	while(n != 1 && n != 2)
	{
		printf("����������������룺");
		GetNumber(&n);
	}
	int begin = 0;
	int end = size - 1;
	if(size == 0) return ;
	int t,t1,i,j;
	if(n == 1)
	{
		printf("�������������ţ�");
		GetNumber(&n);
		while(1)
		{
			if(n > size)
			{
				printf("����Ԫ������%d��\n",n);
				return ;
			}
			if(begin == end && size - begin == n)
			{
				printf("��%d�����Ϊ%d\n",n,a[begin]);
				return ;
			}
			i = begin;
			j = i + 1;
			t=a[i];
			while(j < end)
			{
				j++;
				if(a[j] < t)
				{
					i++;
					t1 = a[i];
					a[i] = a[j];
					a[j] = t1;
				}
			}
			i ++;
			if(a[i] < t)
			{
				a[begin] = a[i];
				a[i] = t;
			}
			if(size - i == n)
			{
				printf("��%dС����Ϊ%d\n",i,a[i]);
				return ;
			}
			if(n < size - i)				//Ҫ�ҵ����ڵ�i�������ұ� 
			{
				begin = i + 1;
				continue ;
			}
			if(n > size - i)				//Ҫ�ҵ����ڵ�i��������� 
			{
				end = i - 1;
				continue ;
			}
		}
	}
	else if(n == 2)
	{
		printf("������С������ţ�");
		GetNumber(&n);
		while(1)
		{
			if(n > size)
			{
				printf("����Ԫ������%d��\n",n);
				return ;
			}
			if(begin == end && begin + 1 == n)
			{
				printf("��%dС����Ϊ%d\n",n,a[begin]);
				return ;
			}
			i = begin;
			j = i + 1;
			t=a[i];
			while(j < end)
			{
				j++;
				if(a[j] < t)
				{
					i++;
					t1 = a[i];
					a[i] = a[j];
					a[j] = t1;
				}
			}
			i ++;
			if(a[i] < t)
			{
				a[begin] = a[i];
				a[i] = t;
			}
			if(i + 1 == n)
			{
				printf("��%dС����Ϊ%d\n",i,a[i]);
				return ;
			}
			if(n < i + 1)						//Ҫ�ҵ����ڵ�i��������� 
			{
				end = i - 1;
				continue ;
			}
			if(n > i + 1)						//Ҫ�ҵ����ڵ�i�������ұ� 
			{
				begin = i + 1;
				continue ;
			}
		}
	}
}





















 
