# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#              #
#    Updated: 2018/03/30 22:25:59 by jhamon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jhamon.filler 

AUTEUR = jhamon
CC = gcc
FLAG = -Wall -Werror -Wextra
G3 = -fsanitize=address -g3
OBJ = $(SRC:.c=.o)
SRC = main.c ft_hercul.c ft_parseur.c ft_rec_tb.c ft_vrf_plc.c ft_rsv_flr.c ft_chr_ink.c ft_iter_ink.c
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

define OTR
	@echo -n ''
	@tput setaf 92
	@echo -n 'auteur : '
	@tput setaf 160
	@echo $(AUTEUR)
	@tput sgr0
endef

all : $(NAME)
	@:

$(NAME) : $(OBJ) auteur
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
	@rm -rf $(NAME) $(OTR)
	@tput setaf 50
	@echo -n $(NAME)
	@tput setaf 10
	@echo '	clean success'
	@tput sgr0

re : fclean all

silence :
	@make SLEEP=1

force :
	@make -C libft force
	$(call LOK)
	@$(CC) -o $(NAME) $(SRC) $(LIB)
	$(call FOK, $*)

debug : $(OBJ)
	@$(CC) -o $(NAME) $(SRC) $(LIB) $(G3)


auteur :
	@touch $@
	@echo $(AUTEUR) > $@
ifndef SLEEP
	$(call OTR, $(AUTEUR))
endif


.PHONY : all clean fclean re force silence otr
