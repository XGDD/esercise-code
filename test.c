#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

int main()
{
	Heap hp;
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	CreateHeap(&hp, array, 9, Less);
	InsertHeap(&hp, 5, Less);
	RemoveHeap(&hp, Less);
	Print(hp);
	DestoryHeap(&hp);
	Print(hp);
	//int ret = EmptyHeap(&hp);
	////printf("%d\n", ret);
	//if (1 == ret)
	//{
	//	printf("¶Ñ¿Õ\n");
	//}
	//else
	//{
	//	printf("¶Ñ²»¿Õ\n");

	//}
	return 0;
}