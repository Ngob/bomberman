//
// Iplay.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Tue May 24 10:05:58 2011 romain capot
// Last update Sun Jun  5 13:27:54 2011 antoine basset
//

#include	"Game.hpp"

#ifndef		__APLAY_HH__
#define		__APLAY_HH__

class APlay
{
protected:
  bool			_exit;

  gdl::Window		* _win;
  gdl::GameClock	* _clock;
  gdl::Input		* _in;

public:
  APlay(gdl::Window *, gdl::GameClock *, gdl::Input *);
  virtual ~APlay();

  virtual void initialize(void) = 0;
  virtual void update(void) = 0;
  virtual void draw(void) = 0;
};

#endif
