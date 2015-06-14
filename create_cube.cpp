//
// create_cube.cpp for ] in /u/all/benham_a/rendu/tek2/C++/bomberman/bomberman-2014-capot_r
// 
// Made by camille benhamou
// Login   <benham_a@epitech.net>
// 
// Started on  Mon May 30 14:15:57 2011 camille benhamou
// Last update Sun Jun  5 17:49:19 2011 camille benhamou
//

#include "create_cube.hh"

Cube::Cube(int cubeSize, int mapX, int mapY)
  : _cubeSize(cubeSize), _mapX(mapX), _mapY(mapY)
{
}

void	Cube::initialize(void)
{
}

void	Cube::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void)gameClock;
  (void)input;
}

void	Cube::draw()
{
}

void	Cube::draw(int blockX, int blockY, gdl::Image & tex)
{
  int	x, y;


  tex.bind();
  glBegin(GL_QUADS);

  x = ((this->_mapX * 20) / -2) + 10 + (blockX * 20);
  y = ((this->_mapY * 20) / -2) + 10 + (blockY * 20);

  // FACE TOP
  /// Vertex superieur gauche
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(x + -10.0f, 20.0f, y + 10.0f);
  /// Vertex inferieur gauche
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(x + -10.0f, 20.0f, y + -10.0f);
  /// Vertex inferieur droit
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(x + 10.0f, 20.0f, y + -10.0f);
  /// Vertex superieur droit
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(x + 10.0f, 20.0f, y + 10.0f);

  // FACE FRONT
  /// Vertex superieur gauche
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(x + -10.0f, 20.0f, y + 10.0f);
  /// Vertex inferieur gauche
  glTexCoord2f(0.0f, 0.1f);
  glVertex3f(x + -10.0f, 0.0f, y + 10.0f);
  /// Vertex inferieur droit
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(x + 10.0f, 0.0f, y + 10.0f);
  /// Vertex superieur droit
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(x + 10.0f, 20.0f, y + 10.0f);

  // FACE LEFT
  /// Vertex superieur gauche
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(x + -10.0f, 20.0f, y + -10.0f);
  /// Vertex inferieur gauche
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(x + -10.0f, 0.0f, y + -10.0f);
  /// Vertex inferieur droit
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(x + -10.0f, 0.0f, y + 10.0f);
  /// Vertex superieur droit
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(x + -10.0f, 20.0f, y + 10.0f);

  // FACE BACK
  /// Vertex superieur gauche
  glVertex3f(x + 10.0f, 20.0f, y + -10.0f);
  /// Vertex inferieur gauche
  glVertex3f(x + 10.0f, 0.0f, y + -10.0f);
  /// Vertex inferieur droit
  glVertex3f(x + -10.0f, 0.0f, y + -10.0f);
  /// Vertex superieur droit
  glVertex3f(x + -10.0f, 20.0f, y + -10.0f);

  // FACE RIGHT
  /// Vertex superieur gauche
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(x + 10.0f, 20.0f, y + 10.0f);
  /// Vertex inferieur gauche
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(x + 10.0f, 0.0f, y + 10.0f);
  /// Vertex inferieur droit
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(x + 10.0f, 0.0f, y + -10.0f);
  /// Vertex superieur droit
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(x + 10.0f, 20.0f, y + -10.0f);

  glEnd();
}
