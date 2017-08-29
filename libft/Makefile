# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-moul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 11:29:42 by lde-moul          #+#    #+#              #
#    Updated: 2017/08/29 15:02:43 by lde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes

SRCBASE = ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_strlen.c \
		  ft_strncpy.c \
		  ft_strcmp.c \
		  ft_atoi.c \
		  ft_isdigit.c \
		  ft_memalloc.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_putnbr.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdelfrom.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstrev.c \

SRC = $(SRCBASE:%=$(SRCDIR)/%)
OBJ = $(SRCBASE:%.c=$(OBJDIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

%.c:
	@/bin/echo $@ does not exist.

$(OBJDIR):
	@/bin/mkdir $(OBJDIR)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
