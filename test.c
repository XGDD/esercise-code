#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

int main()
{
	int arr[] = { 2, 5, 1, 9, 3, 6, 8, 7, 0, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print(arr, size);
	printf("\n");
	//InsretSort(arr, size);
	//ShellSort(arr, size);
	//SelectSort(arr, size);
	//SelectSort_OP(arr, size);
	//HeapSort(arr, size);
	BubbleSort(arr, size);

	Print(arr, size);

	return 0;
}