#ifndef __FUN_H__
#define __FUN_H__





void TestType1(void (*foo)(int *a, int n));				//测试插入排序、非递归快排、桶排序 
void TestQuickSort_Recursion(void);				//测试递归版快排 
void TestCountSort(void);				//测试计数排序 
void TestMergeArray(void);				//测试归并排序 
void TestColorSort(void);				//测试颜色排序 
void TestFindNumber(void);				//测试寻找第K个最大/小数  

void menu(void);
void GetNumber(int *n);

#endif 
