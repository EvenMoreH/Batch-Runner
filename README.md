# Batch Runner v2

## Instructions
1. In line 1 of config.ini set the delay, how much time must pass before scripts execution (must be in seconds).
2. Write batch scripts directly in scripts.txt (example file included in the folder).
3. Create a shortcut to BatchRunner.exe and place the shortcut in your Startup folder.

### BatchRunnerConsole.exe
Compiled .exe that runs with console window turned on.

## Project Tree
📦Batch-Runner
 ┣ 📂build
 ┃ ┣ 📜BatchRunner.exe
 ┃ ┗ 📜BatchRunnerConsole.exe
 ┣ 📂include
 ┃ ┣ 📜config.ini
 ┃ ┣ 📜example.txt
 ┃ ┗ 📜scripts.txt
 ┣ 📂src
 ┃ ┗ 📜BatchRunner.c
 ┣ 📜.gitignore
 ┗ 📜README.md