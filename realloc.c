/*
** realloc.c for realloc in /home/rouane_q/projets/unix/malloc/tp
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Wed Feb  5 16:49:25 2014 quentin rouanet
** Last update Thu Feb  6 15:39:39 2014 quentin rouanet
*/

#include "malloc.h"

void    *realloc(void *ptr, size_t size)
{
  void  *new;

  if (ptr == NULL)
    new = malloc(size);
  else if (size == 0)
    free(ptr);
  else
    {
      new = malloc(size);
      if (new != NULL)
        new = memcpy(new, ptr, size);
    }
  return (new);
}
