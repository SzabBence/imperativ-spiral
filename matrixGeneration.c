#include "matrix.h"
int getDirection()
{
    int askForOption = -1;
    while(askForOption < 1 || askForOption > 4)
    {
        printf("Please select direction \n");
        printf("1 - Up \n");
        printf("2 - Down \n");
        printf("3 - Right \n");
        printf("4 - Left \n");
        printf("-> ");
        scanf("%d", &askForOption);
    }

    return askForOption;
}

int getClockDirection()
{
    int askForOption = -1;
    while(askForOption != 1 || askForOption != 2)
    {
        printf("Please select direction \n");
        printf("1 - Clockwise \n");
        printf("2 - CounterClockWise \n");
        printf("-> ");
        scanf("%d", &askForOption);
    }

    return askForOption;
}
int main(){
    int N = 5;
    GenerateMatrix(N);
    
    return 0;
}