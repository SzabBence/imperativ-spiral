#include <stdio.h>
#include "matrix.h"

void print_user_manual_menu()
{
    printf("You can use the features by following the terminal and typing in numbers. \n");
    printf("Please note that every file is saved to the same folder, where the program runs. Also \n");
    printf("we save every file to the same folder during the run, where we read from. \n \n"); 
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
        DisplayMatrixBetter(matrix);
        break;
    case 1:
        WriteMatrixToFileFromTerminal(matrix);
        break;
    case 2:
        DisplayMatrixBetter(matrix);
        WriteMatrixToFileFromTerminal(matrix);
        break;
    case 3:
        break;
    }
    
    FreeMatrix(matrix);
    printf("Returning to main menu...\n");
    printf("\n");
}

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
    printf("\n");
    return askForOption;
}

int getClockDirection()
{
    int askForOption = -1;
    while(askForOption < 1 || askForOption > 2)
    {
        printf("Please select direction \n");
        printf("1 - Clockwise \n");
        printf("2 - CounterClockWise \n");
        printf("-> ");
        scanf(" %d", &askForOption);
    }
    printf("\n");
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
    
    int generalDirection = getDirection();
    int clockDirection = getClockDirection();
    int combinedDirection = generalDirection + clockDirection * 10; 
    Matrix generatedMatrix = CreateMatrix(N, N);
    GenerateMatrix(&generatedMatrix,combinedDirection);
    
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
    printf("Szabo Software: Where code is our passion. Copyright 1994. All rights reserved. \n");
    int goOn = -1;
    while(goOn != 3)
    {
        goOn = play();
    }
    
    return 0;
}

