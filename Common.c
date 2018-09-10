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

unsigned long StrToINT(const char * str)
{
	unsigned int seed = 131;//31,131,1313,13131,131313
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash*seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

unsigned long DefToINT(long data)
{
	return data;
}