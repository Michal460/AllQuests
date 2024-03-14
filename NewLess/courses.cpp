#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE    10
#define MINES   12

int main(void)
{
    char pg[SIZE][SIZE] = {0};

    srand(time(NULL));
    int count = 0;
    printf("%d", pg[-1][-1]);
    // while(count != MINES){
    //     char x = rand()%10;
    //     char y = rand()%10;
    //     if(x == 0 || x == 9){
    //         if(pg[x][y] )
    //     }
        // if(pg[x-1][y] == 0 && pg[x+1][y] == 0 && pg[x][y-1] == 0 && pg[x][y+1] == 0 && pg[x])
    // }

    return 0;
}