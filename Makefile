SFILES      = push_swap.c push_swap_command.c push.c reverse.c rotate.c split.c utils.c utils_2.c utils_3.c commands.c utils_4.c
OFILES      = $(SFILES:.c=.o)
CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror -I. -g3# -fsanitize=leak,address

NAME        = push_swap

$(NAME):    $(OFILES)
	$(CC) $(OFILES) -o $(NAME)

all:        $(NAME)

clean:
	$(RM) $(OFILES)

fclean:     clean
	$(RM) $(NAME)

re:         fclean all

.PHONY:     all clean fclean re
