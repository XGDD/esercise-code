#ifndef __SORT_H__
#define __SORT_H__

#include<stdio.h>

//ֱ�Ӳ�������
void InsretSort(int arr[], int size);
//ϣ������
void ShellSort(int arr[], int size);
//ѡ������
void SelectSort(int arr[], int size);
void SelectSort_OP(int arr[], int size);
void Swap(int* left, int* right);
//������
void HeapSort(int arr[], int size);
void HeapAdjust(int arr[], int size, int root);
//ð������
void BubbleSort(int arr[], int size);


void Print(int arr[], int size);

#endif //__SORT_H__