#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int countLines(char *filePath)
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

int countColumns(char *filePath)
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

int countDigits(int number)
{
    int count = 0;

    if (number == 0)
    {
        return 1;
    }

    while (number != 0)
    {
        number /= 10;
        count++;
    }

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
void printNumberBasedOnDigit(int maxDigits, int valueToPrint)
{
    int actualDigits = countDigits(valueToPrint);
    switch (maxDigits)
    {
    case 1:
        printf("%d ", valueToPrint);
        break;
    case 2:
        switch(actualDigits)
        {
            case 1:
                printf(" %d ", valueToPrint);
                break;
            case 2:
                 printf("%d ", valueToPrint);
                break;
        }
        break;
    case 3:
        switch(actualDigits)
        {
            case 1:
                printf("  %d ", valueToPrint);
                break;
            case 2:
                 printf(" %d ", valueToPrint);
                break;
            case 3:
                printf("%d ", valueToPrint);
                break;
        }
        break;
    }
}
void DisplayMatrixBetter(Matrix *matrix)
{
    int temp;
    int numbers = matrix->rows * matrix->rows;
    int maxDigitLength = countDigits(numbers);
    for(int i = 0; i < matrix->rows; i++)
    {
        for(int j = 0; j < matrix->columns; j++)
        {
            temp = matrix->data[i][j];
            printNumberBasedOnDigit(maxDigitLength, temp);
        }
        printf("\n");
    }
    printf("\n");
}

int file_exists(char *filename)
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

RotationMapping initRotationMapping()
{
    RotationMapping rotationMapping;
    rotationMapping.x1 = 0;
    rotationMapping.x2 = 0;
    rotationMapping.x3 = 0;
    rotationMapping.x4 = 0;
    rotationMapping.y1 = 0;
    rotationMapping.y2 = 0;
    rotationMapping.y3 = 0;
    rotationMapping.y4 = 0;
    return rotationMapping;
}

RotationMapping createRotationMapping(int combinedDirection)
{
    RotationMapping rotationMapping = initRotationMapping();
    switch (combinedDirection)
    {
    case 11: // UP CW
        rotationMapping.x1 = -1;
        rotationMapping.x3 = 1;
        rotationMapping.y2 = 1;
        rotationMapping.y4 = -1;
        break;
    case 21: // UP CCW
        rotationMapping.x1 = -1;
        rotationMapping.x3 = 1;
        rotationMapping.y2 = -1;
        rotationMapping.y4 = 1;
        break;
    case 12: // DOWN CW
        rotationMapping.x1 = 1;
        rotationMapping.y2 = -1;
        rotationMapping.x3 = -1;
        rotationMapping.y4 = 1;
        break;
    case 22: // DOWN CCW
        rotationMapping.x1 = 1;
        rotationMapping.x3 = -1;
        rotationMapping.y2 = 1;
        rotationMapping.y4 = -1;
        break;
    case 13: //RIGHT CW
        rotationMapping.y1 = 1;
        rotationMapping.x2 = 1;
        rotationMapping.y3 = -1;
        rotationMapping.x4 = -1;
        break;
    case 23: // RIGHT CCW
        rotationMapping.y1 = 1;
        rotationMapping.x2 = -1;
        rotationMapping.y3 = -1;
        rotationMapping.x4 = 1;
        break;
    case 14: // LEFT CW
        rotationMapping.y1 = -1;
        rotationMapping.x2 = -1;
        rotationMapping.y3 = 1;
        rotationMapping.x4 = 1;
        break;
    case 24: // LEFT CCW
        rotationMapping.y1 = -1;
        rotationMapping.x2 = 1;
        rotationMapping.y3 = 1;
        rotationMapping.x4 = -1;
        break;
    default:
        printf("Ups, something went wrong. Couldn't create matrix!");
        break;
    }

    return rotationMapping;
}

oddDeltas getOddDeltas(int combinedDirection)
{
    oddDeltas oddDelta;
    oddDelta.deltaX = 0;
    oddDelta.deltaY = 0;

    switch (combinedDirection)
    {
    case 11: // UP CW
        oddDelta.deltaY = -1;
        break;
    case 21: // UP CCW
        
        break;
    case 12: // DOWN CW
        oddDelta.deltaX = -1;
        break;
    case 22: // DOWN CCW
        oddDelta.deltaX = -1;
        oddDelta.deltaY = -1;
        break;
    case 13: //RIGHT CW
        oddDelta.deltaX = -1;
        oddDelta.deltaY = -1;
        break;
    case 23: // RIGHT CCW
        oddDelta.deltaY = -1;
        break;
    case 14: // LEFT CW
        oddDelta.deltaY = -1;
        break;
    case 24: // LEFT CCW
        oddDelta.deltaX = -1;
        break;
    }

    return oddDelta;
}

void GenerateMatrix(Matrix *matrix, int combinedDirection)
{
    RotationMapping rotationMapping = createRotationMapping(combinedDirection);
    int N = matrix->rows;
    int x = N / 2;
    int y = x;
    if(N % 2 == 0)
    {
        oddDeltas oddDelta = getOddDeltas(combinedDirection);
        x = x + oddDelta.deltaX;
        y = y + oddDelta.deltaY;
    }
    int k = 1;
    int i = 1;
    int until = N * N;
    matrix->data[x][y] = i;
    while (i != until)
    {
        if(k % 2 == 1)
        {
            for(int j = 0; j <k; j++)
            {
                if(i != until){
                    i++;
                    x = x + rotationMapping.x1;
                    y = y + rotationMapping.y1;
                    matrix->data[x][y] = i;
                }
            }

            for(int j = 0; j <k; j++)
            {
                if(i != until){
                    i++;
                    x = x + rotationMapping.x2;
                    y = y + rotationMapping.y2;
                    matrix->data[x][y] = i;
                }
            }
        }else{
            for(int j = 0; j <k; j++)
            {
                if(i != until){
                    i++;
                    x = x + rotationMapping.x3;
                    y = y + rotationMapping.y3;
                    matrix->data[x][y] = i;
                }
            }

            for(int j = 0; j <k; j++)
            {
                if(i != until){
                    i++;
                    x = x + rotationMapping.x4;
                    y = y + rotationMapping.y4;
                    matrix->data[x][y] = i;
                }
            }
        }
        
        k++;
    }
}
    