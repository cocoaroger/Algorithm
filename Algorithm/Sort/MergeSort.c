/**
 * 归并排序
 * 时间复杂度为O(logn * n)
 * 空间复杂度O(n)
 * 排序效率是相对较高的
 */

/**
 * 自顶向下的归并排序
 * 排序思想：要将一个数组排序，可以先（递归的）将它分为两半分别排序，
 * 然后将结果归并起来。
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// 将有二个有序数列a[first...mid]和a[mid...last]合并。  
void merge(int array[], int first, int mid, int last, int *temp)
{
	int i = first, j = mid + 1; // 两个数组的起始位置
	int m = mid, n = last; // 结束位置
	int k = 0;
	
	while(i <= m && j <= n) 
	{
		if (array[i] <= array[j]) {
			temp[k++] = array[i++];
		} else {
			temp[k++] = array[j++];
		}
	}

	while(i <= m)
	{
		temp[k++] = array[i++];
	}
	while(j <= n) 
	{
		temp[k++] = array[j++];
	}

	for (i = 0; i < k; i++)
	{
		array[first+i] = temp[i];
	}
}

// 核心算法，递归分解数列
void mergeSort(int array[], int first, int last, int *temp)
{
	if (first < last) {
		int mid = (first+last)/2;
		mergeSort(array, first, mid, temp); // 左半边排序
		mergeSort(array, mid+1, last, temp); // 右半边排序
		merge(array, first, mid, last, temp);
	}
}

int* sort(int array[], int length)
{
	int *temp = (int*)malloc(sizeof(int) * length);
	mergeSort(array, 0, length - 1, temp);
	return temp;
}

int main(int argc, char const *argv[])
{
	int data[5] = {20, 5, 9, 1, 3};
	int *temp = sort(data, 5);

	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", temp[i]);
	}

	return 0;
}

