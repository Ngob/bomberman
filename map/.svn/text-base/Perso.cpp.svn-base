//
// Perso.cpp for  in /u/all/ngo_b/cu/rendu/projetTek2/cpp/bomber/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 11 22:38:24 2011 benoit ngo
// Last update Thu May 26 16:26:29 2011 antoine basset
//

#include		"Perso.hh"

void		Perso::set_bomb(const bool bomb)
{
  this->_bomb = bomb;
}

void		Perso::move_back()
{
  this->_x = this->_ex_x;
  this->_y = this->_ex_y;
}

bool		Perso::is_computer() const
{
  return (this->_ia);
}

bool		Perso::could_bomb() const
{
  return (this->_bomb);
}

void		Perso::move_right()
{
  this->_ex_x = this->_x;
  this->_x += this->_dim_x;
}

void		Perso::move_left()
{
  this->_ex_x = this->_x;
  this->_x -= this->_dim_x;
}

void		Perso::move_down()
{
  this->_ex_y = this->_y;
  this->_y -= this->_dim_y;
}

void		Perso::move_up()
{
  this->_ex_y = this->_y;
  this->_y += this->_dim_y;
}

Perso::Perso(const int x, const int y, const bool isplayer):
  Obj(x, y, "perso", 10, 10, PERSO), _ia(isplayer), _bomb(true)
{

}

Perso::~Perso()
{

}
