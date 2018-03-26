# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#              #
#    Updated: 2018/03/26 15:15:42 by jhamon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jhamon.filler

CC = gcc
FLAG = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
SRC = main.c
LIB = -L libft -lft
INC = -I libft/

define OK
	@tput setaf 254
	@echo -n $1
	@tput setaf 10
	@echo ' 	[Ok]'
	@tput sgr0
endef

define FOK
	@echo ''
	@tput setaf 50
	@echo -n $(NAME)
	@tput setaf 10
	@tput blink 10
	@echo ' [Compiled]'
	@tput sgr0
endef

define LOK
	@tput setaf 50
	@echo -n 'libft'
	@tput setaf 10
	@echo '	 	[Compiled]'
	@tput sgr0
endef

all : $(NAME)
	@:

$(NAME) : $(OBJ)
	@make -C libft SLEEP=1
ifndef SLEEP
	$(call LOK)
endif
	@$(CC) -o $@ $(SRC) $(LIB) $(FLAG)
ifndef SLEEP
	$(call FOK, $*)
endif

%.o: %.c
	@$(CC) -c $(FLAG) $< -o $@
ifndef SLEEP
	$(call OK, $*)
endif

clean :
	@make -C libft clean
	@rm -rf $(OBJ)
	@tput setaf 50
	@echo -n 'Obj_fdf'
	@tput setaf 10
	@echo '	clean success'
	@tput sgr0

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@tput setaf 50
	@echo -n $(NAME)
	@tput setaf 10
	@echo '	clean success'
	@tput sgr0

re : fclean all

silence :
	@make SLEEP=1

force : $(OBJ)
	@make -C libft force SLEEP=1
	$(call LOK)
	$(call MLXOK)
	@$(CC) -o $(NAME) $(SRC) $(LIB)
	$(call FOK, $*)

.PHONY : all clean fclean re force silence
