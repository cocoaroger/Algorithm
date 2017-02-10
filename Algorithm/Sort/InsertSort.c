/**
 * 插入排序
 */

#include <stdio.h>
#include <stdlib.h>

int getArrayLength(int *array)
{
	return (sizeof(array)/sizeof(array[0]));
}

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
 * 插入排序第一种实现，时间复杂度：最好O(n),平均O(n^2)，空间复杂度O(1)
 * @param array 需要排序的数组
 */
void insertSort1(int array[], int length)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j >= 1 && array[j] < array[j-1]; j--)
		{
			swap(array, j, j-1);
		}
	}
}

/**
 * 在内循环中将较大的元素一次性向右移动而不是交换两个元素，这样访问数组的次数将减半 
 */
void insertSort2(int array[], int length)
{
	for (int i = 1; i < length; i++)
	{
		int temp = array[i];
		int index = 0; // 插入temp的位置
		for (int j = i; j >= 1; j--)
		{
			if (temp < array[j-1])
			{
				array[j] = array[j-1];
			} else {
				index = j;
				break;
			}
		}
		array[index] = temp;
	}
}

int main(int argc, char const *argv[])
{
	int data[5] = {20, 5, 9, 1, 3};
	// insertSort1(data, 5);
	insertSort2(data, 5);
	
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", data[i]);
	}


	return 0;
}