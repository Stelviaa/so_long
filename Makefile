SRCS	= srcs/so_long_second.c srcs/move.c srcs/animation.c srcs/animation2.c \
	srcs/pathfinding.c srcs/pathfinding2.c srcs/pathfinding3.c srcs/so_long3.c srcs/so_long.c

SRCS_BONUS	= srcs_bonus/so_long_second.c srcs_bonus/move.c srcs_bonus/animation.c srcs_bonus/animation2.c \
	srcs_bonus/pathfinding.c srcs_bonus/pathfinding2.c srcs_bonus/pathfinding3.c srcs_bonus/so_long3.c srcs_bonus/so_long.c srcs_bonus/ennemies.c srcs_bonus/ennemies2.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Iincludes
NAME = so_long
NAME_BONUS = so_long_bonus
RM = rm -f
LIBS = -lmlx -framework OpenGL -framework AppKit -Llibft -lft

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
		make -C libft
		$(CC) -o $(NAME) $(OBJS) $(LIBS)

bonus:	fclean $(OBJS_BONUS)
		make -C libft
		$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBS)

debug: CFLAGS+=-g 
debug: re

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)
		make clean -C libft

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)
		make fclean -C libft

re: fclean all

.PHONY: all fclean clean re debug bonus