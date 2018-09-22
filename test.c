#define _CRT_SECURE_NO_WARNINGS 1

#include"MergeSort.h"

int main()
{
	int array[] = { 4, 0, 3, 5, 9, 7, 6, 1, 2, 8 };
	int size = sizeof(array) / sizeof(array[0]);
	MergeSort(array, size);
	Print(array, size);
	return 0;
}