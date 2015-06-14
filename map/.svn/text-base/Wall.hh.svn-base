//
// Wall.hh for  in /u/all/ngo_b/cu/rendu/projetTek2/cpp/bomber/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 11 22:29:50 2011 benoit ngo
// Last update Tue May 31 17:07:12 2011 benoit ngo
//

#ifndef		__WALL_H__
# define	__WALL_H__

# include	"AObj.hh"
# include	<string>

class		Wall : public Obj
{
  bool		_dest; // mur destructible ou pas
  int		_id;
  EType		getType(const bool);
  //rajouter une variable pr le bonus si dest
public:
  Wall(const int, const int, const bool);
  ~Wall();
  void		setdest(const bool);
  bool		is_dest() const;
};

#endif		/*__WALL_H__*/
