//
// Play.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Tue May 24 09:51:29 2011 romain capot
// Last update Sun Jun  5 14:40:24 2011 benoit ngo
//

#include	<iostream>
#include	<list>
#include	"APlay.hh"
#include	"APlayer.hh"
#include	"Human.hh"
#include	"IA.hh"
#include	"Primitives.hh"
#include	"ModPlayer.hh"
#include	"Plate.hh"
#include	"Camera.hh"
#include	"create_cube.hh"
#include	"map/map.hh"
#include	"AffMap.hh"
#include	"AffPlayer.hh"
#include	"CheckBomb.hh"
#include	"CheckQuit.hh"
#include	"Score.hh"
#include	"HighScores.hh"

#ifndef		__PLAY_HH__
#define		__PLAY_HH__

class Play : public APlay
{
protected:
  int		_nbPlayers;
  int		_nbIA;

  Map		*_map;


  CameraGame	_camGame;

  AffMap	*_aff;
  AffPlayer	*_affPlayer;
  Plate		*_plate;

  std::list<APlayer *>	_players;

  gdl::Image	_texClear;

  CheckBomb	*_check;
  CheckQuit	*_checkQuit;
  Score		*_score;
  // static vars

public:
  /*a deplacer ??*/
  static int const addKillScore = 150;
  static int const addBlocDestruct = 20;
  static int const addDamage = 50;
  static int const blockSize = 20;

public:
  Play(int, gdl::Window *, gdl::GameClock *, gdl::Input *, std::string const &, int mapSize = 20, int nbIA = 0);
  Play(gdl::Window *, gdl::GameClock *, gdl::Input *, const int);
  ~Play();

  void		runGame();
  void		initPos();

  virtual void initialize(void);
  virtual void update(void);
  virtual void draw(void);
};

#endif
