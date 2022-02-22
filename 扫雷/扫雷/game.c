#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void board(char arr[ROWS][COKS], int rows, int coks ,char ret)
{
	int x, y;
	for (x = 0; x < rows; x++)
	{
		for (y = 0; y < coks; y++)
		{
			arr[x][y] = ret;
		}
	}
}
void putboard(char arr[ROWS][COKS], int row, int cok)
{
	int x, y;
	for (x = 0; x <= row; x++)
	{
		printf(" %d", x);
	}
	printf("\n");
	for (x = 1; x <= row; x++)
	{
		printf(" %d", x);
		for (y = 1; y <= cok; y++)
		{
			printf(" %c", arr[x][y]);
		}
		printf("\n");
	}
}
void putmine(char arr[ROWS][COKS], int row, int cok)
{
	int x, y, z;
	z = MINECOUNT;
	while (z > 0)
	{
		x = rand() % row + 1;
		y = rand() % cok + 1;
		if (arr[x][y] == '0' && arr[x][y] != '1')
		{
			arr[x][y] = '1';
			z--;
		}
	}
}
int around(char arr[ROWS][COKS], int a, int b)
{
	return arr[a][b - 1] +
		arr[a - 1][b - 1] +
		arr[a - 1][b] +
		arr[a - 1][b + 1] +
		arr[a][b + 1] +
		arr[a + 1][b + 1] +
		arr[a + 1][b] +
		arr[a + 1][b - 1] - 8 * '0';
}
void around1(char arr[ROWS][COKS], char arr1[ROWS][COKS], int row, int cok, int a, int b)
{
	if ((a >= 1 && a <= row) && (b >= 1 && b <= cok))
	{
		if (around(arr, a, b) == 0)
		{
			if (arr[a][b] == '0' && arr1[a][b] == '*')
			{
				arr1[a][b] = around(arr, a, b) + '0';
				around1(arr, arr1, row, cok, a - 1, b);
				around1(arr, arr1, row, cok, a + 1, b);
				around1(arr, arr1, row, cok, a, b - 1);
				around1(arr, arr1, row, cok, a, b + 1);
			}
		}
		else
		{
			arr1[a][b] = around(arr, a, b) + '0';
		}
	}
}
void searchmine(char arr[ROWS][COKS], char arr1[ROWS][COKS], int row, int cok)
{
	int a = 0;
	int d = 0;
	int c = 0;
	int b = 0;
	int e = 0;
	do
	{
		printf("请玩家输入坐标>: ");
		scanf("%d%d", &a, &b);
		if ((a >= 1 && a <= row) && (b >= 1 && b <= cok))
		{
			if (arr[a][b] == '1')
			{
				printf("被炸死了\n");
				putboard(arr, ROW, COK);//打印棋盘
				break;
			}
			else
			{	
				around1(arr, arr1,row,cok, a, b);//统计玩家坐标周围的炸弹数
				putboard(arr1, ROW, COK);
				for (c = 1; c <= row; c++)
				{
					for (d = 1; d <= cok; d++)
					{
						if (arr1[c][d] == '*')
						{
							e++;
							if (e == MINECOUNT)
							{
								goto cuv;
							}
								
						}
						
					}
				}
			}	
		}
		else 
		{
			printf("输入错误，请重新输入\n");
		}
	} while (1);
cuv:
	printf("获胜\n");
}











