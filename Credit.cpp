//
// Credit.cpp for Bomberman in /home/chaulv_c//rendu/cpp/bomberman/bomberman-2014-capot_r
// 
// Made by chris chaulvet
// Login   <chaulv_c@epitech.net>
// 
// Started on  Thu Jun  2 15:15:51 2011 chris chaulvet
// Last update Sun Jun  5 17:30:59 2011 romain capot
//

#include	"Credit.hh"

Credit::Credit(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, int w, int h)
  : _win(win), _clock(clock), _in(in), _winWidth(w), _winHeight(h)
{
  this->_exit = false;
}

Credit::~Credit()
{
}

void			Credit::draw()
{
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_back->draw();
  this->_win->display();
}

void			Credit::update()
{
  this->_win->catchEvent();
  if (_in->isKeyDown(gdl::Keys::Escape))
    this->_exit = true;
}

void			Credit::initialize()
{
  _texBack = gdl::Image::load("data/buttons/btn_menu_credits.png");
  _back = new Primitives::Rectangle(0, 0, this->_winWidth, this->_winHeight, this->_texBack);
}

void			Credit::runCredit()
{
  this->initialize();
  while(!_exit)
    {
      this->update();
      if (!this->_win->isOpened())
	break ;
      this->draw();
      usleep(90000);
    }
  delete this->_back;
}
