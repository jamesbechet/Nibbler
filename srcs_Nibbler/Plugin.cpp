
#include "Plugin.hh"

IDisplayModule*		Plugin::load(char const *name, uint x, uint y) const
{
  void			*ptr;
  get_instance		getter;
  IDisplayModule	*interface;

  if (this->isOpen() == true && (ptr = dlsym(this->_fd, name)) != NULL)
    {
      getter = reinterpret_cast<get_instance>(ptr);
      interface = getter(x, y);
      return (interface);
    }
  return (NULL);
}

bool	Plugin::isOpen(void) const
{
  return (this->_open);
}

char	*Plugin::get_error(void) const
{
  return (dlerror());
}

Plugin::Plugin(char const *path) : _open(true)
{
  if ((this->_fd = dlopen(path, RTLD_LAZY)) == NULL)
    this->_open = false;
}

Plugin::~Plugin(void)
{
  if (this->isOpen() == true && dlclose(this->_fd) != 0)
    std::cerr << this->get_error() << std::endl;
}
