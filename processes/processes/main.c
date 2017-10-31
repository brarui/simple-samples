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

void forker(int processNumbers, char ** fileNames)
{
    pid_t pid;
    int fd[2];
    int success = 0;
    
    pipe(fd);
    if(processNumbers > 0)
    {
        if ((pid = fork()) < 0)
        {
            perror("fork");
        }
        else if (pid == 0)
        {
            // Child
            //printf("Child PID: %d\n", getpid());
            if(fopen(fileNames[processNumbers], "r")){
                success = 1;
                write(fd[1], &success, sizeof(success));
                //printf("(Child) success reading: %s\n", fileNames[processNumbers]);
            }
            else{
                success = 0;
                write(fd[1], &success, sizeof(success));
                //printf("(Child) Problema reading: %s\n", fileNames[processNumbers]);
            }
        }
        else if(pid > 0)
        {
            // Parent
            read(fd[0], &success, sizeof(success));
            if(success){
                printf("(Parent) success reading: %s\n", fileNames[processNumbers]);
            }
            else{
                printf("(Parent Problema reading: %s\n", fileNames[processNumbers]);
            }
            forker(processNumbers - 1, fileNames);
        }
    }
}

int main(int argc, char *argv[])
{
    int processNumbers = argc - 1;
    
    forker(processNumbers, argv);

    return 0;
}
