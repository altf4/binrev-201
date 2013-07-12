#include "stdlib.h"
#include <stdio.h>
#include <sys/ptrace.h>
#include <string.h>
#include <unistd.h>

char flag[20];

//Generates the flag: "psyK1K_pow3rs"
void GenerateFlag()
{
    memset(flag, '\0', sizeof flag);
    for(int i = 0; i < sizeof flag; i++)
    {
        flag[i] = (247345 * i) + 789;
    }

    flag[0] *= 25;
    flag[0] += 99;
    flag[1] *= 2;
    flag[1] -= 25;
    flag[2] += 2;
    flag[3] *= 345346;
    flag[3] -= 5;
    flag[4] *= 9876234;
    flag[4] -= 73;
    flag[5] = flag[3];
    flag[6] += 36; 
    flag[7] += 4;
    flag[8] = flag[7] - 1;
    flag[9] *= 4256786;
    flag[9] -= 5;
    flag[10] = flag[11] + 3;
    flag[11] *= 3;
    flag[11] -= 30;
    flag[12] += 18;
    flag[13] = '\0';
}

void DeleteFlag()
{
    memset(flag, '\0', sizeof flag);
}

int main()
{
    if(ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    {
        printf("Hey! No debuggers, that's cheating!\n");
        exit(EXIT_FAILURE);
    }

    printf("Can you read minds?\n");
    fflush(stdout);
    sleep(1);
    printf("Oh yea? Then what am I thinking...");
    fflush(stdout);
    sleep(1);
    printf("right...");

    fflush(stdout);
    sleep(1);
    
    GenerateFlag();
    printf("NOW?\n");
    fflush(stdout);
    DeleteFlag();
    
    return EXIT_SUCCESS;
}
