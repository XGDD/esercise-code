#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("*************************\n");
	printf("********1. play**********\n");
	printf("********0. error**********\n");
	printf("*************************\n");
}

void game()
{
	char arr[R+Ex][C+Ex] = { 0 };
	char ret = 0;
	is_Board(arr, R+Ex, C+Ex);
	display_Board(arr, R + Ex, C + Ex);
	while (1)
	{
		play_person(arr, R + Ex, C + Ex);
		display_Board(arr, R + Ex, C + Ex);
		ret = Judge(arr, R + Ex, C + Ex);
		if (ret != ' ')
		{
			break;
		}
		play_computer(arr, R + Ex, C + Ex);
		display_Board(arr, R + Ex, C + Ex);
		ret = Judge(arr, R + Ex, C + Ex);
		if (ret != ' ')
		{
			break;
		}
	}
		if (ret == 'X')
		{
			printf("��ϲ�㣬��Ӯ�ˣ�\n");
		}
		else if(ret == 'O')
		{
			printf("���ź��������ˣ�\n");
		}
		else if (ret == 'q')
		{
			printf("ƽ�֣�\n");
		}
		display_Board(arr, R + Ex, C + Ex);
}


int main()
{
	int num = 0;
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			//printf("��ʼ����Ϸ��\n");
			break;
		case 0:
			printf("�˳���Ϸ������\n");
			break;
		default:
			printf("enter data error!\n");
		}

	}while (num);
	return 0;
}