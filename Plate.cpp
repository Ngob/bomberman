//
// Plate.cpp for Bomberman in /home/chaulv_c//rendu/cpp/bomberman/bomberman-2014-capot_r
// 
// Made by chris chaulvet
// Login   <chaulv_c@epitech.net>
// 
// Started on  Mon May 30 17:43:37 2011 chris chaulvet
// Last update Sun Jun  5 16:51:02 2011 romain capot
//

#include	"Plate.hh"
#include	<iostream>

Plate::Plate(int w, int h)
 : width(w), height(h)
{
  texBack = gdl::Image::load("data/textures/herbe.png");
}

Plate::~Plate()
{
}

void			Plate::draw()
{
  texBack.bind();
  glBegin(GL_QUAD_STRIP);

  int w = this->width * 20;
  int h = this->height * 20;


  /// Vertex superieur gauche
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(w/2 * -1, 0.0f, h/2);
  /// Vertex inferieur gauche
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(w/2 * -1, 0.0f, h/2 * -1);
  /// Vertex inferieur droit
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(w/2, 0.0f, h/2);
  /// Vertex superieur droit
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(w/2, 0.0f, h/2 * -1);
  glEnd();
}
