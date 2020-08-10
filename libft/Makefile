# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/30 16:02:34 by olydden           #+#    #+#              #
#    Updated: 2020/08/07 21:41:41 by olydden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES = 	ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strnstr.c\
			ft_strncmp.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putendl.c\
			ft_putnbr.c\
			ft_strndup.c\
			ft_free.c\
			ft_itoa_base.c\
			ft_nbrlen.c\
			ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_nbrlen_u.c\
			ft_putnbr_u.c\
			ft_itoa_base_upper.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/libft.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
