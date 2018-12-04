#define _CRT_SECURE_NO_WARNINGS 1

#include"DPAAR.h"

void main()
{
	int i;
	while (1)
	{
		printf("**************************\n");
		printf("1、首次适应算法\n");
		printf("2、最佳适应算法\n");
		printf("3、退出\n");
		printf("**************************\n");
		printf("请选择要进行的操作\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			FirstFit(); 
			break;
		case 2:
			BestFit(); 
			break;
		case 3:
			return;
		}
	}
}