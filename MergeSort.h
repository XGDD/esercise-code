#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void _MergeSort(int* array, int left, int right, int* temp);
void MergeData(int* array, int left, int mid, int right, int* temp);
void MergeSort(int* array, int size);
void Print(int* array, int size);


#endif //__MERGESORT_H__