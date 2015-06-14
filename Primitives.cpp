//
// Primitives.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Mon May  2 15:27:30 2011 romain capot
// Last update Sun Jun  5 17:54:08 2011 inan asan
//

#include	"Game.hpp"
#include	"Primitives.hh"

namespace Primitives
{
  // TRIANGLE
  void		Triangle::initialize()
  {
  }

  void		Triangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    (void)gameClock;
    (void)input;
  }

  void		Triangle::draw(void) const
  {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.50f, 0.75f);

    /// Vertex haut
    glVertex3f(0.0f, 150.0f, 0);
    /// Vertex bas gauche
    glVertex3f(-150.0f, 0.0f, 0);
    /// Vertex bas droit
    glVertex3f(150.0f, 00.0f, 0);

    glEnd();
  }

  //RECTANGLE
  Rectangle::Rectangle(float posX, float posY, float width, float height, gdl::Image & texture)
    : AObject(posX, posY, width, height)
  {
    this->_texture = texture;
  }

  void		Rectangle::initialize(void)
  {
  }

  void		Rectangle::update(gdl::GameClock const & clock, gdl::Input &input)
  {
    (void)clock;
    (void)input;
  }

  void		Rectangle::draw(void)
  {
    this->_texture.bind();
    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
     /// Vertex superieur gauche
    glVertex3f(this->_posX, this->_posY + this->_height, 0.0f);
     /// Vertex inferieur gauche
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(this->_posX, this->_posY, 0.0f);
    /// Vertex inferieur droit
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(this->_posX + this->_width, this->_posY, 0.0f);
    /// Vertex superieur droit
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(this->_posX + this->_width, this->_posY + this->_height, 0.0f);
    glEnd();
  }
}
