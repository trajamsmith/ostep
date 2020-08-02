#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("No filename provided.\n");
    return 1;
  }

  if (argc > 1) {
    // We want to accept any number of file names
    for (int i = 1; i < argc; i++) {
      FILE *fp = fopen(argv[i], "r");
      char *line = malloc(100);

      if (fp == NULL) {
        printf("wcat: cannot open file\n");
        return 1;
      }

      // This is the syntax for reading through a file
      while (fgets(line, 100, fp) != NULL) {
        printf("%s", line);
      }
    }
  }

  return 0;
}