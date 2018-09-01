#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void test()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	//PushBack(&seq, 1);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	//PushBack(&seq, 1);
	PrintSeqList(&seq);
	//BubbleSort(&seq);
	//SelectSort(&seq);
	//SelectSortOP(&seq);
	BinarySearch(&seq, 4);
	//BinarySearch_R(&seq, 0, 3, 2);
	int ret = 0;
	ret = BinarySearch(&seq, 4);
	PrintSeqList(&seq);
	printf("找到了，下标为:%d\n", ret);
	//Insert(&seq, 1, 5);
	//Erase(&seq, 2);
	//Remove(&seq, 2);
	//RemoveAll(&seq, 1);
	//int ret = Size(&seq);
	//printf("该顺序表的大小为:%d\n", ret);
	//PrintSeqList(&seq);
	/*int ret = Empty(&seq);
	if (ret == 1)
	{
		printf("顺序表为空\n");
	}
	else if (ret == 0)
	{
		printf("顺序表不为空\n");
	}*/
}

void PushFront_test()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	/*PopFront(&seq);
	PopFront(&seq);*/
	PrintSeqList(&seq);
	Find(&seq, 3);
}

int main()
{
	//test();
	test();

	return 0;
}