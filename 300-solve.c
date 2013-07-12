#include "stdlib.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char buffer[20];

void DecodeMessage(char *input)
{

    strncpy(buffer, input, sizeof(buffer));
    for(int i = 0; i < sizeof(buffer); i++)
    {
        buffer[i] += i; 
    }
    
    char temp = buffer[9];
    for(int i = 0; i < sizeof(buffer); i++)
    {
        buffer[i] += (temp * 3); 
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
    memset(buffer, '\0', sizeof(buffer));
    DecodeMessage(argv[1]);
    printf("%s\n", buffer);
}
