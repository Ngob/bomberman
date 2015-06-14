//
// LoadGame.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Sat Jun  4 15:04:38 2011 romain capot
// Last update Sun Jun  5 17:25:58 2011 camille benhamou
//

#ifndef		__LOADGAME_HH_
#define		__LOADGAME_HH_

#include	"Primitives.hh"
#include	"Game.hpp"
#include	"Menu.hh"
#include	"AffNb.hh"
#include	"NbIA.hh"
#include	"PlaySound.hh"

class		LoadGame
{
  gdl::Window		* _win;
  gdl::GameClock        * _clock;
  gdl::Input		* _in;
  int			_winWidth;
  int			_winHeight;

  int			_saveSize;

  AffNb			affNb;

  bool			_exit;

  gdl::Image		_texBack;
  Primitives::Rectangle	* _back;

public:
  LoadGame(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in);
  ~LoadGame();

  void		draw();
  void		update();
  void		initialize(void);
  void		runLoadGame();
};

#endif		/*__LOADGAME_HH_*/
