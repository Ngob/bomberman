//
// MapSize.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Sat Jun  4 15:04:38 2011 romain capot
// Last update Sat Jun  4 17:00:04 2011 romain capot
//

#ifndef		__NBIA_HH__
#define		__NBIA_HH__

#include	"Primitives.hh"
#include	"Game.hpp"
#include	"Menu.hh"
#include	"AffNb.hh"
#include	"Play.hh"

class		NbIA
{
  gdl::Window		* _win;
  gdl::GameClock        * _clock;
  gdl::Input		* _in;
  int			_winWidth;
  int			_winHeight;

  int			_nbPlayers;
  int			_nbIA;

  AffNb			affNb;

  bool			_exit;

  gdl::Image		_texBack;
  Primitives::Rectangle	* _back;

  int			_maxIA;

  int			_mapSize;
  std::string		_mapPath;

public:
  NbIA(int, gdl::Window *, gdl::GameClock *, gdl::Input *, int);
  NbIA(int, gdl::Window *, gdl::GameClock *, gdl::Input *, std::string const &);
  ~NbIA();

  void		draw();
  void		update();
  void		initialize(void);
  void		runNbIA();
};

#endif		/*__NbIA_HH__*/
