//
// HighScores.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Fri Jun  3 10:44:15 2011 romain capot
// Last update Sun Jun  5 16:58:51 2011 romain capot
//

#include	"HighScores.hh"

HighScores::HighScores(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, Primitives::Rectangle * back)
  : _win(win), _clock(clock), _in(in), _back(back)
{
  this->_exit = false;
}

HighScores::~HighScores()
{
}

void			HighScores::draw()
{
  int		x = 100;
  int		y = 450;

  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_back->draw();
  for (std::vector<std::string>::iterator it = nb.begin(); it != nb.end(); ++it)
    {
      affNb.draw(x, y, *it);
      y -= 50;
    }
  this->_win->display();
}

void			HighScores::update()
{
  this->_win->catchEvent();
  if (_in->isKeyDown(gdl::Keys::Escape))
    this->_exit = true;
}

void			HighScores::initialize()
{
  _best.file_to_vector("./data/scores/higth_score.log");
  setNb(_best.getStringHighScores());
}

void			HighScores::runHighScores()
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
}

void		HighScores::setNb(std::vector<std::string> const & tab)
{
  this->nb = tab;
}
