//
// highScores.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Fri Jun  3 10:45:13 2011 romain capot
// Last update Fri Jun  3 19:05:21 2011 antoine basset
//

#ifndef		__HIGHSCORES_HH__
#define		__HIGHSCORES_HH__

#include	<iostream>
#include	<vector>
#include	"Primitives.hh"
#include	"Game.hpp"
#include	"Menu.hh"
#include	"AffNb.hh"
#include	"Score.hh"

class HighScores
{
protected:
  gdl::Window		* _win;
  gdl::GameClock        * _clock;
  gdl::Input		* _in;
  int			_winWidth;
  int			_winHeight;
  bool			_exit;
  Primitives::Rectangle	*_back;
  AffNb			affNb;
  std::vector<std::string>	nb;
  Score			_best;

public:
  HighScores(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, Primitives::Rectangle * back);
  ~HighScores();
  void		setNb(std::vector<std::string> const & tab);
  void		draw();
  void		update();
  void		initialize(void);
  void		runHighScores();
};

#endif
