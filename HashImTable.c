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

//��ϣ��������
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
		//1.�����¿ռ�
		int newCapacity = GetNextPrime(pHT->_capacity);
		pNew = (HTElem*)malloc(newCapacity * sizeof(HTElem));
		if (NULL == pNew)
		{
			assert(0);
			return;
		}
		//2.����Ԫ��
		pHT->_capacity = newCapacity;
		for (i = 0; i < newCapacity; i++)
		{
			pNew[i]._state = EMPTY;
		}
		for (i = 0; i < oldCapacity; i++)
		{
			if (EXIST != pHT->_ht[i]._state)//�����ں�ɾ���˵Ĳ��ÿ���
				continue;
			hashAddr = HashFun(pHT, pHT->_ht[i]._data);
			//2.�Ҵ洢λ��
			while (EMPTY != pHT->_ht[hashAddr]._state)
			{
				if (pHT->_ht[hashAddr]._state == EXIST)
					return 0;

				else
				{
					////����̽��
					//hashAddr++;
					////Խ��==����newCapacity
					//if (hashAddr == newCapacity)
					//	hashAddr = 0;

					//����̽��
					j++;
					hashAddr = hashAddr + 2 * j + 1;
					if (hashAddr>newCapacity)
						hashAddr %= newCapacity;  //���Խ���˾Ͳ�����0�ˣ���һi�ܴ��ˣ�2*i�ʹ���newCapacity�ˣ���Զ�����ܽ����ϣ�����ˣ���ȡģ�ֻص�ԭ����λ����
				}
			}
			//3.����Ԫ��
			pNew[hashAddr]._data = pHT->_ht[i]._data;
			pNew[hashAddr]._state = EXIST;
		}
		//�ͷžɿռ�
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
	//��֤��ϣ�����пռ�
	CheckCapacity(pHT, data);
	//1.�����ϣ��ַ

	hashAddr = HashFun(pHT, data);
	//2.�Ҵ洢λ��
	while (EMPTY != pHT->_ht[hashAddr]._state)
	{
		if (pHT->_ht[hashAddr]._state == EXIST && data == pHT->_ht[hashAddr]._data)
			return 0;

		else
		{
			////����̽��
			//hashAddr++;
			////Խ��==����MAX_SIZE
			//if (hashAddr == MAX_SIZE)
			//	hashAddr = 0;

			//����̽��
			i++;
			hashAddr = hashAddr + 2 * i + 1;
			if (hashAddr>pHT->_capacity)
				hashAddr %= pHT->_capacity;  //���Խ���˾Ͳ�����0�ˣ���һi�ܴ��ˣ�2*i�ʹ���MAX_SIZE�ˣ���Զ�����ܽ����ϣ�����ˣ���ȡģ�ֻص�ԭ����λ����
		}
	}
	//3.����Ԫ��
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
	if (-1 != ret)//�ҵ�data��
	{
		pHT->_ht[ret]._state = DELETE;
		pHT->_size -= 1;
		return 1;
	}
	return 0;
}


//Ҫ�����޸�
int FindHashTable(HT* pHT, HTDataType data)
{
	int i = 0;
	assert(pHT);
	int hashAddr = HashFun(pHT, data);
	while (EMPTY != pHT->_ht[hashAddr]._state)
	{
		if (pHT->_ht[hashAddr]._state == EXIST && strcmp(data, pHT->_ht[hashAddr]._data) == 0)//�ж������ַ����Ƿ����Ҫ��strcmp()
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

