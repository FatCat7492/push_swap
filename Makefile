NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -Ipushswap_functions

RM = rm -f

SRC = main.c \
	main_helper.c \
	algos/adaptive.c \
	algos/chunk_based_algo.c \
	algos/disorder.c \
	algos/selection_sort.c \
	algos/binary_radix_sort.c \
	algos/chunk_based_clean.c \
	algos/helpers_algos.c \
	pushswap_functions/ft_checkstat.c \
	pushswap_functions/ft_parsing.c \
	pushswap_functions/helpers.c \
	pushswap_functions/pushtop.c \
	pushswap_functions/shiftup.c \
	pushswap_functions/ft_md_atoi.c \
	pushswap_functions/ft_parsing_ultimate.c \
	pushswap_functions/shiftdown.c \
	pushswap_functions/swaptop.c \
	benchmark/benchmark.c \
	benchmark/benchmark_helpers.c \
	main_helper.c



OBJ = $(SRC:.c=.o)

PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(PRINTF): FORCE
	$(MAKE) -C ft_printf

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ft_printf fclean

re: fclean
	$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE

