#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Amount of .bat lines in text file
#define MAX_LINES 20
// Max length for the name of each .bat file
#define MAX_LINE_LENGTH 100

int main() {
    // Run windowless
    FreeConsole();

    // Config file
    const char *config = "config.ini";
    FILE *configFile = fopen(config, "r");
    int delay;
    int windowless;
    fscanf(configFile, "%d", &delay);

    if (configFile == NULL) {
        perror("Unable to open file");
        return 1;
    }
    printf("%d\n", delay);

    fclose(configFile);

    // Text file name
    const char *fileName = "BatchList.txt";
    // Pointer to read set file
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int lineCount = 0;

    while (fgets(lines[lineCount], sizeof(lines[lineCount]), file)) {
        // Remove newline character if any
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0';
        lineCount++;

        // Check if the maximum number of lines was exceeded
        if (lineCount >= MAX_LINES) {
            fprintf(stderr, "Exceeded maximum number of lines (%d)\n", MAX_LINES);
            break;
        }
    }

    fclose(file);

    // Set delay based on DELAY define when scripts will start executing
    Sleep(delay*1000);

    // Run system() function to activate each batch
    for (int i = 0; i < lineCount; i++) {
        printf("> Executing batch #%d.\n", i + 1);
        system(lines[i]);
        Sleep(1000);
    }

    return 0;
}