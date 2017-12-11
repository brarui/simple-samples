// checkers.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

void AskForDimensitons(int * rows, int * columns) {
	int dimention;
	printf("Enter the board dimention: ");
	scanf("%d", &dimention);

	*rows = dimention;
	* columns = dimention;
}

char ** AlocateMemoryForBoard(int rows, int columns) {
	int i;
	char ** board = (char **)malloc(rows * sizeof(char *));

	for (i = 0; i < rows; i++) {
		board[i] = (char *)malloc(columns * sizeof(char));
		//**board[i] = ' ';
	}

	return board;
}


void ClearBoard(char ** board, int rows, int columns){
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < rows; j++)
			printf("|%c|", board[i][j]);
}

void BoardAtStartingPoint(char ** board, int rows, int columns){
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < rows; j++)
			printf("|%c|", board[i][j]);
}

void ResetBoard(char ** board, int rows, int columns) {
	ClearBoard(board, rows, columns);
	BoardAtStartingPoint(board, rows, columns);
}

int main()
{
	int rows = 0, columns = 0, i, j;
	char ** board;

	AskForDimensitons(&rows, &columns);
	board = AlocateMemoryForBoard(rows, columns);

	ResetBoard(board, rows, columns);

	for (i = 0; i < rows; i++)
		for (j = 0; j < rows; j++)
			printf("|%c|", board[i][j]);

	printf("(%d, %d)", rows, columns);

	getchar();
    return 0;
}

