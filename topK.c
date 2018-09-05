#define _CRT_SECURE_NO_WARNINGS 1

#include"topK.h"


void CreatetopK(topK* t, HPDataType* array, int k, int size)
{
	assert(t);
	//��ǰK��Ԫ�ؽ���һ��С��
	CreateHeap(&(t->hp), array, k, Less);
	//��ʣ���N-K��Ԫ����Ѷ�Ԫ�رȽϣ����ȶѶ�Ԫ�ش���Ѷ�Ԫ�ؽ��������������ȶѶ�Ԫ��С����������Ԫ��
	
	while (k < size)
	{
		
		int root = (k - 1) >> 1;
		if (t->hp._hp[0] < array[k])
		{
			Swap(&(t->hp._hp[0]), &(array[k]));
			AdjustDown(&(t->hp), root, Less);
			k += 1;
		}
		else
			k += 1;
	}
}