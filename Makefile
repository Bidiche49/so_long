# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 22:58:35 by ntardy            #+#    #+#              #
#    Updated: 2023/01/19 23:03:55 by ntardy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			so_long

NAME_BONUS =	so_long_bonus

CC =			gcc

CFLAGS =		-Wall -Werror -Wextra -g3

LIB_MLX =		minilibx-linux

SRCS_LOC =		srcs/
SRCS_GNL =		GNL/
BONUS_LOC = 	srcs/bonus/

SRCS =			$(SRCS_LOC)so_long.c				\
				$(SRCS_LOC)ft_utils.c				\
				$(SRCS_LOC)ft_utils2.c				\
				$(SRCS_LOC)ft_itoa.c				\
				$(SRCS_LOC)parsing.c				\
				$(SRCS_LOC)parsing2.c				\
				$(SRCS_LOC)parsing3.c				\
				$(SRCS_LOC)error.c					\
				$(SRCS_LOC)free.c					\
				$(SRCS_LOC)fill_content.c			\
				$(SRCS_LOC)fill_images.c			\
				$(SRCS_LOC)fill_window.c			\
				$(SRCS_LOC)init_data.c				\
				$(SRCS_LOC)moves.c					\
				$(SRCS_GNL)get_next_line.c			\
				$(SRCS_GNL)get_next_line_utils.c

SRCS_BONUS =	$(SRCS_LOC)ft_utils.c				\
				$(SRCS_LOC)ft_utils2.c				\
				$(SRCS_LOC)parsing2.c				\
				$(SRCS_LOC)parsing3.c				\
				$(SRCS_LOC)error.c					\
				$(SRCS_LOC)free.c					\
				$(SRCS_LOC)fill_content.c			\
				$(SRCS_LOC)fill_images.c			\
				$(SRCS_LOC)ft_itoa.c				\
				$(SRCS_LOC)init_data.c				\
				$(SRCS_GNL)get_next_line.c			\
				$(SRCS_GNL)get_next_line_utils.c	\
				$(BONUS_LOC)so_long_bonus.c			\
				$(BONUS_LOC)parsing_bonus.c			\
				$(BONUS_LOC)moves_bonus.c			\
				$(BONUS_LOC)moves_monster.c			\
				$(BONUS_LOC)fill_window_bonus.c		\
				$(BONUS_LOC)animation.c


OBJS =        $(SRCS:.c=.o)

OBJS_BONUS =  $(SRCS_BONUS:.c=.o)

MLX =        -L$(LIB_MLX) -lmlx_Linux -L/usr/lib -I$(LIB_MLX) -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I$(LIB_MLX) -Imlx_linux -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_MLX)
	$(CC) $(CFLAGS) -I$(LIB_MLX) $(OBJS) $(MLX) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C $(LIB_MLX)
	$(CC) $(CFLAGS) -I$(LIB_MLX) $(OBJS_BONUS) $(MLX) -o $(NAME_BONUS)


.PHONY: bonus
bonus: $(NAME_BONUS)
	@make -C $(LIB_MLX)
	$(CC) $(CFLAGS) -I$(LIB_MLX) $(OBJS_BONUS) $(MLX) -o $(NAME_BONUS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME) $(NAME_BONUS) ${LIB_MLX}/*.o

.PHONY: re
re: fclean $(NAME)
