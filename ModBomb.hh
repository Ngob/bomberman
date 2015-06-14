//
// ModBomb.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Wed Jun  1 14:20:58 2011 romain capot
// Last update Wed Jun  1 14:33:36 2011 romain capot
//

#include	<iostream>
#include	"Game.hpp"
#include	"Model.hpp"

#ifndef		__MODBOMB_HH__
#define		__MODBOMB_HH__

class ModBomb
{
private:
  int		_mapX;
  int		_mapY;
  int		_cubeSize;

  gdl::Model	model_;

public:
  ModBomb(int, int, int);

  void initialize(void);
  void update(gdl::GameClock const &, gdl::Input &);
  void draw(int, int);

  void	setPos(int, int);
};

#endif
