NAME = libftprintf

LIBFT = libft

SRC = ft_parse.c ft_util_str.c ft_printf.c util.c\
		ft_printf_c.c ft_printf_int.c ft_printf_x.c\
		ft_printf_uns.c ft_itoa_super.c

SRC_OBJECTS = $(patsubst %.c,%.o,$(SRC))

HEADERS = ft_printf.h

FLAGS = -Wall -Wextra -Werror -g

all: MKLIB $(NAME).a

MKLIB:
	make -C $(LIBFT)
$(NAME).a: $(LIBFT)/$(LIBFT).a $(SRC_OBJECTS)
	cp $(LIBFT)/$(LIBFT).a ./$(NAME).a
	ar rcs $(NAME).a $(SRC_OBJECTS)

# $@ -Имя цели обрабатываемого правила
# $< Имя первой зависимости обрабатываемого правила
%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$@ added"
clean:
	@/bin/rm -rf $(SRC_OBJECTS)
	make -C $(LIBFT) clean
	@echo "All objects removed"

fclean: clean
	@/bin/rm -rf $(NAME).a
	make -C $(LIBFT) fclean
	@echo "$(NAME) removed"

re:
	make -C $(LIBFT) fclean
	make fclean
	make all

bonus: all
.PHONY: all clean fclean re
