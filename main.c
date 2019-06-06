#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "lib/mathlib.h"
#include <stdio.h>
#include <memory.h>

char getoptChar(int argc, char **argv)
{
  extern char *optarg;
  char opt;
  printf("%c", opt);
  while ((opt = getopt(argc, argv, "f:asm")) != -1)
  {
    switch (opt)
    {
    case 'm':
      return 'a';

    case 's':
      return 'b';

    default:
      break;
    }
  }
  return '0';
}

int main(int argc, char **argv)
{
  int a, b, c, wynik;
  printf("[a - POLE PROSTOPADLOSCIANU | b - PITAGORAS | c - ls -l | d - STWORZ FOLDER + nazwa]\n");
  char liczba = getoptChar(argc, argv), command[50], opcja;

  char folder[50];
  char mk[50];
  if (liczba == 'b')
  {
    printf("WYBIERZ ZADANIE: ");
    scanf("%s", &opcja);
    if (opcja == 'd')
    {
      printf("PODAJ NAZWE KATALOGU: ");
      scanf("%s", folder);
    }
    strcpy(mk, "mkdir ");
    strcpy(folder, folder);
    strcat(mk, folder);
    printf("%s", mk);
    switch (opcja)
    {
    case 'c':
      strcpy(command, "ls -l");
      system(command);
      return 0;
    case 'd':
      strcpy(command, mk);
      system(command);
      return 0;
    default:
      printf("%s\n", "COS POSZLO NIE TAK!");
      return -1;
    }
  }
  if (liczba == 'a')
  {
    printf("WYBIERZ ZADANIE: ");
    scanf("%s", &opcja);
    printf("PODAJ TRZY LICZBY: ");
    scanf("%i %i %i", &a, &b, &c);

    switch (opcja)
    {
    case 'a':
      printf("POLE PROSTOPADLOSCIANU: ");
      wynik = prostopadloscian(a, b, c);
      break;
    case 'b':
      printf("PITAGORAS: ");
      wynik = pitagoras(a, b, c);
      if (wynik != 0)
        printf("TAK");
      else
        printf("NIE");
      break;
    default:
      printf("%s\n", "COS POSZLO NIE TAK!");
      return -1;
    }
  }
  printf("%i\n", wynik);
  return 0;
}
