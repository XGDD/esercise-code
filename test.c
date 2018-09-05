#define _CRT_SECURE_NO_WARNINGS 1

#include"topK.h"

int main()
{
	topK t;
	HPDataType array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int k = 5;
	CreatetopK(&t, array, k, 9);
	Print((t.hp));
	return 0;
}