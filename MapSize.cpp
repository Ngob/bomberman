//
// MapSize.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Sat Jun  4 15:04:28 2011 romain capot
// Last update Sun Jun  5 17:59:34 2011 camille benhamou
//

#include	"MapSize.hh"

MapSize::MapSize(int nbPlayers, gdl::Window * win, gdl::GameClock * clock, gdl::Input * in)
  : _win(win), _clock(clock), _in(in), _nbPlayers(nbPlayers)
{
  this->_exit = false;
  this->_mapSize = 15;
  if (this->_nbPlayers == 1)
    this->_mapMax = 100;
  else if (this->_nbPlayers == 2)
    this->_mapMax = 22;
}

MapSize::~MapSize()
{
}

void			MapSize::draw()
{
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_back->draw();
  this->affNb.draw(350, 336, this->affNb.convNb(this->_mapSize));
  this->_win->display();
}

void			MapSize::update()
{
  this->_win->catchEvent();
  if (_in->isKeyDown(gdl::Keys::Up))
    {
      if (this->_mapSize < this->_mapMax)
	++this->_mapSize;
    }
  if (_in->isKeyDown(gdl::Keys::Down))
    {
      if (this->_mapSize > 15)
	--this->_mapSize;
    }
  if (_in->isKeyDown(gdl::Keys::Return))
    {
      NbIA		nbIA(this->_nbPlayers, this->_win, this->_clock, this->_in, this->_mapSize);

      nbIA.runNbIA();
      this->_exit = true;
    }
  if (this->_in->isKeyDown(gdl::Keys::Escape))
    this->_exit = true;
}

void			MapSize::initialize()
{
  this->_texBack = gdl::Image::load("data/backgrounds/bg_select_map_size.png");
  this->_back = new Primitives::Rectangle(0, 0, _win->getWidth(), _win->getHeight(), this->_texBack);
}

void			MapSize::runMapSize()
{
  this->initialize();
  while(!this->_exit)
    {
      usleep(90000);
      this->update();
      if (!this->_win->isOpened())
	break ;
      this->draw();
    }
  delete this->_back;
}
