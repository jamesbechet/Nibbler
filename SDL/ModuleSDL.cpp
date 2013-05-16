#include "ModuleSDL.hh"

action_e    	ModuleSDL::get_key(void)
{
  while (SDL_PollEvent(&this->event))
    {
      switch(this->event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  return (ESCAPE);
	case SDLK_UP:
	  return (UP);
	case SDLK_DOWN:
	  return (DOWN);
	case SDLK_RIGHT:
	  return (RIGHT);
	case SDLK_LEFT:
	  return (LEFT);
	default:
	  return (OTHER);
	}
    }
  return (OTHER);
}

ModuleSDL::ModuleSDL(uint x, uint y)
{
  int		r;

  if ((r = SDL_Init(SDL_INIT_VIDEO)) == -1)
    throw Exception(SDL_GetError());
  this->s_ecran = SDL_SetVideoMode(BLOCK_SIZE * x, BLOCK_SIZE * y, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (this->s_ecran == NULL)
    throw Exception(SDL_GetError());
  SDL_WM_SetCaption(WINDOW_TITLE, (char const *)NULL);
  this->s_head = IMG_Load(IMG_PATHHEAD);
  this->s_body =  IMG_Load(IMG_PATHBODY);
  this->s_empty = IMG_Load(IMG_PATHEMPTY);
  this->s_fruit = IMG_Load(IMG_PATHFRUIT);
  this->s_wall = IMG_Load(IMG_PATHWALL);
  if (this->s_head == NULL ||
      this->s_body == NULL ||
      this->s_empty == NULL ||
      this->s_fruit == NULL ||
      this->s_wall == NULL)
    throw Exception(IMG_GetError());
}

void		ModuleSDL::display_slot(uint x, uint y, slot_t type)
{
  SDL_Rect	coord;
  SDL_Surface	*square;
  int		r;

  coord.x = x * BLOCK_SIZE;
  coord.y = y * BLOCK_SIZE;
  switch (type)
    {
    case EMPTY:
      square = this->s_empty;
      break ;
    case FRUIT:
      square = this->s_fruit;
      break ;
    case SNAKE_H:
      square = this->s_head;
      break ;
    case SNAKE_B:
      square = this->s_body;
      break ;
    default:
      throw Exception("SDL: Unknown type");
      break ;
    }
  r = SDL_BlitSurface(square, NULL, s_ecran, &coord);
  if (r != 0)
    throw Exception(SDL_GetError());
}

void		ModuleSDL::display(map_t const & map)
{
  uint		x, y;
  int		r;

  y = 0;
  r = SDL_FillRect(this->s_ecran, NULL, SDL_MapRGB(this->s_ecran->format, 0, 0, 0));
  if (r == -1)
    throw Exception(SDL_GetError());
  for (std::vector<std::vector<slot_t> >::const_iterator it_y = map.begin(); it_y != map.end(); ++it_y)
    {
      x = 0;
      for (std::vector<slot_t>::const_iterator it_x = (*it_y).begin(); it_x != (*it_y).end(); ++it_x)
	{
	  display_slot(x, y, (*it_x));
	  ++x;
	}
      ++y;
    }
  r = SDL_Flip(this->s_ecran);
  if (r == -1)
    throw Exception(SDL_GetError());
}

ModuleSDL::~ModuleSDL(void)
{
  SDL_FreeSurface(this->s_head);
  SDL_FreeSurface(this->s_body);
  SDL_FreeSurface(this->s_empty);
  SDL_FreeSurface(this->s_fruit);
  SDL_Quit();
}

extern "C"
{
  IDisplayModule                *get_instance(uint x, uint y)
  {
    return (new ModuleSDL(x, y));
  }
}
