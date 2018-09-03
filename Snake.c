#define _CRT_SECURE_NO_WARNINGS 1

#include"Snake.h"

void SetPos(int x, int y)
{
	COORD pos = { 0 };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);//���ñ�׼����ϵĹ��λ��Ϊpos
}

void WelcomeToGame()
{
	//���ô��ڴ�С
	system("mode con cols=100 lines=30");

	SetPos(50, 15);//���ù�꣨���ƾ��λ�ã�
	printf("��ӭ����̰������Ϸ");
	SetPos(50, 28);
	system("pause");
	system("cls");

	SetPos(50, 15);
	printf("�á������������������ߵ��˶�����,F1Ϊ����,F2Ϊ����");
	SetPos(50, 16);
  	printf("��ܰ��ʾ�����ٵ÷ָ���Ŷ");
	SetPos(50, 29);
	system("pause");
	system("cls");
}

void CreateMap()
{
	int i = 0;
	//�ϱ߽�
	for (i = 0; i <= 58; i += 2)
	{
		SetPos(i, 0);
		printf(WALL);
	}

	//�±߽�
	for (i = 0; i <= 58; i += 2)
	{
		SetPos(i, 27);
		printf(WALL);
	}

	//��߽�
	for (i = 1; i < 27; i++)
	{
		SetPos(0, i);
		printf(WALL);
	}

	//�ұ߽�
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
		printf("�������ʧ��");
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
		cur->x = first->x + 2;//��Ϊ���Ϊ2
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
	//��֤ʳ������Ϸ�
	pfood->y = rand() % 26 + 1;
	do
	{
		pfood->x = rand() % 55 + 2;
	} while (pfood->x % 2 != 0);  //����ʳ�����겻���������У���Ϊʳ��ͱ߽�ͼ�δ�Сռ2�У���Ȼ����Զ�Բ���ʳ��

	//ʳ�ﲻ�ܳ�����������
	while (cur)
	{
		if (cur->x == pfood->x && cur->y == pfood->y)//���ʳ������������ϣ����Ǿ��ٵݹ���ú��������´���ʳ�� 
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
	//��ӡ��ӭ����
	WelcomeToGame();

	//������ͼ
	CreateMap();

	//��ʼ����
    InitSnake(ps);

	//����ʳ��
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
		if (GetAsyncKeyState(VK_SPACE))//�ٰ�һ�¿ո����������ͣ�����������ƶ�
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
	//��ӡ�����ӵĽ��
	SetPos(ps->_pSnake->x, ps->_pSnake->y);
	printf(FOOD);
	ps->_TotalScore += ps->_AddScore;
	//ʳ�ﱻ�Ե��ˣ�Ҫ����������һ��
	CreateFood(ps);
}

void NoFood(pSnake ps, pSnakeNode pn)
{
	pSnakeNode cur = NULL;
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	//��ӡ�����ӵĽ��
	SetPos(ps->_pSnake->x, ps->_pSnake->y);
	printf(FOOD);
	//����β���
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
	printf("��ǰ�ܷ�Ϊ��%d", ps->_TotalScore);
	SetPos(62, 12);
	printf("��ǰ�÷�Ϊ��%d", ps->_AddScore);
	SetPos(62, 13);
	printf("��ܰ��ʾ���á�������������");
	SetPos(62, 14);
	printf("�����ߵ��˶�����");
	SetPos(62, 15);
	printf("���ٵ÷ָ���Ŷ");
	SetPos(62, 16);
	printf("���ո���ͣ��Ϸ");
	SetPos(62, 17);
	printf("��ESC�˳���Ϸ");
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
			   //��ʳ��
			   if (NextIsFood(ps, pNext))
			   {
				   EatFood(ps, pNext);
			   }
			   else   //����ʳ��
				   NoFood(ps, pNext);
			   break;
	}
	case DOWN:
	{
				 pNext->x = ps->_pSnake->x;
				 pNext->y = ps->_pSnake->y + 1;
				 //��ʳ��
				 if (NextIsFood(ps, pNext))
				 {
					 EatFood(ps, pNext);
				 }
				 else   //����ʳ��
					 NoFood(ps, pNext);
				 break;
	}
	case LEFT:
	{
				 pNext->x = ps->_pSnake->x - 2;
				 pNext->y = ps->_pSnake->y;
				 //��ʳ��
				 if (NextIsFood(ps, pNext))
				 {
					 EatFood(ps, pNext);
				 }
				 else   //����ʳ��
					 NoFood(ps, pNext);
				 break;
	}
	case RIGHT:
	{
				  pNext->x = ps->_pSnake->x + 2;
				  pNext->y = ps->_pSnake->y;
				  //��ʳ��
				  if (NextIsFood(ps, pNext))
				  {
					  EatFood(ps, pNext);
				  }
				  else   //����ʳ��
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
	//ȷ������
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
		else if (GetAsyncKeyState(VK_SPACE))//�ո����ͣ��Ϸ
		{
			Pause();
		}
		else if (GetAsyncKeyState(VK_ESCAPE))//ESC�˳���Ϸ
		{
			ps->_Status = NORMAL_END;
			break;
		}
		else if (GetAsyncKeyState(VK_F1))//F1����
		{
			if (ps->_SleepTime >= 40)//Ӧ����һ�����ޣ����ps->SleepTime=0���Ͳ����ߣ�̫���ˣ�û�취����
			{
				ps->_SleepTime -= 20;//ÿ������ʱ�����20����(�ٶȼӿ�)
				ps->_AddScore += 2;//Խ��÷�Խ�ߣ�ÿ����ԭ���Ļ����ϼ�2
			}
		}
		else if (GetAsyncKeyState(VK_F2))//F2����
		{
			if (ps->_SleepTime <= 300)//_AddScore�ĳ�ʼֵ��10��û��һ�¼�2��ps->SleepTime(��ʼֵΪ100)��20����_SleepScore>200��_AddScore��ֵ�ͱ�Ϊ��ֵ�ˣ�������
			{
				ps->_SleepTime += 20;
				ps->_AddScore -= 2;
			}
			if (ps->_SleepTime > 300)
			{
				ps->_AddScore = 1;
			}
		}
		//�ߵ��ƶ�
		SnakeMove(ps);

		Sleep(ps->_SleepTime);//����ÿ�ƶ�һ��Ҫ��ͣ(�ƶ�����һ�㣬�����ۿ��Կ��������ƶ���Ҳ���ļ�������һ���ķ���)һ�£���Ȼ��һֱͣ������

		//��ǽײ��
		KillByWall(ps);

		//���Լ�ײ��
		KillBySelf(ps);

	} while (ps->_Status == OK);

}

void GameEnd(pSnake ps)
{
	SetPos(26, 14);
	if (ps->_Status == NORMAL_END)
	{
		printf("�����˳�");
	}
	if (ps->_Status == KILL_BY_WALL)
	{
		printf("��ѽ��ײǽ��");
	}
	if (ps->_Status == KILL_BY_SELF)
	{
		printf("������˼������ɱ��");
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