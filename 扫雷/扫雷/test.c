#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
game()
{
	char arr[ROWS][COKS] = { '0' };
	char arr1[ROWS][COKS] = { '0' };
	board(arr, ROWS, COKS , '0');//���̳�ʼ��
	board(arr1, ROWS, COKS, '*');//���̳�ʼ��
	putboard(arr, ROW, COK);//��ӡ����
	putboard(arr1, ROW, COK);//��ӡ����
	putmine(arr, ROW, COK);//����
	putboard(arr, ROW, COK);
	searchmine(arr, arr1, ROW, COK);//����
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
		printf("������>: ");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
		}
	} while (i);
}
int main()
{
	srand((unsigned int)time(0));
	handle();
	return 0;
}































