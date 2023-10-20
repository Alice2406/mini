# Nom de l'archive
NAME	=	libft.a

# compilateur utiliser
CC = cc

# les flags pour la compialtion
CFLAGS = -Wall -Wextra -Werror

# l'empalcement du directorie pour la compilation
HEADERS = .

# les fichier de .c de la partie principale
SRC = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_bzero.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_atoi.c \
			ft_atoli.c \
			ft_atolli.c \
			ft_itoa.c \
			ft_calloc.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strncmp.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_free_tab.c \
			ft_tab_size.c \
			get_next_line.c \
			get_next_line_utils.c 

# specifie aue OBJ represente les .c des SRC en .o
OBJ = $(SRC:.c=.o)

# Reset
Nocolor	=	\033[0m

# Regular Colors
Black		=	\033[0;30m
Red			=	\033[0;31m
Green		=	\033[0;92m
Yellow	=	\033[0;33m
Blue		=	\033[0;34m
Purple	=	\033[0;35m
Cyan		=	\033[0;36m
White		=	\033[0;37m

all : $(NAME)

# ar rc :	"ar" est la commande pour creer une archive
#					"r" est pour gerer l'actualisation des fichier deja existant dans l'archive
#					"c" est pour empecher un warning et recreer l'archive si elle n'existe pas apres une update
#ranlib :	creer un index dans l'archive ce aui rend plus rapide et simplifie l'utilisation de l'archive (revient a faire "ar -s")
$(NAME)	: $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo -e '\n	$(Green)compiling [libft] done$(Nocolor)'

# "%.o : %.c" =	".c.o :"
# Permet de construire des .o a partir de .c (c'est une regle generique)
# $< =	le nom de la premiere dependance (ici .c)
# $@ =	le nom de la cible (ici .o)
# -c :	ne link pas les fichiers sources et les transforme en .o
# -o 'file' :	plae the primary output in file 'file'
# - I :	include le directorie $(HEADERS)
# -lbsd : c'est pour utiliser strlcat pour les test donc pas important
%.o : %.c
	@echo -e '$(Yellow)compiling $(Cyan) $@'
	@$(CC) -c $(CFLAGS) $< -o $@ -I $(HEADERS)

norm :
	@echo "\n		$(Purple)Norminette libft$(Nocolor)\n"
	@norminette $(SRC) libft.h get_next_line.h
	@echo -en '\n'

# Enleve les .o / -f = --force
clean	:
	@rm -f $(OBJ)
	@echo -e '$(Green)libft clean !$(Nocolor)'

# Appelle clean et enleve le libft.a
fclean	: clean
	@rm -f $(NAME)
	@echo -e '$(Green)libft.a remove !$(Nocolor)'

re	: fclean all

.PHONY : clean norm
