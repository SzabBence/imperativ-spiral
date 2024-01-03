#include <stdio.h>
#include "matrix.h"

int main() {
    const char *filePath = "output_matrix.txt";

    
    Matrix matrix = LoadDataToMatrix("matrix.txt");  

    if (matrix.data != NULL) {
        DisplayMatrix(&matrix);

        WriteMatrixToFile(&matrix, filePath);

        FreeMatrix(&matrix);
    }

    return 0;
}
