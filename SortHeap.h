#ifndef __SORTHEAP_H__
#define __SORTHEAP_H__

#include"Heap.h"

typedef struct Sort
{
	Heap hp;
}Sort;

void SortHeapUp(Sort* s, HPDataType array, int size);
void SortHeapDown(Sort* s, HPDataType array, int size);

#endif //__SORTHEAP_H__