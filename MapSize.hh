//
// MapSize.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Sat Jun  4 15:04:38 2011 romain capot
// Last update Sun Jun  5 11:16:04 2011 romain capot
//

#ifndef		__MAPSIZE_HH__
#define		__MAPSIZE_HH__

#include	"Primitives.hh"
#include	"Game.hpp"
#include	"Menu.hh"
#include	"AffNb.hh"
#include	"NbIA.hh"

class		MapSize
{
  gdl::Window		* _win;
  gdl::GameClock        * _clock;
  gdl::Input		* _in;
  int			_winWidth;
  int			_winHeight;

  int			_nbPlayers;
  int			_mapSize;

  AffNb			affNb;

  bool			_exit;

  gdl::Image		_texBack;
  Primitives::Rectangle	* _back;

  int			_mapMax;

public:
  MapSize(int nbPlayers, gdl::Window * win, gdl::GameClock * clock, gdl::Input * in);
  ~MapSize();

  void		draw();
  void		update();
  void		initialize(void);
  void		runMapSize();
};

#endif		/*__MapSIZE_HH__*/
