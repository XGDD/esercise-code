#define _CRT_SECURE_NO_WARNINGS 1
#include"os.h"

int main()
{
	int i;
	//char c = '0';
	_PCB* pcb;
	InitPcb(&pcb);
	Screen();
	printf("请输入你要选择的服务：");
	//while ((c == getchar()) != EOF && c != '\n');
	setbuf(stdin, NULL);
	scanf("%d", &i);
	//printf("%d\n", i);
	Server(i, &pcb);
	return 0;
}