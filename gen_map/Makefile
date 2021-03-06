# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#              #
#    Updated: 2018/05/20 00:51:58 by jhamon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gen_map

AUTEUR = jhamon

CC = gcc

FLAG = -Wall -Werror -Wextra
G3 = -fsanitize=address -g3

OBJ = $(SRC:.c=.o)
SRC = 	main.c ft_write.c

LIB = -L ../libft -lft
INC = -I ../libft/

# Utile
_END=tput sgr0
_BOLD=tput bold
_UNDER=tput smul
_REV=tput smso
_DAFUK=tput smacs

# Colors
_GREY=tput setaf 250
_RED=tput setaf 160
_GREEN=tput setaf 10
_YELLOW=tput setaf 11
_BLUE=tput setaf 27
_PURPLE=tput setaf 92
_CYAN=tput setaf 50
_WHITE=tput setaf 255

# Inverted
_IGREY=tput setab 250
_IRED=tput setab 160
_IGREEN=tput setab 10
_IYELLOW=tput setab 11
_IBLUE=tput setab 27
_IPURPLE=tput setab 92
_ICYAN=tput setab 50
_IWHITE=tput setab 255

define OK
	@$(call _GREEN) && printf "[Ok]	"
	@$(call _UNDER)
	@$(call _YELLOW) && printf "$1\n"
	@$(call _END)
endef

define FOK
	@$(call _GREEN) && printf "\n[Compiled]	"
	@$(call _CYAN) && printf "$(NAME)\n"
	@$(call _END)
endef

define CLNOK
	@$(call _GREEN) && printf "[clean]	"
	@$(call _GREY) && printf "$1\n"
	@$(call _END)
endef

define CLNOBJOK
	@$(call _GREEN) && printf "[clean]	"
	@$(call _GREY) && printf "Obj_$(NAME)\n"
	@$(call _END)
endef

define BULSHIT
	@$(call _PURPLE) && printf "auteur :	"
	@$(call _RED) && printf "$(AUTEUR)\n"
	@$(call _END)
endef

all : $(NAME)
	@:

$(NAME) : $(OBJ)
	@make -C ../libft
	@$(CC) -o $@ $(SRC) $(LIB) $(FLAG)
	@make auteur
	$(call FOK)


%.o: %.c
	@$(CC) -c $(FLAG) $< -o $@
	$(call OK,$*)

clean :
	@make -C ../libft clean
	@rm -rf $(OBJ)
	$(call CLNOBJOK,$(OBJ))

fclean : clean
	@make -C ../libft fclean
	@rm -rf $(NAME) auteur map_custom
	$(call CLNOK,$(NAME))

re : fclean all

force :
	@make -C ../libft
	@$(CC) -o $(NAME) $(SRC) $(LIB)

debug : $(OBJ)
	@make -C ../libft
	@$(CC) -o $(NAME) $(SRC) $(LIB) $(G3)

auteur :
	@touch $@ && echo $(AUTEUR) > $@
	$(call BULSHIT,$(AUTEUR))

norme :
	@norminette $(SRC)

.PHONY : all clean fclean re force debug auteur
