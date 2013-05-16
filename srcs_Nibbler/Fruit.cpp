
#include "Fruit.hh"

coor_t const &	Fruit::getCoord(void) const
{
  return (this->_coord);
}

void		Fruit::setCoord(uint x, uint y)
{
  this->_coord.first = x;
  this->_coord.second = y;
}

void		Fruit::new_fruit(Map const & map)
{
  slot_t	t;
  uint		x;
  uint		y;
  uint		i;

  i = 0;
  do
    {
      if (i >= this->_max_iter)
	throw Exception("Fruit: Can't find a place to place new fruit");
      x = rand() % this->_size_x;
      y = rand() % this->_size_y;
      t = map.getSlotType(x, y);
      ++i;
    } while (t != EMPTY);
  this->setCoord(x, y);
}

Fruit::Fruit(Map const & map)
{
  srand(xtime(NULL));
  this->_size_x = map.getXSize();
  this->_size_y = map.getYSize();
  this->_max_iter = (this->_size_x * this->_size_y);
  this->new_fruit(map);
}
