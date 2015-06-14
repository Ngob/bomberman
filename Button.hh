//
// Button.hh for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Wed May  4 10:59:07 2011 romain capot
// Last update Mon May  9 14:20:32 2011 romain capot
//

#ifndef		__BUTTON_HH__
#define		__BUTTON_HH__

#include	<iostream>
#include	<string>
#include	"MenuEnum.hh"
#include	"AObject.hh"

class	Button : public AObject
{
protected:
  std::string	_name;
  bool		_select;

  gdl::Image	_texture;
  gdl::Image	_textureOver;

  MenuEnum::eMenuType	_type;
  MenuEnum::eMenuType	_typeNext;

public:
  Button(std::string const &, MenuEnum::eMenuType, MenuEnum::eMenuType,
	 gdl::Image &, gdl::Image &, float, float);
  ~Button();

  std::string const &	getName() const;
  bool			getSelect() const;
  MenuEnum::eMenuType	getType() const;
  MenuEnum::eMenuType	getTypeNext() const;

  void		switchSelect();

  virtual void		initialize();
  virtual void		update(gdl::GameClock const &, gdl::Input &);
  virtual void		draw();
};

#endif
