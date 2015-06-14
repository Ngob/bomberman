//
// Wall.cpp for  in /afs/epitech.net/users/epitech_2014/ngo_b/rendu/projetTek2/cpp/bomber/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Thu May 12 13:14:12 2011 benoit ngo
// Last update Wed Jun  1 14:20:21 2011 benoit ngo
//

#include	"Wall.hh"


Wall::~Wall()
{

}

EType		Wall::getType(const bool t)
{
  if (t == true)
    return (DWALL);
  else
    return (WALL);
}

void		Wall::setdest(const bool t)
{
  if (t == true)
    this->_type = DWALL;
  else
    this->_type = WALL;
  this->_dest = t;
}

Wall::Wall(const int x, const int y, const bool dest):
  Obj(x, y, getType(dest)), _dest(dest)
{

}

bool		Wall::is_dest() const
{
  return (this->_dest);
}
