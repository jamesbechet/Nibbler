#ifndef __ModuleSDL_HH__
# define __ModuleSDL_HH__

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include "IDisplayModule.hh"
# include "define.hh"
# include "Nibbler.hh"
# include "Exception.hh"

INT_DEFINE BLOCK_SIZE = 20;
STR_DEFINE WINDOW_TITLE = "Nibbler";
STR_DEFINE IMG_PATHHEAD = "./SDL/img/head.png";
STR_DEFINE IMG_PATHBODY = "./SDL/img/body.png";
STR_DEFINE IMG_PATHEMPTY = "./SDL/img/empty.png";
STR_DEFINE IMG_PATHFRUIT = "./SDL/img/fruit.png";
STR_DEFINE IMG_PATHWALL = "./SDL/img/wall.jpg";

class ModuleSDL : public IDisplayModule
{
private:
  SDL_Surface	*s_ecran;
  SDL_Surface	*s_head;
  SDL_Surface	*s_body;
  SDL_Surface	*s_fruit;
  SDL_Surface	*s_empty;
  SDL_Surface	*s_wall;
  SDL_Event	event;
private:
  void		display_slot(uint x, uint y, slot_t type);
public:
  ModuleSDL(uint x, uint y);
  virtual ~ModuleSDL(void);
  virtual action_e	get_key(void);
  virtual void		display(map_t const & map);
};


#endif //!__ModuleSDL_HH__

