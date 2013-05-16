
#include <cstdlib>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <dlfcn.h>
#include "define.hh"
#include "Game.hh"
#include "IDisplayModule.hh"
#include "lib.hpp"
#include "Plugin.hh"

static int	usage(char const *err)
{
  extern STR_DEFINE     USAGE;

  std::cerr << "Error: " << err << std::endl;
  std::cerr << USAGE << std::endl;
  return (EXIT_FAILURE);
}

static int	launchGame(uint x, uint y, IDisplayModule *interface)
{
  Game		game(x, y, interface);

  return (EXIT_SUCCESS);
}

static int	nibbler(char **argv)
{
  extern STR_DEFINE	BAD_VALUE;
  int			r;

  if (is_of_type<uint>(argv[1]) && is_of_type<uint>(argv[2]))
    {
      extern UINT_DEFINE	MAX_X;
      extern UINT_DEFINE	MAX_Y;
      extern UINT_DEFINE	MIN_X;
      extern UINT_DEFINE	MIN_Y;
      uint x = from_string<uint>(argv[1]);
      uint y = from_string<uint>(argv[2]);

      if (x >= MIN_X && y >= MIN_Y && y <= MAX_Y && x <= MAX_X)
	{
	  extern STR_DEFINE    	PLUGIN_GETTER;
	  Plugin		plugin(argv[3]);
	  IDisplayModule	*interface;

	  if ((interface = plugin.load(PLUGIN_GETTER, x, y)) != NULL)
	    {
	      try
		{
		  launchGame(x, y, interface);
		}
	      catch (std::exception const & e)
		{
		  delete interface;
		  throw ;
		}
	    }
	  else
	    r = usage(plugin.get_error());
	}
      else
	r = usage(BAD_VALUE);
    }
  else
    r = usage(BAD_VALUE);
  return (r);
}

static int	nibbler_e(char **argv)
{
  int		r;

  try
    {
      r = nibbler(argv);
    }
  catch (std::exception const & e)
    {
      std::cerr << e.what() << std::endl;
      r = EXIT_FAILURE;
    }
  return (r);
}

int		main(int argc, char **argv)
{
  extern STR_DEFINE	BAD_ARGC;

  return (argc == 4 ? nibbler_e(argv) : usage(BAD_ARGC));
}
