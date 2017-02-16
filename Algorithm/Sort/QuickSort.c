/**
 * 快速排序
 *
 * 排序思想：通过一趟排序将要排序的数据切分成独立的两部分，
 * 其中一部分的所有数据都比另外一部分的所有数据都要小，
 * 然后再按此方法对这两部分数据分别进行快速排序，
 * 整个排序过程可以递归进行，以此达到整个数据变成有序序列。
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 迭代法
 */
typedef struct _Range {
	int start, end;
} Range;

Range newRange(int start, int end)
{
	Range r;
	r.start = start;
	r.end = end;
	return r;
}

void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void quickSort(int array[], const int length)
{
	if (length <= 0)
	{
		return;
	}
	// r[]模拟堆叠，p为数量，r[p++]为push，r[--p]为pop且取得值
	Range r[length];
	int p = 0;
	r[p++] = newRange(0, length-1);

	while (p) {
		Range range = r[--p];
		if (range.start >= range.end)
		{
			continue;
		}

		int mid = array[range.end];
		int left = range.start, right = range.end - 1;
		while (left < right) {
			while (array[left] < mid && left < right) {
				left ++;
			}
			while (array[right] >= mid && left < right) {
				right --;
			}
			swap(&array[left], &array[right]);
		}

		if (array[left] >= array[range.end]) {
			swap(&array[left], &array[range.end]);
		} else {
			left++;
		}
		r[p++] = newRange(range.start, left-1);
		r[p++] = newRange(left+1, range.end);
	}
}

/**
 * 递归法
 */
void quickSortRecursive(int array[], int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int mid = array[end];
	int left = start, right = end - 1;
	while(left < right) {
		while(array[left] < mid && left < right) {
			left++;
		}
		while(array[right] >= mid && left < right) {
			right--;
		}
		swap(&array[left], &array[right]);
	}

	if (array[left] >= array[end])
	{
		swap(&array[left], &array[end]);
	} else {
		left++;
	}

	if (left)
	{
		quickSortRecursive(array, start, left-1);
	}
	quickSortRecursive(array, left+1, end);
}

void quickSort2(int array[], int length)
{
	quickSortRecursive(array, 0, length-1);
}


int main(int argc, char const *argv[])
{
	int array[] = {10, 2, 3, 1, 5, 30, 12, 18, 25, 44, 45};
	int length = sizeof(array)/sizeof(array[0]);
	// quickSort(array, length);
	quickSort2(array, length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", array[i]);
	}
	return 0;
}