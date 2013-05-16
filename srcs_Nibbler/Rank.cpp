#include "Rank.hh"

std::vector<std::string>	Rank::split(std::string const & s, char c)
{
  std::vector<std::string>	vector;
  std::string::size_type	prev_pos = 0;
  std::string::size_type	pos = 0;
  std::string			substring;

  while ((pos = s.find(c, pos)) != std::string::npos)
    {
      substring = s.substr(prev_pos, pos - prev_pos);
      vector.push_back(substring);
      prev_pos = ++pos;
    }
  substring = s.substr(prev_pos, pos - prev_pos);
  vector.push_back(substring);
  return (vector);
}

void				Rank::load_rank(char const *path)
{
  std::string                   line;
  std::ifstream                 file;
  std::vector<std::string>	vector;

  file.open(path, std::ios::in);
  if (file.is_open() == false)
    return ;
  while (std::getline(file, line))
    {
      vector = split(line, ':');
      if (vector.size() == 2 && vector[0].size() > 3 &&
	  is_of_type<uint>(vector[1]) == true &&
	  vector[0].size() < 10)
	this->add(vector[0].c_str(), from_string<uint>(vector[1]));
    }
  file.close();
}

void				Rank::add(char const *login, uint score)
{
  if (login != NULL)
    this->_ranking.push_back(std::pair<uint, std::string>(score, login));
}

static bool    	my_sort(std::pair<uint, std::string> a, std::pair<uint, std::string> b)
{
  return (a.first > b.first);
}

void				Rank::sort_rank(void)
{
  this->_ranking.sort(&my_sort);
}

void				Rank::print(void) const
{
  uint				rank;

  rank = 1;
  std::cout << std::endl << "Nibbler ranking :" << std::endl;
  std::cout << "Player - Score" << std::endl;
  for (std::list<std::pair<uint, std::string> >::const_iterator it = this->_ranking.begin(); it != this->_ranking.end() && rank < 11; it++)
    {
      std::cout << rank << " " << (*it).second << " - " << (*it).first << std::endl;
      ++rank;
    }
}

Rank::~Rank(void)
{
  std::ofstream file(this->_path);
  uint	       		rank;

  rank = 1;
  for (std::list<std::pair<uint, std::string> >::const_iterator it = this->_ranking.begin(); it != this->_ranking.end() && rank < 11; it++)
    {
      file << (*it).second << ":" << (*it).first << std::endl;
      ++rank;
    }
}

Rank::Rank(char const *path)
{
  this->_path = path;
  this->load_rank(path);
}
