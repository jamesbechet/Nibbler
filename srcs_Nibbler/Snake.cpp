#include <iostream>
#include "Nibbler.hh"
#include "Snake.hh"

snk_boby const &	Snake::getBody(void) const
{
  return (this->_body);
}

coor_t		Snake::getHead(void) const
{
  return (this->_body.front());
}

void		Snake::setAlive(bool status)
{
  this->_alive = status;
}

bool		Snake::getAlive(void) const
{
  return (this->_alive);
}

void		Snake::addElem(uint x, uint y)
{
  coor_t       	coord;

  coord.first = x;
  coord.second = y;
  this->_body.push_back(coord);
}

void		Snake::setHeadCoor(Map const & map)
{
  uint		x;
  uint		y;

  x = map.getXSize() / 2;
  y = map.getYSize() / 2;
  this->addElem(x, y);
}

void	       		Snake::growUp(Map const & map)
{
  std::list<coor_t>::reverse_iterator	rit = this->_body.rbegin();
  coor_t			last = (*rit);

  if (map.getSlotType(last.first - 1, last.second) == EMPTY)
    this->addElem(last.first - 1, last.second);
  else if (map.getSlotType(last.first, last.second - 1) == EMPTY)
    this->addElem(last.first, last.second - 1);
  else if (map.getSlotType(last.first, last.second + 1) == EMPTY)
    this->addElem(last.first, last.second + 1);
  else if (map.getSlotType(last.first + 1, last.second) == EMPTY)
    this->addElem(last.first + 1, last.second);
  else
    this->setAlive(false);
}

bool		Snake::eat(Fruit const & fruit)
{
  if (fruit.getCoord() != this->getHead())
    {
      this->_body.pop_back();
      return (false);
    }
  return (true);
}

void			Snake::move(Map const & map, action_t direction)
{
  coor_t		head;

  switch (direction)
    {
    case UP :
      direction = (this->_dir == DOWN) ? this->_dir : direction;
      break ;
    case DOWN :
      direction = (this->_dir == UP) ? this->_dir : direction;
      break ;
    case RIGHT :
      direction = (this->_dir == LEFT) ? this->_dir : direction;
      break ;
    case LEFT :
      direction = (this->_dir == RIGHT) ? this->_dir : direction;
      break ;
    default:
      break ;
    }
  direction = (IS_MOVE(direction)) ? direction : this->_dir;
  head = this->getHead();
  switch (direction)
    {
    case UP :
      head.second -= 1;
      break ;
    case DOWN :
      head.second += 1;
      break ;
    case RIGHT :
      head.first += 1;
      break ;
    case LEFT :
      head.first -= 1;
      break ;
    default:
      break ;
    }
  this->_dir = direction;
  slot_t t = map.getSlotType(head);
  if (t != EMPTY && t != FRUIT && !(t == SNAKE_B && head == this->_body.back()))
    this->setAlive(false);
  else
    this->_body.push_front(head);
}

Snake::Snake(uint size, Map & map) : _alive(true), _dir(RIGHT)
{
  this->setHeadCoor(map);
  while (this->getAlive() && size > 1)
    {
      this->growUp(map);
      --size;
    }
}
