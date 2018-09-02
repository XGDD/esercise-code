#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define R 12
#define C 12
#define COUNT 10

show[R][C];//玩家数组
mine[R][C];//设计者数组
void init_board();//初始化雷盘
void print_player();//打印玩家棋盘
void print_mine();//打印设计者棋盘
void set_mine();//给设计者棋盘布雷
int count_mine(int x, int y);//检测周围8个区域雷的个数
void safe_mine();//避免第一次被雷炸死
void open_mine(int x, int y);//坐标周围展开函数
int sweep_mine();//扫雷函数，踩到雷返回1，没有踩到雷返回0
int count_show();//判断剩余未知区域的个数，个数为雷数时玩家赢