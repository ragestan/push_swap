NAME = push_swap
NAME_B = checker
RM = rm -f
SRC	= check.c\
	split.c\
	stack.c\
	util.c\
	toools.c\
	check2.c\
	toools2.c\
	util2.c\
	stack2.c\
	stack3.c\
	stack4.c\

BONUS_SRC = get_next_line.c\
	get_next_line_utils.c\

FILIO = $(SRC:.c=.o)

FILIO_B= ${BONUS_SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(FILIO)
	${CC} ${CFLAGS} ${FILIO} main.c -o ${NAME}


bonus: $(NAME_B)

$(NAME_B):	$(FILIO_B) $(FILIO)
	${CC} ${CFLAGS}	${FILIO} ${FILIO_B} cheker.c -o ${NAME_B}

clean:	
	$(RM) $(FILIO) $(FILIO_B)
fclean: clean
	$(RM) $(NAME) $(NAME_B)
re: fclean all
 
.PHONY: all clean fclean re bonus