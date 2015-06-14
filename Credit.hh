//
// Credit.hh for Bomberman in /home/chaulv_c//rendu/cpp/bomberman/bomberman-2014-capot_r
// 
// Made by chris chaulvet
// Login   <chaulv_c@epitech.net>
// 
// Started on  Thu Jun  2 15:16:39 2011 chris chaulvet
// Last update Sat Jun  4 18:52:35 2011 chris chaulvet
//

#ifndef		__CREDIT_HH__
#define		__CREDIT_HH__

#include	"Primitives.hh"
#include	"Game.hpp"
#include	"Menu.hh"

class		Credit
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
  Credit(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, int w, int h);
  ~Credit();
  void		draw();
  void		update();
  void		initialize(void);
  void		runCredit();
};

#endif		/*__CREDIT_HH__*/
