#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include<stdio.h>

void QuickSort(int* array, int left, int right);
//hoare�汾
int partion1(int* array, int left, int right);
//�ڿӷ�
int partion2(int* array, int left, int right);
//ǰ��ָ�뷨
int partion3(int* array, int left, int right);
//�Ż���
int partion_OP(int* array, int left, int right);
void Swap(int* left, int* right);
void Print(int* array, int size);


#endif //__QUICKSORT_H__