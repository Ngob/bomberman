//
// IA.hh for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Thu May 26 16:14:15 2011 romain capot
//

#include	"APlayer.hh"

#ifndef		__IA_HH__
# define		__IA_HH__

#include	"Bomb.hh"

class	IA : public APlayer
{
public:
  IA(APlayer::ePlayerType, Map *, int, gdl::GameClock *);
  virtual ~IA();

  virtual void	update(gdl::Input&);

public:
  int		_nb;
  int		_way;

public:
  void		move_up();
  void		move_down();
  void		move_left();
  void		move_right();
  void		drop_bomb();
  void		check_moves();
  int		check_dwall();
  int		check_players();
  int		check_bombs();
  int		check_x(const EType type);
    int		check_y(const EType type);
};

#endif
