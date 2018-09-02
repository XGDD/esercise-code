#include"Maze.h"

void PrintMaze(Maze* m)
{
	assert(m != NULL);
	int i = 0;
	int j = 0;
	for (i = 0; i < Row; i++)
	{
		for (j = 0; j < Col; j++)
		{
			printf("%d  ", m->_map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void InitMaze(Maze* m, int map[Row][Col])
{
	assert(m != NULL);
	int i = 0;
	int j = 0;
	for (i = 0; i < Row; i++)
	{
		for (j = 0; j < Col; j++)
		{
			m->_map[i][j] = map[i][j];
		}
	}
}

void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->top = 0;
}

void StackPush(Stack* ps, SDataType data)
{
	assert(ps != NULL);
	if (ps->top == MaxSize)
		return;
	else
	{
		ps->_arry[ps->top] = data;
		ps->top++;
	}
}

void StackPop(Stack* ps)
{
	assert(ps != NULL);
	if (ps->top)
		ps->top--;
}

int IsExit(Maze* m, Position pos, Position enter)
{
	if ((pos._x == 0 || pos._y == Row - 1) || (pos._y == 0 || pos._y == Col - 1) && (pos._x != enter._x || pos._y != enter._y))
	{
		return 1;
	}
	return 0;
}

int StackEmpty(Stack* ps)
{
	assert(ps != NULL);
	if (0 == ps->top)
		return 1;//栈空
	return 0;
}

SDataType StackTop(Stack* ps)
{
	assert(ps != NULL);
	return ps->_arry[ps->top - 1];
}

int IsValidEnter(Maze* m, Position enter)
{
	assert(m != NULL);
	if ((enter._x >= 0 || enter._x < Row) && (enter._y >= 0 || enter._y < Col))
	{
		return 1;
	}
	return 0;
}

int StackSize(Stack* ps)
{
	assert(ps != NULL);
	return ps->top;
}

int IsPass(Maze* m, Position cur, Position next)
{
	assert(m != NULL);
	if (m->_map[next._x][next._y] > m->_map[cur._x][cur._y] || m->_map[next._x][next._y] == 1)
		return 1;

	return 0;
}

void SaveshortPath(Stack* shortPath, Stack* Path)
{
	assert(Path);
	assert(shortPath);
	int i = 0;
	int size = 0;
	size = StackSize(Path);
	for (i = 0; i < size; i++)
	{
		shortPath->_arry[i] = Path->_arry[i];
	}
	shortPath->top = size;
}

void PassMaze(Maze* m, Position enter, Stack* shortPath)
{
	Stack Path;
	StackInit(&Path);
	assert(m != NULL);
	if (!IsValidEnter(m, enter))//如果入口不合法
	{
		printf("入口不合法！！！\n");
		return;
	}
	else
		_GetMazeshortPath(m, enter, enter, &Path, shortPath);
}

void _GetMazeshortPath(Maze* m, Position cur, Position enter, Stack* Path, Stack* shortPath)
{
	Position next;
	//判断是否为出口，若为出口，保存最短路径，Pop
	if (IsExit(m, cur, enter))
	{
		StackPush(Path, cur);
		if (StackSize(Path) < StackSize(shortPath) || StackEmpty(shortPath))
		{
			SaveshortPath(shortPath, Path);
		}
		StackPop(Path);
		//return;
	}
	if (StackEmpty(Path))
		m->_map[enter._x][enter._y] = 2;
	StackPush(Path, cur);

	//上
	next = cur;
	next._x -= 1;
	if (IsPass(m, cur, next))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;//标记
		_GetMazeshortPath(m, next, enter, Path, shortPath);
	}

	//左
	next = cur;
	next._y -= 1;
	if (IsPass(m, cur, next))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_GetMazeshortPath(m, next, enter, Path, shortPath);
	}


	//右
	next = cur;
	next._y += 1;
	if (IsPass(m, cur, next))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_GetMazeshortPath(m, next, enter, Path, shortPath);
	}

	//下
	next = cur;
	next._x += 1;
	if (IsPass(m, cur, next))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_GetMazeshortPath(m, next, enter, Path, shortPath);
	}

	//说明上步走错了
	StackPop(Path);
}