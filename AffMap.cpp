//
// AffMap.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Tue May 31 09:36:38 2011 romain capot
// Last update Sun Jun  5 17:40:09 2011 antoine basset
//

#include	"AffMap.hh"

affWall		aff[]={
  {WALL, &AffMap::affWall},
  {DWALL, &AffMap::affDWall},
  {EXP, &AffMap::affExplode},
  {EXP, &AffMap::affBomb},
  {WALL, NULL}
};

AffMap::AffMap(Map *map, int blockSize)
  : _map(map), _blockSize(blockSize)
{
  this->_cube = new Cube(this->_blockSize, this->_map->get_sizeX(), this->_map->get_sizeY());
  // load des textures
  this->_texExp = gdl::Image::load("data/textures/textureFeu.png");
  this->_texWall = gdl::Image::load("data/textures/textureMetalWInd.png");
  this->_texDWall = gdl::Image::load("data/textures/texturePlancheWDes.png");
  this->_reload = true;
}

AffMap::~AffMap()
{
}

void		AffMap::checkAff()
{
  Obj		*curObj;

  for (int y = 0; y < this->_map->get_sizeY(); ++y)
    {
      for (int x = 0; x < this->_map->get_sizeX(); ++x)
	{
	  curObj = this->_map->getObj(x, y);
	    for (int i = 0; aff[i].ptrFunc; ++i)
	      {
		if (curObj->get_type() == aff[i].typeWall)
		  {
		    (this->*aff[i].ptrFunc)(x, y);
		    break ;
		  }
	      }
	}
    }
  this->_reload = false;
}

void		AffMap::affWall(int x, int y)
{
  if (this->_reload == false)
    this->_cube->draw(x, y, _texWall);
}

void		AffMap::affDWall(int x, int y)
{
  this->_cube->draw(x, y, this->_texDWall);
}

void		AffMap::affBomb(int x, int y)
{
  this->_cube->draw(x, y, this->_texExp);
}

void		AffMap::affExplode(int x, int y)
{
  this->_cube->draw(x, y, this->_texExp);
  this->_map->setObj(x, y, EMPTY);
}

