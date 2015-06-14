//
// Plate.hh for Bomberman in /home/chaulv_c//rendu/cpp/bomberman/bomberman-2014-capot_r
// 
// Made by chris chaulvet
// Login   <chaulv_c@epitech.net>
// 
// Started on  Mon May 30 17:48:07 2011 chris chaulvet
// Last update Sun Jun  5 16:50:52 2011 romain capot
//

#ifndef			__PLATE_HH__
#define			__PLATE_HH__
#include		"GL/gl.h"
#include		"GL/glu.h"
#include		"Game.hpp"
#include		"Image.hpp"

class			Plate
{
  int			width;
  int			height;
  gdl::Image		texBack;

public:
  Plate(int, int);
  ~Plate();

  void			draw();
};

#endif			/* __PLATE_HH__ */
