#define _CRT_SECURE_NO_WARNINGS 1
#include"os.h"

int main()
{
	int i;
	//char c = '0';
	_PCB* pcb;
	InitPcb(&pcb);
	Screen();
	printf("��������Ҫѡ��ķ���");
	//while ((c == getchar()) != EOF && c != '\n');
	setbuf(stdin, NULL);
	scanf("%d", &i);
	//printf("%d\n", i);
	Server(i, &pcb);
	return 0;
}