#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#ifndef __GAME_H__
#define __GAME_H__

#define R 3//��
#define C 3//��
#define Ex 0//������

void is_Board(char arr[R+Ex][C+Ex], int r, int c);    //��ʼ������
void display_Board(char arr[R + Ex][C + Ex], int r, int c);   //��ӡ����
void play_person(char arr[R + Ex][C + Ex], int r, int c);     //�����
void play_computer(char arr[R + Ex][C + Ex], int r, int c);   //������
char Judge(char arr[R + Ex][C + Ex], int r, int c);           //�ж���Ӯ����
int is_all_equal_without_blank(char arr[R + Ex]);             //�жϳ�ÿһ��ֱ����Ԫ���Ƿ�ȫ����Ȳ��Ҳ�Ϊ��
int full(char arr[R + Ex][C + Ex], int r, int c);       //�ж������Ƿ�����

#endif //__GAME_H__