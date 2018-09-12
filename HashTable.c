#define _CRT_SECURE_NO_WARNINGS 1

#include"HashTable.h"

void InitHashTable(HashBucket* pHB, int capacity, PDTInt pDTInt)
{
	assert(pHB);
	pHB->_capacity = capacity;
	pHB->_table = (pNode*)malloc(capacity * sizeof(pNode));
	int i = 0;
	for (i = 0; i < capacity; i++)
	{
		pHB->_table[i] = NULL;
	}
	pHB->_pDTInt = pDTInt;
	pHB->_size = 0;
}

pNode BuyNode(HBDataType data)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->_data = data;
	newNode->_pNext = NULL;
	return newNode;
}

void CheckCapacity(HashBucket* pHB)
{
	assert(pHB);
	int oldCapacity = pHB->_capacity;
	int i = 0;
	int hashAddr = 0;
	pNode pCur = NULL;
	//当有效元素个数=哈希桶数，需要增容（最佳：每个桶挂一个结点）
	if (pHB->_size == pHB->_capacity)
	{
		int newCapacity = GetNextPrime(pHB->_capacity);
		pHB->_capacity = newCapacity;
		pNode* pNewTable = (pNode*)malloc(sizeof(pNode)*newCapacity);
		//初始化新哈希表
		memset(pNewTable, 0, sizeof(pNode)* newCapacity);
		//把旧哈希表中的数据重新散列到新哈希表中
		for (i = 0; i < oldCapacity; i++)
		{
			pCur = pHB->_table[i];
			while (pCur)
			{
				hashAddr = HashFun(pHB, pCur->_data);
				//将pCur从原链表中删除
				pHB->_table[i] = pCur->_pNext;
				//将pCur插入新链表
				pCur->_pNext = pNewTable[hashAddr];
				pNewTable[hashAddr] = pCur;
				//取原链表中下一个结点
				pCur = pHB->_table[i];
			}
		}
		free(pHB->_table);
		pHB->_table = pNewTable;
	}
}

int InsertHashTable(HashBucket* pHB, HBDataType data)
{
	assert(pHB);
	pNode pCur = NULL;
	CheckCapacity(pHB);
	int bucketNo = 0;
	bucketNo = HashFun(pHB, data);
	pCur = pHB->_table[bucketNo];
	//找到要插入的位置
	while (pCur)
	{
		if (data == pHB->_table[bucketNo])
			return 0;
		pCur = pCur->_pNext;
	}
	//插入元素，头插法
	pCur = BuyNode(data);
	pCur->_pNext = pHB->_table[bucketNo];
	pHB->_table[bucketNo] = pCur;
	pHB->_size++;
	return 1;
}

int DeleteHashTable(HashBucket* pHB, HBDataType data)
{
	assert(pHB);
	int bucketNo = HashFun(pHB, data);
	pNode pCur = pHB->_table[bucketNo];
	pNode pPre = NULL;
	while (pCur)
	{
		if (data == pCur->_data)
		{
			//删除的是第一个结点
			if (data == pHB->_table[bucketNo]->_data)
				pHB->_table[bucketNo] = pCur->_pNext;
			else
				pPre->_pNext = pCur->_pNext;
			free(pCur);
			return 1;
		}
		pPre = pCur;
		pCur = pCur->_pNext;
	}
	return 0;
}

int HashFun(HashBucket* pHB, HBDataType data)
{
	return pHB->_pDTInt(data) % pHB->_capacity;
}

int FindHashTable(HashBucket* pHB, HBDataType data)
{
	assert(pHB);
	pNode pCur = NULL;
	int bucketNo = HashFun(pHB, data);
	pCur = pHB->_table[bucketNo];
	while (pCur)
	{
		if (data == pCur->_data)//找到了返回1
		{
			return 1;
		}
		pCur = pCur->_pNext;
	}
	return 0;
}

int SizeHashTable(HashBucket* pHB)
{
	assert(pHB);
	return pHB->_size;
}

int EmptyHashTable(HashBucket* pHB)
{
	assert(pHB);
	return 0 == pHB->_size;//1为真，0为假
}
void DestroyHashTable(HashBucket* pHB)
{
	assert(pHB);
	int i = 0;
	pNode pDel = NULL;
	for (; i < pHB->_capacity; i++)
	{
		pDel = pHB->_table[i];
		while (pDel)
		{
			pHB->_table[i] = pDel->_pNext;
			free(pDel);
			pDel = pHB->_table[i];
			pHB->_size--;
		}
	}
}

void Print(HashBucket* pHB)
{
	assert(pHB);
	int i = 0;
	pNode pCur = NULL;
	for (; i < pHB->_capacity; i++)
	{
		printf("pHB->_table[%d]:", i);
		pCur = pHB->_table[i];
		while (pCur)
		{
			printf("%d--->", pCur->_data);
			pCur = pCur->_pNext;
		}
		printf("\n");
	}
}
