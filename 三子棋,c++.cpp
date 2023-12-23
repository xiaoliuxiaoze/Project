#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("***************\n");
	printf("*** 1.play ****\n");
	printf("*** 0.exit ****\n");
	printf("***************\n");
}
void game()
{
	//存储二维数据
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;//接受游戏状态
	while (1)
	{
		//玩家下
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		//电脑下
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
	}
	if (ret == '*')
	{
		printf("你赢啦!\n");
	}
	else if (ret == '!')
	{
		printf("你输了!你连这都赢不了？别玩电脑了！60秒后关机！\n");
	again:
		printf("如果你还想证明自己，那就输入“我是猪”来取消关机:>\n");
		char input[20] = { 0 };
		system("shutdown -s -t 60");
		scanf("%s", input);
		if (strcmp(input, "我是猪") == 0)
		{
			system("shutdown -a");
		}
		else
		{
			goto again;
		}
	}
	else
	{
		printf("旗鼓相当（bushi）!\n");
	}
	DisplayBoard(board, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("三子棋游戏\n");
				game();
				break;
		case 0:
				printf("退出游戏\n");
				break;
		default:
				printf("选择错误，请重新选择\n");
				break;
		}
	} while (input);
	return 0;
}