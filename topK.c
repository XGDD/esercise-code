#define _CRT_SECURE_NO_WARNINGS 1

#include"topK.h"


void CreatetopK(topK* t, HPDataType* array, int k, int size)
{
	assert(t);
	//用前K个元素建立一个小堆
	CreateHeap(&(t->hp), array, k, Less);
	//用剩余的N-K个元素与堆顶元素比较，若比堆顶元素大，与堆顶元素交换，调整，若比堆顶元素小，则舍弃该元素
	
	while (k < size)
	{
		
		int root = (k - 1) >> 1;
		if (t->hp._hp[0] < array[k])
		{
			Swap(&(t->hp._hp[0]), &(array[k]));
			AdjustDown(&(t->hp), root, Less);
			k += 1;
		}
		else
			k += 1;
	}
}