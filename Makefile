# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#              #
#    Updated: 2018/05/20 00:52:34 by jhamon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jhamon.filler

AUTEUR = jhamon

CC = gcc

FLAG = -Wall -Werror -Wextra
G3 = -fsanitize=address -g3

OBJ = $(SRC:.c=.o)
SRC = 	main.c ft_chr_oink.c ft_cas_prt.c ft_hercul.c ft_parseur.c ft_rec_tb.c \
		ft_vrf_plac.c ft_rsv_flr.c ft_chr_ink.c ft_iter_ink.c \

LIB = -L libft -lft
INC = -I libft/

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
	@make -C libft && make -C visu && make -C gen_map
	@$(CC) -o $@ $(SRC) $(LIB) $(FLAG)
	@make auteur
	$(call FOK)


%.o: %.c
	@$(CC) -c $(FLAG) $< -o $@
	$(call OK,$*)

clean :
	@make -C libft clean && make -C visu clean && make -C gen_map clean
	@rm -rf $(OBJ)
	$(call CLNOBJOK,$(OBJ))

fclean : clean
	@make -C libft fclean && make -C visu fclean && make -C gen_map fclean
	@rm -rf $(NAME) auteur traceur
	$(call CLNOK,$(NAME))

re : fclean all

force :
	@make -C libft && make -C visu
	@$(CC) -o $(NAME) $(SRC) $(LIB)

debug : $(OBJ)
	@make -C libft && make -C visu
	@$(CC) -o $(NAME) $(SRC) $(LIB) $(G3)

traceur :
	@make -C libft
	@$(CC) -o traceur check.c $(FLAG) $(LIB)

auteur :
	@touch $@ && echo $(AUTEUR) > $@
	$(call BULSHIT,$(AUTEUR))

norme :
	@make -C libft norme && make -C visu norme && make -C gen_map norme
	@norminette $(SRC) check.c

.PHONY : all clean fclean re force debug auteur traceur
