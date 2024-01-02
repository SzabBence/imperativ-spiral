#include <stdio.h>
void print_user_manual_menu()
{
    printf("User manual");
}

void generate_matrix_menu()
{
    printf("Generate matrix");
}

void load_matrix_menu()
{
    printf("Load matrix");
}

void exit_menu()
{
    printf("Exiting. Thank you for playing with this software! Good bye!");
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
    case 2:
        load_matrix_menu();
    case 3:
        exit_menu();
        break;
    }
}
int play(){

    int outcome = 0;
    int option = -1;
    while(option<0 && option >4)
    {
        printf("Spiral Matrix Imperative");
        printf("0 - User manual");
        printf("1 - Generate matrix");
        printf("2 - Load matrix");
        printf("3 - Exit");

        scanf("%d", &option);
    }

    if(option != 3)
    {
        outcome = 1; 
    }
    return outcome;
}

int main()
{
    int doPlay = 1;
    while(doPlay == 1)
    {
        doPlay = play();
    }
    return 0;
}

