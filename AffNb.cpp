//
// AffNb.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Fri Jun  3 09:29:33 2011 romain capot
// Last update Sun Jun  5 17:42:04 2011 antoine basset
//

#include	"AffNb.hh"

AffNb::AffNb()
{
  gdl::Image	img;
  std::string	texName;

  for (int i = 0; i < 10; ++i)
    {
      texName = "data/bitmapNb/bmp_";
      texName += convNb(i);
      texName += ".png";
      img = gdl::Image::load(texName);
      this->_listTex.push_back(img);
    }
}

AffNb::~AffNb()
{

}

int		AffNb::convNb(std::string const & str) const
{
  int			nb;
  std::stringstream     Str;

  Str << str;
  Str >> nb;
  return nb;
}

std::string	AffNb::convNb(int nb) const
{
  std::ostringstream temp;

  temp << nb;
  return temp.str();
}

void		 AffNb::draw(int posX, int posY, std::string const & nb)
{
  this->drawNb(posX + (20 * (nb.size() - 1)), posY, this->convNb(nb));
}

void		AffNb::drawNb(int posX, int posY, int nb)
{
  int   mod;

  if (nb / 10 > 0)
    this->drawNb(posX - 20, posY, nb / 10);
  mod = nb % 10;
  // std::cout << mod << std::endl;
  Primitives::Rectangle	rect(posX, posY, 20, 40, this->_listTex[mod]);
  rect.draw();
}
