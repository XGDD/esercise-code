#define _CRT_SECURE_NO_WARNINGS 1

#include"SortHeap.h"

void SortHeapUp(Sort* s, HPDataType array, int size)
{
	assert(s);
	//先创建一个大堆
	CreateHeap(&(s->hp), array, size, Great);
	Print(s->hp);
	//堆顶元素（最大）和最后一个元素交换（最小），除去最后一个元素（因为已经是最大了），把前n-1个元素调整为大堆...循环，每次少调整一个元素
	int end = s->hp._size - 1;
	int hpsize = s->hp._size;
	while (s->hp._size)
	{
		s->hp._size -= 1;

		Swap(&(s->hp._hp[0]), &(s->hp._hp[s->hp._size]));
		//end--;
		//int root = (s->hp._hp[s->hp._size] - 2) >> 1;
		AdjustDown(&(s->hp), 0, Great);
	}
	s->hp._size = hpsize;
}

void SortHeapDown(Sort* s, HPDataType array, int size)//降序
{
	assert(s);
	//先建一个小堆
	CreateHeap(&(s->hp), array, size, Less);
	Print(s->hp);
	//将堆顶元素与最后一个元素交换，除了交换后的最后一个元素，将size-1个元素调整为小堆，size--再将堆顶元素与最后一个交换（倒数第二个）
	int end = s->hp._size - 1;
	int hpsize = s->hp._size;//因为hp->_size被改变了，Print函数还需要用size打印，所以先标记起来，最后赋给size
	while (end)
	{
		Swap(&(s->hp._hp[0]), &(s->hp._hp[end]));
		s->hp._size -= 1;
		AdjustDown(&s->hp, 0, Less);
		end--;
	}
	s->hp._size = hpsize;
}