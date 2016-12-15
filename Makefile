#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/06/15 14:15:13 by dbourdon          #+#    #+#             *#
#*   Updated: 2016/10/20 15:49:34 by dbourdon         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = ft_select

SRC = ./src/*.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean re libft norme check

all: $(NAME)

$(NAME) : libft $(OBG)
	-@clang $(FLAGS) $(SRC) -g -o $(NAME) -L./libft/ -lft -l termcap
	@echo "Compilation"

libft:
	-@make -C libft/

clean: 
	-@make -C libft/ clean
	-@rm -f $(OBJ) *.gch
	@echo "Supression"

fclean: clean
	-@rm -f $(NAME)
	-@make -C libft/ fclean
	@echo "totale..."

re: fclean all
	-@make re -C libft/

norme:
	@norminette *.[ch] ./libft/*.[ch]

check:
	@echo "***** Verification norme :"
	@make norme
	@echo "***** Verification auteur :"
	cat -e auteur
	@echo "***** Lancement du make re ... "
	@make re
	@echo "***** Fini !"
