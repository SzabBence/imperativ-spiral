#include <stdio.h>
#include <stdlib.h>

int countLines(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return -1;  // Return -1 to indicate an error
    }

    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    fclose(file);
    return count;
}

int countColumns(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return -1;  // Return -1 to indicate an error
    }

    int count = 0;
    char ch;

    // Read the first line to determine the number of columns
    while ((ch = fgetc(file)) != '\n' && ch != EOF) {
        if (ch == ' ') {
            count++;
        }
    }

    // Increment count for the last column
    count++;

    fclose(file);
    return count;
}

int** GetMatrixFromPath(int rows, int columns, const char *filePath) {
    FILE *file = fopen(filePath, "r");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }

    // Read the matrix from the file
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (fscanf(file, "%d", &matrix[i][j]) != 1)
            {
                fprintf(stderr, "Error reading matrix from file\n");
                fclose(file);

                // Free allocated memory before returning
                for (int k = 0; k < rows; k++)
                {
                    free(matrix[k]);
                }
                free(matrix);

                return NULL;
            }
        }
    }

    // Close the file
    fclose(file);

    return matrix;
}

void WriteMatrixToFile(int** matrix, int rows, int columns, const char *filePath)
{
    FILE *file = fopen(filePath, "w");

    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    // Write the matrix to the file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    // Close the file
    fclose(file);

    printf("Matrix successfully written to file: %s\n", filePath);
}

void FreeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void DisplayMatrix(int** matrix, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    const char *filePath = "matrix.txt";  // Replace with your file path
    int lines = countLines(filePath);
    int columns = countColumns(filePath);

    int** matrix = GetMatrixFromPath(lines, columns, filePath);

    if (matrix != NULL) 
    {
        
        DisplayMatrix(matrix, lines, columns);

        WriteMatrixToFile(matrix, lines, columns, "matrixFromMemory.txt");

        FreeMatrix(matrix, lines);
    }

    return 0;
}
