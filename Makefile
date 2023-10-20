NAME = minishell

CC = cc

CFLAG = -Wall -Werror -Wextra -g

LIBFTDIR = ./libft

LIB = ./libft/libft.a

READLINEFLAG = -L /usr/lib/x86_64-linux-gnu -lreadline

SRC = $(addprefix src/, minishell.c signal.c parsing.c error_msg.c garbage_collector.c utils.c new_env.c path_split.c init_struct.c)

OBJ = $(SRC:.c=.o)

# Reset
Color_Off	=	\033[0m

# Regular Colors
Black		=	\033[0;30m
Red			=	\033[0;31m
Green		=	\033[0;92m
Yellow	=	\033[0;33m
Blue		=	\033[0;34m
Purple	=	\033[0;35m
Cyan		=	\033[0;36m
White		=	\033[0;37m

all : $(LIB) $(NAME)

$(LIB) :
	@make -C $(LIBFTDIR)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(READLINEFLAG) $(LIB)
	@echo -e '\n$(Blue)compiling $(Yellow)[$(Green)minishell$(Yellow)] $(Green)done !$(Color_Off)'

%.o : %.c
	@echo -en '\n$(Blue)compiling $(Cyan)$@$(Color_Off)'
	@$(CC) -c $(CFLAG) $< -o $@

ms : $(NAME)
	@rm -f $(OBJ)
	@echo -e '$(Green)src clean !$(Color_Off)'

clean :
	@make clean -C $(LIBFTDIR)
	@rm -f $(OBJ)
	@echo -e '$(Green)src clean !$(Color_Off)'

fclean :
	@make fclean -C $(LIBFTDIR)
	@rm -f $(OBJ) $(NAME)
	@echo -e '$(Green)src clean !$(Color_Off)'
	@echo -e '$(Green)minshell remove !$(Color_Off)'

re : fclean all

norm :
	@echo -e '		$(Purple)Norminette minishell$(Color_Off)\n'
	@norminette $(SRC) include
	@echo -en '\n'

.PHONY : libft norm clean fclean