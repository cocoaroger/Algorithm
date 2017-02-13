/**
 * 归并排序
 */

/**
 * 自顶向下的归并排序
 * 排序思想：要将一个数组排序，可以先（递归的）将它分为两半分别排序，
 * 然后将结果归并起来。
 * 
 */

#include <stdio.h>

// 一个数组左右半边分别有序，归并
void merge(int array[], int down, int mid, int up)
{
	int i = down, j = mid + 1;

	// 复制数组中元素
	for (int k = down; k <= up; k++)
	{
		
	}
}

// 核心算法
void mergeSort(int array[], int down, int up)
{
	if (up <= down) return; // 结束条件
	int mid = (up - down)/2 + down;
	mergeSort(array, down, mid); // 左半边排序
	mergeSort(array, mid+1, up); // 右半边排序
	merge(array, down, mid, up);
}

void sort(int array[], int length)
{
	mergeSort(array, 0, length - 1);
}

