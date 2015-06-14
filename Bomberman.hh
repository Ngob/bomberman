//
// bomberman.hh for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Mon May  2 11:13:13 2011 romain capot
// Last update Sat Jun  4 14:52:42 2011 romain capot
//

#include	<iostream>
#include	<list>
#include	<stdexcept>
#include	"Game.hpp"
#include	"Camera.hh"
#include	"AObject.hh"
#include	"Primitives.hh"

#ifndef		__BOMBERMAN_HH__
#define		__BOMBERMAN_HH__

class Bomberman : public gdl::Game
{
protected:
  Camera		_camera;

  bool			exit;

  // Options de la fenetres
  size_t	_winWidth;
  size_t	_winHeight;

public:
  Bomberman(void);
  ~Bomberman(void);

  virtual void	update(void) = 0;
  virtual void	draw(void) = 0;
  virtual void	unload(void) = 0;
};

#endif
