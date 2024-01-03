#ifndef MATRIX_H
#define MATRIX_H


typedef struct 
{
    int **data;  
    int rows;     
    int columns;  
} Matrix;

int countLines(const char *filePath);
int countColumns(const char *filePath);

Matrix CreateMatrix(int rows, int columns);
Matrix LoadDataToMatrix(const char *filePath);

void FreeMatrix(Matrix *matrix);
void WriteMatrixToFile(Matrix *matrix, const char *filePath);
void DisplayMatrix(Matrix *matrix);

#endif  