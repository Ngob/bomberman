//
// Options.hh for Bombermass in /home/chaulv_c//rendu/cpp/bomberman/bomberman-2014-capot_r
// 
// Made by chris chaulvet
// Login   <chaulv_c@epitech.net>
// 
// Started on  Sat Jun  4 18:43:09 2011 chris chaulvet
// Last update Sun Jun  5 16:51:28 2011 romain capot
//

#ifndef		__OPTIONS_HH__
#define		__OPTIONS_HH__

#include	"Primitives.hh"
#include	"Game.hpp"
#include	"Menu.hh"

class		Options
{
  gdl::Window		* _win;
  gdl::GameClock        * _clock;
  gdl::Input		* _in;
  int			_winWidth;
  int			_winHeight;
  bool			_exit;
  gdl::Image		_texBack;
  Primitives::Rectangle	* _back;
public:
  Options(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, int w, int h);
  ~Options();

  void		draw();
  void		update();
  void		runOptions();
  void		initialize();
};

#endif
