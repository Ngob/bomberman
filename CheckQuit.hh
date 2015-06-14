//
// CheckQuit.hh for  in /home/benham_a//Desktop/rendu/bomberman/bomberman-2014-capot_r
// 
// Made by camille benhamou
// Login   <benham_a@epitech.net>
// 
// Started on  Thu Jun  2 14:51:21 2011 camille benhamou
// Last update Sun Jun  5 17:08:24 2011 romain capot
//

#ifndef		__CHECKQUIT_HH__
#define		__CHECKQUIT_HH__

#include	<iostream>
#include	<list>
#include	"APlayer.hh"

class CheckQuit
{
public:
  enum	eWinPlayer
    {
      PLAYER1,
      PLAYER2,
      IA,
      EQUALITY,
      NONE
    };

protected:
  std::list<APlayer *> * players;
  int	foundIA;
  int	foundPlayer1;
  int	foundPlayer2;
  eWinPlayer winPlayer;

public:
  CheckQuit(int, std::list<APlayer *> *);
  ~CheckQuit();

  bool	checkPlayerAlive(int nbPlayer);
  bool  checkOnePlayer();
  bool	checkTwoPlayer();
  bool		playerOneWin();
  bool		playerTwoWin();
  bool		IAWin();
  bool		twoPlayerDead();
  eWinPlayer	getWinner() const;
};

#endif
