NAME	=	abstractvm

SRCS	=	main.cpp		\
			parser.cpp		\
			exception.cpp	\
			lexer.cpp		\
			avm.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

CC	=	g++  

FLAGS	= -std=c++11 -Wall -Werror -Wextra

%.o: %.cpp
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'
		@$(CC) -c -o $@ $< $(FLAGS)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all