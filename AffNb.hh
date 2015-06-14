//
// AffNb.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Fri Jun  3 09:29:39 2011 romain capot
// Last update Sun Jun  5 17:12:34 2011 romain capot
//

#include	<iostream>
#include	<vector>
#include	<sstream>
#include	"Game.hpp"
#include	"Image.hpp"
#include	"Primitives.hh"

#ifndef		__AFFNB_HH__
#define		__AFFNB_HH__

class AffNb
{
protected:
  std::vector<gdl::Image>	_listTex;

public:
  AffNb();
  ~AffNb();

  int		convNb(std::string const &) const;
  std::string	convNb(int) const;
  void		draw(int, int, std::string const &);
  void		drawNb(int, int, int);
};

#endif
