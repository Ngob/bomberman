//
// Start.cpp for START in /home/asan_i//svn/bomberman-2014-capot_r
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Sat Jun  4 14:55:11 2011 inan asan
// Last update Sun Jun  5 17:41:07 2011 inan asan
//

#include	"Start.hh"

Start::Start(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, int w, int h)
  : _win(win), _clock(clock), _in(in), _winWidth(w), _winHeight(h)
{
  this->_exit = false;
}

Start::~Start()
{
}

void			Start::draw() const
{
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_back->draw();
  this->_win->display();
}

void			Start::update()
{
  this->_win->catchEvent();
  if (this->_in->isKeyDown(gdl::Keys::Escape))
    this->_exit = true;
}

void			Start::runStart()
{
  this->initialize();
  while(!this->_exit)
    {
      this->update();
      if (!this->_win->isOpened() ||  _exit == true)
	break ;
      this->draw();
      usleep(1500000);
      if (!this->_win->isOpened() || _exit == true)
	break ;
      this->initialize2();
      this->update();
      this->draw();
      usleep(1500000);
      if (!this->_win->isOpened() || _exit == true)
	break ;
      this->initialize3();
      this->update();
      this->draw();
      usleep(900000);
      if (!this->_win->isOpened() || _exit == true)
	break ;
      this->initialize4();
      this->update();
      this->draw();
      usleep(900000);
      if (!this->_win->isOpened() || _exit == true)
	break ;
      this->initialize5();
      this->update();
      this->draw();
      usleep(900000);
      if (!this->_win->isOpened() || _exit == true)
	break ;
      this->initialize6();
      this->update();
      this->draw();
      usleep(900000);
      this->_exit = true;
      delete this->_back;
    }
}

void			Start::initialize()
{
  this->_texBack = gdl::Image::load("data/backgrounds/intro1.png");
  this->_back = new Primitives::Rectangle(0, 0, this->_winWidth, this->_winHeight, this->_texBack);
}

void			Start::initialize2()
{
  this->_texBack = gdl::Image::load("data/backgrounds/intro2.png");
  this->_back = new Primitives::Rectangle(0, 0, this->_winWidth, this->_winHeight, this->_texBack);
}

void			Start::initialize3()
{
  this->_texBack = gdl::Image::load("data/backgrounds/intro3.png");
  this->_back = new Primitives::Rectangle(0, 0, this->_winWidth, this->_winHeight, this->_texBack);
}

void			Start::initialize4()
{
  this->_texBack = gdl::Image::load("data/backgrounds/intro4.png");
  this->_back = new Primitives::Rectangle(0, 0, this->_winWidth, this->_winHeight, this->_texBack);
}

void			Start::initialize5()
{
  this->_texBack = gdl::Image::load("data/backgrounds/intro5.png");
  this->_back = new Primitives::Rectangle(0, 0, this->_winWidth, this->_winHeight, this->_texBack);
}

void			Start::initialize6()
{
  this->_texBack = gdl::Image::load("data/backgrounds/intro5.png");
  this->_back = new Primitives::Rectangle(0, 0, this->_winWidth, this->_winHeight, this->_texBack);
}
