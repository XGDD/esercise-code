#define _CRT_SECURE_NO_WARNINGS 1

#include"SortHeap.h"

int main()
{
	Sort s;
	HPDataType array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	SortHeapDown(&s, array, 9);
	Print(s.hp);

	return 0;
}