//
// create_cube.hh for  in /u/all/benham_a/rendu/tek2/C++/bomberman/bomberman-2014-capot_r
// 
// Made by camille benhamou
// Login   <benham_a@epitech.net>
// 
// Started on  Mon May 30 14:25:03 2011 camille benhamou
// Last update Sat Jun  4 14:09:37 2011 romain capot
//

#ifndef	__CREATE_CUBE_HH__
# define __CREATE_CUBE_HH__

#include	"AObject.hh"

class Cube : public AObject
{
protected:
  int	_cubeSize;

  int	_mapX;
  int	_mapY;

public:
  Cube(int, int, int);

  virtual void initialize(void);
  virtual void update(gdl::GameClock const &, gdl::Input &);
  virtual void draw();
  void draw(int, int, gdl::Image &);
};

#endif
