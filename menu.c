#include <stdio.h>
#include "matrix.h"

void print_user_manual_menu()
{
    printf("User manual\n");
}

void generate_matrix_menu()
{
    int N = -1;
    while(N < 1 || N > 20)
    {
        printf("Please type in the number (N) 1-20 : \n");
        printf("->");
        scanf("%d", &N);
    }
    
    Matrix generatedMatrix = CreateMatrix(N, N);
    generatedMatrix.generatedMatrix = 1;
    generatedMatrix.loadedMatrix = 0;
    
    int askForOption = -1;
    while(askForOption < 0 || askForOption >3)
    {
        printf("Please choose from the following options: \n");
        printf("0 - Display matrix \n");
        printf("1 - Write matrix to file \n");
        printf("2 - Display and write matrix to file \n");
        printf("3 - Do nothing, exit\n");
        printf("-> ");
        scanf("%d", &askForOption);
    }

    switch (askForOption)
    {
    case 0:
        DisplayMatrix(&generatedMatrix);
        break;
    case 1:
        WriteMatrixToFileFromTerminal(&generatedMatrix);
        break;
    case 2:
        DisplayMatrix(&generatedMatrix);
        WriteMatrixToFileFromTerminal(&generatedMatrix);
        break;
    case 3:
        break;
    }
    
    FreeMatrix(&generatedMatrix);
    printf("Returning to main menu...\n");
    
}

void load_matrix_menu()
{
    Matrix loadedMatrix = LoadMatrixFromTerminal();
    int askForOption = -1;
    while(askForOption < 0 || askForOption >3)
    {
        printf("Please choose from the following options: \n");
        printf("0 - Display matrix \n");
        printf("1 - Write matrix to file \n");
        printf("2 - Display and write matrix to file \n");
        printf("3 - Do nothing, exit\n");
        printf("-> ");
        scanf("%d", &askForOption);
    }

    switch (askForOption)
    {
    case 0:
        DisplayMatrix(&loadedMatrix);
        break;
    case 1:
        WriteMatrixToFileFromTerminal(&loadedMatrix);
        break;
    case 2:
        DisplayMatrix(&loadedMatrix);
        WriteMatrixToFileFromTerminal(&loadedMatrix);
        break;
    case 3:
        break;
    }
    
    FreeMatrix(&loadedMatrix);
    printf("Returning to main menu...\n");
    
}

void exit_menu()
{
    printf("Exiting. Thank you for playing with this software! Good bye!\n");
}
void menu_chosen_option(int option)
{
    switch (option)
    {
    case 0:
        print_user_manual_menu();
        break;
    case 1:
        generate_matrix_menu();
        break;
    case 2:
        load_matrix_menu();
        break;
    case 3:
        exit_menu();
        break;
    }
}
int play(){

    int option = -1;
    while(option<0 || option >4)
    {
        printf("Spiral Matrix Imperative\n");
        printf("0 - User manual\n");
        printf("1 - Generate matrix\n");
        printf("2 - Load matrix\n");
        printf("3 - Exit\n");
        printf("-> ");
        scanf("%d", &option);
    }
    menu_chosen_option(option);
    return option;
}

int main()
{
    int goOn = -1;
    while(goOn != 3)
    {
        goOn = play();
    }
    
    return 0;
}

