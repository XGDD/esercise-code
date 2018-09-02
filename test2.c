#define _CRT_SECURE_NO_WARNINGS 1

#include "game2.h"

void menu()
{
	printf("************************\n");
	printf("*******1.  play ********\n");
	printf("*******0.  exit ********\n");
	printf("************************\n");
}

void game()
{
	int x = 0;
	int y = 0;
	int ret = 0;
	init_board();//初始化棋盘
	set_mine();//给设计者棋盘布雷
	print_mine();//打印设计者棋盘
	print_player();//打印玩家棋盘
	safe_mine();//避免第一次被炸死
	if (count_show() == COUNT)//一步就赢的情况
	{
		print_mine();
		printf("恭喜你，你赢了\n");
		return;
	}print_player();//打印玩家棋盘
	while (1)//循环扫雷
	{
		int ret = sweep_mine();//扫雷，踩到雷返回1，没有踩到雷返回0
		if (count_show() == COUNT)
		{
			print_mine();//打印设计者数组
			printf("恭喜你，你赢了\n");
			break;
		}
		if (ret)//判断是否踩到雷
		{
			printf("很遗憾，你输了\n");
			print_mine();//打印设计者棋盘
			break;
		}print_player();//打印玩家棋盘
	}

}

int main()
{
	srand((unsigned int)time(NULL));//产生随机数生成器
	int num;
	do
	{
		menu();
		printf("请选择>\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			//printf("进行游戏\n");
			break;
		case 0:
			printf("推出游戏\n");
			break;
		default:
			printf("enter data error\n");
		}
	} while (num);

	return 0;
}