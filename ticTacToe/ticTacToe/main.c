//
//  main.c
//  ticTacToe
//
//  Created by Rui Silva on 31/10/17.
//  Copyright © 2017 Rui Silva. All rights reserved.
//


#include <stdio.h>

#define linhas 3
#define colunas 3

void iniciarTabulerio(char tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }
};

void mostrarTabuleiro(char tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++)
    {
        printf("---------------------\n");
        printf("|     ||     ||     |\n");
        for (int j = 0; j < colunas; j++)
        {
            printf("|  %c  |", tabuleiro[i][j]);
        }
        printf("\n|     ||     ||     |\n");
    }
    printf("---------------------\n");
}

void mostrarTabuleiroVazio() {
    int coordenada = 0;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++, coordenada++)
        {
            printf("| %d |", coordenada);
        }
        printf("\n");
    }
}

void mostrarTabuleiroParaJogar() {
    int coordenada = 1;
    
    printf("     %d    %d   %d\n", coordenada, coordenada + 1, coordenada + 2);
    
    for (int i = 0; i < linhas; i++)
    {
        printf(" %d ", coordenada + i);
        for (int j = 0; j < colunas; j++)
        {
            printf("|   |");
        }
        printf("\n");
    }
}

int GetInt(int minimum, int maximum){
    int number;
    do{
        printf("Escolha um valor entre 1 e 3: ");
        scanf("%d", &number);
    }while(number < minimum || number > maximum );
    return number;
}

void jogar(char tabuleiro[linhas][colunas], char jogador) {
    int coordenadaLinha = -1, coordenadaColuna = -1;
    
    //mostrarTabuleiroVazio();
    mostrarTabuleiroParaJogar();
    
    printf("\nJogador %c\nQual a sua jogada?\n", jogador);
    do{
        coordenadaLinha = GetInt(1,3) - 1;
        coordenadaColuna = GetInt(1,3) - 1;
        
        if(tabuleiro[coordenadaLinha][coordenadaColuna] != ' ')
            printf("Invalid play.\nTry again.\n");
    }
    while(tabuleiro[coordenadaLinha][coordenadaColuna] != ' ');
    
    tabuleiro[coordenadaLinha][coordenadaColuna] = jogador;

}

int verificarLinhas(char tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++)
    {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2])
            return 1;
    }
    return 0;
}

int verificarColunas(char tabuleiro[linhas][colunas]) {
    for (int i = 0; i < colunas; i++)
    {
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
            return 1;
    }
    return 0;
}

int verificarDiagonais(char tabuleiro[linhas][colunas]) {
    if ((tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2])
        || (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][0]))
        return 1;
    else
        return 0;
}

int verificarVitoria(char tabuleiro[linhas][colunas], char jogador) {
    if (verificarLinhas(tabuleiro) || verificarColunas(tabuleiro) || verificarDiagonais(tabuleiro))
        return 1;
    else
        return 0;
}

char trocarJogador(char jogadorAtivo) {
    if (jogadorAtivo == 'X')
        return 'O';
    else
        return 'X';
}

int main()
{
    char tabuleiro[linhas][colunas];
    char jogadorAtivo;
    int resultadoJogo;
    iniciarTabulerio(tabuleiro);
    
    jogadorAtivo = 'X';
    resultadoJogo = 0;
    do
    {
        system("clear");
        mostrarTabuleiro(tabuleiro);
        jogar(tabuleiro, jogadorAtivo);
        if (verificarVitoria(tabuleiro, jogadorAtivo)) {
            resultadoJogo = 1;
            break;
        }
        else
            jogadorAtivo = trocarJogador(jogadorAtivo);
    } while (1);
    
    mostrarTabuleiro(tabuleiro);
    if (resultadoJogo)
        printf("Parabens Jogador %c\n\n", jogadorAtivo);
    else
        printf("Empate! Acontece...\n\n");
    
    
    return 0;
}

