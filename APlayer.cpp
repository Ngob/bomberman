//
// APlayer.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Thu May 26 11:06:01 2011 romain capot
// Last update Sun Jun  5 17:46:36 2011 antoine basset
//

#include	"APlayer.hh"

APlayer::APlayer(int x, int y, APlayer::ePlayerType type, Map * map, int blockSize, gdl::GameClock * clock)
  : _x(x), _y(y), _type(type), _dir(dir::FRONT), _map(map), _isAlive(true), _score(0), clock_(clock)
{
  this->_mod = new ModPlayer(this->_map->get_sizeX(), this->_map->get_sizeY(), blockSize, this->clock_);
  if (type == PLAYER1)
    this->_mod->setColor(142, 42, 42);
  else if (type == PLAYER2)
    this->_mod->setColor(42, 142, 142);
  else
    this->_mod->setColor(0, 0, 0);
  this->_bomb = new Bomb(map->get_sizeX(), map->get_sizeY(), blockSize, map);
}

APlayer::~APlayer()
{
  delete this->_bomb;
}

void		APlayer::setScore(int score)
{
  this->_score = score;
}

int		APlayer::getScore() const
{
  return this->_score;
}

void		APlayer::addScore(int score)
{
  this->_score += score;
}

void		APlayer::setXY(int newx, int newy)
{
  this->_x = newx;
  this->_y = newy;
}

int		APlayer::getX() const
{
  return this->_x;
}

int		APlayer::getY() const
{
  return this->_y;
}

int		APlayer::getMapX() const
{
  return this->_map->get_sizeX();
}

int		APlayer::getMapY() const
{
  return this->_map->get_sizeY();
}

APlayer::ePlayerType	APlayer::getType() const
{
  return this->_type;
}

dir::eDir	APlayer::getDir() const
{
  return this->_dir;
}

void		APlayer::setX(int x)
{
  this->_x = x;
}

void		APlayer::setY(int y)
{
  this->_y = y;
}

Bomb *		APlayer::getBomb() const
{
  return this->_bomb;
}

bool		APlayer::getAlive() const
{
  return this->_isAlive;
}

void		APlayer::setAlive(bool status)
{
  this->_isAlive = status;
}

void		APlayer::draw()
{
  this->_mod->draw(this->_x, this->_y, this->_dir);
  this->_bomb->draw();
}
