#ifndef __MAZE_H__
#define __MAZE_H__

#include<stdio.h>
#include<assert.h>

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
	SDataType _arry[MaxSize];
	int top;
}Stack;

typedef struct Maze
{
	int _map[Row][Col];
}Maze;

void PrintMaze(Maze* m);
void InitMaze(Maze* m, int map[Row][Col]);
void PassMaze(Maze* m, Position enter, Stack* shortPath);
void StackInit(Stack* ps);
void StackPush(Stack* ps, SDataType data);
void StackPop(Stack* ps);
int IsExit(Maze* m, Position pos, Position enter);
int StackEmpty(Stack* ps);
SDataType StackTop(Stack* ps);
int IsValidEnter(Maze* m, Position enter);
int StackSize(Stack* ps);
int IsPass(Maze* m, Position cur, Position next);
void _GetMazeshortPath(Maze* m, Position cur, Position enter, Stack* Path, Stack* shortPath);
void SaveshortPath(Stack* Path, Stack* shortPath);

#endif //__MAZE_H__