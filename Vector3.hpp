//
// Vector3.hpp for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Mon May  2 14:33:30 2011 romain capot
// Last update Mon May  2 15:50:34 2011 romain capot
//

#ifndef		__VECTOR3_HH__
#define		__VECTOR3_HH__

template<typename T>
class	Vector3
{
protected:
  T	_x;
  T	_y;
  T	_z;

public:
  Vector3()
    : _x(0), _y(0), _z(0)
  {
  }

  Vector3(T x, T y, T z)
    : _x(x), _y(y), _z(z)
  {
  }

  T	getX() const
  {
    return this->_x;
  }

  T	getY() const
  {
    return this->_y;
  }

  T	getZ() const
  {
    return this->_z;
  }

  void	setX(T const & x)
  {
    this->_x = x;
  }

  void	setY(T const & y)
  {
    this->_y = y;
  }

  void	setZ(T const & z)
  {
    this->_z = z;
  }
};

#endif
