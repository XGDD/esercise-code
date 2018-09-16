#ifndef __SORT_H__
#define __SORT_H__

#include<stdio.h>

//÷±Ω”≤Â»Î≈≈–Ú
void InsretSort(int arr[], int size);
//œ£∂˚≈≈–Ú
void ShellSort(int arr[], int size);
//—°‘Ò≈≈–Ú
void SelectSort(int arr[], int size);
void SelectSort_OP(int arr[], int size);
void Swap(int* left, int* right);
//∂—≈≈–Ú
void HeapSort(int arr[], int size);
void HeapAdjust(int arr[], int size, int root);
//√∞≈›≈≈–Ú
void BubbleSort(int arr[], int size);


void Print(int arr[], int size);

#endif //__SORT_H__