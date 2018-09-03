#define _CRT_SECURE_NO_WARNINGS 1

#include"Snake.h"

void test()
{
	Snake snake = { 0 };//创建贪吃蛇

	srand((unsigned int)time(NULL));
	//游戏开始
	GameStart(&snake);

	//游戏开始跑
	GameRun(&snake);

	//游戏结束
	GameEnd(&snake);
}

int main()
{
	test();
	system("pause");
  	return 0;
}