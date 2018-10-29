#define _CRT_SECURE_NO_WARNINGS 1

#include"os.h"

_PCB* BuyNode1(_PCB* pcb)
{
	char i = 0;
	int j = 0;
	int k = 0;
	_PCB* newNode = (_PCB*)malloc(sizeof(_PCB));
	if (NULL == newNode)
		return NULL;
	else
	{
		setbuf(stdin, NULL);
		scanf("%c %d %d", &newNode->Name, &newNode->ArriveTime, &newNode->ServerTime);
		newNode->next = NULL;
		return newNode;
	}
}

void DestoryPcb(_PCB** pcb)
{
	_PCB* cur = NULL;
	_PCB* del = NULL;
	assert(pcb);
	if (NULL == (*pcb))
		return;
	cur = (*pcb);
	while (cur)
	{
		del = cur->next;
		free(cur);
		cur = del;
	}
	(*pcb) = NULL;
}

_PCB* BuyNode2(_PCB* pcb)
{
	char i = 0;
	int j = 0;
	int k = 0;
	_PCB* newNode = (_PCB*)malloc(sizeof(_PCB));
	if (NULL == newNode)
		return NULL;
	else
	{
		setbuf(stdin, NULL);
		scanf("%c %d %d %d", &newNode->Name, &newNode->ArriveTime, &newNode->ServerTime, &newNode->Front);
		newNode->next = NULL;
		return newNode;
	}
}

void PushFront1(_PCB** pcb)
{
	_PCB* cur = NULL;
	assert(pcb);
	if (*pcb == NULL)
	{
		(*pcb) = BuyNode1(*pcb);
		return;
	}
	else
	{
		cur = BuyNode1(*pcb);
		cur->next = (*pcb);
		(*pcb) = cur;
	}
}

void PushFront2(_PCB** pcb)
{
	_PCB* cur = NULL;
	assert(pcb);
	if (*pcb == NULL)
	{
		(*pcb) = BuyNode2(*pcb);
		return;
	}
	else
	{
		cur = BuyNode2(*pcb);
		cur->next = (*pcb);
		(*pcb) = cur;
	}
}

void InitPcb(_PCB** pcb)
{
	assert(pcb);
	if (NULL == (*pcb))
		return;
	(*pcb) = NULL;
}

void Screen()
{
	printf("**************************\n");
	printf("1. �����ȷ���\n");
	printf("2. ��̬���ȼ�����\n");
	printf("3. ʱ��Ƭ��ת����\n");
	printf("**************************\n");
}

void Input1(_PCB** pcb)
{
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		PushFront1(pcb);
	}
}

void Input2(_PCB** pcb)
{
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		PushFront2(pcb);
	}
}

void Print1(_PCB** pcb)
{
	_PCB* cur = NULL;
	cur = (*pcb);
	assert(pcb);
	if (NULL == (*pcb))
		return;
	printf("������\t����ʱ��\t����ʱ��\t��ʼִ��ʱ��\t���ʱ��\t��תʱ��\t��Ȩ��תʱ��\n");
	while (cur)
	{
		printf("%c\t%d\t%d\t%d\t%d\t%d\t%f\n", cur->Name, cur->ArriveTime, cur->ServerTime, cur->StartTime, cur->FinishTime, cur->WholeTime, cur->ValueWholeTime);
		cur = cur->next;
	}
}

void Print2(_PCB** pcb)
{
	_PCB* cur = NULL;
	cur = (*pcb);
	assert(pcb);
	if (NULL == (*pcb))
		return;
	printf("������\t����ʱ��\t����ʱ��\t���ȼ���\t��ʼִ��ʱ��\t���ʱ��\t��תʱ��\t��Ȩ��תʱ��\n");
	while (cur)
	{
		printf("%c\t%d\t%d\t%d\t%d\t%d\t%d\t%f\n", cur->Name, cur->ArriveTime, cur->ServerTime, cur->Ago, cur->StartTime, cur->FinishTime, cur->WholeTime, cur->ValueWholeTime);
		cur = cur->next;
	}
}

void Turn(_PCB** pcb)
{
	_PCB* cur = (*pcb);
	_PCB* pre = cur->next;
	_PCB* pb = pre->next;
	assert(pcb);
	if (NULL == pcb)
		return;
	cur->next = NULL;
	while (pre && pb)
	{
		pre->next = cur;
		cur = pre;
		pre = pb;
		pb = pb->next;
	}
	pre->next = cur;
	(*pcb) = pre;
}

void OrderServer(_PCB** pcb)
{
	_PCB* cur = NULL;
	_PCB* pre = NULL;//������¼ǰһ����㣬���㿪ʼִ��ʱ����Ҫ�õ�ǰһ��������Ϣ
	Turn(pcb);
	cur = pre = (*pcb);
	assert(pcb);
	int i = 0;//��¼��ǰ�ǵڼ�������
	if (NULL == (*pcb))
		return;
	while (cur)
	{
		if (0 == i || 1 == i)//˵���ǵ�һ��/�ڶ�������
		{
			if (0 == i)
			{
				cur->StartTime = cur->ArriveTime;
				i++;
			}
			else//�ǵڶ������̣���Ϊ�ڶ������̵�pre��ͷ��㣬���Բ���Ҫ�ƶ�����������
			{
				cur->StartTime = pre->FinishTime;
				i++;
			}
			cur->FinishTime = cur->ServerTime + cur->StartTime;
			cur->WholeTime = cur->FinishTime - cur->ArriveTime;
			cur->ValueWholeTime = (float)cur->WholeTime / (float)cur->ServerTime;
			cur = cur->next;
		}
		else
		{
			pre = pre->next;
			cur->StartTime = pre->FinishTime;
			cur->FinishTime = cur->ServerTime + cur->StartTime;
			cur->WholeTime = cur->FinishTime - cur->ArriveTime;
			cur->ValueWholeTime = (float)cur->WholeTime / (float)cur->ServerTime;
			cur = cur->next;
			i++;
		}
	}
}

_PCB* FindPcur(_PCB** pcb)
{
	_PCB* cur = NULL;
	assert(pcb);
	if (NULL == (*pcb))
		return NULL;
	cur = (*pcb);
	while (cur)
	{
		if (cur->Ago != 1)
			return cur;
		else
			cur = cur->next;
	}
}

void PriorityServer(_PCB** pcb)
{
	_PCB* cur = NULL;
	_PCB* pCur = NULL;//������¼û�����ʹ��Ľ��
	_PCB* pb = NULL;//������¼cur�ĺ�һ�����
	_PCB* pre = NULL;//������¼ǰһ����㣬���㿪ʼִ��ʱ����Ҫ�õ�ǰһ��������Ϣ
	int i = 0;//��¼��ǰ�ǵڼ�������
	assert(pcb);
	if (NULL == (*pcb))
		return;
	Turn(pcb);
	cur = pre = (*pcb);
	//pCur = FindPcur(pcb);
	while (i < MAX)
	{
		pCur = FindPcur(pcb);
		pb = cur->next;
		while (pb)
		{
			if (0 == i)//˵���ǵ�һ������
			{
				cur->StartTime = cur->ArriveTime;
				i++;
				cur->FinishTime = cur->ServerTime + cur->StartTime;
				cur->WholeTime = cur->FinishTime - cur->ArriveTime;
				cur->ValueWholeTime = (float)cur->WholeTime / (float)cur->ServerTime;
				cur->Ago = 1;//��ʾ��ǰ��㱻���ʹ���
				cur = pCur;
				//pb = cur->next;
			}
			//pb = cur->next;
		//	cur = cur->next;
			if (cur->Front > pb->Front && pb->Ago != 1)
			{
				cur = pb;
				pb = pb->next;
			}
			else
				pb = pb->next;
		}
		if (i == MAX - 1)
		{
			cur = pCur;
		}
		cur->StartTime = pre->FinishTime;
		cur->FinishTime = cur->ServerTime + cur->StartTime;
		cur->WholeTime = cur->FinishTime - cur->ArriveTime;
		cur->ValueWholeTime = (float)cur->WholeTime / (float)cur->ServerTime;
		cur->Ago = 1;
		pre = cur;
		cur = pCur;
		i++;
	}
}

void Server(int n, _PCB** pcb)
{
	switch (n)
	{
	case 1:
		printf("������\t����ʱ��\t����ʱ��\n");
		Input1(pcb);
		OrderServer(pcb);
		Print1(pcb);
		//DestoryPcb(pcb);
		break;
	case 2:
		printf("������\t����ʱ��\t����ʱ��\t������\n");
		Input2(pcb);
		PriorityServer(pcb);
		Print2(pcb);
		//DestoryPcb(pcb);
		break;
	//case 3:
	//	RotateServer();
	//	break;
	//default:
	//	printf("error");
	//	break;
	}
}