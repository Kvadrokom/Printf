NAME := libftprintf.a

PRINTF := ft_printf.c

UTILS := 	bezerostruct.c\
			ft_doubletostr.c\
			ft_isdigit.c\
			ft_itoabase.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_strchr.c\
			ft_strjoin.c\
			ft_strlen.c\
			ifchar.c\
			iffloat.c\
			ifhex.c\
			ifint.c\
			ifpercent.c\
			ifptr.c\
			ifstring.c\
			ifudecint.c

PRINT :=	ft_bprint.c\
			ft_printch.c\
			ft_printnmb.c

PARCE :=	conversations.c\
			ft_printf_prs.c\
			modifiers.c\
			parcel2.c			

source_dirs := $(PRINTF) $(addprefix utils/, $(UTILS))\
				$(addprefix print/, $(PRINT))\
				$(addprefix parce/, $(PARCE))

search_wildcards := $(wildcard $(source_dirs))

OBJ := $(patsubst %.c,%.o, $(search_wildcards))

VPATH := $(source_dirs)

CC := gcc

FLAGS := -Wall -Wextra -Werror

DEBUG_FLAGS := -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	$(CC) $(DEBUG_FLAGS) $(source_dirs) main.c

debug_clean:
	rm -r a.out.dSYM

norm:
	norminette $(source_dirs) printf.h

.PHONY: all clean fclean re