#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "lib/mathLibs.h"

int openFile(char* filename) {
  int c;
  FILE *file;
  file = fopen(filename, "r");
  if (file) {
      while ((c = getc(file)) != EOF)
          putchar(c);
      fclose(file);
  }
  return 0;
}

char getCharArgs(int argc, char** argv) {
  extern char *optarg;
  char* file;
  char opt;
  while((opt = getopt(argc, argv, "f:asm")) != -1) {
    switch (opt)
    {
    case 'x':
      return 'x';

    case 'y':
      return 'y';

    case 'z':
      return 'z';

    case 's':
      return 's';

    case 'l':
      return 'l';

    case 'f':
      printf("file\n");
      file = optarg;
      openFile(file);

    default:
      break;
    }
  }
  return '0';
}

int main(int argc, char** argv) {
  int a, b, c, wynik;
  char liczba = getCharArgs(argc, argv), command[50];
  scanf("%i %i %i", &a, &b, &c);
  switch (liczba) {
  case 'x':
    wynik = delta(a, b, c);
    break;
  case 'y':
    wynik = pitagoras(a, b, c);
    break;
  case 'z':
    wynik = procent(a, b);
    break;
  case 'l':
    strcpy(command, "ls -l" );
    system(command);
  default:
    printf("%i\n", 30);
    return -1;
  }

  printf("%i\n", wynik);
  return 0;
}
