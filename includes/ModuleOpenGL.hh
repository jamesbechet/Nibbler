#ifndef __ModuleOpenGL_HH__
# define __ModuleOpenGL_HH__

# include <SDL/SDL.h>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include "IDisplayModule.hh"
# include "Exception.hh"
# include "Nibbler.hh"

class ModuleOpenGL : public IDisplayModule
{
private:
  uint		width;
  uint		height;
private:
  SDL_Event	event;
private:
  void		display_slot(uint x, uint y, slot_t type);
public:
  ModuleOpenGL(uint x, uint y);
  virtual ~ModuleOpenGL(void);
  virtual action_t	get_key(void);
  virtual void		display(map_t const & map);
};

#endif	//!__ModuleOpenGL_HH__
