#ifndef MATRIX_H
#define MATRIX_H


typedef struct 
{
    int **data;  
    int rows;     
    int columns;
    int generatedMatrix;
    int loadedMatrix;
    int loadingFailed;  
} Matrix;

int countLines(const char *filePath);
int countColumns(const char *filePath);

Matrix CreateMatrix(int rows, int columns);
Matrix LoadDataToMatrix(char *filePath);

void FreeMatrix(Matrix *matrix);
void WriteMatrixToFile(Matrix *matrix, char *filePath);
void DisplayMatrix(Matrix *matrix);
void WriteMatrixToFileFromTerminal(Matrix *matrix);
Matrix LoadMatrixFromTerminal();

#endif