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
		printf("��ѡ��Ҫ���ģ�\n");
		scanf("%d %d", &i, &j);
		i--;   //��Ϊ�����±��Ǵ�0��ʼ
		j--;
		if ((i >= 0 && i <= R + Ex - 1) && (j >= 0 && j <= C + Ex - 1))    //�ж����������Ƿ�Ϸ�
		{
			if (arr[i][j] == ' ')
			{
				arr[i][j] = 'X';
				break;
			}
			else
			{
				printf("�������,����������!\n");
			}
		}
		else
		{
			printf("�����������������!\n");
		}
	}
	
}

void play_computer(char arr[R + Ex][C + Ex], int r, int c)
{
	srand((unsigned int)time(NULL));     //���������
	while (1)
	{
		int x = rand() % (R + Ex);     //ʹ���ɵ�����������귶Χ��
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
		if (empty != arr[i] || empty == ' ')    //empty == ' '��Ϊ�˷�ֹȫΪ�յ����
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
	//�ж������
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
	//�ж������
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
	//�ж�����
	for (i = 0; i < R + Ex; i++)
	{
		tmp[i] = arr[i][i];
	}
	if (is_all_equal_without_blank(tmp))
	{
		return tmp[0];
	}
	//�жϷ���
	for (i = 0; i < R + Ex; i++)
	{
		tmp[i] = arr[i][C + Ex - i - 1];
		if (is_all_equal_without_blank(tmp))
		{
			return tmp[0];
		}
	}
	//�ж�ƽ��
	if (full(arr , R+Ex, C+Ex))
	{
		return 'q';
	}

	return ' ';
}