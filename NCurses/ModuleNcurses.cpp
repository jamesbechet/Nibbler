
#include "Map.hh"
#include "Snake.hh"
#include "Exception.hh"
#include "ModuleNcurses.hh"

action_e	ModuleNcurses::get_key(void)
{
  int		key;

  key = wgetch(this->win);
  switch (key)
    {
    case KEY_ESCAPE:
      return (ESCAPE);
    case KEY_UP:
      return (UP);
    case KEY_DOWN:
      return (DOWN);
    case KEY_LEFT:
      return (LEFT);
    case KEY_RIGHT:
      return (RIGHT);
    }
  return (OTHER);
}

void		ModuleNcurses::display_slot(uint x, uint y, slot_t type)
{
 switch (type)
    {
    case EMPTY:
      wattron(this->win, COLOR_PAIR(1));
      mvwprintw(this->win, y, x, " ");
      wattroff(this->win, COLOR_PAIR(1));
      break;
    case WALL:
      mvwprintw(this->win, y, x, "|");
      break;
    case FRUIT:
      wattron(this->win, COLOR_PAIR(3));
      mvwprintw(this->win, y, x, "$");
      wattroff(this->win, COLOR_PAIR(3));
      break;
    case SNAKE_H:
      wattron(this->win, COLOR_PAIR(2));
      mvwprintw(this->win, y, x, "@");
      wattroff(this->win, COLOR_PAIR(2));
      break;
    case SNAKE_B:
      mvwprintw(this->win, y, x, "*");
      break;
    default:
      std::cerr << "Unknown type" << std::cout;
      return;
      break;
    }
}

void		ModuleNcurses::display(map_t const & map)
{
  uint		x;

  if (werase(this->win) == ERR)
    throw Exception(strerror(errno));
  for (uint y = 0; y != map.size() ; ++y)
    {
      for (x = 0; x != map.size() ; ++x)
	display_slot(x, y, map[y][x]);
    }
  if (wrefresh(this->win) == ERR)
    throw Exception(strerror(errno));
}

ModuleNcurses::ModuleNcurses(uint x, uint y)
{
  if (initscr() != stdscr || raw() == ERR || noecho() == ERR)
    throw Exception(strerror(errno));
  if ((this->win = newwin(x, y, 0, 0)) == NULL)
    throw Exception(strerror(errno));
  if (curs_set(0) == ERR ||
      start_color() == ERR)
    throw Exception(strerror(errno));
  if (init_pair(1, COLOR_BLUE, COLOR_CYAN) == ERR ||
      init_pair(2, COLOR_RED, COLOR_CYAN) == ERR ||
      init_pair(3, COLOR_BLUE, COLOR_CYAN) == ERR)
    throw Exception(strerror(errno));
  if (keypad(this->win, TRUE) == ERR)
    throw Exception(strerror(errno));
  intrflush(this->win, FALSE);
  if (werase(this->win) == ERR ||
      wrefresh(this->win) == ERR ||
      notimeout(this->win, TRUE) == ERR ||
      nodelay(this->win, TRUE) == ERR)
    throw Exception(strerror(errno));
}

ModuleNcurses::~ModuleNcurses(void)
{
  delwin(this->win);
  endwin();
}

extern "C"
{
  IDisplayModule                *get_instance(uint x, uint y)
  {
    return (new ModuleNcurses(x, y));
  }
}
