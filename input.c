#include <stdio.h>

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

int main() {
    const char *filePath = "matrix.txt";  // Replace with your file path
    int lines = countLines(filePath);
    int columns = countColumns(filePath);
    printf("Number of lines in the file: %d\n", lines);
    printf("Number of columns in the file: %d\n", columns);

    return 0;
}
