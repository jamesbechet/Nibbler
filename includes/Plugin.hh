#ifndef __PLUGIN_HH__
# define __PLUGIN_HH__

# include <dlfcn.h>
# include "IDisplayModule.hh"

typedef IDisplayModule                *(*get_instance)(uint x, uint y);

class Plugin
{
private:
  void *_fd;
  bool	_open;
public:
  bool	isOpen(void) const;
  char	*get_error(void) const;
  IDisplayModule*	load(char const *name, uint x, uint y) const;
  Plugin(char const *path);
  ~Plugin(void);
public:
};

#endif //!__PLUGIN_HH__
