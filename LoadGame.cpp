//
// LoadGame.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Last update Sun Jun  5 18:53:38 2011 benoit ngo
//

#include	"LoadGame.hh"

LoadGame::LoadGame(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in)
  : _win(win), _clock(clock), _in(in), _saveSize(1)
{
  this->_exit = false;
}

LoadGame::~LoadGame()
{
}

void			LoadGame::draw()
{
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_back->draw();
  this->affNb.draw(350, 336, this->affNb.convNb(this->_saveSize));
  this->_win->display();
}

void			LoadGame::update()
{
  this->_win->catchEvent();
  if (this->_in->isKeyDown(gdl::Keys::Up))
    {
      ++this->_saveSize;
    }
  if (this->_in->isKeyDown(gdl::Keys::Down))
    {
      if (this->_saveSize > 1)
	--this->_saveSize;
    }
  if (this->_in->isKeyDown(gdl::Keys::Return))
    {
      Play		play(_win, _clock, _in, this->_saveSize);

      if (play.getNbPlayers() != 0)
	{
	  play.runGame();
	}
      this->_exit = true;
    }
  if (this->_in->isKeyDown(gdl::Keys::Escape))
    this->_exit = true;
}

void			LoadGame::initialize()
{
  _texBack = gdl::Image::load("data/backgrounds/bg_select_load.png");
  _back = new Primitives::Rectangle(0, 0, _win->getWidth(), _win->getHeight(), this->_texBack);
}

void			LoadGame::runLoadGame()
{
  this->initialize();
  while(!_exit)
    {
      usleep(90000);
      this->update();
      if (!this->_win->isOpened())
	break ;
      this->draw();

    }
  delete this->_back;
}
