#include"Common.h"

unsigned long GetNextPrime(unsigned long prime)
{
	static unsigned long _PrimeList[PRIME_SIZE] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 39324ul, 786433ul,
		1572869ul, 3145739ul, 6291459ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	int i = 0;
	for (; i < PRIME_SIZE; i++)
	{
		if (_PrimeList[i]>prime)
			return _PrimeList[i];
	}
}

unsigned long StrToINT1(const char * str)
{
	unsigned int seed = 131;//31,131,1313,13131,131313
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash*seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

unsigned long StrToINT2(const char *str)
{
	if (!*str)   // 这是由本人添加，以保证空字符串返回哈希值0  
		return 0;
	int hash = 5381;
	int ch = 0;
	while (ch = (int)*str++)
	{
		hash = hash * 33 ^ ch;
	}
	return hash;
}

/// @brief SDBM Hash Function  
/// @detail 本算法是由于在开源项目SDBM（一种简单的数据库引擎）中被应用而得名，它与BKDRHash思想一致，只是种子不同而已。  

unsigned long StrToINT3(const char *str)
{
	int hash = 0;
	int ch = 0;
	while (ch = (int)*str++)
	{
		hash = 65599 * hash + ch;
		//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
	}
	return hash;
}
/// @brief RS Hash Function  
/// @detail 因Robert Sedgwicks在其《Algorithms in C》一书中展示而得名。  

unsigned long StrToINT4(const char *str)
{
	int hash = 0;
	int magic = 63689;
	int ch = 0;
	while (ch = (int)*str++)
	{
		hash = hash * magic + ch;
		magic *= 378551;
	}
	return hash;
}
/// @brief AP Hash Function  
/// @detail 由Arash Partow发明的一种hash算法。  

unsigned long StrToINT5(const char *str)
{
	int hash = 0;
	int ch;
	for (long i = 0; ch = (int)*str++; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		}
	}
	return hash;
}

