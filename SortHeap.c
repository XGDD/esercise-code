#define _CRT_SECURE_NO_WARNINGS 1

#include"SortHeap.h"

void SortHeapUp(Sort* s, HPDataType array, int size)
{
	assert(s);
	//�ȴ���һ�����
	CreateHeap(&(s->hp), array, size, Great);
	Print(s->hp);
	//�Ѷ�Ԫ�أ���󣩺����һ��Ԫ�ؽ�������С������ȥ���һ��Ԫ�أ���Ϊ�Ѿ�������ˣ�����ǰn-1��Ԫ�ص���Ϊ���...ѭ����ÿ���ٵ���һ��Ԫ��
	int end = s->hp._size - 1;
	int hpsize = s->hp._size;
	while (s->hp._size)
	{
		s->hp._size -= 1;

		Swap(&(s->hp._hp[0]), &(s->hp._hp[s->hp._size]));
		//end--;
		//int root = (s->hp._hp[s->hp._size] - 2) >> 1;
		AdjustDown(&(s->hp), 0, Great);
	}
	s->hp._size = hpsize;
}

void SortHeapDown(Sort* s, HPDataType array, int size)//����
{
	assert(s);
	//�Ƚ�һ��С��
	CreateHeap(&(s->hp), array, size, Less);
	Print(s->hp);
	//���Ѷ�Ԫ�������һ��Ԫ�ؽ��������˽���������һ��Ԫ�أ���size-1��Ԫ�ص���ΪС�ѣ�size--�ٽ��Ѷ�Ԫ�������һ�������������ڶ�����
	int end = s->hp._size - 1;
	int hpsize = s->hp._size;//��Ϊhp->_size���ı��ˣ�Print��������Ҫ��size��ӡ�������ȱ����������󸳸�size
	while (end)
	{
		Swap(&(s->hp._hp[0]), &(s->hp._hp[end]));
		s->hp._size -= 1;
		AdjustDown(&s->hp, 0, Less);
		end--;
	}
	s->hp._size = hpsize;
}