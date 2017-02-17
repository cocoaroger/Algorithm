/**
 * 堆排序
 *
 * 堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。
 * 堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void swap(int* a, int* b) 
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

/**
 * 最大堆排序，将堆的末端子节点作调整，使得子节点永远小于父节点
 */
void maxHeapify(int array[], int start, int end)
{
	int dad = start;
	int son = 2 * dad + 1;
	while (son <= end) { // 子节点在范围内才比较
		if (son + 1 <= end && array[son] < array[son + 1]) // 左右子节点中，取大的一个
		{
			son++;
		}
		if (array[dad] > array[son]) // 父大于子，调整完毕
		{
			return;
		} else {
			swap(&array[dad], &array[son]);
			dad = son;
			son = 2 * dad + 1;
		}
	}
}

void heapSort(int array[], int length) {
	int i;
	// 初始化，i从最后一个父节点开始调整
	for (i = length/2-1; i > 0; i--)
	{
		maxHeapify(array, i, length-1);
	}
	// 先讲第一个元素和已牌号元素前一位做交换，再重新调整，直到排序完成
	for (i = length-1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		maxHeapify(array, 0, i-1);
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
	
	heapSort(array, length);
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", array[i]);
	}
	return 0;
}