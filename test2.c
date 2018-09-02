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
	init_board();//��ʼ������
	set_mine();//����������̲���
	print_mine();//��ӡ���������
	print_player();//��ӡ�������
	safe_mine();//�����һ�α�ը��
	if (count_show() == COUNT)//һ����Ӯ�����
	{
		print_mine();
		printf("��ϲ�㣬��Ӯ��\n");
		return;
	}print_player();//��ӡ�������
	while (1)//ѭ��ɨ��
	{
		int ret = sweep_mine();//ɨ�ף��ȵ��׷���1��û�вȵ��׷���0
		if (count_show() == COUNT)
		{
			print_mine();//��ӡ���������
			printf("��ϲ�㣬��Ӯ��\n");
			break;
		}
		if (ret)//�ж��Ƿ�ȵ���
		{
			printf("���ź���������\n");
			print_mine();//��ӡ���������
			break;
		}print_player();//��ӡ�������
	}

}

int main()
{
	srand((unsigned int)time(NULL));//���������������
	int num;
	do
	{
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			//printf("������Ϸ\n");
			break;
		case 0:
			printf("�Ƴ���Ϸ\n");
			break;
		default:
			printf("enter data error\n");
		}
	} while (num);

	return 0;
}