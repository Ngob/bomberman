//
// mod.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Tue May 24 09:44:02 2011 romain capot
// Last update Sun Jun  5 16:54:37 2011 romain capot
//

#include	<iostream>
#include	"Game.hpp"
#include	"Model.hpp"
#include	"dir.hh"

#ifndef		__MODPLAYER_HH__
#define		__MODPLAYER_HH__

class ModPlayer
{
private:
  int		_mapX;
  int		_mapY;
  int		_cubeSize;

  gdl::Model	model_;
  gdl::GameClock * clock_;

public:
  ModPlayer(int, int, int, gdl::GameClock *);

  void initialize(void);
  void update();
  void draw(int, int, dir::eDir);

  void	setDir(dir::eDir);
  void	setPos(int, int);

  void setColor(const int, const int,
		const int, const int a = 250);

  void		playAnim();
  void		stopAnim();
};

typedef struct	dirChoose
{
  dir::eDir	dirType;
  float		rot;
}		dirChoose;

#endif
