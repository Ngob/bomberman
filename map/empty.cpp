//
// empty.cpp for  in /home/ngo_b//rendu/proj/bomberman-2014-capot_r/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 25 20:08:16 2011 benoit ngo
// Last update Sun Jun  5 18:03:53 2011 benoit ngo
//

#include		"empty.hh"

empty::empty(const int x, const int y):
  Obj(x, y, EMPTY),
  _isFire(false)
{

}

void		empty::setFire(const bool f)
{
  this->_isFire = f;
}

bool		empty::getFire() const
{
  return (this->_isFire);
}

empty::~empty()
{

}
