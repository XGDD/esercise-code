#ifndef __SHAREDSTACK_H__
#define __SHAREDSTACK_H__

#include<stdio.h>
#include<assert.h>

typedef int SDataType;

#define MaxSize 10

typedef struct SharedStack
{
	SDataType arry[MaxSize];
	int top1;
	int top2;
}SharedStack;

void SharedStackInit(SharedStack* ps);
void SharedStackPush(SharedStack* ps, SDataType data, int which);
void SharedStackPop(SharedStack* ps, int which);
int SharedStackSize(SharedStack* ps);

#endif //__SHAREDSTACK_H__