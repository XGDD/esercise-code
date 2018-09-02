#include"Maze.h"

void test()
{
	Position enter;
	enter._x = 5;
	enter._y = 1;
	Maze m;
	Stack shortPath;
	StackInit(&shortPath);
	int map[Row][Col] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 0 },
	{ 0, 1, 1, 1, 1, 1 },
	{ 0, 1, 0, 0, 0, 0 } };
	InitMaze(&m, map);
	PrintMaze(&m);
	PassMaze(&m, enter, &shortPath);
	PrintMaze(&m);
}

int main()
{
	test();

	return 0;
}