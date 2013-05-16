#ifndef __IDisplayModule_HH__
# define __IDisplayModule_HH__

# include "Nibbler.hh"

class IDisplayModule
{
public:
  virtual action_e	get_key(void) = 0;
  virtual void		display(map_t const & map) = 0;
  virtual		~IDisplayModule(void) {}
};

#endif //!__IDisplayModule_HH__
