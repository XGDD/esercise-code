#ifndef __OS_H__
#define __OS_H__
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 4

typedef struct PCB{
	char Name;//进程名
	int ArriveTime;//到达时间
	int ServerTime;//服务时间
	int Time;//时间片
	int Front;//优先级
	int StartTime;//开始执行时间
	int FinishTime;//完成时间
	int WholeTime;//周转时间
	float ValueWholeTime;//带权周转时间
	int Ago;//标记当前结点有没有被访问过
	struct PCB* next;
}_PCB;

void InitPcb(_PCB** pcb);//初始化
_PCB* BuyNode1(_PCB* pcb);
_PCB* BuyNode2(_PCB* pcb);
void PushFront1(_PCB** pcb);//头插
void PushFront2(_PCB** pcb);
void Screen();//界面
void Input1(_PCB** pcb);//输入函数
void Input2(_PCB** pcb);
void Print1(_PCB** pcb);//打印
void Print2(_PCB** pcb);
void Server(int n, _PCB** pcb);
void OrderServer(_PCB** pcb);//先来先服务
void PriorityServer(_PCB** pcb);//优先级服务
void RotateServer();//时间片轮转服务
void Turn(_PCB** pcb);//将链表翻转过来
_PCB* FindPcur(_PCB** pcb);
void DestoryPcb(_PCB** pcb);


#endif //__OS_H__