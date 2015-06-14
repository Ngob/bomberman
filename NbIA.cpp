//
// MapSize.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Sat Jun  4 15:04:28 2011 romain capot
// Last update Sun Jun  5 17:39:30 2011 inan asan
//

#include	"NbIA.hh"

NbIA::NbIA(int nbPlayers, gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, int mapSize)
  : _win(win), _clock(clock), _in(in), _nbPlayers(nbPlayers), _mapSize(mapSize), _mapPath("")
{
}

NbIA::NbIA(int nbPlayers, gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, std::string const & mapPath)
  : _win(win), _clock(clock), _in(in), _nbPlayers(nbPlayers), _mapSize(0), _mapPath(mapPath)
{
}

NbIA::~NbIA()
{
}

void			NbIA::draw()
{
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_back->draw();
  this->affNb.draw(350, 336, this->affNb.convNb(this->_nbIA));
  this->_win->display();
}

void			NbIA::update()
{
  this->_win->catchEvent();
  if (_in->isKeyDown(gdl::Keys::Up))
    {
      if (this->_nbIA < this->_maxIA)
	++this->_nbIA;
    }
  if (_in->isKeyDown(gdl::Keys::Down))
    {
      if (this->_nbIA > 0)
	--this->_nbIA;
    }
  if (_in->isKeyDown(gdl::Keys::Return))
    {
      Play		play(this->_nbPlayers, this->_win, this->_clock, this->_in, this->_mapPath, this->_mapSize, this->_nbIA);

      play.runGame();
      this->_exit = true;
    }
  if (_in->isKeyDown(gdl::Keys::Escape))
    this->_exit = true;
}

void			NbIA::initialize()
{
  this->_exit = false;
  this->_maxIA = 100;
  this->_nbIA = 0;
  this->_texBack = gdl::Image::load("data/backgrounds/bg_select_ai_nb.png");
  this->_back = new Primitives::Rectangle(0, 0, _win->getWidth(), _win->getHeight(), this->_texBack);
}

void			NbIA::runNbIA()
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
