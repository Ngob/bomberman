//
// AffPlayer.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Wed Jun  1 11:16:05 2011 romain capot
// Last update Wed Jun  1 11:58:09 2011 romain capot
//

#include	<iostream>
#include	<list>
#include	"APlayer.hh"
#include	"ModPlayer.hh"

#ifndef		__AFFPLAYER_HH__
#define		__AFFPLAYER_HH__

class	AffPlayer
{
protected:
  std::list<APlayer *>	*_playersList;

public:
  AffPlayer(std::list<APlayer *> *);
  ~AffPlayer();

  void	draw(void);
};

#endif
