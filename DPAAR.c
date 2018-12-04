#define _CRT_SECURE_NO_WARNINGS 1

#include"DPAAR.h"

void Init() //空闲分区链的初始化
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
		printf("没有空闲的区域!\n");
		p = NULL;
		return p;
	}
	else
	{
		while (p != NULL && a>p->size)
			p = p->next;
		if (p == NULL)
		{
			printf("没有找到合适的空闲空间!");
			p = NULL;
			return p;
		}
		else
			return p;
	}
}
void Recovery(int a, int b) //内存回收
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
		printf("没有找到这样的作业!");
	else
	{
		h->next = k->next;
		if (h->next == NULL)
			n = h;
	}
	while (r != NULL) //若回收得到的空闲块的前方有空闲块合并此空闲块
	{
		if (k->add == r->address + r->size)
		{
			r->size = r->size + k->size;
			break;
		}
		else
			r = r->next;
	}
	if (r == NULL) //若回收得到的空闲块的后面有空闲块合并此空闲块
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
	while (d != NULL) //保证空闲链表中没有相邻的空闲空间
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
void Alloc(int a, int b) //分配内存
{
	Node *p, *q = L.next;
	U *m;
	p = Search(b);
	if (p == NULL)
		return;
	m = (U *)malloc(sizeof(U));//生成一个被占用链表的结点并插入到该链表的尾部
		m->add = p->address;
	m->size = b;
	m->num = a;
	m->next = n->next;
	n->next = m;
	n = m; //保证 n 始终指向被占用链表的尾部，方便以后新生成结点的插入
	if (p->size>b) //如果申请空间的大小小于找到空闲空间的大小的处理
	{
		p->size = p->size - b;
		p->address = p->address + b;
	}
	else //如果申请空间的大小等于找到空闲空间的大小的处理
	{
		p->pre->next = p->next;
		if (p->pre != NULL)
			p->next->pre = p->pre;
		free(p);
	}
}
void Sort() //对空闲链表进行排序
{
	int max;
	Node *p, *q = NULL, *r, *s;
	Node a;
	p = L.next;
	while (p != NULL) //让指针 q 指向链表的最后一个结点
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
	printf("\n 空闲区域列表:\n");
	printf("*********************\n");
	printf("作业号 始址 大小\n");
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
		printf("\n 已分配区域列表:\n");
		printf("作业号\t 始址\t 大小\n");
		while (q != NULL)
		{
			printf("%d\t", q->num);
			printf("%d\t", q->add);
			printf("%d\n", q->size);
			q = q->next;
		}
	}
}
void FirstFit() //首次适应算法
{
	int a, b, i;
	Init();
	Print();
	while (1)
	{
		printf("\n1、申请空间\n");
		printf("2、释放空间\n");
		printf("3、退出首次适应算法\n");
		printf("请输入你的选择:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
		{
				  printf("请输入申请空间的作业号:");
				  scanf("%d", &a);
				  printf("请输入申请空间的大小:");
				  scanf("%d", &b);
				  Alloc(a, b);
				  Print();
				  break;
		}
		case 2:
		{
				  printf("请输入释放空间的作业号:");
				  scanf("%d", &a);
				  printf("请输入释放空间的大小:");
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
		printf("\n1、申请空间\n");
		printf("2、释放空间\n");
		printf("3、退出最佳适应算法\n");
		printf("#########################\n");
		printf("请输入你的选择:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
		{
				  printf("请输入申请空间的作业号:");
				  scanf("%d", &a);
				  printf("请输入申请空间的大小:");
				  scanf("%d", &b);
				  Alloc(a, b);
				  Sort();
				  Print();
				  break;
		}
		case 2:
		{
				  printf("请输入释放空间的作业号:");
				  scanf("%d", &a);
				  printf("请输入释放空间的大小:");
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