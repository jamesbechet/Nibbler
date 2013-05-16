.SUFFIXES	: .cpp .o .hh .so

NAME		=	lib_nibbler_OpenGL.so

ROOT		=	.

SRCS		=	$(ROOT)/ModuleOpenGL.cpp

CC		=	g++
RM		=	rm -rf
CP		=	cp
PRINTF		=	printf

OBJS		=	$(SRCS:.cpp=.o)

FLAGS		=	-W -Wall -Werror

BIN_PATH	=	../bin/$(NAME)
H_PATH		=	../includes
CFLAGS		=	$(FLAGS) -I$(H_PATH)
LFLAGS		=	-framework SDL -framework OpenGl
#$(shell sdl-config --clfags)
#$(shell sdl-config --libs)
#-lGL -lGLU

all		: $(NAME) bin

$(NAME)		: $(OBJS)
		$(CC) -shared -o $(NAME) $(OBJS) $(LFLAGS)

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
