#define _CRT_SECURE_NO_WARNINGS 1

#include"DPAAR.h"

void main()
{
	int i;
	while (1)
	{
		printf("**************************\n");
		printf("1���״���Ӧ�㷨\n");
		printf("2�������Ӧ�㷨\n");
		printf("3���˳�\n");
		printf("**************************\n");
		printf("��ѡ��Ҫ���еĲ���\n");
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