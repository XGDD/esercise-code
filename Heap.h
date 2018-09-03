#ifndef __HEAP_H__
#define __HEAP_H__

#include<stdio.h>
#include<assert.h>

typedef int HPDataType;
typedef int(*Compare)(HPDataType left, HPDataType right);
typedef struct Heap
{
	HPDataType* _hp;
	int _capacity;
	int _size;
	Compare _compare;//一个函数指针，用来表示创建大堆还是小堆
}Heap;

void InitHeap(Heap* hp);
void Swap(HPDataType** left, HPDataType** right);
void AdjustDown(Heap* hp, int root, Compare compare);
void AdjustDown(Heap* hp, int root, Compare compare);
void AdjustUp(Heap* hp, int root, Compare compare);
void CreateHeap(Heap* hp, HPDataType* array, int size, Compare compare);
void Print(Heap hp);
int Great(HPDataType left, HPDataType right);
int Less(HPDataType left, HPDataType right);
void InsertHeap(Heap* hp, HPDataType data, Compare compare);
Heap* CheckHeap(Heap* hp);
void RemoveHeap(Heap* hp, Compare compare);
int SizeHeap(Heap* hp);
int EmptyHeap(Heap* hp);
HPDataType TopHeap(Heap* hp);
void DestoryHeap(Heap* hp);

#endif //__HEAP_H__