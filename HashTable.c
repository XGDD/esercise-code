#define _CRT_SECURE_NO_WARNINGS 1

#include"HashTable.h"

void InitHashTable(HT* pHT)
{
	assert(pHT);
	int i = 0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		pHT->_ht[i]._state = EMPTY;
	}
	pHT->_size = 0;
}

int InsertHashTable(HT* pHT, HTDataType data)
{
	int i = 0;
	assert(pHT);
	//防止数据堆积
	if (pHT->_size * 10 / MAX_SIZE > 7)
		return 0;

	//1.计算哈希地址
	int hashAddr = HashFun(data);
	//2.找存储位置
	while (EMPTY != pHT->_ht[hashAddr]._state)
	{
		if (pHT->_ht[hashAddr]._state == EXIST && data == pHT->_ht[hashAddr]._data)
			return 0;

		else
		{
			////线性探测
			//hashAddr++;
			////越界==超过MAX_SIZE
			//if (hashAddr == MAX_SIZE)
			//	hashAddr = 0;

			//二次探测
			i++;
			hashAddr = hashAddr + 2 * i + 1;
			if (hashAddr>MAX_SIZE)
				hashAddr %= MAX_SIZE;  //这次越界了就不能置0了，万一i很大了，2*i就大于MAX_SIZE了，永远都不能进入哈希表中了，但取模又回到原来的位置了
		}
	}
	//3.插入元素
	pHT->_ht[hashAddr]._data = data;
	pHT->_ht[hashAddr]._state = EXIST;
	pHT->_size++;
}

int FindHashTable(HT* pHT, HTDataType data)
{
	int i = 0;
	assert(pHT);
	int hashAddr = HashFun(data);
	while (EMPTY != pHT->_ht[hashAddr]._state)
	{
		if (pHT->_ht[hashAddr]._state == EXIST && data == pHT->_ht[hashAddr]._data)
			return hashAddr;
		/*hashAddr++;
		if (hashAddr == MAX_SIZE)
			hashAddr = 0;*/
		i++;
		hashAddr = hashAddr + 2 * i + 1;
		if (hashAddr>MAX_SIZE)
			hashAddr %= MAX_SIZE;
	}
	return -1;
}

int DeleteHashTable(HT* pHT, HTDataType data)
{
	assert(pHT);
	int ret = FindHashTable(pHT, data);
	if (-1 != ret)//找到data了
	{
		pHT->_ht[ret]._state = DELETE;
		pHT->_size -= 1;
		return 1;
	}
	return 0;
}

int EmptyHashTable(HT* pHT)
{
	if (pHT == NULL)
		return 0;
	return 0 == pHT->_size;
}

int SizeHashTable(HT* pHT)
{
	if (NULL == pHT)
		return 0;
	return pHT->_size;
}

int HashFun(HTDataType data)//求哈希地址
{
	return data % MAX_SIZE;
}