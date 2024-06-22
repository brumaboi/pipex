# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 17:45:57 by sbruma            #+#    #+#              #
#    Updated: 2024/06/22 21:36:52 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
NAME_BONUS		=	pipex_bonus
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar rcs

BLUE			= \033[0;34m
PURPLE			= \033[0;35m
WHITE			= \033[0;37m
BLACK			= \033[0;30m
CYAN			= \033[0;36m
YELLOW			= \033[0;33m
RED				= \033[0;31m
GREEN			= \033[0;32m
NC				= \033[0m

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
	  $(SRC_DIR)path-finder.c \
	  $(SRC_DIR)validate_input.c

SRC_BONUS = $(SRC_BONUS_DIR)pipex_bonus.c \
			$(SRC_BONUS_DIR)handle_bonus.c \
			$(SRC_BONUS_DIR)utils_bonus.c \
			$(SRC_BONUS_DIR)split_bonus.c \
			$(SRC_BONUS_DIR)error_bonus.c \
			$(SRC_BONUS_DIR)path-finder_bonus.c \
			$(SRC_BONUS_DIR)validate_input_bonus.c \
			$(SRC_BONUS_DIR)here_doc.c

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
BONUS_OBJ = $(patsubst $(SRC_BONUS_DIR)%.c,$(OBJ_BONUS_DIR)%.o,$(SRC_BONUS))

all :	$(NAME) create_files
bonus : $(NAME_BONUS) create_files

$(NAME) : $(OBJ) $(LIBFT_PATH)/$(LIBFT)
	clear; \
	echo "$(RED)  ______   ______   ______   ______ "
	@echo " /_____/  /_____/  /_____/  /_____/ "
	@echo "                                    "
	@echo "                                    "
	@echo "__________.__                       "
	@echo "\______   \__|_____   ____ ___  ___ "
	@echo " |     ___/  \____ \_/ __ \\   \/  / "
	@echo " |    |   |  |  |_> >  ___/ >    <  "
	@echo " |____|   |__|   __/ \___  >__/\_ \ "
	@echo "             |__|        \/      \/ "
	@echo "                                    "
	@echo "                            -sbruma "
	@echo "  ______   ______   ______   ______ "
	@echo " /_____/  /_____/  /_____/  /_____/ $(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_PATH)/$(LIBFT)
	@pid=$$!; \
	sleep 1; \
	clear; \
	echo "$(YELLOW)  ______   ______   ______   ______ "; \
	echo " /_____/  /_____/  /_____/  /_____/ "; \
	echo "                                    "; \
	echo "                                    "; \
	echo "__________.__                       "; \
	echo "\______   \__|_____   ____ ___  ___ "; \
	echo " |     ___/  \____ \_/ __ \\   \/  / "; \
	echo " |    |   |  |  |_> >  ___/ >    <  "; \
	echo " |____|   |__|   __/ \___  >__/\_ \ "; \
	echo "             |__|        \/      \/ "; \
	echo "                                    "; \
	echo "                            -sbruma "; \
	echo "  ______   ______   ______   ______ "; \
	echo " /_____/  /_____/  /_____/  /_____/ $(NC)"; \
	sleep 1; \
	clear; \
	echo "$(GREEN)  ______   ______   ______   ______ "; \
	echo " /_____/  /_____/  /_____/  /_____/ "; \
	echo "                                    "; \
	echo "                                    "; \
	echo "__________.__                       "; \
	echo "\______   \__|_____   ____ ___  ___ "; \
	echo " |     ___/  \____ \_/ __ \\   \/  / "; \
	echo " |    |   |  |  |_> >  ___/ >    <  "; \
	echo " |____|   |__|   __/ \___  >__/\_ \ "; \
	echo "             |__|        \/      \/ "; \
	echo "                                    "; \
	echo "                            -sbruma "; \
	echo "  ______   ______   ______   ______ "; \
	echo " /_____/  /_____/  /_____/  /_____/ $(NC)"; \
	wait $$pid
	
$(NAME_BONUS) : $(BONUS_OBJ) $(LIBFT_PATH)/$(LIBFT)
	clear; \
	echo "$(RED)  ______   ______   ______   ______ "
	@echo " /_____/  /_____/  /_____/  /_____/ "
	@echo "                                    "
	@echo "                                    "
	@echo "__________.__                       "
	@echo "\______   \__|_____   ____ ___  ___ "
	@echo " |     ___/  \____ \_/ __ \\   \/  / "
	@echo " |    |   |  |  |_> >  ___/ >    <  "
	@echo " |____|   |__|   __/ \___  >__/\_ \ "
	@echo "             |__|        \/      \/ "
	@echo "                                    "
	@echo "                            -sbruma "
	@echo "  ______   ______   ______   ______ "
	@echo " /_____/  /_____/  /_____/  /_____/ $(NC)"
	@$(CC) $(CFLAGS) -D BONUS -o $(NAME_BONUS) $(BONUS_OBJ) $(LIBFT_PATH)/$(LIBFT)
	@pid=$$!; \
	sleep 1; \
	clear; \
	echo "$(YELLOW)  ______   ______   ______   ______ "; \
	echo " /_____/  /_____/  /_____/  /_____/ "; \
	echo "                                    "; \
	echo "                                    "; \
	echo "__________.__                       "; \
	echo "\______   \__|_____   ____ ___  ___ "; \
	echo " |     ___/  \____ \_/ __ \\   \/  / "; \
	echo " |    |   |  |  |_> >  ___/ >    <  "; \
	echo " |____|   |__|   __/ \___  >__/\_ \ "; \
	echo "             |__|        \/      \/ "; \
	echo "                                    "; \
	echo "                            -sbruma "; \
	echo "  ______   ______   ______   ______ "; \
	echo " /_____/  /_____/  /_____/  /_____/ $(NC)"; \
	sleep 1; \
	clear; \
	echo "$(GREEN)  ______   ______   ______   ______ "; \
	echo " /_____/  /_____/  /_____/  /_____/ "; \
	echo "                                    "; \
	echo "                                    "; \
	echo "__________.__                       "; \
	echo "\______   \__|_____   ____ ___  ___ "; \
	echo " |     ___/  \____ \_/ __ \\   \/  / "; \
	echo " |    |   |  |  |_> >  ___/ >    <  "; \
	echo " |____|   |__|   __/ \___  >__/\_ \ "; \
	echo "             |__|        \/      \/ "; \
	echo "                                    "; \
	echo "                            -sbruma "; \
	echo "  ______   ______   ______   ______ "; \
	echo " /_____/  /_____/  /_____/  /_____/ $(NC)"; \
	wait $$pid
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJ_BONUS_DIR)%.o:	$(SRC_BONUS_DIR)%.c
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) -I $(BONUS_INC) -c $< -o $@
						
$(LIBFT_PATH)/$(LIBFT) : 
	@make -C $(LIBFT_PATH) > /dev/null 2>&1

create_files:
	@touch input.txt
	@touch output.txt
	@echo "##1" > test_list.log
	@echo "Command: ./pipex input.txt \"cat\" \"cat\" output.txt" >> test_list.log
	@echo "Input (input.txt):" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo "Expected Output (output.txt):" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##2" >> test_list.log
	@echo "Command: ./pipex input.txt \"cat\" \"grep Hello\" output.txt" >> test_list.log
	@echo "Input (input.txt):" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo "Goodbye, World!" >> test_list.log
	@echo "Expected Output (output.txt):" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##3 -bonus" >> test_list.log
	@echo "Command: ./pipex_bonus input.txt \"cat\" \"grep Hello\" \"sort\" \"uniq\" output.txt" >> test_list.log
	@echo "Input (input.txt):" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo "Hello, Universe!" >> test_list.log
	@echo "Goodbye, World!" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo "Expected Output (output.txt):" >> test_list.log
	@echo "Hello, Universe!" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##4" >> test_list.log
	@echo "Command: ./pipex non_existent.txt \"cat\" \"cat\" output.txt" >> test_list.log
	@echo "Expected Output:" >> test_list.log
	@echo "(error message about non-existent file)" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##5" >> test_list.log
	@echo "Command: ./pipex input.txt \"invalid_command\" \"cat\" output.txt" >> test_list.log
	@echo "Input (input.txt):" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo "Expected Output (output.txt):" >> test_list.log
	@echo "(error message about invalid command)" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##6" >> test_list.log
	@echo "Command: ./pipex input.txt \"echo a;b\" \"sed 's/;/,/g'\" output.txt" >> test_list.log
	@echo "Input (input.txt):" >> test_list.log
	@echo "a;b" >> test_list.log
	@echo "Expected Output (output.txt):" >> test_list.log
	@echo "a,b" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##7 -bonus" >> test_list.log
	@echo "Command: ./pipex_bonus input.txt \"cat\" \"|\" \"grep Hello\" output.txt" >> test_list.log
	@echo "Expected Output:" >> test_list.log
	@echo "(error message about syntax error)" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##8 -bonus" >> test_list.log
	@echo "Command: ./pipex_bonus input.txt \"cat\" \"\" \"grep Hello\" output.txt" >> test_list.log
	@echo "Expected Output:" >> test_list.log
	@echo "(error message about empty command)" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##9" >> test_list.log
	@echo "Command: ./pipex input.txt \"cat\" \">&-\" output.txt" >> test_list.log
	@echo "Expected Output:" >> test_list.log
	@echo "(error message about invalid file descriptor)" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##10 -bonus" >> test_list.log
	@echo "Command: ./pipex_bonus input.txt \"cat\" \"grep Hello\" \"sort\" \"uniq\" \"wc -l\" output.txt" >> test_list.log
	@echo "Input (input.txt):" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo "Hello, Universe!" >> test_list.log
	@echo "Goodbye, World!" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo "Expected Output (output.txt):" >> test_list.log
	@echo "2" >> test_list.log
	@echo >> test_list.log
	@echo >> test_list.log
	@echo "##11 -add" >> test_list.log
	@echo "Command: ./pipex input.txt \"grep Hello\" \"awk '{print \$1}'\" output.txt" >> test_list.log
	@echo "Input (input.txt):" >> test_list.log
	@echo "Hello, World!" >> test_list.log
	@echo "Hello, Universe!" >> test_list.log
	@echo "Goodbye, World!" >> test_list.log
	@echo "Expected Output (output.txt):" >> test_list.log
	@echo "Hello," >> test_list.log
	@echo "Hello," >> test_list.log


clean :
	@$(RM) -f $(OBJ) $(BONUS_OBJ)
	@$(RM) -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make -C $(LIBFT_PATH) clean > /dev/null 2>&1
	@$(RM) -f input.txt output.txt test_list.log
	clear; \
	echo  "$(CYAN)  ______   ______   ______   ______ "
	@echo  " /_____/  /_____/  /_____/  /_____/ "
	@echo  "                                    "
	@echo  "       .__                          "
	@echo  "  ____ |  |   ____ _____    ____    "
	@echo  "_/ ___\|  | _/ __ \\\\__   \  /    \   "
	@echo  "\  \___|  |_\  ___/ / __ \|   |  \  "
	@echo  " \___  >____/\___  >____  /___|  /  "
	@echo  "     \/          \/     \/     \/   "
	@echo  "                                    "
	@echo  "                           -sbruma  "
	@echo  "  ______   ______   ______   ______ "
	@echo  " /_____/  /_____/  /_____/  /_____/ $(NC)"

fclean : clean
	@$(RM) -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_PATH) fclean > /dev/null 2>&1

re : clean fclean all bonus