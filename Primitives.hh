//
// Primitives.hh for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Mon May  2 15:29:04 2011 romain capot
// Last update Sun Jun  5 16:47:16 2011 romain capot
//

#ifndef		__PRIMITIVES_HH__
#define		__PRIMITIVES_HH__

#include	"AObject.hh"

namespace Primitives
{
  class Triangle : public AObject
  {
  public:
    virtual void	initialize(void);
    virtual void	update(gdl::GameClock const &, gdl::Input &);
    virtual void	draw(void) const;
  };

  class Rectangle : public AObject
  {
  protected:
    gdl::Image	_texture;

  public:
    Rectangle(float, float, float, float, gdl::Image &);
    virtual void	initialize(void);
    virtual void	update(gdl::GameClock const &, gdl::Input &);
    virtual void	draw(void);
  };
}

#endif

