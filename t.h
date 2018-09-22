#ifndef __T_H__
#define __T_H__

#include<stdio.h>
#include"Stack.h"

void QuickSort(int* array, int left, int right);
//hoare°æ±¾
int partion1(int* array, int left, int right);
int partion_OP(int* array, int left, int right);
int GetMiddleIndex(int* array, int left, int right);
void Swap(int* left, int* right);
void Print(int* array, int size);

#endif //__T_H__