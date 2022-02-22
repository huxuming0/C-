#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
game()
{
	char arr[ROWS][COKS] = { '0' };
	char arr1[ROWS][COKS] = { '0' };
	board(arr, ROWS, COKS , '0');//棋盘初始化
	board(arr1, ROWS, COKS, '*');//棋盘初始化
	putboard(arr, ROW, COK);//打印棋盘
	putboard(arr1, ROW, COK);//打印棋盘
	putmine(arr, ROW, COK);//放雷
	putboard(arr, ROW, COK);
	searchmine(arr, arr1, ROW, COK);//找雷
}
boundary()
{
	printf("************************\n");
	printf("*********1.play*********\n");
	printf("*********0.exit*********\n");
	printf("************************\n");
}
handle()
{
	int i=0;
	do
	{
		boundary();
		printf("请输入>: ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (i);
}
int main()
{
	srand((unsigned int)time(0));
	handle();
	return 0;
}































