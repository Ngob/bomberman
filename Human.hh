//
// Human.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Thu May 26 11:15:20 2011 romain capot
// Last update Sun Jun  5 11:22:42 2011 antoine basset
//

#include	"APlayer.hh"

#ifndef		__HUMAN_HH__
#define		__HUMAN_HH__

class	Human : public APlayer
{
public:
  Human(APlayer::ePlayerType, Map *, int, gdl::GameClock *);
  virtual ~Human();

  virtual void	update(gdl::Input &);

  void		moveTop(void);
  void		moveBot(void);
  void		moveLeft(void);
  void		moveRight(void);
  void		putBomb(void);
  //  void		saveCurGame(void);
};

typedef	struct	control
{
  APlayer::ePlayerType	type;
  gdl::Keys::Key        key;
  void		(Human::*ptr)(void);
}		t_control;

#endif
