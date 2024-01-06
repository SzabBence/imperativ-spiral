#ifndef MATRIX_H
#define MATRIX_H


typedef struct 
{
    int **data;  
    int rows;     
    int columns;
    int loadingFailed;  
} Matrix;

int countLines(char *filePath);
int countColumns(char *filePath);
int file_exists(char *filename);

Matrix CreateMatrix(int rows, int columns);
Matrix LoadDataToMatrix(char *filePath);

void FreeMatrix(Matrix *matrix);
void WriteMatrixToFile(Matrix *matrix, char *filePath);
void DisplayMatrix(Matrix *matrix);
void WriteMatrixToFileFromTerminal(Matrix *matrix);
void FillMatrixWithDefaultValues(Matrix *matrix);
Matrix LoadMatrixFromTerminal();

#endif