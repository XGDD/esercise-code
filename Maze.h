#ifndef __MAZE_H__
#define __MAZE_H__

#include<assert.h>
#include<stdio.h>

#define MaxSize 20
#define Row 6
#define Col 6

typedef struct Position
{
	int _x;
	int _y;
}Position;

typedef Position SDataType;

typedef struct Stack
{
	int top;
	SDataType _arry[MaxSize];
}Stack;

typedef struct Maze
{
	int _map[Row][Col];
}Maze;

void PassMaze(Maze* m, Position enter);
void InitMaze(Maze* m, int map[Row][Col]);
void PrintMaze(Maze* m);
int IsValidEnter(Maze* m, Position enter);//是否为入口
void StackPush(Stack* ps, SDataType data);
void StackInit(Stack* ps);
void StackPop(Stack* ps);
int IsExit(Position pos, Position enter);//是否为出口
int IsPass(Maze* m, Position pos);
int StackEmpty(Stack* ps);
SDataType StackTop(Stack* ps);//返回栈顶元素

#endif //__MAZE_H__