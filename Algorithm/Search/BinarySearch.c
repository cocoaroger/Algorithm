/**
 * 二分查找
 *
 * 是一种在有序数组中查找某一特定元素的搜索算法。
 * 搜索过程从数组的中间元素开始，如果中间元素正好是要查找的元素，
 * 则搜索过程结束；如果某一特定元素大于或者小于中间元素，
 * 则在数组大于或小于中间元素的那一半中查找，而且跟开始一样从中间元素开始比较。
 * 如果在某一步骤数组为空，则代表找不到。这种搜索算法每一次比较都使搜索范围缩小一半。
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 递归实现
 */
int binary_search(const int array[], int start, int end, int key)
{
	if (start > end)
	{
		return -1; // 没搜到
	}
	int mid = start + (end - start)/2;
	if (array[mid] > key)
	{
		return binary_search(array, start, mid-1, key);
	}
	if (array[mid] < key)
	{
		return binary_search(array, mid+1, end, key);
	}
	return mid;
}

/**
 * while实现
 */
int binary_search2(const int array[], int start, int end, int key) 
{
	int mid;
	while (start <= end) {
		mid = start + (end - start)/2;
		if (array[mid] > key)
		{
			start = mid+1;
		} else if (array[mid] < key)
		{
			end = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}