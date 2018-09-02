#include"Maze.h"

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

int IsValidEnter(Maze* m, Position enter)
{
	assert(m != NULL);
	if ((enter._x >= 0 || enter._x < Row) && (enter._y >= 0 || enter._y < Col))
	{
		return 1;
	}
	return 0;
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

void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->top = 0;
}

void StackPop(Stack* ps)
{
	assert(ps != NULL);
	if (ps->top)
		ps->top--;
}

int IsExit(Position pos, Position enter)
{
	if ((pos._x == 0 || pos._y == Row - 1) || (pos._y == 0 || pos._y == Col - 1) && (pos._x !=enter._x || pos._y !=enter._y))
	{
		return 1;
	}
	return 0;
}

int IsPass(Maze* m, Position pos)
{
	assert(m != NULL);
	if (1 == m->_map[pos._x][pos._y])
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

void PassMaze(Maze* m, Position enter)
{
	assert(m != NULL);
	if (!IsValidEnter(m, enter))//如果入口不合法
	{
		printf("入口不合法！！！\n");
		return;
	}
	else
	{
		Stack s;
		StackInit(&s);
		StackPush(&s, enter);
		while (!StackEmpty(&s))
		{
			Position pos;
			Position next;
			pos = StackTop(&s);
			m->_map[pos._x][pos._y] = 2;//将走过的路标记为2
			if (IsExit(pos, enter))
				return;
			else
			{
				//上
				next = pos;
				next._x -= 1;
				if (IsPass(m, next))
				{
					StackPush(&s, next);
					continue;
				}
				//左
				next = pos;
				next._y -= 1;
				if (IsPass(m, next))
				{
					StackPush(&s, next);
					continue;
				}
				//右
				next = pos;
				next._y += 1;
				if (IsPass(m, next))
				{
					StackPush(&s, next);
					continue;
				}
				//下
				next = pos;
				next._x += 1;
				if (IsPass(m, next))
				{
					StackPush(&s, next);
					continue;
				}
				m->_map[pos._x][pos._y] = 3;
				StackPop(&s);
			}
		}
	}
}