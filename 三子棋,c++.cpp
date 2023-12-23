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
	//�洢��ά����
	char board[ROW][COL];
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬
	while (1)
	{
		//�����
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		//������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
	}
	if (ret == '*')
	{
		printf("��Ӯ��!\n");
	}
	else if (ret == '!')
	{
		printf("������!�����ⶼӮ���ˣ���������ˣ�60���ػ���\n");
	again:
		printf("����㻹��֤���Լ����Ǿ����롰��������ȡ���ػ�:>\n");
		char input[20] = { 0 };
		system("shutdown -s -t 60");
		scanf("%s", input);
		if (strcmp(input, "������") == 0)
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
		printf("����൱��bushi��!\n");
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
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("��������Ϸ\n");
				game();
				break;
		case 0:
				printf("�˳���Ϸ\n");
				break;
		default:
				printf("ѡ�����������ѡ��\n");
				break;
		}
	} while (input);
	return 0;
}