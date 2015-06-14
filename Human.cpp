//
// Human.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Thu May 26 11:15:12 2011 romain capot
// Last update Sun Jun  5 17:56:52 2011 camille benhamou
//

#include	"Human.hh"

t_control	ctrl[]={
  {APlayer::PLAYER1, gdl::Keys::Up, &Human::moveTop},
  {APlayer::PLAYER1, gdl::Keys::Down, &Human::moveBot},
  {APlayer::PLAYER1, gdl::Keys::Left, &Human::moveLeft},
  {APlayer::PLAYER1, gdl::Keys::Right, &Human::moveRight},
  {APlayer::PLAYER1, gdl::Keys::RControl, &Human::putBomb},
  {APlayer::PLAYER2, gdl::Keys::W, &Human::moveTop},
  {APlayer::PLAYER2, gdl::Keys::S, &Human::moveBot},
  {APlayer::PLAYER2, gdl::Keys::A, &Human::moveLeft},
  {APlayer::PLAYER2, gdl::Keys::D, &Human::moveRight},
  {APlayer::PLAYER2, gdl::Keys::Space, &Human::putBomb},
  {APlayer::NONE, gdl::Keys::Q, NULL}
};

Human::Human(APlayer::ePlayerType type, Map * map, int blockSize, gdl::GameClock * clock)
  : APlayer(0, 0, type, map, blockSize, clock)
{
}

Human::~Human()
{
}

void	Human::update(gdl::Input & in)
{
  this->_mod->stopAnim();
  for (int i = 0; ctrl[i].type != APlayer::NONE; ++i)
    {
      if (in.isKeyDown(ctrl[i].key) && this->_type == ctrl[i].type)
	{
	  this->_mod->playAnim();
	  (this->*(ctrl[i].ptr))();
	}
    }
  this->_mod->update();
  this->_bomb->update(_map);
}

void		Human::moveTop(void)
{
 Obj		* curObj;

 if (_y - 1 < 0)
   return ;
 curObj = this->_map->getObj(this->_x, this->_y - 1);
 if (curObj->get_type() == EMPTY || curObj->get_type() == PERSO)
   {
     if (this->_map->getObj(this->_x, this->_y)->get_type() == PERSO)
      this->_map->setObj(this->_x, this->_y, EMPTY);
     this->_y -= 1;
     curObj->setType(PERSO);
   }
 this->_dir = dir::BACK;
}

void		Human::moveBot(void)
{
  Obj		* curObj;

  if (this->_y + 2 > this->_map->get_sizeY())
   return ;
  curObj = this->_map->getObj(this->_x, this->_y + 1);
  if (curObj->get_type() == EMPTY || curObj->get_type() == PERSO)
    {
     if (this->_map->getObj(this->_x, this->_y)->get_type() == PERSO)
      this->_map->setObj(this->_x, this->_y, EMPTY);
    this->_y += 1;
      curObj->setType(PERSO);
    }
  this->_dir = dir::FRONT;
}

void		Human::moveLeft(void)
{
  Obj		* curObj;

  if (this->_x - 1 < 0)
    return ;
  curObj = this->_map->getObj(this->_x - 1, this->_y);
  if (curObj->get_type() == EMPTY || curObj->get_type() == PERSO)
    {
      if (this->_map->getObj(this->_x, this->_y)->get_type() == PERSO)
	this->_map->setObj(this->_x, this->_y, EMPTY);
      this->_x -= 1;
      curObj->setType(PERSO);
    }
  _dir = dir::LEFT;
}

void		Human::moveRight(void)
{
  Obj		* curObj;

  if (this->_x + 2 > this->_map->get_sizeX())
   return ;
  curObj = this->_map->getObj(this->_x + 1, this->_y);
  if (curObj->get_type() == EMPTY || curObj->get_type() == PERSO)
    {
      if (this->_map->getObj(this->_x, this->_y)->get_type() == PERSO)
	this->_map->setObj(this->_x, this->_y, EMPTY);
     this->_x += 1;
      curObj->setType(PERSO);
    }
  this->_dir = dir::RIGHT;
}

void		Human::putBomb(void)
{

  if (this->_bomb->isDispo())
    this->_bomb->putBomb(this->_x, this->_y);
}
