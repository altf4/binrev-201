#include "stdlib.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char buffer[20];

void EncodeMessage(char *input)
{
    __asm__ ("jmp labelA+1\n\t"
          "labelA: nop\n\t"
          "");

    strncpy(buffer, input, sizeof(buffer));

    __asm__ ("jmp labelB+1\n\t"
          "labelB: nop\n\t"
          "");

    int i = 0;

    __asm__ ("jmp labelC+1\n\t"
          "labelC: nop\n\t"
          "");
    while(i < sizeof(buffer))
    {

        __asm__ ("jmp labelD+1\n\t"
              "labelD: nop\n\t"
              "");    
        buffer[i] += i;
        __asm__ ("jmp labelE+1\n\t"
              "labelE: nop\n\t"
              "");
        i++;
        __asm__ ("jmp labelF+1\n\t"
              "labelF: nop\n\t"
              "");
    }
    
    buffer[2] += buffer[12];
    buffer[6] += buffer[2];
    buffer[9] += buffer[13];
    buffer[13] += buffer[3];
    buffer[0] += buffer[8];
    buffer[1] += buffer[7];
    buffer[19] += buffer[11];
    buffer[10] += buffer[4];
    buffer[7] += buffer[17];
    buffer[8] += buffer[5];
    buffer[3] += buffer[14];
    buffer[4] += buffer[1];
    buffer[15] += buffer[10];
    buffer[5] += buffer[6];
    buffer[14] += buffer[19];
    buffer[16] += buffer[15];
    buffer[12] += buffer[9];
    buffer[18] += buffer[3];
    buffer[17] += buffer[18];
    buffer[11] += buffer[16];

    //Get rid of NULLs at the end
    for(int i = 0; i < sizeof(buffer)-1; i++)
    {
        if(buffer[i] == '\0')
        {
            buffer[i] = '_';
        }
    }
    
}


int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Usage: ./300-jmping_for_joy <string_to_encode>\n");
        exit(1);
    }
    memset(buffer, '\0', sizeof(buffer));
    EncodeMessage(argv[1]);
    printf("%s\n", buffer);
}
