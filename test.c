#define _CRT_SECURE_NO_WARNINGS 1

#include"t.h"

int main()
{
	//int array[] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 5 };
	int array[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int size = sizeof(array) / sizeof(array[0]);
	QuickSort(array, 0, size);
	Print(array, size);
	return 0;
}