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
	//��ֹ���ݶѻ�
	if (pHT->_size * 10 / MAX_SIZE > 7)
		return 0;

	//1.�����ϣ��ַ
	int hashAddr = HashFun(data);
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
			if (hashAddr>MAX_SIZE)
				hashAddr %= MAX_SIZE;  //���Խ���˾Ͳ�����0�ˣ���һi�ܴ��ˣ�2*i�ʹ���MAX_SIZE�ˣ���Զ�����ܽ����ϣ�����ˣ���ȡģ�ֻص�ԭ����λ����
		}
	}
	//3.����Ԫ��
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
	if (-1 != ret)//�ҵ�data��
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

int HashFun(HTDataType data)//���ϣ��ַ
{
	return data % MAX_SIZE;
}