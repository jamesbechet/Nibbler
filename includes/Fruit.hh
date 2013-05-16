#ifndef __FRUIT_HH__
# define __FRUIT_HH__

# include <iostream>
# include <cstdlib>
# include "Exception.hh"
# include "xlib.hh"
# include "Nibbler.hh"
# include "Map.hh"

class                   Fruit
{
private:
  uint			_size_x;
  uint			_size_y;
  uint			_max_iter;
  coor_t		_coord;
public:
  coor_t const & getCoord(void) const;
  void		setCoord(uint x, uint y);
  void		new_fruit(Map const & map);
  Fruit(Map const & map);
};

#endif //!__FRUIT_HH__
