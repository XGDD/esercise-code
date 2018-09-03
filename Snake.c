#define _CRT_SECURE_NO_WARNINGS 1

#include"Snake.h"

void SetPos(int x, int y)
{
	COORD pos = { 0 };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);//设置标准输出上的光标位置为pos
}

void WelcomeToGame()
{
	//设置窗口大小
	system("mode con cols=100 lines=30");

	SetPos(50, 15);//设置光标（控制句柄位置）
	printf("欢迎进入贪吃蛇游戏");
	SetPos(50, 28);
	system("pause");
	system("cls");

	SetPos(50, 15);
	printf("用↑，↓，←，→控制蛇的运动方向,F1为加速,F2为减速");
	SetPos(50, 16);
  	printf("温馨提示：加速得分更多哦");
	SetPos(50, 29);
	system("pause");
	system("cls");
}

void CreateMap()
{
	int i = 0;
	//上边界
	for (i = 0; i <= 58; i += 2)
	{
		SetPos(i, 0);
		printf(WALL);
	}

	//下边界
	for (i = 0; i <= 58; i += 2)
	{
		SetPos(i, 27);
		printf(WALL);
	}

	//左边界
	for (i = 1; i < 27; i++)
	{
		SetPos(0, i);
		printf(WALL);
	}

	//右边界
	for (i = 1; i < 27; i++)
	{
		SetPos(58, i);
		printf(WALL);
	}
}

pSnakeNode BuyNode()
{
	pSnakeNode cur;
	cur = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (NULL == cur)
	{
		printf("创建结点失败");
		return NULL;
	}
	cur->next = NULL;
	cur->x = 0;
	cur->y = 0;
	return cur;
}

void InitSnake(pSnake ps)
{
	assert(ps);
	int i = 0;
	pSnakeNode first = BuyNode();
	pSnakeNode cur = NULL;
	first->x = INIT_X;
	first->y = INIT_Y;
	for (i = 0; i < 4; i++)
	{
		cur = BuyNode();
		cur->x = first->x + 2;//因为宽度为2
		cur->y = first->y;
		cur->next = first;
		first = cur;
	}
	while (cur)
	{
		SetPos(cur->x, cur->y);
		printf(FOOD);
		cur = cur->next;
	}
	//printf("\n");
	ps->_pSnake = first;
//	system("pause");
}

void CreateFood(pSnake ps)
{
	assert(ps);
	pSnakeNode cur = ps->_pSnake;
	pSnakeNode pfood = BuyNode();
	//保证食物坐标合法
	pfood->y = rand() % 26 + 1;
	do
	{
		pfood->x = rand() % 55 + 2;
	} while (pfood->x % 2 != 0);  //并且食物坐标不能在奇数列，因为食物和边界图形大小占2列，不然蛇永远吃不到食物

	//食物不能出现在蛇身上
	while (cur)
	{
		if (cur->x == pfood->x && cur->y == pfood->y)//如果食物出现在蛇身上，我们就再递归调用函数，重新创建食物 
		{
			CreateFood(ps);
			return;
		}
		cur = cur->next;
	}
	ps->_pFood = pfood;
	SetPos(pfood->x, pfood->y);
	printf(FOOD);
	//system("pause");
}

void GameStart(pSnake ps)
{
	assert(ps);
	//打印欢迎界面
	WelcomeToGame();

	//创建地图
	CreateMap();

	//初始化蛇
    InitSnake(ps);

	//创建食物
	CreateFood(ps);

	ps->_AddScore = 10;
	ps->_TotalScore = 0;
	ps->_SleepTime = 200;
	ps->_Dir = RIGHT;
	ps->_Status = OK;
}

void Pause()
{
	while (1)
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_SPACE))//再按一下空格键，跳出暂停函数，继续移动
		{
			break;
		}
	}
}

int NextIsFood(pSnake ps, pSnakeNode pn)
{
	if ((ps->_pFood->x == pn->x) && (ps->_pFood->y == pn->y))
	{
		return 1;
	}
	return 0;
}

void EatFood(pSnake ps, pSnakeNode pn)
{
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	//打印新增加的结点
	SetPos(ps->_pSnake->x, ps->_pSnake->y);
	printf(FOOD);
	ps->_TotalScore += ps->_AddScore;
	//食物被吃掉了，要再重新生成一个
	CreateFood(ps);
}

void NoFood(pSnake ps, pSnakeNode pn)
{
	pSnakeNode cur = NULL;
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	//打印新增加的结点
	SetPos(ps->_pSnake->x, ps->_pSnake->y);
	printf(FOOD);
	//处理尾结点
	cur = ps->_pSnake;
	while (cur->next->next)
	{
		cur = cur->next;
	}
	SetPos(cur->next->x, cur->next->y);
	printf(" ");
	free(cur->next);
	cur->next = NULL;
}

void PrintHelpIafo(pSnake ps)
{
	SetPos(62, 11);
	printf("当前总分为：%d", ps->_TotalScore);
	SetPos(62, 12);
	printf("当前得分为：%d", ps->_AddScore);
	SetPos(62, 13);
	printf("温馨提示：用↑，↓，←，→");
	SetPos(62, 14);
	printf("控制蛇的运动方向");
	SetPos(62, 15);
	printf("加速得分更多哦");
	SetPos(62, 16);
	printf("按空格暂停游戏");
	SetPos(62, 17);
	printf("按ESC退出游戏");
}

void SnakeMove(pSnake ps)
{
	PrintHelpIafo(ps);
	pSnakeNode pNext = BuyNode();
	switch (ps->_Dir)
	{
	case UP:
	{
			   pNext->x = ps->_pSnake->x;
			   pNext->y = ps->_pSnake->y - 1;
			   //是食物
			   if (NextIsFood(ps, pNext))
			   {
				   EatFood(ps, pNext);
			   }
			   else   //不是食物
				   NoFood(ps, pNext);
			   break;
	}
	case DOWN:
	{
				 pNext->x = ps->_pSnake->x;
				 pNext->y = ps->_pSnake->y + 1;
				 //是食物
				 if (NextIsFood(ps, pNext))
				 {
					 EatFood(ps, pNext);
				 }
				 else   //不是食物
					 NoFood(ps, pNext);
				 break;
	}
	case LEFT:
	{
				 pNext->x = ps->_pSnake->x - 2;
				 pNext->y = ps->_pSnake->y;
				 //是食物
				 if (NextIsFood(ps, pNext))
				 {
					 EatFood(ps, pNext);
				 }
				 else   //不是食物
					 NoFood(ps, pNext);
				 break;
	}
	case RIGHT:
	{
				  pNext->x = ps->_pSnake->x + 2;
				  pNext->y = ps->_pSnake->y;
				  //是食物
				  if (NextIsFood(ps, pNext))
				  {
					  EatFood(ps, pNext);
				  }
				  else   //不是食物
					  NoFood(ps, pNext);
				  break;
	}
	}
}

void KillByWall(pSnake ps)
{
	if ((ps->_pSnake->x == 0) || (ps->_pSnake->x == 58) || (ps->_pSnake->y == 0) || (ps->_pSnake->y == 27))
		ps->_Status = KILL_BY_WALL;
}

void KillBySelf(pSnake ps)
{
	pSnakeNode pNext = ps->_pSnake->next;
	while (pNext)
	{
		if ((ps->_pSnake->x == pNext->x) && (ps->_pSnake ->y == pNext->y))
		{
			ps->_Status = KILL_BY_SELF;
		}
		pNext = pNext->next;
	}
}

void GameRun(pSnake ps)
{
	//确定方向
	do
	{
		if (GetAsyncKeyState(VK_UP) && ps->_Dir != DOWN)
		{
			ps->_Dir = UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && ps->_Dir != UP)
		{
			ps->_Dir = DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) && ps->_Dir != RIGHT)
		{
			ps->_Dir = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && ps->_Dir != LEFT)
		{
			ps->_Dir = RIGHT;
		}
		else if (GetAsyncKeyState(VK_SPACE))//空格键暂停游戏
		{
			Pause();
		}
		else if (GetAsyncKeyState(VK_ESCAPE))//ESC退出游戏
		{
			ps->_Status = NORMAL_END;
			break;
		}
		else if (GetAsyncKeyState(VK_F1))//F1加速
		{
			if (ps->_SleepTime >= 40)//应该有一个极限，如果ps->SleepTime=0，就不休眠，太快了，没办法控制
			{
				ps->_SleepTime -= 20;//每次休眠时间减少20毫秒(速度加快)
				ps->_AddScore += 2;//越快得分越高，每次在原来的基础上加2
			}
		}
		else if (GetAsyncKeyState(VK_F2))//F2减速
		{
			if (ps->_SleepTime <= 300)//_AddScore的初始值是10，没慢一下减2，ps->SleepTime(初始值为100)加20，若_SleepScore>200，_AddScore的值就变为负值了，不合理
			{
				ps->_SleepTime += 20;
				ps->_AddScore -= 2;
			}
			if (ps->_SleepTime > 300)
			{
				ps->_AddScore = 1;
			}
		}
		//蛇的移动
		SnakeMove(ps);

		Sleep(ps->_SleepTime);//在蛇每移动一下要暂停(移动的慢一点，让肉眼可以看清它的移动，也来的急控制下一步的方向)一下，不然会一直停不下来

		//被墙撞死
		KillByWall(ps);

		//被自己撞死
		KillBySelf(ps);

	} while (ps->_Status == OK);

}

void GameEnd(pSnake ps)
{
	SetPos(26, 14);
	if (ps->_Status == NORMAL_END)
	{
		printf("正常退出");
	}
	if (ps->_Status == KILL_BY_WALL)
	{
		printf("哎呀，撞墙了");
	}
	if (ps->_Status == KILL_BY_SELF)
	{
		printf("不好意思，你自杀了");
	}
	SetPos(80, 27);
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode Del = NULL;
		Del = cur;
		cur = cur->next;
		free(Del);
		Del = NULL;
	}
	ps->_pSnake = NULL;
	free(ps->_pFood);
	ps->_pFood = NULL;
}