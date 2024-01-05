#include <stdio.h>
#include "matrix.h"

void print_user_manual_menu()
{
    printf("User manual\n");
}

void generate_matrix_menu()
{
    printf("Generate matrix\n");
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
    case 3:
        break;
    }
    
    FreeMatrix(&loadedMatrix);
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

    int outcome = 0;
    int option = -1;
    while(option<0 || option >4)
    {
        printf("Spiral Matrix Imperative\n");
        printf("0 - User manual\n");
        printf("1 - Generate matrix\n");
        printf("2 - Load matrix\n");
        printf("3 - Exit\n");

        scanf("%d", &option);
    }
    menu_chosen_option(option);

    if(option != 3)
    {
        outcome = 1; 
    }
    return outcome;
}

int main()
{
    play();
    return 0;
}

