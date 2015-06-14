//
// AObj.cpp for  in /u/all/ngo_b/cu/rendu/projetTek2/cpp/bomber/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 11 22:31:04 2011 benoit ngo
// Last update Sat Jun  4 14:34:22 2011 inan asan
//

#include	"AObj.hh"

void		Obj::setMaze(const bool t)
{
  this->_maze = t;
}

bool		Obj::getMaze() const
{
  return (this->_maze);
}
EType		Obj::get_type() const
{
  return (this->_type);
}

void		Obj::setType(EType type)
{
  this->_type = type;
}

void		Obj::set_y(const int y)
{
  this->_y = y;
}
void		Obj::set_x(const int x)
{
  this->_x = x;
}

int		Obj::get_x() const
{
  return (this->_x);
}

int		Obj::get_y() const
{
  return (this->_y);
}

bool		Obj::operator==(const Obj & o) const
{
  if (this->_x == o.get_x() && this->_y == o.get_y())
    return (true);
  return (false);
}

Obj::Obj(const int x, const int y,
	 const EType type):
  _x(x), _y(y),
  _type(type), _maze(false)
{

}

Obj::~Obj()
{

}
