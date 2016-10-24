/*
** malloc.h for malloc in /home/rouane_q/projets/unix/malloc/tp
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Mon Feb  3 14:51:35 2014 quentin rouanet
** Last update Thu Feb  6 15:45:29 2014 quentin rouanet
*/

#ifndef MALLOC_H__
# define MALLOC_H__

#include <sys/types.h>
#include <unistd.h>
#include <string.h>

typedef struct		s_blockmem
{
  int			free;
  size_t		size;
  void			*ptr;
  struct s_blockmem	*next;
}			t_blockmem;

t_blockmem	*search_memory(size_t size);
void		add_last(t_blockmem *p);
t_blockmem	*alloc(size_t size);
void		*malloc(size_t size);
void		free(void *ptr);
void		*realloc(void *ptr, size_t size);
void		*calloc(size_t nmemb, size_t size);

#define SIZE_BLOCK sizeof(struct s_blockmem)

#endif /* !MALLOC_H__ */
