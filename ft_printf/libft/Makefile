# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/09 12:32:15 by crgrandj          #+#    #+#              #
#    Updated: 2026/10/12 17:46:08 by crgrandj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

# Variable qui contient tout les .c
SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
		ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c 

# := : Pour dire a droite "pour tout les fichier .c fait moi un .o"
OBJS :=	$(SRC:%.c=%.o)

RM = rm -f

CCFLAGS = -Wextra -Wall -Werror

INC_DIR = .

CPPFLAGS = -I$(INC_DIR)

ARRNAME = ar rcs $(NAME)

CC = gcc

all: $(NAME)


$(NAME): $(OBJS)
	$(ARRNAME) $(OBJS)

# Compile les .o avec leur .c
%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $< 

# Supp tout les .o file
clean:
	$(RM) $(OBJS)

# Doit etre run apres clean !!  
 fclean: clean
	$(RM) $(NAME)

# re call fclean->clean and all
re: fclean all

.PHONY: all clean fclean re