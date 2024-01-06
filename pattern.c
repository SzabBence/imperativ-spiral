#include <stdio.h>

int main()
{
    int k = 1;
    int fj = 0;
    int lb = 0; 
    int i = 0;
    int N = 12;
    while(i != N)
    {
        if(k % 2 == 1){
            fj = 1;
            lb = 0;
        }else{
            fj = 0;
            lb = 1;
        }
        if (fj == 1){
            for(int j = 1; j <=k; j++){
                if(i != N){
                    i++;
                    printf("F - %d \n",i);
                }
            }

            for(int j = 1; j <=k; j++){
                if(i != N){
                    i++;
                    printf("J - %d \n",i);
                }
            }
        }else{
            for(int j = 1; j <=k; j++){
                if(i != N){
                    i++;
                    printf("L - %d \n",i);
                }
            }

            for(int j = 1; j <=k; j++){
                if(i != N){
                    i++;
                    printf("B - %d \n",i);
                }
            }
        }
        k++;
    }
    return 0;
}