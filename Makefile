# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: screight <screight@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 13:51:23 by screight          #+#    #+#              #
#    Updated: 2019/05/02 22:21:05 by screight         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all make mklib

NAME	= fillit

SRC		= ft_fillit.c main.c ft_valid.c get_next_line.c ft_tetra_list.c \
			ft_coord_list.c ft_solver.c ft_replacer.c

SRCDIR 	= sources/

OBJDIR 	= objectives/

LIBDIR 	= libft/

SRCS 	= $(addprefix $(SRCDIR), $(SRC))

OBJS 	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

HEADER 	= includes/

LIBHDR 	= libft/includes/

CC 		= -gcc

FLAGS 	= -Wall -Wextra -Werror

all: 		$(NAME)

$(NAME): 	$(OBJS) | mklib
			@$(CC) $(FLAG) $(OBJS) -I $(LIBHDR) -I $(HEADER) -L $(LIBDIR) -lft -o $(NAME)

$(OBJS): 	$(OBJDIR)%.o: $(SRCDIR)%.c
			@$(CC) $(FLAGS) -I $(LIBHDR) -I $(HEADER) -c $< -o $@
mklib: 
			@make -C $(LIBDIR) --no-print-directory
clean:
			@/bin/rm -f $(OBJS)
			@make clean -C $(LIBDIR) --no-print-directory

fclean: 	clean
			@/bin/rm -f $(NAME)
			@make fclean -C $(LIBDIR) --no-print-directory

re: 		fclean all