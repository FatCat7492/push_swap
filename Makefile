NAME = push_swap
BONUS = checker

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
	algos/small_sort.c \
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
	benchmark/benchmark_helpers.c

BONUS_DIR = bonus/

BONUS_SRC = main_bonus.c \
			helper.c

GNL_DIR = gnl/

GNL_SRC = $(BONUS_DIR)$(GNL_DIR)get_next_line.c \
		$(BONUS_DIR)$(GNL_DIR)get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS_OBJS = $(addprefix $(BONUS_DIR),$(BONUS_SRC:.c=.o))

GNL_OBJ = $(GNL_SRC:.c=.o)

SHARED_OBJ = $(filter-out main.o,$(OBJ))

PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(PRINTF): FORCE
	$(MAKE) -C ft_printf

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(GNL_OBJ) $(SHARED_OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJS) $(GNL_OBJ)
	$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	$(MAKE) -C ft_printf fclean

re: fclean
	$(MAKE) all

FORCE:

.PHONY: all bonus clean fclean re FORCE bonus
