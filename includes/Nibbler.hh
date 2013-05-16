#ifndef __NIBBLER_HH__
# define __NIBBLER_HH__

# define UNUSED __attribute__((unused))

# include <iostream>
# include <list>
# include <vector>
# include "define.hh"

STR_DEFINE BAD_VALUE = "Bad argument value";
STR_DEFINE BAD_ARGC = "Bad number of arguments";

STR_DEFINE USAGE = "Usage: ./nibbler x y file.so";
STR_DEFINE PLUGIN_GETTER = "get_instance";

UINT_DEFINE MAX_X = 50;
UINT_DEFINE MAX_Y = 50;
UINT_DEFINE MIN_X = 10;
UINT_DEFINE MIN_Y = 10;

typedef enum	slot_e
{
  EMPTY,
  WALL,
  FRUIT,
  SNAKE_H,
  SNAKE_B,
  OUTMAP

}		slot_t;

typedef enum	action_e
{
  UP = 0,
  DOWN = 1,
  RIGHT = 2,
  LEFT = 3,
  ESCAPE = 4,
  OTHER = 5
}		action_t;

typedef unsigned int				uint;

typedef std::pair<uint, uint>			coor_t;

typedef std::vector<slot_t>			map_line_t;
typedef std::vector<map_line_t>			map_t;
typedef std::list<coor_t>			fruits;

typedef std::list<coor_t>			slot_list;

#endif //!__NIBBLER_HH__
