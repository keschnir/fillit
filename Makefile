# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/17 11:29:05 by fablin       #+#   ##    ##    #+#        #
#    Updated: 2017/11/27 13:47:03 by fablin      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
NAME =		fillit

INC_DIR =	./inc/

SRC_DIR =	./src/

OBJ_DIR =	./obj/

C_FILES =	main.c					\
			ft_print_solution.c		\
			ft_solve.c				\
			ft_test_input.c			\
			ft_set_env.c			\
			ft_set_tetri.c			\
			ft_set_tetri_ext.c		\
			ft_solve_ext.c			\

O_FILES =	$(C_FILES:.c=.o)

SOURCES =	$(addprefix $(SRC_DIR), $(C_FILES))

OBJECTS =	$(addprefix $(OBJ_DIR), $(O_FILES))

CC =		gcc

CC_FLAGS =	-Wall -Werror -Wextra

DEBUG_FLAG = -ggdb

I_LIBFT = -I ./libft/inc

all: $(NAME)

$(NAME):$(OBJECTS)
	@make -C libft
	@$(CC) $(CC_FLAGS) $(OBJECTS) -I ./inc/ -I ./libft/inc/ -L libft/ -lft -o $(NAME)
	@echo "$(NAME) is ready :)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CC_FLAGS) -c $< -o $@ -I ./inc/ -I ./libft/inc/

clean:
	@make clean -C libft
	@rm -fr $(OBJ_DIR)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
	@make re -C libft

.PHONY: all clean fclean re