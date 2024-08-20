#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  char exit[4] = "exit";

  while (1) {
    printf("$ ");
    fflush(stdout);

    // Gets user input
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "exit") == 0) {
      printf("Exiting shell...\a\n");
      break;
    } else if (strncmp(input, "echo ", 5) == 0) {
      char *echo = input + 5;
      printf("%s\n", echo);
    } else {
      printf("%s: command not found\n", input);
    } 
  } 

  return 0;
}
