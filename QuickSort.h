#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include<stdio.h>

void QuickSort(int* array, int left, int right);
//hoare版本
int partion1(int* array, int left, int right);
//挖坑法
int partion2(int* array, int left, int right);
//前后指针法
int partion3(int* array, int left, int right);
//优化版
int partion_OP(int* array, int left, int right);
void Swap(int* left, int* right);
void Print(int* array, int size);


#endif //__QUICKSORT_H__