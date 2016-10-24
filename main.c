/*
** main.c for tp malloc in /home/rouane_q/projets/unix/malloc/tp
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Mon Feb  3 10:53:59 2014 quentin rouanet
** Last update Thu Feb  6 15:06:09 2014 quentin rouanet
*/

#include <stdlib.h>
#include <stdio.h>

struct test
{
  int ceci;
  char est;
  char un;
  unsigned short test;
};

int main()
{
  char *ptr;
  void *nul;
  void *tres_lourd;
  void *lourd;
  void *leger;
  int i;
  struct test *t;

  i = 0;
  t = malloc(sizeof(struct test));
  ptr = malloc(5 * sizeof(char));
  t->est = 'o';
  t->un = 'k';
  printf("%c%c\n", t->est, t->un);
  ptr[0] = 'p';
  ptr[1] = 'l';
  ptr[2] = 'o';
  ptr[3] = 'p';
  ptr[4] = ' ';
  ptr = realloc(ptr, 500);
  ptr[5] = '!';
  ptr[6] = '\0';
  printf("%s\n", ptr);
  nul = malloc(0);
  free(nul);
  tres_lourd = malloc(1000000000);
  if (tres_lourd == NULL)
    write(1, "down\n", 6);
  free(tres_lourd);
  lourd = malloc(1000000);
  leger = calloc(0, 1);
  free(ptr);
  free(ptr);
  free(t);
  free(lourd);
  free(leger);
  /* while (i < 50) */
  /*   { */
  /*     lourd = malloc(1000000); */
  /*     free(lourd); */
  /*     leger = malloc(1); */
  /*     free(leger); */
  /*     i++; */
  /*   } */
}
