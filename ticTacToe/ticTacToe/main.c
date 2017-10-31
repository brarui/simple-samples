//
//  main.c
//  ticTacToe
//
//  Created by Rui Silva on 31/10/17.
//  Copyright © 2017 Rui Silva. All rights reserved.
//


#include <stdio.h>

#define lines 3
#define columns 3

void inicializeBoard(char board[lines][columns]) {
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = ' ';
        }
    }
};

void showBoard(char board[lines][columns]) {
    for (int i = 0; i < lines; i++)
    {
        printf("---------------------\n");
        printf("|     ||     ||     |\n");
        for (int j = 0; j < columns; j++)
        {
            printf("|  %c  |", board[i][j]);
        }
        printf("\n|     ||     ||     |\n");
    }
    printf("---------------------\n");
}

void showBoardInstructions() {
    int coordinate = 1;
    
    printf("     %d    %d   %d\n", coordinate, coordinate + 1, coordinate + 2);
    
    for (int i = 0; i < lines; i++)
    {
        printf(" %d ", coordinate + i);
        for (int j = 0; j < columns; j++)
        {
            printf("|   |");
        }
        printf("\n");
    }
}

int GetInt(int minimum, int maximum){
    int number;
    do{
        printf("Pick a number between %d and %d: ", minimum, maximum);
        scanf("%d", &number);
    }while(number < minimum || number > maximum );
    return number;
}

void play(char board[lines][columns], char player) {
    int lineCoordinate = -1, columnCoordinate = -1;
    
    showBoardInstructions();
    
    printf("\nPlayer %c\nWhat's your move?\n", player);
    do{
        lineCoordinate = GetInt(1,3) - 1;
        columnCoordinate = GetInt(1,3) - 1;
        
        if(board[lineCoordinate][columnCoordinate] != ' ')
            printf("Invalid play.\nTry again.\n");
    }
    while(board[lineCoordinate][columnCoordinate] != ' ');
    
    board[lineCoordinate][columnCoordinate] = player;

}

int checkLines(char board[lines][columns]) {
    for (int i = 0; i < lines; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return 1;
    }
    return 0;
}

int checkColumns(char board[lines][columns]) {
    for (int i = 0; i < columns; i++)
    {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return 1;
    }
    return 0;
}

int checkDiagonals(char board[lines][columns]) {
    if ((board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        || (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][0] == board[2][0]))
        return 1;
    else
        return 0;
}

int isVictory(char board[lines][columns], char player) {
    if (checkLines(board) || checkColumns(board) || checkDiagonals(board))
        return 1;
    else
        return 0;
}

int isEndOfGame(char board[lines][columns]) {
    int i, j;
    for(i = 0; i < lines; i++)
        for(j = 0; j < columns; j++)
            if (board[i][j] == ' ' )
                return 0;
    return 1;
}

char changePlayers(char activePlayer) {
    if (activePlayer == 'X')
        return 'O';
    else
        return 'X';
}

int main()
{
    char board[lines][columns];
    char activePlayer;
    int matchResult;
    inicializeBoard(board);
    
    activePlayer = 'X';
    matchResult = 0;
    do
    {
        system("clear");
        showBoard(board);
        play(board, activePlayer);
        if (isVictory(board, activePlayer)) {
            matchResult = 1;
            break;
        }
        else{
            if(isEndOfGame(board))
                break;
            else
                activePlayer = changePlayers(activePlayer);
        }
    } while (1);
    
    showBoard(board);
    if (matchResult)
        printf("Congradulations Player %c\n\n", activePlayer);
    else
        printf("Draw! Better luck next time...\n\n");
    
    return 0;
}

