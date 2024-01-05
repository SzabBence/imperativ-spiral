#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int countLines(const char *filePath)
{
    FILE *file = fopen(filePath, "r");
    
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;  // Return -1 to indicate an error
    }

    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            count++;
        }
    }

    fclose(file);
    return count;
}

int countColumns(const char *filePath)
{
    FILE *file = fopen(filePath, "r");
    
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;  // Return -1 to indicate an error
    }

    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != '\n' && ch != EOF)
    {
        if (ch == ' ')
        {
            count++;
        }
    }

    // Increment count for the last column
    count++;

    fclose(file);
    return count;
}

Matrix CreateMatrix(int rows, int columns) {
    Matrix matrix;
    matrix.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (int *)malloc(columns * sizeof(int));
    }

    matrix.rows = rows;
    matrix.columns = columns;

    return matrix;
}


void FreeMatrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

Matrix LoadDataToMatrix(char *filePath)
 {
    Matrix matrix = CreateMatrix(countLines(filePath), countColumns(filePath));  

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        // Handle error, possibly return an empty matrix
        return matrix;
    }

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++) {
            if (fscanf(file, "%d", &matrix.data[i][j]) != 1) {
                fprintf(stderr, "Error reading matrix from file\n");
                fclose(file);
                FreeMatrix(&matrix);
                // Handle error, possibly return an empty matrix
                return matrix;
            }
        }
    }

    fclose(file);
    matrix.generatedMatrix = 0;
    matrix.loadedMatrix = 1;
    matrix.loadingFailed = 0;
    return matrix;
}

void WriteMatrixToFile(Matrix *matrix, char *filePath)
{
    FILE *file = fopen(filePath, "w");

    if (file == NULL)
    {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            fprintf(file, "%d ", matrix->data[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    printf("Matrix successfully written to file: %s\n", filePath);
}

void DisplayMatrix(Matrix *matrix)
{
    for(int i = 0; i < matrix->rows; i++)
    {
        for(int j = 0; j < matrix->columns; j++)
        {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int file_exists(const char *filename)
{
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    return 0;
  }

  fclose(file);
  return 1;
}

Matrix LoadMatrixFromTerminal()
{
    char fileName[51];
    printf("Please type in your input file's path (50 char long at max): \n");
    scanf("%50s", fileName);

    if(fileName[strlen(fileName) - 1] == '\n')
    {
        fileName[strlen(fileName) - 1] = '\0';
    }
    int fileopen = file_exists(fileName);
    if(fileopen == 1)
    {
        Matrix matrix = LoadDataToMatrix(&fileName);

        return matrix;

    }
    else
    {
        printf("File: '%s' cannot be opened\n", fileName);
        Matrix matrix = CreateMatrix(0,0);
        matrix.loadingFailed = 1;
        matrix.generatedMatrix = 0;
        matrix.loadedMatrix = 0;
        return matrix;
    }
}

void WriteMatrixToFileFromTerminal(Matrix *matrix)
{
    char fileName[51];
    printf("Please type in your new file's path where you want to write the matrix (50 char long at max): \n");
    scanf("%50s", fileName);

    if(fileName[strlen(fileName) - 1] == '\n')
    {
        fileName[strlen(fileName) - 1] = '\0';
    }
    
    WriteMatrixToFile(matrix, fileName);
}

void FillMatrixWithDefaultValues(Matrix *matrix)
{
    for(int i = 0; i<matrix->rows; i++)
    {
        for(int j = 0; j<matrix->columns; j++)
        {
            matrix->data[i][j] = 1;
        }
    }
}