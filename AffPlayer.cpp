//
// AffPlayer.cpp for ] in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Wed Jun  1 11:15:38 2011 romain capot
// Last update Sun Jun  5 17:42:48 2011 antoine basset
//

#include	"AffPlayer.hh"

AffPlayer::AffPlayer(std::list<APlayer *> * list)
  : _playersList(list)
{
}

AffPlayer::~AffPlayer()
{
}

void	AffPlayer::draw()
{
  for (std::list<APlayer *>::iterator it = this->_playersList->begin(); it != this->_playersList->end(); ++it)
    {
      if ((*it)->getAlive() == true)
	(*it)->draw();
    }
}

