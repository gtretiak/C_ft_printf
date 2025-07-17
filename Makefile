# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtretiak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:46:38 by gtretiak          #+#    #+#              #
#    Updated: 2024/11/22 17:30:00 by gtretiak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_DIR = C_libft/
LIBFT = libft.a
SRCS_DIR = Sources/
SRCS = ft_printf.c ft_unitoa.c ft_print_address.c ft_print_hex.c \
       ft_take_address.c ft_check_chars.c ft_check_numbers.c ft_check_else.c
OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
HEAD = ft_printf.h
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT): 
	@if [ -d $(LIBFT_DIR) ]; then \
		echo "C-libft is already cloned."; \
	else \
		git clone git@github.com:gtretiak/C_libft.git $(LIBFT_DIR); \
	fi
	@if [ -f $(LIBFT_DIR)$(LIBFT) ]; then \
		echo "libft.a is already compiled."; \
	else \
		$(MAKE) -C $(LIBFT_DIR); \
	fi

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	ar -rc $(NAME) $^

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c $(HEAD)
	cc $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

.PHONY: clean fclean re test test2

clean:
	rm -f $(OBJS)
	@if [ -d $(LIBFT_DIR) ]; then make clean -C $(LIBFT_DIR); fi

fclean: clean
	@if [ -f $(NAME) ]; then rm -f $(NAME); fi
	@if [ -f test ]; then rm -f test; fi
	@if [ -f test2 ]; then rm -f test2; fi
	@if [ -d $(LIBFT_DIR) ]; then make fclean -C $(LIBFT_DIR); fi
	@if [ -d $(LIBFT_DIR) ]; then rm -rf $(LIBFT_DIR); fi

re: fclean all

test: $(LIBFT) $(NAME)
	@if [ -f $(NAME) ]; then cc $(CFLAGS) test_main.c $(NAME) $(LIBFT_DIR)$(LIBFT) -I$(LIBFT_DIR) -o test; fi
	@echo "test is compiled!";

test2: $(LIBFT) $(NAME)
	@if [ -f $(NAME) ]; then cc $(CFLAGS) test_main2.c $(NAME) $(LIBFT_DIR)$(LIBFT) -I$(LIBFT_DIR) -o test2; fi
	@echo "test2 is compiled!";

