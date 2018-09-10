#define _CRT_SECURE_NO_WARNINGS 1

#include"HashImTable.h"

void InitHashTable(HT* pHT, int capacity, PDTInt pDTInt)
{
	assert(pHT);
	int i = 0;
	capacity = GetNextPrime(capacity);
	pHT->_ht = (HTElem*)malloc(capacity*sizeof(HTElem));
	if (NULL == pHT->_ht)
	{
		assert(0);
		return;
	}
	pHT->_capacity = capacity;
	for (i = 0; i < capacity; i++)
	{
		pHT->_ht->_state = EMPTY;
	}
	pHT->_size = 0;
	pHT->_total = 0;
	pHT->_PDTInt = pDTInt;
}

//哈希负载因子
void CheckCapacity(HT* pHT, HTDataType data)
{
	assert(pHT);
	int i = 0;
	int j = 0;
	HTElem* pNew = NULL;
	int hashAddr = 0;
	if (pHT->_total * 10 / pHT->_capacity >= 7)
	{
		int oldCapacity = pHT->_capacity;
		//1.开辟新空间
		int newCapacity = GetNextPrime(pHT->_capacity);
		pNew = (HTElem*)malloc(newCapacity * sizeof(HTElem));
		if (NULL == pNew)
		{
			assert(0);
			return;
		}
		//2.拷贝元素
		pHT->_capacity = newCapacity;
		for (i = 0; i < newCapacity; i++)
		{
			pNew[i]._state = EMPTY;
		}
		for (i = 0; i < oldCapacity; i++)
		{
			if (EXIST != pHT->_ht[i]._state)//不存在和删除了的不用拷贝
				continue;
			hashAddr = HashFun(pHT, pHT->_ht[i]._data);
			//2.找存储位置
			while (EMPTY != pHT->_ht[hashAddr]._state)
			{
				if (pHT->_ht[hashAddr]._state == EXIST)
					return 0;

				else
				{
					////线性探测
					//hashAddr++;
					////越界==超过newCapacity
					//if (hashAddr == newCapacity)
					//	hashAddr = 0;

					//二次探测
					j++;
					hashAddr = hashAddr + 2 * j + 1;
					if (hashAddr>newCapacity)
						hashAddr %= newCapacity;  //这次越界了就不能置0了，万一i很大了，2*i就大于newCapacity了，永远都不能进入哈希表中了，但取模又回到原来的位置了
				}
			}
			//3.插入元素
			pNew[hashAddr]._data = pHT->_ht[i]._data;
			pNew[hashAddr]._state = EXIST;
		}
		//释放旧空间
		free(pHT->_ht);
		pHT->_ht = pNew;
		pHT->_total = pHT->_size;
	}
}

int InsertHashTable(HT* pHT, HTDataType data)
{
	assert(pHT);
	int i = 0;
	int hashAddr = 0;
	//保证哈希表中有空间
	CheckCapacity(pHT, data);
	//1.计算哈希地址

	hashAddr = HashFun(pHT, data);
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
			if (hashAddr>pHT->_capacity)
				hashAddr %= pHT->_capacity;  //这次越界了就不能置0了，万一i很大了，2*i就大于MAX_SIZE了，永远都不能进入哈希表中了，但取模又回到原来的位置了
		}
	}
	//3.插入元素
	pHT->_ht[hashAddr]._data = data;
	pHT->_ht[hashAddr]._state = EXIST;
	pHT->_size++;
	pHT->_total++;
	return 1;
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


//要做以修改
int FindHashTable(HT* pHT, HTDataType data)
{
	int i = 0;
	assert(pHT);
	int hashAddr = HashFun(pHT, data);
	while (EMPTY != pHT->_ht[hashAddr]._state)
	{
		if (pHT->_ht[hashAddr]._state == EXIST && strcmp(data, pHT->_ht[hashAddr]._data) == 0)//判断两个字符串是否相等要用strcmp()
			return hashAddr;
		/*hashAddr++;
		if (hashAddr == pHT->_capacity)
		hashAddr = 0;*/
		i++;
		hashAddr = hashAddr + 2 * i + 1;
		if (hashAddr>pHT->_capacity)
			hashAddr %= pHT->_capacity;
	}
	return -1;
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

int HashFun(HT* pHT, HTDataType data)
{
	return pHT->_PDTInt(data) % pHT->_capacity;
}

void DestroyHashTable(HT* pHT)
{
	assert(pHT);
	free(pHT->_ht);
	pHT->_ht = NULL;
	pHT->_capacity = 0;
	pHT->_size = 0;
	pHT->_total = 0;
}

