# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 14:29:01 by lde-moul          #+#    #+#              #
#    Updated: 2017/08/29 15:13:05 by lde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem-in

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = objs

SRCBASE = main.c\
		  solver.c\
		  distances.c\
		  parser.c\
		  room.c\
		  get_room_by_name.c\
		  tube.c\
		  line.c\
		  get_next_line.c\

SRC = $(SRCBASE:%=$(SRCDIR)/%)
OBJ = $(SRCBASE:%.c=$(OBJDIR)/%.o)

DIR_LIBFT = libft
NAME_LIBFT = $(DIR_LIBFT)/libft.a
INC_LIBFT = $(DIR_LIBFT)/includes


.PHONY: all clean fclean re

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ_LIBFT)
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME_LIBFT)
	@/bin/rm -f $(NAME)

re: fclean all

$(NAME): $(NAME_LIBFT) $(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(NAME_LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC_LIBFT)

$(OBJDIR):
	@/bin/mkdir $(OBJDIR)

$(NAME_LIBFT):
	@make -C $(DIR_LIBFT)
