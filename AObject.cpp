//
// AObject.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Mon May  2 15:19:41 2011 romain capot
// Last update Thu May  5 13:22:15 2011 romain capot
//

#include	"AObject.hh"

AObject::AObject()
  : _posX(0), _posY(0), _width(0), _height(0), _position(0.0f, 0.0f, 0.0f), _rotation(0.0f, 0.0f, 0.0f)
{
}

AObject::AObject(float posX, float posY, float width, float height)
  : _posX(posX), _posY(posY), _width(width), _height(height),  _position(posX, posY, 0.0f), _rotation(0.0f, 0.0f, 0.0f)
{
}

AObject::~AObject()
{
}
