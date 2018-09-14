#define _CRT_SECURE_NO_WARNINGS 1

#define PRIME_SIZE 28

unsigned long GetNextPrime(unsigned long prime);
//将任何形式的参数都转换为整型
unsigned long StrToINT(const char * str);

//默认的转换方式，如果传的是int型，那么我们就不需要转换
unsigned long StrToINT1(long data);
unsigned long StrToINT2(long data);
unsigned long StrToINT3(long data);
unsigned long StrToINT4(long data);
unsigned long StrToINT5(long data);