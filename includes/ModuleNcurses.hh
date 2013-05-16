#ifndef __ModuleNcurses_HH__
# define __ModuleNcurses_HH__

# include <cstring>
# include <cstdio>
# include <errno.h>
# include <iostream>
# include <ncurses.h>
# include <vector>
# include <curses.h>
# include <cstdlib>
# include "IDisplayModule.hh"
# include "Nibbler.hh"

# define KEY_ESCAPE 27

class ModuleNcurses : public IDisplayModule
{
private:
  WINDOW	*win;
private:
  void		display_slot(uint x, uint y, slot_t type);
public:
  ModuleNcurses(uint x, uint y);
  virtual ~ModuleNcurses(void);
  virtual action_t	get_key(void);
  virtual void		display(map_t const & map);
};

#endif


