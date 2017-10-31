//
//  main.c
//  processes
//
//  Created by Rui Silva on 30/10/17.
//  Copyright © 2017 Rui Silva. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void forker(int numeroDeProcessos, char ** nomeDoFicheiro)
{
    pid_t pid;
    int fd[2];
    int sucesso = 0;
    
    pipe(fd);
    if(numeroDeProcessos > 0)
    {
        if ((pid = fork()) < 0)
        {
            perror("fork");
        }
        else if (pid == 0)
        {
            // FILHO 
            //printf("Filho com PID: %d\n", getpid());
            if(fopen(nomeDoFicheiro[numeroDeProcessos], "r")){
                sucesso = 1;
                write(fd[1], &sucesso, sizeof(sucesso));
                //printf("(Filho) Sucesso a ler: %s\n", nomeDoFicheiro[numeroDeProcessos]);
            }
            else{
                sucesso = 0;
                write(fd[1], &sucesso, sizeof(sucesso));
                //printf("(Filho) Problema a ler: %s\n", nomeDoFicheiro[numeroDeProcessos]);
            }
        }
        else if(pid > 0)
        {
            // PAI
            read(fd[0], &sucesso, sizeof(sucesso));
            if(sucesso){
                printf("(Pai) Sucesso a ler: %s\n", nomeDoFicheiro[numeroDeProcessos]);
            }
            else{
                printf("(Pai Problema a ler: %s\n", nomeDoFicheiro[numeroDeProcessos]);
            }
            forker(numeroDeProcessos - 1, nomeDoFicheiro);
        }
    }
}

int main(int argc, char *argv[])
{
    int numeroDeProcessos = argc - 1;
    
    forker(numeroDeProcessos, argv);

    return 0;
}
