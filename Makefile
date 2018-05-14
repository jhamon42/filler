# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 14:53:08 by jhamon            #+#    #+#              #
#    Updated: 2018/05/14 20:23:15 by jhamon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jhamon.filler

AUTEUR = jhamon
CC = gcc
FLAG = -Wall -Werror -Wextra
G3 = -fsanitize=address -g3
OBJ = $(SRC:.c=.o)
SRC = main.c ft_chr_oink.c ft_cas_prt.c ft_hercul.c ft_parseur.c ft_rec_tb.c ft_vrf_plac.c ft_rsv_flr.c ft_chr_ink.c ft_iter_ink.c
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
	@$(call _UNDER)
	@$(call _YELLOW) && printf "$1	"
	@$(call _END)
	@$(call _GREEN) && printf "[Ok]\n"
	@$(call _END)
endef

define FOK
	@$(call _CYAN) && printf "\n$(NAME)	"
	@$(call _GREEN) && printf "[Compiled]\n"
	@$(call _END)
endef

define BULSHIT
	@$(call _PURPLE) && printf "\nauteur :	"
	@$(call _RED) && printf "$(AUTEUR)\n"
	@$(call _END)
endef

all : $(NAME)
	@:

$(NAME) : $(OBJ) auteur
	@make -C libft SLEEP=1
	@make -C visu
	$(call LOK)
	@$(CC) -o $@ $(SRC) $(LIB) $(FLAG)
	$(call FOK,$*)


%.o: %.c
	@$(CC) -c $(FLAG) $< -o $@
	$(call OK,$*)

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
	$(call FOK,$*)

debug : $(OBJ)
	@$(CC) -o $(NAME) $(SRC) $(LIB) $(G3)


auteur :
	@touch $@ && echo $(AUTEUR) > $@
	$(call BULSHIT,$(AUTEUR))

.PHONY : all clean fclean re force silence otr
