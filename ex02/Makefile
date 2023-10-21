SRCS	=	$(shell find . -name "*.cpp")

OBJS	=	${SRCS:.cpp=.o}

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror # defalt bana cxxflags-@

NAME	=	prog
# NAME	=	$(shell basename "$(pwd)")

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
	@rm -f ${OBJS} 
fclean:	clean
	@rm -f $(NAME)
	@if [ -n "$(shell ls *.txt 2>/dev/null)" ]; then \
        rm -f *.txt; \
    fi

ex01 DZI!!!!!!!!!

re:	fclean	all

.PHONY:	all clean fclean re