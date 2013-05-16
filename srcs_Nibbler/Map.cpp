#include "Exception.hh"
#include "Map.hh"

uint			Map::getXSize(void) const
{
  return (this->_map[0].size());
}

uint			Map::getYSize(void) const
{
  return (this->_map.size());
}

map_t const &		Map::getMap(void) const
{
  return (this->_map);
}

map_t			Map::createMap(uint x, uint y) const
{
  map_t			map;
  map_line_t		line;

  for (uint j = 0 ; j < x ; ++j)
    line.push_back(EMPTY);
  for (uint i = 0 ; i < y ; ++i)
    map.push_back(line);
  return (map);
}

void			Map::print(void) const
{
  for (std::vector<std::vector<slot_t> >::const_iterator y = this->_map.begin(); y != this->_map.end(); ++y)
    {
      for (std::vector<slot_t>::const_iterator x = (*y).begin(); x != (*y).end(); ++x)
	{
	  switch ((*x))
	    {
	    case EMPTY:
	      std::cout << ".";
	      break ;
	    case WALL:
	      std::cout << "|";
	      break ;
	    case FRUIT:
	      std::cout << "*";
	      break ;
	    case SNAKE_H:
	      std::cout << "@";
	      break ;
	    case SNAKE_B:
	      std::cout << "~";
	      break ;
	    default:
	      std::cout << "?";
	      break ;
	    }
	}
      std::cout << std::endl;
    }
}

void			Map::clear(void)
{
  for (std::vector<std::vector<slot_t> >::iterator y = this->_map.begin(); y != this->_map.end(); ++y)
    {
      for (std::vector<slot_t>::iterator x = (*y).begin(); x != (*y).end(); ++x)
	*x = EMPTY;
    }
}

void			Map::merge(coor_t const & coor, slot_t type)
{
  this->merge(coor.first, coor.second, type);
}

void			Map::merge(uint x, uint y, slot_t type)
{
  if (x < this->getXSize() && y < this->getYSize())
    this->_map[y][x] = type;
  else
    throw Exception("Map: Merge is out of map");
}

void			Map::merge(slot_list const & list, slot_t type)
{
  for (slot_list::const_iterator it = list.begin() ; it != list.end() ; ++it)
    this->merge((*it), type);
}

slot_t			Map::getSlotType(uint x, uint y) const
{
  if (x < this->getXSize() && y < this->getYSize())
    return (this->_map[y][x]);
  return (OUTMAP);
}

slot_t			Map::getSlotType(coor_t const & coord) const
{
  return (this->getSlotType(coord.first, coord.second));
}

Map::Map(uint x, uint y)
{
  this->_map = this->createMap(x, y);
}
