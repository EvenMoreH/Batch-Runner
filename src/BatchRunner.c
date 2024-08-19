#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Amount of .bat lines in text file
#define MAX_LINES 20
// Max length for the name of each .bat file
#define MAX_LINE_LENGTH 100

// Max length of command = 512 characters
char command[513];

int main() {
    // Run windowless
    FreeConsole();

    // Config file to set a delay in seconds
    const char *config = "../include/config.ini";
    FILE *configFile = fopen(config, "r");
    int delay;
    fscanf(configFile, "%d", &delay);

    if (configFile == NULL) {
        perror("Unable to open file");
        return 1;
    }

    fclose(configFile);

    // Scripts file name
    const char* scripts = "../include/scripts.txt";
    FILE* scriptsFile = fopen(scripts, "r");

    if (scriptsFile == NULL) {
        perror("Unable to open file");
        return 1;
    }

    // Set delay based on DELAY define when scripts will start executing
    Sleep(delay*1000);

    while (fscanf(scriptsFile, "%512[^\n]\n", &command) != EOF)
    {
        system(command);
        printf("\n--------------------\n\n");
    }

    fclose(scriptsFile);


    return 0;
}