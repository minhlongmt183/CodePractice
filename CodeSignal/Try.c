#include <stdio.h>

struct Computer{
    int x;
    int y;
} ;

int main(){
    struct  Computer PC = {1,3};
    struct Computer *pPC;
    pPC = &PC;

    printf("value: %d \n", *(pPC + 4));


    return 0;
}