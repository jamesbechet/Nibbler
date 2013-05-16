#include "ModuleOpenGL.hh"
#include "Exception.hh"

# define BLOCK_SIZE 20

static void		xglBegin(GLenum mode)
{
  int			error;

  glBegin(mode);
  error = glGetError();
  if (error != GL_NO_ERROR)
    throw Exception("OpenGl: glBegin");
}

static void		xglEnd(void)
{
  int			error;

  glEnd();
  error = glGetError();
  if (error != GL_INVALID_OPERATION)
    throw Exception("OpenGl: glEnd");
}

static void		xglFlush(void)
{
  int			error;

  glFlush();
  error = glGetError();
  if (error == GL_INVALID_OPERATION)
    throw Exception("OpenGl: glFlush");
}

void			ModuleOpenGL::display_slot(uint x, uint y, slot_t type)
{
  float			scale;

  x = -(this->width/2) + (BLOCK_SIZE/2) + (x * BLOCK_SIZE);
  y = (this->height/2)  - (BLOCK_SIZE/2) - (y * BLOCK_SIZE);
  glViewport(x, y, this->width, this->height);
  scale = ((float)BLOCK_SIZE / (float)this->width);
  switch (type)
    {
    case EMPTY:
      break ;
    case WALL:
      break ;
    case FRUIT:
      xglBegin(GL_QUADS);
      glColor3ub(255,102,0);
      glVertex2d(-scale,scale);
      glVertex2d(-scale,-scale);
      glColor3ub(255,102,0);
      glVertex2d(scale,scale);
      glVertex2d(scale,-scale);
      xglEnd();
      break ;
    case SNAKE_H:
      xglBegin(GL_QUADS);
      glColor3ub(162,162,162);
      glVertex2d(-scale,-scale);
      glVertex2d(-scale,scale);
      glColor3ub(162,162,162);
      glVertex2d(scale,scale);
      glVertex2d(scale,-scale);
      xglEnd();
      break ;
    case SNAKE_B:
      xglBegin(GL_QUADS);
      glColor3ub(102, 0, 204);
      glVertex2d(-scale,-scale);
      glVertex2d(-scale,scale);
      glColor3ub(102, 0, 204);
      glVertex2d(scale,scale);
      glVertex2d(scale,-scale);
      xglEnd();
      break ;
    default:
      throw Exception("OpenGL: Unknown type");
      break ;
    }
}

ModuleOpenGL::ModuleOpenGL(uint x, uint y)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw Exception(SDL_GetError());
  SDL_WM_SetCaption("Nibbler", NULL);
  if (SDL_SetVideoMode(x * BLOCK_SIZE, y * BLOCK_SIZE,
		       32, SDL_OPENGL) == NULL)
        throw Exception(SDL_GetError());
  this->width = x * BLOCK_SIZE;
  this->height = y * BLOCK_SIZE;
  glClear(GL_COLOR_BUFFER_BIT);
}

ModuleOpenGL::~ModuleOpenGL(void)
{
  SDL_Quit();
}

action_t		ModuleOpenGL::get_key(void)
{
  while	(SDL_PollEvent(&this->event))
    {
      switch(this->event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  return (ESCAPE);
	case SDLK_UP:
	  return (UP);
	case SDLK_DOWN:
	  return (DOWN);
	case SDLK_RIGHT:
	  return (RIGHT);
	case SDLK_LEFT:
	  return (LEFT);
	default:
	  return (OTHER);
	}
    }
  return (OTHER);
}


void		ModuleOpenGL::display(map_t const & map)
{
  uint		x;
  uint		y = 0;

  glClear(GL_COLOR_BUFFER_BIT);
  glViewport(0, 0, this->width, this->height);
  xglBegin(GL_QUADS);
  glColor3ub(51, 51, 51);
  glVertex2d(-1,-1);
  glVertex2d(-1,1);
  glColor3ub(30, 30, 30);
  glVertex2d(1,1);
  glVertex2d(1,-1);
  xglEnd();
  for (std::vector<std::vector<slot_t> >::const_iterator it_y = map.begin(); it_y != map.end(); ++it_y)
  {
    x = 0;
    for (std::vector<slot_t>::const_iterator it_x = (*it_y).begin(); it_x != (*it_y).end(); ++it_x)
    {
      display_slot(x, y, (*it_x));
      ++x;
    }
    ++y;
  }
  xglFlush();
  SDL_GL_SwapBuffers();
}

extern "C"
{
  IDisplayModule                *get_instance(uint x, uint y)
  {
    return (new ModuleOpenGL(x, y));
  }
}
