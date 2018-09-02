#ifndef __MATCHBRACKETS_H__
#define __MATCHBRACKETS_H__

#include<stdio.h>
#include<assert.h>
#include<string.h>

#define MaxSize 20

typedef char SDataType;
typedef struct Stack
{
	int top;
	SDataType _arry[MaxSize];
}Stack;

void MatchBrackets(Stack* ps, int sz);
int IsBrackets(char arry[], int i);
int StackSize(Stack* ps);
void StackPush(Stack* ps, SDataType data, char arry[]);
void StackPop(Stack* ps);
int StackEmpty(Stack* ps);
void StackInit(Stack* ps);



#endif //__MATCHBRACKETS_H__