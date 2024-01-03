#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int **data;  
    int rows;     
    int columns;  
} Matrix;

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

    // Allocate memory for the matrix data
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

Matrix LoadDataToMatrix(const char *filePath)
 {
    // Example implementation:
    Matrix matrix = CreateMatrix(countLines(filePath), countColumns(filePath));  

    // Read matrix from file and populate matrix.data
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

    return matrix;
}

void WriteMatrixToFile(Matrix *matrix, const char *filePath)
{
    FILE *file = fopen(filePath, "w");

    if (file == NULL)
    {
        perror("Error opening file for writing");
        return;
    }

    // Write the matrix to the file
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            fprintf(file, "%d ", matrix->data[i][j]);
        }
        fprintf(file, "\n");
    }

    // Close the file
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
}

int main() {
    const char *filePath = "matrix.txt";
    const char *outputPath = "structResult.txt";

    Matrix matrix = LoadDataToMatrix(filePath);
    
    DisplayMatrix(&matrix);

    WriteMatrixToFile(&matrix, outputPath);

    FreeMatrix(&matrix);

    return 0;
}
