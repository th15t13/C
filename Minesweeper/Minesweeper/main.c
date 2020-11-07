#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)

#define ROW 9
#define COL 9
#define MINE_COUNT 10

int menu(){
	printf("======================\n");
	printf("====== 1. start ======\n");
	printf("====== 0. exit  ======\n");
	printf("======================\n");
	int option = -1;
	scanf("%d", &option);
	return option;
}

void init(char gameMap[ROW][COL], char mineMap[ROW][COL]){
	srand((unsigned int)time(0));
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			gameMap[i][j] = '*';
		}
	}
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			mineMap[i][j] = '0';
		}
	}
	int n = 0;
	while (n < MINE_COUNT){
		int row = rand() % ROW;
		int col = rand() % COL;
		if (mineMap[row][col] != '1'){
			mineMap[row][col] = '1';
			n++;
		}
		else{
			continue;
		}
	}
}

void printMap(char Map[ROW][COL]){
	printf("  |");
	for (int i = 0; i < COL; i++){
		printf("%d ", i);
	}
	printf("\n");
	printf("--+------------------\n");
	for (int i = 0; i < ROW; i++){
		printf(" %d|", i);
		for (int j = 0; j < COL; j++){
			printf("%c ", Map[i][j]);
		}
		printf("\n");
	}
}

void updateGameMap(char gameMap[ROW][COL],char mineMap[ROW][COL],int row,int col){
	int count = 0;
	for (int i = row-1; i <=row+1 ; i++){
		for (int j = col-1; j <= col+1; j++){
			if (i >= ROW || i < 0 || j >= COL || j < 0){
				continue;
			}
			if (mineMap[i][j] == '1'){
				count++;
			}
		}
	}
	gameMap[row][col] = '0' + count;
	//自动展开
	if (gameMap[row][col] == '0'){
		if (row < ROW && row >= 0 && col < COL && col - 1 >= 0
			&& gameMap[row][col - 1] == '*'){
			//起初漏了为'*'则展开这个条件，导致翻开的格子仍反复递归，最终栈溢出
			updateGameMap(gameMap, mineMap, row, col - 1);
		}
		if (row < ROW && row >= 0 && col + 1 < COL && col >= 0
			&& gameMap[row][col + 1] == '*'){
			updateGameMap(gameMap, mineMap, row, col + 1);
		}
		if (row < ROW && row - 1 >= 0 && col < COL && col >= 0
			&& gameMap[row - 1][col] == '*'){
			updateGameMap(gameMap, mineMap, row - 1, col);
		}
		if (row + 1 < ROW && row >= 0 && col < COL && col >= 0
			&& gameMap[row + 1][col] == '*'){
			updateGameMap(gameMap, mineMap, row + 1, col);
		}
	}
}

void game(){
	char gameMap[ROW][COL] = { ' ' };
	char mineMap[ROW][COL] = { ' ' };
	srand((unsigned int)time(0));
	init(gameMap, mineMap);
	int openedBlockCount = 0;
	while (1){
		//printMap(mineMap);
		//printf("=================================\n");
		printMap(gameMap);
		int row = 0;
		int col = 0;
		printf("请输入坐标(row col)# ");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("输入有误!\n");
			continue;
		}
		if (gameMap[row][col] != '*') {
			printf("此坐标已经翻开了!\n");
			continue;
		}
		if (mineMap[row][col] == '1') {
			printf("踩雷了!游戏结束...\n");
			printMap(mineMap);
			break;
		}
		else{
			updateGameMap(gameMap, mineMap, row, col);
			openedBlockCount++;
			if (openedBlockCount == ROW*COL - MINE_COUNT){
				printf("你赢了！\n");
				printMap(mineMap);
				break;
			}
		}
	}
}


int main(){

	while (1){
		system("cls");
		int option = menu();
		if (option == 1){
			game();
			break;
		}
		else if (option == 0){
			break;
		}
		else{		
			printf("输入有误!\n");
		}
	}

	system("pause");
	return 0;
}