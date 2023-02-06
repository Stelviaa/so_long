SRCS	=	ft_strlen.c \
		  	ft_bzero.c \
		  	ft_isalnum.c \
		  	ft_isalpha.c \
		  	ft_isascii.c \
		  	ft_isdigit.c \
		  	ft_isprint.c \
		  	ft_memchr.c \
		  	ft_memcmp.c \
		  	ft_memcpy.c \
		  	ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
		  	ft_strlcat.c \
		  	ft_strlcpy.c \
		  	ft_strncmp.c \
		  	ft_strrchr.c \
		  	ft_tolower.c \
		  	ft_toupper.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr.c	\
			ft_putnbr_fd.c	\
			get_next_line.c	\
			ft_putnbr_u.c	\
			ft_printf.c	\
			out_conv.c	\
			out_conv2.c

SRC_BONUS	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

OBJS	=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRC_BONUS:.c=.o}

NAME = libft.a

CC	= gcc
RM	= rm -f
AR	= ar rc

CFLAGS 	= -Wall -Wextra -Werror
CFLAGS += -I../includes

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJS_BONUS}
			${AR} ${NAME} ${OBJS_BONUS}	

clean:		
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
