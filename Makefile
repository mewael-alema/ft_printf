NAME 		= libftprintf.a

SRCS 		=  ft_printf.c putstr.c putnbr.c ft_itoa.c puthex.c putptr.c printunum.c
OBJECTS		= $(SRCS:.c=.o)
RM			= rm -f
LIBCREATE	= ar -rcs		
CC 			= cc
CFLAGS 		= -c -Wall -Wextra -Werror

.c.o : $(CC) ${FLAGS} $< -o ${<:.c=.o} 

$(NAME): $(OBJECTS)
	$(LIBCREATE) $(NAME) $(OBJECTS)

all : $(NAME)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re