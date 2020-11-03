#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)

#define ROW 3
#define COL 3

void init(char chessBoard[ROW][COL]){
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			chessBoard[i][j] = ' ';
		}
	}
}

void printChessBoard(char chessBoard[ROW][COL]){
	printf("+---+---+---+\n");
	for (int i = 0; i < ROW; i++){
			printf("| %c | %c | %c |\n", chessBoard[i][0], chessBoard[i][1], chessBoard[i][2]);
			printf("+---+---+---+\n");
	}
}

void playerMove(char chessBoard[ROW][COL]){
	int row = 0;
	int col = 0;
	while (1){
		printf("请输入落子坐标（row col）# ");
		scanf("%d %d", &row, &col);
		if ((row < 0 || row >= ROW) || (col < 0 || col >= COL)){
			printf("输入有误！\n");
			continue;
		}
		else if (chessBoard[row][col] != ' '){
			printf("此坐标已经有子了！\n");
			continue;
		}
		chessBoard[row][col] = 'X';
		break;
	}
}

void comMove(char chessBoard[ROW][COL]){
	while (1){
		int row = rand() % ROW;
		int col = rand() % COL;
		if (chessBoard[row][col] != ' '){
			continue;
		}
		chessBoard[row][col] = 'O';
		break;
	}
}

int isFull(char chessBoard[ROW][COL]){
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char checkState(char chessBoard[ROW][COL]){
	for (int row = 0; row < ROW; row++) {
		if (chessBoard[row][0] != ' '
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	for (int col = 0; col < COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[0][2] == chessBoard[2][0]) {
		return chessBoard[0][2];
	}
	if (isFull(chessBoard)){
		return 'D';
	}
	return ' ';
}

void game(){
	char chessBoard[ROW][COL] = { 0 };
	init(chessBoard);
	char state = ' ';
	printChessBoard(chessBoard);
	while (1){
		playerMove(chessBoard);
		state = checkState(chessBoard);
		if (state != ' '){
			break;
		}
		comMove(chessBoard);
		printChessBoard(chessBoard);
		state = checkState(chessBoard);
		if (state != ' '){
			break;
		}
	}
	printChessBoard(chessBoard);
	if (state == 'X'){
		printf("你赢了！\n");
	}
	if (state == 'O'){
		printf("你输了！\n");
	}
	if (state == 'D'){
		printf("和棋！\n");
	}
}

int menu(){
	printf("#######################\n");
	printf("####### 1.play ########\n");
	printf("####### 0.exit ########\n");
	printf("#######################\n");
	int option = -1;
	scanf("%d", &option);
	return option;
}
int main(){

	srand((unsigned int)time(0));
	while (1){
		int option = 0;
		option = menu();
		if (option == 1){
			game();
			break;
		}
		else if (option == 0){
			break;
		}
		else{
			printf("输入有误，请重新输入!\n");
			getchar();
			continue;
		}
	}

	system("pause");
	return 0;
}