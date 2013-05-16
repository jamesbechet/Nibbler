#ifndef __EXCEPTION_HH__
# define __EXCEPTION_HH__

# include <exception>
# include <string>

class Exception : public std::exception
{
public:
  ~Exception() throw()
  {}

  Exception(std::string const & err) : _msg(err)
  {}

  const char* what(void) const throw()
  { return (_msg.c_str()); }

private:
  std::string _msg;
};

#endif //!__EXCEPTION_HPP__
