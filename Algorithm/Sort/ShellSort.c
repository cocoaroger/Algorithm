/**
 * 希尔排序
 * 也称递减增量排序算法，是插入排序的一种更高效的改进版本。希尔排序是非稳定排序算法。
 * https://zh.wikipedia.org/wiki/%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F
 *
 * 时间复杂度：根据步长序列的不同而不同。已知最好的： O(nlog2n)
 * 空间复杂度	：O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void shellSort(int array[], int length)
{
	int i, j, gap;
	int temp;
	for (gap = length >> 1; gap > 0; gap >>= 1) // 步长,每次右移一位，除以2
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
	int len = 10000;
	int array[len];
	for (int i = 0; i < len; ++i)
	{
		array[i] = random()%100;
	}
	int length = sizeof(array)/sizeof(array[0]);
	
	shellSort(array, length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", array[i]);
	}
	return 0;
}
