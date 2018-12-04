#define _CRT_SECURE_NO_WARNINGS 1

#include"DPAAR.h"

void Init() //���з������ĳ�ʼ��
{
	Node* p;
	p = (Node *)malloc(sizeof(Node));
	p->pre = &L;
	p->next = NULL;
	p->size = 512;
	p->address = 0;
	p->state = 0;
	L.next = p;
	L.pre = NULL;
	L.size = 0;
	u.next = NULL;
	n = &u;
}
Node *Search(int a)
{
	Node *p = L.next;
	if (p == NULL)
	{
		printf("û�п��е�����!\n");
		p = NULL;
		return p;
	}
	else
	{
		while (p != NULL && a>p->size)
			p = p->next;
		if (p == NULL)
		{
			printf("û���ҵ����ʵĿ��пռ�!");
			p = NULL;
			return p;
		}
		else
			return p;
	}
}
void Recovery(int a, int b) //�ڴ����
{
	Node *c, *s, *r = L.next;
	Node *d = L.next, *e;
	U *k = u.next, *h = n;
	while (k != NULL && a != k->num)
	{
		h = k;
		k = k->next;
	}
	if (k == NULL)
		printf("û���ҵ���������ҵ!");
	else
	{
		h->next = k->next;
		if (h->next == NULL)
			n = h;
	}
	while (r != NULL) //�����յõ��Ŀ��п��ǰ���п��п�ϲ��˿��п�
	{
		if (k->add == r->address + r->size)
		{
			r->size = r->size + k->size;
			break;
		}
		else
			r = r->next;
	}
	if (r == NULL) //�����յõ��Ŀ��п�ĺ����п��п�ϲ��˿��п�
	{
		r = L.next;
		while (r != NULL)
		{
			if (k->add + k->size == r->address)
			{
				r->address = k->add;
				r->size = r->size + k->size;
				break;
			}
			else
				r = r->next;
		}
	}
	while (d != NULL) //��֤����������û�����ڵĿ��пռ�
	{
		if (d->next != NULL)
			e = d->next;
		else
			break;
		if (d->address + d->size == e->address)
		{
			d->next = e->next;
			while (e->next != NULL)
				e->next->pre = d;
			d->size = d->size + e->size;
			free(e);
			break;
		}
		else
			d = d->next;
	}
	if (r == NULL)
	{
		r = L.next;
		c = (Node *)malloc(sizeof(Node));
		c->size = b;
		c->address = k->add;
		if (L.next == NULL)
		{
			c->next = L.next;
			c->pre = &L;
			L.next = c;
		}
		else
		{
			r = L.next;
			while (r != NULL)
			{
				if (r->address>c->address)
				{
					c->next = r;
					c->pre = r->pre;
					r->pre->next = c;
					r->pre = c;
					free(k);
					return;
				}
				else
					r = r->next;
			}
		}
	}
	free(k);
}
void Alloc(int a, int b) //�����ڴ�
{
	Node *p, *q = L.next;
	U *m;
	p = Search(b);
	if (p == NULL)
		return;
	m = (U *)malloc(sizeof(U));//����һ����ռ������Ľ�㲢���뵽�������β��
		m->add = p->address;
	m->size = b;
	m->num = a;
	m->next = n->next;
	n->next = m;
	n = m; //��֤ n ʼ��ָ��ռ�������β���������Ժ������ɽ��Ĳ���
	if (p->size>b) //�������ռ�Ĵ�СС���ҵ����пռ�Ĵ�С�Ĵ���
	{
		p->size = p->size - b;
		p->address = p->address + b;
	}
	else //�������ռ�Ĵ�С�����ҵ����пռ�Ĵ�С�Ĵ���
	{
		p->pre->next = p->next;
		if (p->pre != NULL)
			p->next->pre = p->pre;
		free(p);
	}
}
void Sort() //�Կ��������������
{
	int max;
	Node *p, *q = NULL, *r, *s;
	Node a;
	p = L.next;
	while (p != NULL) //��ָ�� q ָ����������һ�����
	{
		q = p;
		p = p->next;
	}
	if (L.next->next == NULL)
		return;
	else
	{
		while (p != q)
		{
			s = r = p = L.next;
			max = r->size;
			while (s != q->next)
			{
				if (s->size>max)
				{
					max = s->size;
					r = s;
					s = s->next;
				}
				else
					s = s->next;
			}
			a.size = q->size;
			a.address = q->address;
			q->size = r->size;
			q->address = r->address;
			r->size = a.size;
			r->address = a.address;
			if (q->pre->pre == &L)
				return;
			else
				q = q->pre;
		}
	}
}
void Print()
{
	Node *p = L.next;
	U *q = u.next;
	int i = 1;
	printf("\n ���������б�:\n");
	printf("*********************\n");
	printf("��ҵ�� ʼַ ��С\n");
	printf("*********************\n");
	while (p != NULL)
	{
		printf("%-5d", i);
		printf("%-5d", p->address);
		printf("%d\n", p->size);
		p = p->next;
		i++;
	}
	if (q == NULL)
		return;
	else
	{
		printf("\n �ѷ��������б�:\n");
		printf("��ҵ��\t ʼַ\t ��С\n");
		while (q != NULL)
		{
			printf("%d\t", q->num);
			printf("%d\t", q->add);
			printf("%d\n", q->size);
			q = q->next;
		}
	}
}
void FirstFit() //�״���Ӧ�㷨
{
	int a, b, i;
	Init();
	Print();
	while (1)
	{
		printf("\n1������ռ�\n");
		printf("2���ͷſռ�\n");
		printf("3���˳��״���Ӧ�㷨\n");
		printf("���������ѡ��:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
		{
				  printf("����������ռ����ҵ��:");
				  scanf("%d", &a);
				  printf("����������ռ�Ĵ�С:");
				  scanf("%d", &b);
				  Alloc(a, b);
				  Print();
				  break;
		}
		case 2:
		{
				  printf("�������ͷſռ����ҵ��:");
				  scanf("%d", &a);
				  printf("�������ͷſռ�Ĵ�С:");
				  scanf("%d", &b);
				  Recovery(a, b);
				  Print();
				  break;
		}
		case 3:
			printf("\n");
			return;
		}
	}
}
void BestFit()
{
	int a, b, i;
	Init();
	Print();
	while (1)
	{
		printf("\n1������ռ�\n");
		printf("2���ͷſռ�\n");
		printf("3���˳������Ӧ�㷨\n");
		printf("#########################\n");
		printf("���������ѡ��:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
		{
				  printf("����������ռ����ҵ��:");
				  scanf("%d", &a);
				  printf("����������ռ�Ĵ�С:");
				  scanf("%d", &b);
				  Alloc(a, b);
				  Sort();
				  Print();
				  break;
		}
		case 2:
		{
				  printf("�������ͷſռ����ҵ��:");
				  scanf("%d", &a);
				  printf("�������ͷſռ�Ĵ�С:");
				  scanf("%d", &b);
				  Recovery(a, b);
				  Sort();
				  Print();
				  break;
		}
		case 3:printf("\n"); return;
		}
	}
}