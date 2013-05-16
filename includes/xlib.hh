#ifndef __XLIB_HH__
# define __XLIB_HH__

# include <ctime>
# include <unistd.h>

int		xusleep(useconds_t usec);
time_t		xtime(time_t *t);

#endif //!__XLIB_HH__
