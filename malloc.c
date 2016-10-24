/*** malloc.c for tp malloc in /home/rouane_q/projets/unix/malloc/tp
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Mon Feb  3 10:35:24 2014 quentin rouanet
** Last update Thu Feb  6 15:42:57 2014 quentin rouanet
*/

#include "malloc.h"

t_blockmem *g_first = NULL;

void		add_last(t_blockmem *p)
{
  t_blockmem	*end;

  end = g_first;
  while (end->next != NULL)
    end = end->next;
  end->next = p;
}

t_blockmem	*alloc(size_t size)
{
  t_blockmem	*ptr;

  ptr = (t_blockmem *)sbrk(0);
  if (sbrk(SIZE_BLOCK) == (void*)-1)
    return (NULL);
  ptr->next = NULL;
  ptr->free = 0;
  ptr->size = size;
  ptr->ptr = sbrk(0);
  if (sbrk(size) == (void*)-1)
    return (NULL);
  return (ptr);
}

void		*malloc(size_t size)
{
  t_blockmem	*p;

  if (g_first != NULL)
    {
      p = search_memory(size);
      if (p == NULL)
	{
	  p = alloc(size);
	  if (p == NULL)
	    return (NULL);
	  add_last(p);
	}
      p->free = 0;
    }
  else
    {
      p = alloc(size);
      g_first = p;
    }

  if (p == NULL)
    return (NULL);
  else
    return (p->ptr);
}

t_blockmem	*search_memory(size_t size)
{
  t_blockmem	*base;
  int		 ok;

  base = g_first;
  ok = 0;
  while (ok == 0)
    {
      if (base == NULL)
	ok = -1;
      else if (base->free == 1 && size <= base->size)
	ok = 1;
      else
	base = base->next;
    }
  return (base);
}

void		free(void *ptr)
{
  t_blockmem	*tmp;

  tmp = g_first;
  while (tmp && tmp->ptr != ptr)
    tmp = tmp->next;
  if (tmp == NULL)
    ptr = NULL;
  else if (tmp->ptr == ptr)
    {
      ptr = memset(ptr, 0, tmp->size);
      tmp->free = 1;
    }
  else
    ptr = NULL;
}
