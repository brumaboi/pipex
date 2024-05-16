# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 17:45:57 by sbruma            #+#    #+#              #
#    Updated: 2024/05/07 22:49:38 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
UTILSNAME = utils.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
UTILSDIR = ./utils

SRCS =	pipex.c \
		pipex_handler.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makeutils:
	@make -C $(UTILSDIR)
	
$(NAME): makeutils $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(UTILSDIR)/$(UTILSNAME) 
	@chmod +x $(NAME)
	
clean:
	@rm -f $(OBJS)
	@cd $(UTILSDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(UTILSDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re