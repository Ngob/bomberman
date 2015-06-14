//
// CheckQuit.cpp for  in /home/benham_a//Desktop/rendu/bomberman/bomberman-2014-capot_r
// 
// Made by camille benhamou
// Login   <benham_a@epitech.net>
// 
// Started on  Thu Jun  2 14:51:08 2011 camille benhamou
// Last update Sun Jun  5 17:48:17 2011 camille benhamou
//

#include	"CheckQuit.hh"

CheckQuit::CheckQuit(int nbPlayer, std::list<APlayer *> * players)
  : players(players)
{
  checkPlayerAlive(nbPlayer);
  this->winPlayer = CheckQuit::NONE;
}

CheckQuit::~CheckQuit()
{

}

bool		CheckQuit::checkOnePlayer()
{
  this->foundIA = 0;
  this->foundPlayer1 = 0;
  this->foundPlayer2 = 0;

  for (std::list<APlayer *>::iterator it = this->players->begin(); it != this->players->end(); ++it)
    {
      if ((*it)->APlayer::getType() == (*it)->APlayer::IA && (*it)->APlayer::getAlive() == true)
	this->foundIA = 1;
      else if ((*it)->APlayer::getType() == (*it)->APlayer::PLAYER1 && (*it)->APlayer::getAlive() == true)
	this->foundPlayer1 = 1;
    }
  if (playerOneWin() || IAWin() || twoPlayerDead())
    return (true);
  else
    return (false);
}

bool		CheckQuit::checkTwoPlayer()
{
  this->foundIA = 0;
  this->foundPlayer1 = 0;
  this->foundPlayer2 = 0;

  for (std::list<APlayer *>::iterator it = this->players->begin(); it != this->players->end(); ++it)
    {
      if ((*it)->APlayer::getAlive() == true)
	{
	  if ((*it)->APlayer::getType() == (*it)->APlayer::IA)
	    this->foundIA = 1;
	  else if ((*it)->APlayer::getType() == (*it)->APlayer::PLAYER1)
	    this->foundPlayer1 = 1;
	  else
	    this->foundPlayer2 = 1;
	}
    }
  if (playerOneWin() || playerTwoWin() || IAWin() || twoPlayerDead())
    return (true);
  else
    return (false);
}

bool		CheckQuit::playerOneWin()
{
  if (this->foundIA == 0 && this->foundPlayer2 == 0 && this->foundPlayer1 == 1)
    {
      this->winPlayer = CheckQuit::PLAYER1 ;
      return (true);
    }
  else
    return (false);
}

bool		CheckQuit::playerTwoWin()
{
  if (this->foundIA == 0 && this->foundPlayer2 == 1 && this->foundPlayer1 == 0)
    {
      this->winPlayer = CheckQuit::PLAYER2;
      return (true);
    }
  else
    return (false);
}

bool		CheckQuit::IAWin()
{
  if (this->foundIA == 1 && this->foundPlayer2 == 0 && this->foundPlayer1 == 0)
    {
      this->winPlayer = CheckQuit::IA;
      return (true);
    }
  else
    return (false);
}

bool		CheckQuit::twoPlayerDead()
{
  if (this->foundIA == 0 && this->foundPlayer2 == 0 && this->foundPlayer1 == 0)
    {
      this->winPlayer = CheckQuit::EQUALITY;
      return (true);
    }
  else
    return (false);
}

bool	       CheckQuit::checkPlayerAlive(int nbPlayer)
{
  if (nbPlayer == 1)
    return (checkOnePlayer());
  else
    return (checkTwoPlayer());
}

CheckQuit::eWinPlayer	CheckQuit::getWinner() const
{
  return (this->winPlayer);
}
