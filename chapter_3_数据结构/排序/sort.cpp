// sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>

int array[10] = {6,4,8,3,2,0,7,1,5,9};
int tempArray[10];

int HeapArray[11] = {0,65,46,88,39,23,44,57,17,50,79};
int tempHeapArray[11];

void InsertSort(int array[], int length)
{
	for(int i = 1; i < length; i++)
	{
		int temp = array[i];
		int j;
		for(j = i-1; j >= 0; j--)
		{
			if(temp < array[j])
			{
				array[j+1] = array[j];
			}
			else
			{
				break;
			}
		}
		array[j+1] = temp;
	}
}

void ShellSort(int array[], int length)
{
	for(int gap = length/2; gap > 0; gap /=2)
	{
		for(int i = gap; i < length; i += gap)
		{
			int temp = array[i];
			int j;
			for(j = i-gap; j >= 0; j -= gap)
			{
				if(temp < array[j])
				{
					array[j+gap] = array[j];
				}
				else
				{
					break;
				}
			}
			array[j+gap] = temp;
		}
	}
}

//选取第N一个节点调整，使得这个节点以下中每个节点都比他的儿子节点大
void HeapAdjust(int array[], int n, int length)
{
	int exChild;
	for(int i = n; i*2 <= length; i = exChild)
	{
		exChild = i*2;//左子节点
		if(exChild+1 <= length && array[exChild+1] > array[exChild])
			exChild++;

		//父节点要比子节点小的时候才交换
		if(array[i] < array[exChild])
		{
			//要交换的节点就是exChild
			int temp = array[i];
			array[i] = array[exChild];
			array[exChild] = temp;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int array[], int length)
{
	int i;
	for(i = length/2; i >= 1; i--)
	{
		HeapAdjust(array, i, length);
	}

	//根节点和最后一个节点交换了，
	int temp = array[1];
	array[1] = array[length];
	array[length] = temp;
	//然后把最后一个节点剔除出去
	length--;

	//一直调整根节点，知道只剩下一个节点
	for(i = length; i > 0; i--)
	{
		HeapAdjust(array, 1, i);
		//调整完之后，根节点，跟最后一个节点交换
		int temp = array[1];
		array[1] = array[i];
		array[i] = temp;
	}
}

void Merge(int array[], int tempArray[], int left, int mid, int right)
{
	int leftIndex = left;
	int rightIndex = mid+1;
	int tempIndex = left;

	while(leftIndex <= mid && rightIndex <= right)
	{
		if(array[leftIndex] < array[rightIndex])
		{
			tempArray[tempIndex++] = array[leftIndex++];
		}
		else
		{
			tempArray[tempIndex++] = array[rightIndex++];
		}
	}

	//拷贝右边剩下的元素
	for(; rightIndex <= right; rightIndex++)
	{
		tempArray[tempIndex++] = array[rightIndex];
	}
	//如果左边还剩下元素
	for(; leftIndex <= mid; leftIndex++)
	{
		tempArray[tempIndex++] = array[leftIndex];
	}
	//拷贝到原始数组中
	for(int i = left; i <= right; i++)
	{
		array[i] = tempArray[i];
	}

}

//归并排序
void MergeSort(int array[], int tempArray[], int left, int right)
{
	//如果数组只有1个元素，说明数组就是有序的，直接返回
	if(left >= right)
	{
		return ;
	}
	int mid = (left+right)/2;
	MergeSort(array, tempArray, left, mid);
	MergeSort(array, tempArray, mid+1, right);
	Merge(array, tempArray, left, mid, right);
}

int Partition(int array[], int left, int right)
{
	int pivot = array[right];
	int tempIndex = left;
	for(int i = left; i < right; i++)
	{
		if(array[i] < pivot)
		{
			//交换
			if(i != tempIndex)
			{
				int temp = array[tempIndex];
				array[tempIndex] = array[i];
				array[i] = temp;

			}
			tempIndex++;
		}
	}
	int temp = array[tempIndex];
	array[tempIndex] = array[right];
	array[right] = temp;

	return tempIndex;
}

void QuickSort(int array[], int left, int right)
{
	if(left >= right)
		return ;
	int mid = Partition(array, left, right);
	QuickSort(array, left, mid-1);
	QuickSort(array, mid+1, right);
}

//O(n+k)
void CounterSort(int array[], int length, int k)
{
	int *counter = new int[k+1];
	memset(counter, 0, sizeof(int)*(k+1));

	int i, index = 0;
	for(i = 0; i < length; i++)
	{
		counter[array[i]]++;
	}
	for(i = 0; i <= k; i++)
	{
		while(counter[i])
		{
			array[index++] = i;
			counter[i]--;
		}
	}
}

int radixArray[11] = {443,63,555457,3566666,543,566674,3445,556,555, 87577777, 444};

int getMaxRadix(int array[], int length)
{
	int radix = 1;
	int temp = 10;
	for(int i = 0; i < length; i++)
	{
		while(array[i] >= temp)
		{
			radix++;
			temp *= 10;
		}
	}

	return radix;
}

void RadixSort(int array[], int length)
{
	int MaxRadix = getMaxRadix(array, length);
	int counter[10];
	int *tempArray = new int[length];
	int Radix = 1;

	for(int i = 1; i <= MaxRadix; i++)
	{
		//清空counter
		int j;
		for(j = 0; j < 10; j++)
		{
			counter[j] = 0;
		}
		for(j = 0; j < length; j++)
		{
			int bit = (array[j]/Radix)%10;
			counter[bit]++;
		}

		int tempCounter[10] = {0};
		//每个counter前面有几个数
		int k;
		for(k = 1; k < 10; k++)
		{	
			tempCounter[k] = 0;
			for(int j = 0; j < k; j++)
			{
				tempCounter[k] += counter[j];
			}
		}

		//遍历原始数组，把它放到临时数组正确的位置上
		for(k = 0; k < length; k++)
		{
			int bit = (array[k]/Radix)%10;
			tempArray[tempCounter[bit]++] = array[k];
		}

		//把临时数组拷贝回原始数组
		for(k = 0; k < length; k++)
		{
			array[k] = tempArray[k];
		}

		Radix *= 10;
	}

	delete [] tempArray;
}

int tempaa[4] = {312, 213, 545, 893};

int main(int argc, char* argv[])
{
	RadixSort(radixArray,11);
	for(int i = 0; i < 11; i++)
	{
		printf("%d\n", radixArray[i]);
	}

/*	HeapSort(HeapArray, 10);
	for(int i = 1; i < 11; i++)
	{
		printf("%3d", HeapArray[i]);
	}

	for(int i = 0; i < 10; i++)
	{
		printf("%3d", array[i]);
	}
	*/
	printf("\nHello World!\n");
	return 0;
}

