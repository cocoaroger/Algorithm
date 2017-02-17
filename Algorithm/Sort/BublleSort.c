/**
 * 冒泡排序
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
 * 依次比较相邻的两个元素，若它们的顺序错误则交换，每次循环都将最大（或最小）元素放在序列一端。
 * 时间复杂度：平均O(n^2)，空间复杂度O(1)
 * @param array 需要排序的数组
 */
void bublleSort(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length-i-1; ++j)
		{
			if (array[j] > array[j+1])
			{
				swap(array, j, j+1);
			}
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
	
	bublleSort(array, length);

	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", array[i]);
	}	
	return 0;
}