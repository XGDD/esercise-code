#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define R 12
#define C 12
#define COUNT 10

show[R][C];//�������
mine[R][C];//���������
void init_board();//��ʼ������
void print_player();//��ӡ�������
void print_mine();//��ӡ���������
void set_mine();//����������̲���
int count_mine(int x, int y);//�����Χ8�������׵ĸ���
void safe_mine();//�����һ�α���ը��
void open_mine(int x, int y);//������Χչ������
int sweep_mine();//ɨ�׺������ȵ��׷���1��û�вȵ��׷���0
int count_show();//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ