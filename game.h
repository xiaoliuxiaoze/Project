#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#include<string.h>

//���ŵĶ���
#define ROW 3
#define COL 3

//��������
//��ʼ������
void InitBoard(char board[ROW][COL],int row,int col);
//��ӡ���̵ĺ���
void DisplayBoard(char board[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);
//�ж���Ӯ
//���ʤ������*
//����ʤ��������
//ƽ�֡���#
//��������c
char IsWin(char board[ROW][COL], int row, int col);