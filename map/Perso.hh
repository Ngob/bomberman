//
// Perso.hh for peros in /u/all/ngo_b/cu/rendu/projetTek2/cpp/bomber/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 11 22:28:34 2011 benoit ngo
// Last update Wed May 11 22:56:11 2011 benoit ngo
//

#ifndef		__PERSO_HH__
# define	__PERSO_HH__

# include	"AObj.hh"

class		Perso : public Obj
{
  int			_ex_x;
  int			_ex_y;
  const bool		_ia;
  bool			_bomb;
public:
  Perso(const int, const int, const bool);
  void			move_right();
  void			move_left();
  void			move_up();
  void			move_down();
  void			move_back();
  bool			could_bomb() const;
  void			set_bomb(const bool bomb);
  bool			is_computer() const;
  ~Perso();
};


#endif		/*__PERSO_HH__*/
