#ifndef __MAP_HH__
# define __MAP_HH__

# include "Nibbler.hh"

class Map
{
private:
  map_t		_map;
public:
  slot_t	getSlotType(coor_t const &) const;
  slot_t       	getSlotType(uint x, uint y) const;
  uint		getXSize(void) const;
  uint		getYSize(void) const;
  void		print(void) const;
  void		clear(void);
  map_t const &	getMap(void) const;
  map_t		createMap(uint x, uint y) const;
  void		merge(coor_t const & coor, slot_t type);
  void		merge(uint x, uint y, slot_t type);
  void		merge(slot_list const & list, slot_t type);
  Map(uint x, uint y);
};

#endif //!__MAP_HH__
