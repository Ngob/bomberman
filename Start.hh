//
// Start.hh for start in /home/asan_i//svn/bomberman-2014-capot_r
// 
// Made by inan asan
// Login   <asan_i@epitech.net>
// 
// Started on  Sat Jun  4 14:55:21 2011 inan asan
// Last update Sun Jun  5 16:34:39 2011 romain capot
//

#ifndef		__START_HH__
#define		__START_HH__

#include	"Primitives.hh"
#include	"Game.hpp"
#include	"Menu.hh"

class		Start
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
  Start(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, int w, int h);
  ~Start();
  void		draw() const;
  void		update();
  void		initialize(void);
  void		initialize2(void);
  void		initialize3(void);
  void		initialize4(void);
  void		initialize5(void);
  void		initialize6(void);
  void		runStart();
};

#endif		/*__START_HH__*/
