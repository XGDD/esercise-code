#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void is_Board(char arr[R+Ex][C+Ex], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < R + Ex; i++)
	{
		for (j = 0; j < C + Ex; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void display_Board(char arr[R + Ex][C + Ex], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < R + Ex; i++)
	{
		for (j = 0; j < C + Ex; j++)
		{
			printf("_%c_|", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void play_person(char arr[R + Ex][C + Ex], int r, int c)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("请选择要走哪：\n");
		scanf("%d %d", &i, &j);
		i--;   //因为数组下标是从0开始
		j--;
		if ((i >= 0 && i <= R + Ex - 1) && (j >= 0 && j <= C + Ex - 1))    //判断输入坐标是否合法
		{
			if (arr[i][j] == ' ')
			{
				arr[i][j] = 'X';
				break;
			}
			else
			{
				printf("输入错误,请重新输入!\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入!\n");
		}
	}
	
}

void play_computer(char arr[R + Ex][C + Ex], int r, int c)
{
	srand((unsigned int)time(NULL));     //生成随机数
	while (1)
	{
		int x = rand() % (R + Ex);     //使生成的随机数在坐标范围内
		int y = rand() % (C + Ex);
		if (arr[x][y] == ' ')
		{
			arr[x][y] = 'O';
			break;
		}
		
	}
}

int full(char arr[R + Ex][C + Ex], int r, int c)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < R + Ex; i++)
	{
		for (j = 0; j < C + Ex; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

int is_all_equal_without_blank(char arr[R + Ex])   
{
	char empty = arr[0];
	for (int i = 1; i < R + Ex; i++)
	{
		if (empty != arr[i] || empty == ' ')    //empty == ' '是为了防止全为空的情况
		{
			return 0;
		}
		else
		{
			empty = arr[i];
		}
	}
	return 1;
}

char Judge(char arr[R + Ex][C + Ex], int r, int c)
{
	int i;
	int j;
	char tmp[R + Ex];
	//判断行相等
	for (i = 0; i < R + Ex; i++)
	{
		for (j = 0; j < C + Ex; j++)
		{
			tmp[j] = arr[i][j];
		}
		if (is_all_equal_without_blank(tmp))
		{
			return tmp[0];
		}
	}
	//判断列相等
	for (j = 0; j < C + Ex; j++)
	{
		for (i = 0; i < R + Ex; i++)
		{
			tmp[i] = arr[i][j];
		}
		if (is_all_equal_without_blank(tmp))
		{
			return tmp[0];
		}
	}
	//判断正交
	for (i = 0; i < R + Ex; i++)
	{
		tmp[i] = arr[i][i];
	}
	if (is_all_equal_without_blank(tmp))
	{
		return tmp[0];
	}
	//判断反交
	for (i = 0; i < R + Ex; i++)
	{
		tmp[i] = arr[i][C + Ex - i - 1];
		if (is_all_equal_without_blank(tmp))
		{
			return tmp[0];
		}
	}
	//判断平局
	if (full(arr , R+Ex, C+Ex))
	{
		return 'q';
	}

	return ' ';
}