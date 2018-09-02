#include "game2.h"

void init_board()//��ʼ����������
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

void print_player()//��ӡ�������
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < R - 1; i++)
	{
		printf("%d ", i);//��ӡ���
	}
	printf("\n");
	for (i = 1; i < C - 2; i++)//��ӡ����
	{
		printf("%d  ", i);
		for(j = 1; j < C - 1; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
	printf("10 ");//��ʼ��ӡ���һ��
	for (i = 1; i < R - 1; i++)
	{
		printf("%c ", show[10][i]);
	}
	printf("\n");
}

void print_mine()//��ӡ���������
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < R - 1; i++)
	{
		printf("%d ", i);//��ӡ���
	}
	printf("\n");
	for (i = 1; i < C - 2; i++)//��ӡ����
	{
		printf("%d  ", i);
		for (j = 1; j < C - 1; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
	printf("10 ");//��ʼ��ӡ���һ��
	for (i = 1; i < R - 1; i++)
	{
		printf("%c ", mine[10][i]);
	}
	printf("\n");
}

void set_mine()//����������̲���
{
	int x = 0;
	int y = 0;
	int count = COUNT;//������
	while (count)//�ײ��������ѭ��
	{
		int x = rand() % 10 + 1;//����1-10����������������±�Ϊ1-10�ķ�Χ�ڲ���
		int y = rand() % 10 + 1;//����1-10����������������±�Ϊ1-10�ķ�Χ�ڲ���
		if (mine[x][y] == '0')//�Ҳ����׵ĵط�����
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int count_mine(int x, int y)//�����Χ8�������׵ĸ���
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

void safe_mine()//�����һ�α���ը��
{
	int x = 0;
	int y = 0;
	char ch = 0;
	int ret = 1;
	printf("��������ɨ��\n");
	while (1)
	{
		scanf("%d%d", &x, &y);//ֻ������1-10�����������������
		if (((x >= 1) && (x <= 10)) && ((y >= 1) && (y <= 10)))//�ж������Ƿ�����
		{
			if (mine[x][y] == '1')//��һ�βȵ��׺󲹾�
			{
				mine[x][y] = '0';
				while (ret)//�������пյĵط�����һ����
				{
					int x1 = rand() % 10 + 1;
					int y1 = rand() % 10 + 1;
					if (mine[x1][y1] == '0'&&(x!=x1||y!=y1))//�Ҳ����׵ĵط�����
					{
						mine[x1][y1] = '1';
						ret--;
						break;
					}
				}break;//�����˺���
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
		else//�������
		{
			printf("��������������\n");
		}
	}
}

void open_mine(int x, int y)//������Χչ������
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

int sweep_mine()//ɨ�׺������ȵ��׷���1��û�вȵ��׷���0
{
	int x = 0;
	int y = 0;
	printf("����������ɨ��\n");
	scanf("%d%d", &x, &y);//ֻ������1-10
	if (((x >= 1) && (x <= 10)) && ((y >= 1) && (y <= 10)))
	{
		if (mine[x][y] == '0')//û�ȵ���
		{
			open_mine(x, y);
			if (count_show() == COUNT)//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
			{
				print_mine();
				printf("��ϲ�㣬��Ӯ��\n");
				return 0;
			}
		}
		else if (mine[x][y] == '1')//�ȵ���
		{
			return 1;
		}
	}
	else
	{
		printf("���������룺\n");
	}
	return 0;//û�ȵ���
}

int count_show()//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
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