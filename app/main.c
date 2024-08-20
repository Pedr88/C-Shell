#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
  bool running = true;
  
  char input[100];
  while (running == true) {
    printf("$ ");
    fflush(stdout);

    fgets(input, 100, stdin);

    input[strcspn(input, "\n")] = 0;
    printf("%s: command not found\n", input);
  } 

  return 0;
}
