#include "functions.h"

int main(void)
{
    srand(time(NULL));
    int numberArray[] = {0,1,2,3,4,5,6,7};

    int** numbersIn = malloc(sizeof(int**));

    *numbersIn = numberArray+5;

    (*numbersIn)[1] = 50;

    printf("%d",numberArray[6]);



    run_program();

    return 0;

    // test
}

