
#ifndef __GAME_HH__
# define __GAME_HH__

# include "Nibbler.hh"
# include "IDisplayModule.hh"

class Game
{
private:
  bool		_game;
  uint		_score;
  time_t	_time;
public:
  Game(uint x, uint y, IDisplayModule * plugin);
  ~Game(void);
  void		setScore(uint score);
  uint		getScore(void) const;
  void		setTime(time_t score);
  time_t	getTime(void) const;
  void		gameOver(void) const;
};

#endif //!__GAME_HH__
