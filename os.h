#ifndef __OS_H__
#define __OS_H__
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 4

typedef struct PCB{
	char Name;//������
	int ArriveTime;//����ʱ��
	int ServerTime;//����ʱ��
	int Time;//ʱ��Ƭ
	int Front;//���ȼ�
	int StartTime;//��ʼִ��ʱ��
	int FinishTime;//���ʱ��
	int WholeTime;//��תʱ��
	float ValueWholeTime;//��Ȩ��תʱ��
	int Ago;//��ǵ�ǰ�����û�б����ʹ�
	struct PCB* next;
}_PCB;

void InitPcb(_PCB** pcb);//��ʼ��
_PCB* BuyNode1(_PCB* pcb);
_PCB* BuyNode2(_PCB* pcb);
void PushFront1(_PCB** pcb);//ͷ��
void PushFront2(_PCB** pcb);
void Screen();//����
void Input1(_PCB** pcb);//���뺯��
void Input2(_PCB** pcb);
void Print1(_PCB** pcb);//��ӡ
void Print2(_PCB** pcb);
void Server(int n, _PCB** pcb);
void OrderServer(_PCB** pcb);//�����ȷ���
void PriorityServer(_PCB** pcb);//���ȼ�����
void RotateServer();//ʱ��Ƭ��ת����
void Turn(_PCB** pcb);//������ת����
_PCB* FindPcur(_PCB** pcb);
void DestoryPcb(_PCB** pcb);


#endif //__OS_H__