#ifndef MATRIX_H
#define MATRIX_H


typedef struct 
{
    int **data;  
    int rows;     
    int columns;
    int loadingFailed;  
} Matrix;

typedef struct 
{
    int x1;
    int x2;
    int x3;
    int x4;
    int y1;
    int y2;
    int y3;
    int y4;
} RotationMapping;

int countLines(char *filePath);
int countColumns(char *filePath);
int file_exists(char *filename);
int countDigits(int number);

Matrix CreateMatrix(int rows, int columns);
Matrix LoadDataToMatrix(char *filePath);

void FreeMatrix(Matrix *matrix);
void WriteMatrixToFile(Matrix *matrix, char *filePath);
void DisplayMatrix(Matrix *matrix);
void DisplayMatrixBetter(Matrix *matrix);
void WriteMatrixToFileFromTerminal(Matrix *matrix);
void FillMatrixWithDefaultValues(Matrix *matrix);
void printNumberBasedOnDigit(int maxDigits, int valueToPrint);
Matrix LoadMatrixFromTerminal();
void GenerateMatrix(Matrix *matrix, int combinedDirection);
int main();

RotationMapping initRotationMapping();
RotationMapping createRotationMapping(int combinedDirection);
#endif