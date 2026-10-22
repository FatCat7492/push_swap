# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crgrandj <crgrandj@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/16 12:23:26 by crgrandj          #+#    #+#              #
#    Updated: 2026/10/16 17:49:10 by crgrandj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC =	ft_itoabx.c ft_printf.c ft_putchar_x.c ft_putnbr_x.c ft_putstr_x.c

OBJS := $(SRC:.c=.o)

RM = rm -f

CCFLAGS = -Wextra -Wall -Werror

INC_DIR = .

# -I dit include et apres on peut mettre une path dans le cas du ficher ci
#  c'est "." ce qui veut dire la ou tu es.
CPPFLAGS = -I$(INC_DIR)

ARRNAME = ar rcs $(NAME)

CC = gcc

LBA = libft/libft.a

LB = libft

# -C change de repertoire
CLB = -C $(LB)

all: $(NAME)

# %@ prend la valeur de $(NAME) soite "libftprintf.a"
$(NAME): $(OBJS) $(LBA)
	cp $(LBA) $@
	$(ARRNAME) $(OBJS)

# -C change de repertoire (ft_pritnf)  --> (libft) -> (execute "make") -> Car $(LB) depend de ca!
$(LBA):
	$(MAKE) $(CLB)
	
# Compile les .o avec leur .c
%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

# Supp tout les .o file
# %@ prend la valeur de "clean"
clean:
	$(RM) $(OBJS)
	$(MAKE) $(CLB) $@
	

# Doit etre run apres clean !!
# %@ prend la valeur de "fclean"
 fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(CLB) $@


# re call fclean->clean and all
re: fclean all
	

.PHONY: all clean fclean re