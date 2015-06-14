//
// Button.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Wed May  4 10:58:59 2011 romain capot
// Last update Sun Jun  5 17:51:02 2011 antoine basset
//

#include	"Button.hh"

Button::Button(std::string const & name, MenuEnum::eMenuType type, MenuEnum::eMenuType typeNext, gdl::Image & texture, gdl::Image & textureOver, float posX, float posY)
  : AObject(posX, posY, 435, 38), _name(name), _select(false), _type(type), _typeNext(typeNext)
{
  this->_texture = texture;
  this->_textureOver = textureOver;
}

Button::~Button()
{
}

std::string const &	Button::getName() const
{
  return this->_name;
}

bool		Button::getSelect() const
{
  return this->_select;
}

MenuEnum::eMenuType		Button::getType() const
{
  return this->_type;
}

MenuEnum::eMenuType		Button::getTypeNext() const
{
  return this->_typeNext;
}

void		Button::switchSelect()
{
  if (this->_select)
    this->_select = false;
  else
    this->_select = true;
}

void		Button::initialize()
{
}

void		Button::update(gdl::GameClock const & clock, gdl::Input & input)
{
  (void)clock;
  (void)input;
}

void		Button::draw()
{
  if (this->_select)
    this->_textureOver.bind();
  else
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
