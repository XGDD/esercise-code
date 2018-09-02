#include"Maze.h"

void test()
{
	Maze m;
	Position enter;
	enter._x = 5;
	enter._y = 2;
	int map[Row][Col] = { { 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 } };
	InitMaze(&m, map);
	PrintMaze(&m);
	PassMaze(&m, enter);
	PrintMaze(&m);
}

int main()
{
	test();

	return 0;
}