
#include <ctime>
#include <iostream>
#include <unistd.h>
#include "define.hh"
#include "IDisplayModule.hh"
#include "Game.hh"
#include "Snake.hh"
#include "Fruit.hh"
#include "Map.hh"
#include "xlib.hh"
#include "Rank.hh"

void		Game::setScore(uint score)
{
  this->_score = score;
}

uint		Game::getScore(void) const
{
  return (this->_score);
}

void		Game::setTime(time_t time)
{
  this->_time = time;
}

time_t		Game::getTime(void) const
{
  return (this->_time);
}

void		Game::gameOver(void) const
{
  std::cout << "G@m3 0v3r !!" << std::endl;
  std::cout << "Player = " << getlogin() << std::endl;
  std::cout << "Time = " << this->getTime() << " seconds" << std::endl;
  std::cout << "Score = " << this->getScore() << std::endl;
}

Game::Game(uint x, uint y, IDisplayModule *plugin) : _game(true), _score(0)
{
  Map		map(x, y);
  Snake		snake(4, map);
  action_t	action;
  Fruit		fruit(map);
  uint		speed = 50000;
  uint		nb_eat = 1;

  this->setTime(xtime(NULL));
  while (this->_game == true)
    {
      action = plugin->get_key();
      snake.move(map, action);
      if (snake.eat(fruit) == true)
	{
	  fruit.new_fruit(map);
	  this->setScore(this->getScore() + nb_eat++);
	}
      if (action == ESCAPE)
      	break ;
      if (snake.getAlive() == false)
	break ;
      map.clear();
      map.merge(snake.getBody(), SNAKE_B);
      map.merge(snake.getHead(), SNAKE_H);
      map.merge(fruit.getCoord(), FRUIT);
      plugin->display(map.getMap());
      if (speed > 8)
	speed -= 8;
      xusleep(speed);
    }
  delete plugin;
  this->setTime(xtime(NULL) - this->getTime());
  this->setScore((this->getScore() * 1000) / (x + y + this->getTime()));
  this->gameOver();
}

Game::~Game(void)
{
  Rank		rank;

  rank.add(getlogin(), this->getScore());
  rank.sort_rank();
  rank.print();
}
