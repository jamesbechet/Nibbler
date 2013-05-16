#include <ctime>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include "Exception.hh"
#include "xlib.hh"

int		xusleep(useconds_t usec)
{
  extern int	errno;
  int		r;

  if ((r = usleep(usec)) == -1)
    throw Exception(strerror(errno));
  return (r);
}

time_t		xtime(time_t *t)
{
  extern int	errno;
  time_t       	r;

  if ((r = time(t)) == ((time_t) -1))
    throw Exception(strerror(errno));
  return (r);
}
