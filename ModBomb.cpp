//
// ModBomb.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Wed Jun  1 14:20:47 2011 romain capot
// Last update Sun Jun  5 18:08:03 2011 camille benhamou
//

#include	"ModBomb.hh"

ModBomb::ModBomb(int mapX, int mapY, int cubeSize)
  : _mapX(mapX), _mapY(mapY), _cubeSize(cubeSize)
{
  this->model_ = gdl::Model::load("data/models/bomb.fbx");
}

void ModBomb::initialize()
{
}

void ModBomb::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void)gameClock;
  (void)input;
}

void ModBomb::draw(int blockX, int blockY)
{
  glPushMatrix();
  gdl::Model::Begin();
  this->setPos(blockX, blockY);
  glScalef(0.07, 0.07, 0.07);
  this->model_.draw();
  gdl::Model::End();
  glPopMatrix();
}

void	ModBomb::setPos(int blockX, int blockY)
{
  int	x, y;

  x = (this->_mapX * -1 * (this->_cubeSize / 2)) + 10;
  y = (this->_mapY * -1 * (this->_cubeSize / 2)) + 10;

  x += (blockX * this->_cubeSize);
  y += (blockY * this->_cubeSize);
  glTranslatef(x, 0, y);
}
