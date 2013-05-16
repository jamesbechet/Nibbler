#ifndef __SNAKE_HH__
# define __SNAKE_HH__

# include "Nibbler.hh"
# include "Map.hh"
# include "Fruit.hh"

typedef std::list<coor_t>	       	snk_boby;

# define IS_MOVE(dir) ((direction != UP && direction != DOWN && direction != RIGHT && direction != LEFT) ? false : true)

class			Snake
{
private:
  bool			_alive;
  action_t		_dir;
  snk_boby		_body;
public:
  void		move(Map const & map, action_t direction);
  void		growUp(Map const & map);
  bool		eat(Fruit const & fruit);
public:
  void		addElem(uint x, uint y);
  Snake(uint size, Map & map);
  snk_boby const &	getBody(void) const;
  coor_t       	getHead(void) const;
  void		setAlive(bool status);
  bool       	getAlive(void) const;
  void		setHeadCoor(Map const & map);
};

#endif //!__SNAKE_HH__
