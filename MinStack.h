#ifndef __STACKTOMIN_H__
#define __STACKTOMIN_H__

#define MaxSize 10

#include<stdio.h>
#include<assert.h>
#include "Stack.h"


typedef struct MinStack
{
	Stack _data;
	Stack _min;
}MinStack;

void MinStackInit(MinStack* s);
void MinStackPush(MinStack* s, SDataType data);
void MinStackPop(MinStack* s);
SDataType MinStackTop(MinStack* s);
SDataType MinStackMin(MinStack* s);
int MainSatckSize(MinStack* s);
int IsEmpty(MinStack* s);


#endif //__STACKTOMIN_H__