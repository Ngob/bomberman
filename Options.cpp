//
// Options.cpp for Bombermass in /home/chaulv_c//rendu/cpp/bomberman/bomberman-2014-capot_r
// 
// Made by chris chaulvet
// Login   <chaulv_c@epitech.net>
// 
// Started on  Sat Jun  4 18:41:44 2011 chris chaulvet
// Last update Sun Jun  5 18:19:02 2011 chris chaulvet
//

#include	"Options.hh"

Options::Options(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, int w, int h)
  : _win(win), _clock(clock), _in(in), _winWidth(w), _winHeight(h)
{
  this->_exit = false;
}

Options::~Options()
{
}

void			Options::draw()
{
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_back->draw();
  this->_win->display();
}

void			Options::update()
{
  this->_win->catchEvent();
  if (this->_in->isKeyDown(gdl::Keys::Escape))
    this->_exit = true;
}

void			Options::initialize()
{
  this->_texBack = gdl::Image::load("data/backgrounds/bg_options.png");
  this->_back = new Primitives::Rectangle(0, 0, this->_winWidth, this->_winHeight, this->_texBack);
}

void			Options::runOptions()
{
  this->initialize();
  while(!this->_exit)
    {
      this->update();
      if (!this->_win->isOpened())
	break ;
      this->draw();
      usleep(90000);
    }
  delete this->_back;
}
