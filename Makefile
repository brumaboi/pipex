# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 17:45:57 by sbruma            #+#    #+#              #
#    Updated: 2024/05/16 14:53:16 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar rcs

LIBFT_PATH = ./libft
LIBFT = libft.a
INC				= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/

SRC = $(SRC_DIR)pipex.c \
	  $(SRC_DIR)pipex_handler.c \
	  $(SRC_DIR)pipex_utils.c

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT_PATH)/$(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_PATH)/$(LIBFT)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(LIBFT_PATH)/$(LIBFT) : 
	@make -C $(LIBFT_PATH)

clean :
	@$(RM) -f $(OBJ)
	@$(RM) -rf $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean

fclean : clean
	@$(RM) -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re : clean fclean all