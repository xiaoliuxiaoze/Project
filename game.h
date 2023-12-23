#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<time.h>
#include <stdio.h>
#include<string.h>

//符号的定义
#define ROW 3
#define COL 3

//函数声明
//初始化棋盘
void InitBoard(char board[ROW][COL],int row,int col);
//打印棋盘的函数
void DisplayBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
//判断输赢
//玩家胜利——*
//电脑胜利——！
//平局——#
//继续——c
char IsWin(char board[ROW][COL], int row, int col);