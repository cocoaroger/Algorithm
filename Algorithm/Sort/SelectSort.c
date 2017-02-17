/**
 * 选择排序
 *
 * 每一次从待排序的数据元素中找出最小（或最大）的一个元素，
 * 将它和待排序的元素中第一个位置的元素进行交换，
 * 直到全部待排序的数据元素排完程为止。
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 值交换
 * @param array 需要交换的数组
 * @param from [description]
 * @param to   [description]
 */
void swap(int array[], int from, int to)
{
	int temp = array[from];
	array[from] = array[to];
	array[to] = temp;
}

/**
 * 时间复杂度：O(n^2)，空间复杂度：O(1)
 * @param array  [description]
 * @param length [description]
 */
void selectSort(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int min = i;
		for (int j = i+1; j < length; ++j)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap(array, min, i);
	}
}

int main(int argc, char const *argv[])
{
	int len = 10000;
	int array[len];
	for (int i = 0; i < len; ++i)
	{
		array[i] = random()%100;
	}
	int length = sizeof(array)/sizeof(array[0]);

	selectSort(array, length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", array[i]);
	}
	return 0;
}
