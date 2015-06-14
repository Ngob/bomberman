//
// APlayer.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Thu May 26 11:06:18 2011 romain capot
// Last update Sun Jun  5 14:12:54 2011 benoit ngo
//

#include	"Game.hpp"
#include	"Bomb.hh"
#include	"map/map.hh"
#include	"ModPlayer.hh"
#include	"dir.hh"

#ifndef		__APLAYER_HH__
#define		__APLAYER_HH__

class	APlayer
{
public:
  enum	ePlayerType
    {
      PLAYER1 = 0,
      PLAYER2 = 1,
      IA,
      NONE
    };

protected:
  int		_x;
  int		_y;
  Bomb		*_bomb;
  ePlayerType	_type;
  dir::eDir	_dir;

  Map *		_map;
  bool		_isAlive;
  int		_score;

  ModPlayer	*_mod;

public:
  int		dir;

public:
  APlayer(int, int, ePlayerType, Map *, int);
  virtual ~APlayer();

  virtual void	update(gdl::Input &) = 0;
  virtual void	draw();

  void		setScore(int score);
  int		getScore() const;
  void		addScore(int score);
  int		getX() const;
  int		getY() const;
  int		getMapX() const;
  int		getMapY() const;
  void		setX(int);
  void		setY(int);
  void		setXY(int x, int y);
  ePlayerType	getType() const;
  dir::eDir	getDir() const;
  Bomb		*getBomb() const;
  bool		getAlive() const;
  void		setAlive(bool);
};

#endif
