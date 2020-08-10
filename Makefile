# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/11 19:50:06 by olydden           #+#    #+#              #
#    Updated: 2020/08/10 09:10:12 by olydden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES = 	ft_printf.c\
			s_specifier.c\
			d_d4_specifier.c\
			d5_d9_specifier.c\
			d10_d14_specifier.c\
			d15_d16_p_specifiers.c\
			u_u4_specifier.c\
			u5_u7_c_specifiers.c\
			x_x4_specifier.c\
			x5_x8_specifier.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OBJS)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re all clean
