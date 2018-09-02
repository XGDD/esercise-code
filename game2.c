#include "game2.h"

void init_board()//初始化两个雷阵
{
	int i = 0;
	int j = 0;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			show[i][j] = '*';
			mine[i][j] = '0';
		}
	}
}

void print_player()//打印玩家棋盘
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < R - 1; i++)
	{
		printf("%d ", i);//打印横标
	}
	printf("\n");
	for (i = 1; i < C - 2; i++)//打印竖标
	{
		printf("%d  ", i);
		for(j = 1; j < C - 1; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
	printf("10 ");//开始打印最后一行
	for (i = 1; i < R - 1; i++)
	{
		printf("%c ", show[10][i]);
	}
	printf("\n");
}

void print_mine()//打印设计者棋盘
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < R - 1; i++)
	{
		printf("%d ", i);//打印横标
	}
	printf("\n");
	for (i = 1; i < C - 2; i++)//打印竖标
	{
		printf("%d  ", i);
		for (j = 1; j < C - 1; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
	printf("10 ");//开始打印最后一行
	for (i = 1; i < R - 1; i++)
	{
		printf("%c ", mine[10][i]);
	}
	printf("\n");
}

void set_mine()//给设计者棋盘布雷
{
	int x = 0;
	int y = 0;
	int count = COUNT;//雷总数
	while (count)//雷布完后跳出循环
	{
		int x = rand() % 10 + 1;//产生1-10的随机数，在数组下标为1-10的范围内布雷
		int y = rand() % 10 + 1;//产生1-10的随机数，在数组下标为1-10的范围内布雷
		if (mine[x][y] == '0')//找不是雷的地方布雷
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int count_mine(int x, int y)//检测周围8个区域雷的个数
{
	int count = 0;
	if (mine[x - 1][y] == '1')
		count++;
	if (mine[x - 1][y - 1] == '1')
		count++;
	if (mine[x - 1][y + 1] == '1')
		count++;
	if (mine[x][y - 1] == '1')
		count++;
	if (mine[x][y + 1] == '1')
		count++;
	if (mine[x + 1][y - 1] == '1')
		count++;
	if (mine[x + 1][y] == '1')
		count++;
	if (mine[x + 1][y + 1] == '1')
		count++;
	return count;
}

void safe_mine()//避免第一次被雷炸死
{
	int x = 0;
	int y = 0;
	char ch = 0;
	int ret = 1;
	printf("输入坐标扫雷\n");
	while (1)
	{
		scanf("%d%d", &x, &y);//只能输入1-10，输入错误重新输入
		if (((x >= 1) && (x <= 10)) && ((y >= 1) && (y <= 10)))//判断坐标是否有误
		{
			if (mine[x][y] == '1')//第一次踩到雷后补救
			{
				mine[x][y] = '0';
				while (ret)//在其余有空的地方设置一个雷
				{
					int x1 = rand() % 10 + 1;
					int y1 = rand() % 10 + 1;
					if (mine[x1][y1] == '0'&&(x!=x1||y!=y1))//找不是雷的地方布雷
					{
						mine[x1][y1] = '1';
						ret--;
						break;
					}
				}break;//跳出此函数
				char ch = count_mine(x, y);
				open_mine(x, y);
			}
			if (mine[x][y] == '0')
			{
				char ch = count_mine(x, y);
				open_mine(x, y);
				break;
			}
		}
		else//坐标错误
		{
			printf("请重新输入坐标\n");
		}
	}
}

void open_mine(int x, int y)//坐标周围展开函数
{
	if (show[x][y] == '*' && ((x >= 1) && (x <= 10)) && ((y >= 1) && (y <= 10)))
	{
		if (count_mine(x, y) != 0)
		{
			show[x][y] = count_mine(x, y) + '0';
		}
		else 
		{
			show[x][y] = ' ';
			open_mine(x - 1, y);
			open_mine(x - 1, y - 1);
			open_mine(x - 1, y + 1);
			open_mine(x, y - 1);
			open_mine(x, y + 1);
			open_mine(x + 1, y - 1);
			open_mine(x + 1, y);
			open_mine(x + 1, y + 1);
		}
	}
	return;
}

int sweep_mine()//扫雷函数，踩到雷返回1，没有踩到雷返回0
{
	int x = 0;
	int y = 0;
	printf("请输入坐标扫雷\n");
	scanf("%d%d", &x, &y);//只能输入1-10
	if (((x >= 1) && (x <= 10)) && ((y >= 1) && (y <= 10)))
	{
		if (mine[x][y] == '0')//没踩到雷
		{
			open_mine(x, y);
			if (count_show() == COUNT)//判断剩余未知区域的个数，个数为雷数时玩家赢
			{
				print_mine();
				printf("恭喜你，你赢了\n");
				return 0;
			}
		}
		else if (mine[x][y] == '1')//踩到雷
		{
			return 1;
		}
	}
	else
	{
		printf("请重新输入：\n");
	}
	return 0;//没踩到雷
}

int count_show()//判断剩余未知区域的个数，个数为雷数时玩家赢
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= R - 2; i++)
	{
		for (j = 1; j <= C - 2; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}