#ifndef __RPN_H__
#define __RPN_H__

#include<stdio.h>
#include<assert.h>

#define MaxSize 20
typedef int SDataType;

typedef struct Stack
{
	int top;
	SDataType arry[MaxSize];
}Stack;

typedef enum
{
	Add = 0,
	Sub,
	Mul,
	Div,
	Data
}OPERATOR;

typedef struct Cell
{
	OPERATOR _op;
	int data;
}Cell;


int CalcRPN(Cell* RPN, int size);
void StackPush(Stack* ps, SDataType data);
void StackPop(Stack* ps);
void StackInit(Stack* ps);


#endif //__RPN_H__