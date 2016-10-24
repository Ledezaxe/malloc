/*
** calloc.c for calloc in /home/rouane_q/projets/unix/malloc/tp
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Wed Feb  5 16:47:46 2014 quentin rouanet
** Last update Thu Feb  6 15:38:34 2014 quentin rouanet
*/

#include "malloc.h"

void    *calloc(size_t nmemb, size_t size)
{
  void  *p;

  p = malloc(nmemb * size);
  if (p)
    p = memset(p, 0, nmemb * size);
  return (p);
}
