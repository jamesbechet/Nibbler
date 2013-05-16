#ifndef __LIB_HPP__
# define __LIB_HPP__

# include <sstream>
# include <string>

template<typename T>
T               from_string(std::string const & s)
{
  std::istringstream    iss(s);
  T                     r;

  iss >> r;
  return (r);
}

/*01*/
template<typename T>
bool            is_of_type(std::string const & s)
{
  std::ostringstream    oss;
  std::string		epur_s;
  T                     tmp;
  size_t	       	i = 0;
  char const	       	*str = s.c_str();

  while (str[i] != '\0' && str[i] == '0')
    ++i;
  epur_s = str[i] == '\0' ? "0" : s.substr(i);
  std::istringstream    iss(epur_s);
  iss >> tmp;
  oss << tmp;
  return (epur_s == oss.str());
}

#endif //!__LIB_HPP__
