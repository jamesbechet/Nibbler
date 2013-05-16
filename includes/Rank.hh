#ifndef __RANK_HH__
# define __RANK_HH__

#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Nibbler.hh"
#include "lib.hpp"

class Rank
{
private:
  std::list<std::pair<uint, std::string> >	_ranking;
  char const *_path;

private:
  std::vector<std::string>	split(std::string const & s, char c);
  void				load_rank(char const *path);
public:
  void				sort_rank(void);
  void				add(char const *login, uint score);
  void				print(void) const;
  Rank(char const *path = "rank.txt");
  ~Rank(void);
};

#endif //!__RANK_HH__
