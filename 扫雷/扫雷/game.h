#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COK 9
#define ROWS  ROW + 2
#define COKS  COK + 2
#define MINECOUNT 80
void board(char arr[ROWS][COKS], int rows ,int coks, char ret );
void putboard(char arr[ROWS][COKS], int row, int cok);
void putmine(char arr[ROWS][COKS], int row, int cok);
void searchmine(char arr[ROWS][COKS], char arr1[ROWS][COKS], int row, int cok);