
.SUFFIXES	: .cpp .o .hh .hpp

NAME		=	nibbler

ROOT		=	.

SRCS		=	$(ROOT)/main.cpp	\
			$(ROOT)/Game.cpp	\
			$(ROOT)/Snake.cpp	\
			$(ROOT)/Rank.cpp	\
			$(ROOT)/Plugin.cpp	\
			$(ROOT)/xfunctions.cpp	\
			$(ROOT)/Fruit.cpp	\
			$(ROOT)/Map.cpp

CC		=	g++
RM		=	rm -rf
CP		=	cp
PRINTF		=	printf

OBJS		=	$(SRCS:.cpp=.o)

FLAGS		=	-W -Wall -Werror

BIN_PATH	=	../bin/$(NAME)
H_PATH		=	../includes
CFLAGS		=	$(FLAGS) -I$(H_PATH)
LFLAGS  	=	-ldl -rdynamic

all		: $(NAME) bin

$(NAME)		: $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

bin		:
		$(CP) $(NAME) $(BIN_PATH)

.cpp.o		:
		$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

clean		:
		$(RM) $(OBJS)

fclean		: clean
		$(RM) $(NAME)
		$(RM) $(BIN_PATH)

re		: fclean all

.PRECIOUS	: $(SRCS)

.PHONY		: all clean fclean re bin

.DEFAULT	:
		@$(PRINTF) "Wrong option : $@.\n"