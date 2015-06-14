//
// AffMap.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Tue May 31 09:36:54 2011 romain capot
// Last update Sat Jun  4 14:37:40 2011 inan asan
//

#include	<iostream>
#include	"Game.hpp"
#include	"map/map.hh"
#include	"map/AObj.hh"
#include	"create_cube.hh"

#ifndef		__AFFMAP_HH__
#define		__AFFMAP_HH__

class	AffMap
{
public:
  bool		_reload;
protected:
  Map		*_map;
  int		_blockSize;
  Cube		*_cube;

  // textures
  gdl::Image	_texWall;
  gdl::Image	_texExp;
  gdl::Image	_texDWall;

public:
  AffMap(Map *, int);
  ~AffMap();

  void		checkAff();
  void		affWall(int, int);
  void		affDWall(int, int);
  void		affExplode(int, int);
  void		affBomb(int, int);
};

typedef	struct	affWall
{
  EType		typeWall;
  void		(AffMap::*ptrFunc)(int, int);
}		affWall;

#endif
