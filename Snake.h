#ifndef __SNAKE_H__
#define __SNAKE_H__

#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<assert.h>
#include<malloc.h>

#define WALL "◆"
#define FOOD "●"
#define INIT_X 20
#define INIT_Y 10

enum Direction
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};

enum GameStatus
{
	OK,
	NORMAL_END,//正常结束
	KILL_BY_WALL,
	KILL_BY_SELF
};

typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode,*pSnakeNode;

typedef struct Snake
{
	pSnakeNode _pSnake;//维护蛇身
	pSnakeNode _pFood;//维护食物
	int _TotalScore;//总分数
	int _AddScore;//增加的分数
	int _SleepTime;//休眠的时间
	enum Direction _Dir;
	enum GameStatus _Status;
}Snake,*pSnake;

void GameStart(pSnake ps);
void WelcomeToGame();
void SetPos(int x, int y);
void CreateMap();
void InitSnake(pSnake ps);
pSnakeNode BuyNode();
void CreateFood(pSnake ps);
void GameRun(pSnake ps);
void Pause();
void SnakeMove(pSnake ps);
int NextIsFood(pSnake ps, pSnakeNode pn);
void EatFood(pSnake ps, pSnakeNode pn);
void NoFood(pSnake ps, pSnakeNode pn);
void KillByWall(pSnake ps);
void KillBySelf(pSnake ps);
void PrintHelpIafo(pSnake ps);
void GameEnd(pSnake ps);

#endif //__SNAKE_H__