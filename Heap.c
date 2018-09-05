#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

void InitHeap(Heap* hp)
{
	assert(hp);
	hp->_compare = Less;
	hp->_capacity = 3;
	hp->_hp = (HPDataType*)malloc(hp->_capacity * (sizeof(HPDataType)));
	if (NULL == hp->_hp)
	{
		assert(0);
		return;
	}
	hp->_size = 0;
}

void Swap(HPDataType** left, HPDataType** right)
{
	HPDataType* tmp = *left;
	*left = *right;
	*right = tmp;
}

int Great(HPDataType left, HPDataType right)
{
	return left > right;
}

int Less(HPDataType left, HPDataType right)
{
	return left < right;
}

void AdjustDown(Heap* hp, int root, Compare compare)
{
	int child = (root << 1) + 1;//child标记最小的孩子，默认是左孩子
	while (child < hp->_size)
	{
		if (child + 1 < hp->_size && compare(hp->_hp[child + 1], hp->_hp[child]))
		{
			child += 1;
		}
		//检测root是否比最小的孩子大
		if (compare(hp->_hp[child], hp->_hp[root]))
		{
			Swap(&hp->_hp[root], &hp->_hp[child]);
			root = child;
			child = (root << 1) + 1;
		}
		else
			return;//本身就满足堆的性质
	}
}

void CreateHeap(Heap* hp, HPDataType* array, int size, Compare compare)
{
	assert(hp);
	int root = (size - 2) >> 1;//找到最下边的一个堆的堆顶
	hp->_hp = malloc(size*(sizeof(HPDataType)));
	if (NULL == hp->_hp)
	{
		printf("初始化失败\n");
		return;
	}
	memcpy(hp->_hp, array, size*sizeof(HPDataType));
	hp->_size = size;
	hp->_capacity = size;
	for (; root >= 0; root--)
	{
		AdjustDown(hp, root, compare);
	}
}

void Print(Heap hp)
{
	int i = 0;
	for (i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._hp[i]);
	}
	printf("\n");
}

Heap* CheckHeap(Heap* hp)
{
	assert(hp);
	HPDataType tmp;
	if (hp->_capacity == hp->_size)//说明堆满了，需要再开辟空间
	{
	    tmp = malloc((2 * hp->_size + 3)*sizeof(HPDataType));
		if (NULL == tmp)
		{
			assert(0);
			return;
		}
		memcpy(tmp, hp->_hp , hp->_size*sizeof(HPDataType));
		free(hp->_hp);
		hp->_hp = tmp;
		hp->_capacity = 2 * hp->_size + 3;
		return hp;
	}
	return hp;
}

void AdjustUp(Heap* hp, Compare compare)
{
	assert(hp);
	int child = hp->_size - 1;
	int root = (hp->_size - 2) >> 1;
	while (root >= 0)
	{
		if (child + 1 < hp->_size && compare(hp->_hp[child + 1], hp->_hp[child]))
			child += 1;
		if (compare(hp->_hp[child], hp->_hp[root]))
		{
			Swap(&hp->_hp[child], &hp->_hp[root]);
			child = root;
			root = (child - 1) >> 1;
		}
		else
		{
			return;
		}
	}
}

void InsertHeap(Heap* hp, HPDataType data, Compare compare)
{
	//将元素放入堆中(最后位置)
	hp = CheckHeap(hp);//检测堆的空间是否足够，若不够，要扩充

	hp->_hp[hp->_size++] = data;
	//对堆进行调整(向上调整)
	AdjustUp(hp, compare);
}

void RemoveHeap(Heap* hp, Compare compare)//删除堆顶元素
{
	int end = hp->_size - 1;
	assert(hp);
	//将堆顶元素与最后一个元素交换
	Swap(&hp->_hp[0], &hp->_hp[end]);
	//删除最后一个元素==size-1
	hp->_size--;
	int root = (hp->_size - 1) >> 1;
	//向下调整堆顶元素
	while (root >= 0)
	{
		AdjustDown(hp, root, compare);
		root--;
	}
}

int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int EmptyHeap(Heap* hp)
{
	assert(hp);
	if (0 == hp->_size)
		return 1;
	return 0;
}

HPDataType TopHeap(Heap* hp)
{
	return hp->_hp[0];
}

void DestoryHeap(Heap* hp)
{
	assert(hp);
	free(hp->_hp);
	hp->_hp = NULL;
	hp->_capacity = 0;
	hp->_compare = NULL;
	hp->_size = 0;
}