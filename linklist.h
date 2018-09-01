#ifndef __LINKLIST_H__ 
#define __LINKLIST_H__ 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, List, *pList;

void InitLinkList(pList* pplist);
pNode BuyNode(DataType d);
void DestroyLinkList(pList* pplist);
void PushBack(pList* pplist, DataType d);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType d);
void PopFront(pList* pplist);
pNode Find(pList plist, DataType d);
pNode FindTail(pList plist);
pNode FindHead(pList plist);

//在指定位置之前插入一个值 
void Insert(pList* pplist, pNode pos, DataType d);
//指定位置删除 
void Erase(pList* pplist, pNode pos);
void Remove(pList* pplist, DataType d);
void RemoveAll(pList* pplist, DataType d);
void EraseNotTailNode(pNode pos);
void PrintLinkList(pList plist);
int GetListLength(pList plist);

//链表面试题 

//1. 逆序打印单项链表 
void PrintTailToHead(pList plist);
//2.删一个无头单链表的非尾节点（不能遍历链表）
void EraseNotTailNode(pList* pplist, pNode pos);
//3.在无头单链表的一个节点前插入一个节点（不能遍历链表）
void InsertPosFront(pNode pos,DataType d);
//4.单链表实现约瑟夫环
pNode JosephCircle(pList plist, int m);
//5.单链表排序（冒泡排序）
void BubbleSort(pList plist);
//6.查找单链表的中间节点，要求只能遍历一次链表
pNode FindMiddleNode(pList plist);
//7.查找单链表的倒数第K个节点，要求只能遍历一次链表
pNode FindLastKNode(pList plist, int k);
//8.逆置/反转单链表
void ReverseList(pList* pplist);
pNode ReverseListOP(pList plist);
//9.合并两个有序链表，合并后依然有序
pNode MergeList(pNode pHead1, pNode pHead2);
//10.删除链表的倒数第K个结点
void EraseTailK(pList *pplist, int k, pNode pos);
//11.判断单链表是否带环？若带环，求环的长度？求环的入口点？
pNode HastListCircle(pList plist);//是否带环
int CircleLength(pList pMeetNode);//环的长度
pNode EnterNode(pList pHead, pList pMeetNode);//环的入口点
//12.判断两个链表是否相交，若相交，求交点(假设链表不带环)
pNode IsCrossList(pList plist1, pList plist2);//判断是否相交
pNode CrossNode(pList plist1, pList plist2);//求交点
//13.判断两个链表是否相交，若相交，求交点(假设链表可能带环)
pNode IsCrossNodeCircle(pList plist1, pList plist2);//判断是否相交
pNode CrossNodeCircle(pList plist1, pList plist2);//求交点


#endif //__LINKLIST_H__ 