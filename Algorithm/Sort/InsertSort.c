/**
 * 插入排序
 */

#include <stdio.h>
#include <stdlib.h>

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

/**
 * 二分查找
 * @param  array  查找的数组
 * @param  length 数组长度
 * @param  temp   查找的元素
 * @param  down   查找的下边界
 * @param  up     查找的上边界
 * @return        应该插入的位置
 */
int binaryFind(int array[], int length, int temp, int down, int up)
{
	if (up < down || up > length || down < 0)
	{
		printf("下标越界\n");
		exit(1);
	}

	if (temp < array[down]) 
	{
		return down;
	}
	if (temp > array[up])
	{
		return up+1;
	}
	
	int mid = (up-down)/2 + down;
	int midData = array[mid];
	if (temp == midData) {
		return mid + 1;	
	} else if (temp < midData) {
		up = mid-1;
	} else if (temp > midData) {
		down = mid + 1;
	}
	return binaryFind(array, length, temp, down, up);
}
/**
 * 二分插入排序
 * 二分插入排序减少了比较次数，特别是当要排序的数据很大时，这个效果将更加明显。
 */
void insertSort3(int array[], int length)
{
	for (int i = 1; i < length; i++)
	{
		int index = binaryFind(array, length, array[i], 0, i-1);
		int temp = array[i];
		// index后的元素向后移动
		for (int j = i; j > index; j--)
		{
			array[j] = array[j-1];
		}
		array[index] = temp;
	}
}


int main(int argc, char const *argv[])
{
	int data[10] = {20, 5, 9, 1, 3};
	// insertSort1(data, 5);
	// insertSort2(data, 5);
	insertSort3(data, 5);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", data[i]);
	}

	return 0;
}