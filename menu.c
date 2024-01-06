#include <stdio.h>
#include "matrix.h"

void print_user_manual_menu()
{
    printf("User manual\n");
}

void matrix_operations(Matrix *matrix)
{
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
        DisplayMatrix(matrix);
        break;
    case 1:
        WriteMatrixToFileFromTerminal(matrix);
        break;
    case 2:
        DisplayMatrix(matrix);
        WriteMatrixToFileFromTerminal(matrix);
        break;
    case 3:
        break;
    }
    
    FreeMatrix(matrix);
    printf("Returning to main menu...\n");
    printf("\n");
}
int reAttemptToLoadMatrix()
{
    int askForOption = -1;
    printf("Do you wish to load a new matrix?\n");
    while(askForOption !=0 || askForOption != 1)
    {
        printf("0 - No \n");
        printf("1 - Yes \n");
        printf("->");
        scanf("%d", &askForOption);
    }

    return askForOption;
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
    FillMatrixWithDefaultValues(&generatedMatrix);
    
    matrix_operations(&generatedMatrix);
}

void load_matrix_menu()
{
    Matrix loadedMatrix;

    do {
        loadedMatrix = LoadMatrixFromTerminal();

        if (loadedMatrix.loadingFailed == 1) {
            FreeMatrix(&loadedMatrix);
            printf("Failed to load matrix. Please try again.\n");
        }
    } while (loadedMatrix.loadingFailed == 1);

    matrix_operations(&loadedMatrix);
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

