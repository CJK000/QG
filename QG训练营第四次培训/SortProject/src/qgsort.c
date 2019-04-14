#include "../inc/qgsort.h"
#include <stdio.h>
#include <stdlib.h>
#include "../inc/stack.h"

#define BIG 10				//基数计数排序中桶的数量 





void insertSort(int *a,int n)		//插入排序 
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



void MergeArray(int *a,int begin,int mid,int end,int *temp)	//归并排序（合并数组）
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





void QuickSort_Recursion(int *a, int begin, int end)	//快速排序 
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





void QuickSort(int *a,int size)			//快排（非递归）
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




void CountSort(int *a, int size , int max)		//计数排序 
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




void RadixCountSort(int *a,int size)		// 桶排序 
{
	int max,i,con,j,h,t;
	int (*b)[size],k[BIG];
	int index = 1;
	int flag = 0;				//标记是否排序完成
	b = (int (*)[BIG])malloc(sizeof(int) * BIG * size);
	while(flag == 0)
	{
		for(i = 0; i < BIG; i++)					//清空所有桶 
		{
			k[i] = 0;
		}
		for(i = 0; i < size; i++)					//分桶 
		{
			b[a[i] / index % 10 ][k[a[i] / index % 10 ]] = a[i];
			k[a[i] / index % 10 ] ++;
		}
		
		
		index *= BIG;			//获取的位数往高一位 
		
		
		h = 0;
		for(i = 0; i < BIG; i ++)			//把所有桶中的数据收集回来 
		{
			for(j = 0; j < k[i]; j ++)
			{
				a[h] = b[i][j];
				h ++;
			}
		}
		
		flag = 1;
		for(i = 0;i < size; i++)		//判断是否需要结束排序 
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





void ColorSort(int *a,int size)		//颜色排序
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



void FindNumber(int *a, int size)				//寻找第K个最大/小数 
{
	int n;
	printf("寻找大数请输入1，寻找小数请输入2：");
	GetNumber(&n);
	while(n != 1 && n != 2)
	{
		printf("输入错误，请重新输入：");
		GetNumber(&n);
	}
	int begin = 0;
	int end = size - 1;
	if(size == 0) return ;
	int t,t1,i,j;
	if(n == 1)
	{
		printf("请输入大数的序号：");
		GetNumber(&n);
		while(1)
		{
			if(n > size)
			{
				printf("数据元素少于%d个\n",n);
				return ;
			}
			if(begin == end && size - begin == n)
			{
				printf("第%d大的数为%d\n",n,a[begin]);
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
				printf("第%d小的数为%d\n",i,a[i]);
				return ;
			}
			if(n < size - i)				//要找的数在第i个数的右边 
			{
				begin = i + 1;
				continue ;
			}
			if(n > size - i)				//要找的数在第i个数的左边 
			{
				end = i - 1;
				continue ;
			}
		}
	}
	else if(n == 2)
	{
		printf("请输入小数的序号：");
		GetNumber(&n);
		while(1)
		{
			if(n > size)
			{
				printf("数据元素少于%d个\n",n);
				return ;
			}
			if(begin == end && begin + 1 == n)
			{
				printf("第%d小的数为%d\n",n,a[begin]);
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
				printf("第%d小的数为%d\n",i,a[i]);
				return ;
			}
			if(n < i + 1)						//要找的数在第i个数的左边 
			{
				end = i - 1;
				continue ;
			}
			if(n > i + 1)						//要找的数在第i个数的右边 
			{
				begin = i + 1;
				continue ;
			}
		}
	}
}





















 
