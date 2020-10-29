#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"game.h"

void menu()
{
	printf("*************************************************\n");
	printf("***************    扫 雷 游 戏    ***************\n");
	printf("***************   1, P  L  A  Y   ***************\n");
	printf("***************   0. E  X  I  T   ***************\n");
	printf("*************************************************\n");
}

void game()
{
	//printf("扫雷\n");
	//雷的信息存储
	
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.排查好的雷的信息
	char show[ROWS][COLS] = { 0 };
	
	//初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	
	//布置雷
	SetMine(mine, ROW, COL);
	
	//显示雷的位置
	DisplayBoard(mine, ROW, COL);
	
	//扫雷
	FindMine(mine,show,ROW,COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} 
	while (input);
	{

	}
}

int main()
{
	test();
	return 0;
}
