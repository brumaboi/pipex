# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 17:45:57 by sbruma            #+#    #+#              #
#    Updated: 2024/06/01 22:40:48 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
NAME_BONUS		=	pipex_bonus
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar rcs

LIBFT_PATH = ./libft
LIBFT = libft.a
INC				= inc/
BONUS_INC		= inc_bonus/
SRC_DIR			= src/
SRC_BONUS_DIR	= src_bonus/
OBJ_DIR			= obj/
OBJ_BONUS_DIR	= obj_bonus/

SRC = $(SRC_DIR)pipex.c \
	  $(SRC_DIR)pipex_handler.c \
	  $(SRC_DIR)pipex_utils.c \
	  $(SRC_DIR)split.c \
	  $(SRC_DIR)path-finder.c

SRC_BONUS = 

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
BONUS_OBJ = $(patsubst $(SRC_BONUS_DIR)%.c,$(OBJ_BONUS_DIR)%.o,$(SRC_BONUS))

all :	$(NAME)
bonus : $(NAME_BONUS)

$(NAME) : $(OBJ) $(LIBFT_PATH)/$(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_PATH)/$(LIBFT)
$(NAME_BONUS) : $(BONUS_OBJ) $(LIBFT_PATH)/$(LIBFT)
	@$(CC) $(CFLAGS) -D BONUS -o $(NAME_BONUS) $(BONUS_OBJ) $(LIBFT_PATH)/$(LIBFT)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJ_BONUS_DIR)%.o:	$(SRC_BONUS_DIR)%.c
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) -I $(BONUS_INC) -c $< -o $@
						
$(LIBFT_PATH)/$(LIBFT) : 
	@make -C $(LIBFT_PATH)

clean :
	@$(RM) -f $(OBJ) $(BONUS_OBJ)
	@$(RM) -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make -C $(LIBFT_PATH) clean

fclean : clean
	@$(RM) -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_PATH) fclean

re : clean fclean all bonus