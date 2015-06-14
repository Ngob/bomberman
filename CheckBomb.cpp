//
// CheckBomb.cpp for  in /home/basset_a//workspace/bomberman-2014-capot_r
//
// Made by antoine basset
// Login   <basset_a@epitech.net>
//
// Started on  Wed Jun  1 11:09:27 2011 antoine basset
// Last update Sun Jun  5 17:42:55 2011 camille benhamou
//

#include	"CheckBomb.hh"

CheckBomb::CheckBomb(std::list<APlayer *> *player)
  : _players(player)
{
  this->_playSound = new PlaySound();
}

CheckBomb::~CheckBomb(){}

void		CheckBomb::update()
{
  for (std::list<APlayer *>::iterator it = this->_players->begin(); it != this->_players->end(); ++it)
    {
      Bomb	*bomb = (*it)->getBomb();
      std::vector<struct s_coord> coord = bomb->getKilledPos();
      std::vector<struct s_coord>::iterator bo = coord.begin();
      while (bo != coord.end())
	{
	  for (std::list<APlayer *>::iterator at = this->_players->begin(); at != this->_players->end(); ++at)
	    {
	      int a = (*at)->getX();
	      int b = (*at)->getY();
	      if (bo->x == a && bo->y == b)
		{
		  this->_playSound->playSounds("data/sounds/Nelson.wav");
		  (*at)->setAlive(false);
		}
	    }
	  ++bo;
	}
      bomb->clearKilledPos();
    }
}
