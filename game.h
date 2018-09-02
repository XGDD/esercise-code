#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#ifndef __GAME_H__
#define __GAME_H__

#define R 3//行
#define C 3//列
#define Ex 0//增加量

void is_Board(char arr[R+Ex][C+Ex], int r, int c);    //初始化棋盘
void display_Board(char arr[R + Ex][C + Ex], int r, int c);   //打印棋盘
void play_person(char arr[R + Ex][C + Ex], int r, int c);     //玩家走
void play_computer(char arr[R + Ex][C + Ex], int r, int c);   //电脑走
char Judge(char arr[R + Ex][C + Ex], int r, int c);           //判断输赢函数
int is_all_equal_without_blank(char arr[R + Ex]);             //判断成每一条直线上元素是否全都相等并且不为空
int full(char arr[R + Ex][C + Ex], int r, int c);       //判断棋盘是否满了

#endif //__GAME_H__