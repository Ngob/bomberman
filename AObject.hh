//
// AObject.hh for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Mon May  2 15:17:35 2011 romain capot
// Last update Fri Jun  3 10:41:58 2011 romain capot
//

#include	<iostream>
#include	"GL/gl.h"
#include	"GL/glu.h"
#include	"Game.hpp"
#include	"Vector3.hpp"
#include	"Image.hpp"

#ifndef		__AOBJECT_HH__
#define		__AOBJECT_HH__

class    AObject
{
protected:
  float		_posX;
  float		_posY;
  float		_width;
  float		_height;

  Vector3<float>	_position;
  Vector3<float>	_rotation;

public:
  AObject(void);
  AObject(float, float, float, float);
  virtual ~AObject(void);

  virtual void initialize(void) = 0;
  virtual void update(gdl::GameClock const &, gdl::Input &) = 0;
  virtual void draw(void) = 0;
};

#endif
