/**
 * 希尔排序
 * 也称递减增量排序算法，是插入排序的一种更高效的改进版本。希尔排序是非稳定排序算法。
 * https://zh.wikipedia.org/wiki/%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F
 */

#include <stdio.h>
#include <stdlib.h>

void shellSort(int array[], int length)
{
	int i, j, gap;
	int temp;
	for (gap = length >> 1; gap > 0; gap >>= 1) // 步长
	{
		for (i = gap; i < length; i++)
		{
			temp = array[i];
			for (j = i - gap; j >= 0 && array[j] > temp; j -= gap)
			{
				array[j + gap] = array[j];
			}
			array[j + gap] = temp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int array[] = {10, 2, 3, 1, 5, 30, 12, 18, 25, 44, 45};
	int length = sizeof(array)/sizeof(array[0]);
	shellSort(array, length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", array[i]);
	}
	return 0;
}