#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Function to check if a file exists and is executable
int isExecutable(const char *path) { return access(path, X_OK) == 0; }

// Function to search for a command in the PATH
char *findInPath(const char *command) {
  char *pathEnv = getenv("PATH");

  if (pathEnv == NULL) {
    return NULL;
  }

  char *pathCopy = strdup(pathEnv);
  char *dir = strtok(pathCopy, ":");
  static char fullPath[1024];

  while (dir != NULL) {
    snprintf(fullPath, sizeof(fullPath), "%s/%s", dir, command);
    
    if (isExecutable(fullPath)) {
      free(pathCopy);
      return fullPath;
    }
    
    dir = strtok(NULL, ":");
  }
  
  free(pathCopy);
  return NULL;
}

// Function to change directory
void changeDirectory(const char *path) {
  char resolvedPath[1024];

  if (realpath(path, resolvedPath) != NULL) {
    if (chdir(resolvedPath) != 0) {
      perror("chdir");
    }
  } else {
      perror("realpath");
  }
}

int main() {
  char input[100];

  while (1) {
    printf("$ ");
    fflush(stdout);

    // Gets user input
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    if (strlen(input) == 0) {
      continue;
    }

    // 'Exit' command
    if (strcmp(input, "exit") == 0) {
      printf("Exiting shell...\a\n");
      break;
    }

    // 'Echo' command
    if (strncmp(input, "echo ", 5) == 0) {
      char *echo = input + 5;
      printf("%s\n", echo);
      continue;
    } 

    // 'Type' command
    if (strncmp(input, "type ", 5) == 0){
      char *type = input + 5;

        // Check for built-in commands
        if (strcmp(type, "echo") == 0 || strcmp(type, "exit") == 0 || strcmp(type, "type") == 0 || strcmp(type, "pwd") == 0) {
          printf("%s is a shell builtin\n", type);
        } else {
          // Search for the command in the PATH
          char *path = findInPath(type);
          if (path) {
            printf("%s is %s\n", type, path);
          } else {
            printf("%s: not found\n", type);
          }
        }

      continue;
    } 

    // 'Pwd' command
    if (strncmp(input, "pwd", 3) == 0) {
      char* pwd;
      char buff[1024];

      pwd = getcwd( buff, 1024 );
      if( pwd != NULL ) {
        printf( "%s\n", pwd );
      }

      continue;
    }

    // 'Cd' command
    if (strncmp(input, "cd ", 3) == 0) {
      char *cd = input + 3;
      changeDirectory(cd);

      continue;
    }
    
    
    // Command not found
    printf("%s: command not found\n", input);
  }

  return 0;
}
