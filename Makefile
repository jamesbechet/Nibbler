ROOT		=	.

NIBBLER_FOLDER	=	$(ROOT)/srcs_Nibbler

SDL_FOLDER	=	$(ROOT)/SDL

NCURSES_FOLDER	=	$(ROOT)/NCurses
OPENGL_FOLDER	=	$(ROOT)/OpenGL
MAKE		=	make
PRINTF		=	printf

all		: nibbler sdl ncurses opengl

nibbler		:
		@$(MAKE) -C $(NIBBLER_FOLDER)

opengl		:
		@$(MAKE) -C $(OPENGL_FOLDER)

sdl		:
		@$(MAKE) -C $(SDL_FOLDER)

ncurses		:
		@$(MAKE) -C $(NCURSES_FOLDER)

clean		:
		@$(MAKE) -C $(NIBBLER_FOLDER) clean
		@$(MAKE) -C $(SDL_FOLDER) clean
		@$(MAKE) -C $(NCURSES_FOLDER) clean
		@$(MAKE) -C $(OPENGL_FOLDER) clean

fclean		:
		@$(MAKE) -C $(NIBBLER_FOLDER) fclean
		@$(MAKE) -C $(SDL_FOLDER) fclean
		@$(MAKE) -C $(NCURSES_FOLDER) fclean
		@$(MAKE) -C $(OPENGL_FOLDER) fclean

re		:
		@$(MAKE) -C $(NIBBLER_FOLDER) re
		@$(MAKE) -C $(SDL_FOLDER) re
		@$(MAKE) -C $(NCURSES_FOLDER) re
		@$(MAKE) -C $(OPENGL_FOLDER) re

.PHONY		: all clean fclean re nibbler sdl ncurses opengl

.DEFAULT	:
		@$(PRINTF) "Wrong option : $@.\n"