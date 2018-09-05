#ifndef __TOPK_H__
#define __TOPK_H__

#include"Heap.h"

typedef struct topK
{
	Heap hp;
}topK;

void CreatetopK(topK* t, HPDataType* array, int k, int size);

#endif //__TOPK_H__