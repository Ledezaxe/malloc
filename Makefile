##
## Makefile for malloc in /home/rouane_q/projets/unix/malloc/tp
## 
## Made by quentin rouanet
## Login   <rouane_q@epitech.net>
## 
## Started on  Mon Feb  3 10:40:41 2014 quentin rouanet
## Last update Wed Feb  5 16:51:21 2014 quentin rouanet
##

NAME	= libmy_malloc_$(HOSTTYPE).so

SRCS	= malloc.c \
	  calloc.c \
	  realloc.c

OBJ	= $(SRCS:.c=.o)

CC	= gcc -shared -fPIC

RM	= rm -f

ECHO	= @echo -e

CFLAGS	+= -W -Wall -Wextra -Werror -I -pedantic

all	: $(NAME)

$(NAME)	: $(OBJ)
	  $(CC) -o $(NAME) $(OBJ)
	  $(ECHO) '\033[0;32m> Compiled\033[0m'

clean	:
	  $(RM) $(OBJ)
	  $(RM) *~
	  $(RM) \#*#
	  $(ECHO) '\033[0;31m> Directory cleaned\033[0m'

fclean	: clean
	  $(RM) $(NAME)
	  $(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

.PHONY	: all clean fclean re

