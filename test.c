#define _CRT_SECURE_NO_WARNINGS 1

#include"Snake.h"

void test()
{
	Snake snake = { 0 };//����̰����

	srand((unsigned int)time(NULL));
	//��Ϸ��ʼ
	GameStart(&snake);

	//��Ϸ��ʼ��
	GameRun(&snake);

	//��Ϸ����
	GameEnd(&snake);
}

int main()
{
	test();
	system("pause");
  	return 0;
}