//
// AffWinner.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Sun Jun  5 10:06:31 2011 romain capot
// Last update Sun Jun  5 14:11:55 2011 camille benhamou
//

#ifndef		__AFFWINNER_HH__
#define		__AFFWINNER_HH__

#include	"Primitives.hh"
#include	"Game.hpp"
#include	"CheckQuit.hh"
#include	"Camera.hh"
#include	"PlaySound.hh"

class		AffWinner
{
  gdl::Window		* _win;
  gdl::GameClock        * _clock;
  gdl::Input		* _in;

  Camera		_camera;

  gdl::Image		_texWinner;
  Primitives::Rectangle	* _back;

  CheckQuit::eWinPlayer	_winner;
  PlaySound	*_playSound;
  bool			_exit;

public:
  AffWinner(gdl::Window *, gdl::GameClock *, gdl::Input *, CheckQuit::eWinPlayer);
  ~AffWinner();

  void		draw();
  void		update();
  void		initialize(void);
  void		affWinner();
};

typedef struct	s_checkWinner
{
  CheckQuit::eWinPlayer	win;
  std::string	pathTex;
}		checkWinner;

#endif		/*__AFFWINNER_HH__*/
