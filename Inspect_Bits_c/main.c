/*
Implement the inspect_bits function that checks if given number contains 2 or more consecutive ones
in its binary representation. If it does, the function should return 1. Otherwise, it should return 0.

For example, inspect_bits(13) should return 1 as it contains 2 consecutive ones in
its binary representation (1101).
*/
#include <stdlib.h>
#include <stdio.h>

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

int inspect_bits(unsigned int number)
{
    int flag = 0;
    size_t size = sizeof(unsigned int)*8;
    for(size_t i=0;i<size;i++){
        if(CHECK_BIT(number,i)){
            if(flag) return 1;
            else flag =1;
        }
        else flag = 0;
    }
    return 0;
}

#ifndef RunTests
int main ()
{
    printf("%d", inspect_bits(13));
}
#endif
