#include <stdio.h>
#include <stdlib.h>

// Function to calculate the result for Part 1
int part1(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Move to the end of the file to determine file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *buffer = malloc(fileSize + 1);

    if (buffer == NULL) {
        perror("Memory error");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read file into the buffer
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return EXIT_FAILURE;
    }
    buffer[fileSize] = '\0';  // Null-terminate the string

    // Prepare variables for counting '(' and ')'
    int openParentheses = 0;
    int closedParentheses = 0;

    for (long i = 0; i < fileSize; i++) {
        char ch = buffer[i];

        if (ch == '(') {
            openParentheses++;
        } else if (ch == ')') {
            closedParentheses++;
        }
    }

    // Calculate the result for Part 1
    int result = openParentheses - closedParentheses;

    // Cleanup
    free(buffer);
    fclose(file);

    return result;
}

int part2(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Move to the end of the file to determine file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *buffer = malloc(fileSize + 1);

    if (buffer == NULL) {
        perror("Memory error");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read file into the buffer
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return EXIT_FAILURE;
    }
    buffer[fileSize] = '\0';  // Null-terminate the string

    // Prepare variables for initialPosition

    int position = 0;
    int counter = 0;
    long i = 0;

    // Loop until the position reaches -1
    while (position != -1 && i < fileSize) {
        char ch = buffer[i];

        if (ch == '(') {
            position++;
        } else if (ch == ')') {
            position--;
        }
        counter++;
        i++;  // Increment i to move to the next character
    }

    // Cleanup
    free(buffer);
    fclose(file);

    return counter;
}

int main() {
    const char *filename = "1.in";
    int result = part1(filename);
    int result2 = part2(filename);

    // Output the result for Part 1 and Part 2
    if (result != EXIT_FAILURE) {
        printf("Part 1: %d\n", result);
    }

    if (result2 != EXIT_FAILURE) {
        printf("Part 2: %d\n", result2);
    }

    return (result == EXIT_FAILURE || result2 == EXIT_FAILURE) ? EXIT_FAILURE : EXIT_SUCCESS;
}
