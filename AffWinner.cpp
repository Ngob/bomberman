//
// AffWinner.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Sun Jun  5 10:05:49 2011 romain capot
// Last update Sun Jun  5 17:44:00 2011 antoine basset
//

#include	"AffWinner.hh"

checkWinner	winTab[]={
  {CheckQuit::PLAYER1, "data/backgrounds/bg_p1_win.png"},
  {CheckQuit::PLAYER2, "data/backgrounds/bg_p2_win.png"},
  {CheckQuit::IA, "data/backgrounds/bg_ai_win.png"},
  {CheckQuit::EQUALITY, "data/backgrounds/bg_you_lose.png"},
  {CheckQuit::NONE, ""},
};

AffWinner::AffWinner(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, CheckQuit::eWinPlayer winner)
  : _win(win), _clock(clock), _in(in), _winner(winner)
{
  this->_exit = false;
  this->_playSound = new PlaySound();
}

AffWinner::~AffWinner()
{
  delete this->_playSound;
}

void			AffWinner::draw()
{
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_back->draw();
  this->_win->display();
}

void			AffWinner::update()
{
  this->_win->catchEvent();
  if (this->_in->isKeyDown(gdl::Keys::Return))
    this->_exit = true;
}

void			AffWinner::initialize()
{
  this->_camera.initialize();

  for (int i = 0; winTab[i].win != CheckQuit::NONE; ++i)
    {
      if (winTab[i].win == this->_winner)
	this->_texWinner = gdl::Image::load(winTab[i].pathTex);
    }
  this->_back = new Primitives::Rectangle(0, 0, this->_win->getWidth(), this->_win->getHeight(), this->_texWinner);
  this->_playSound->playMusic("data/sounds/win/winner.ogg");
}

void			AffWinner::affWinner()
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
  this->_playSound->stopMusic();
}
