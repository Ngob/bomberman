//
// AllWall.hh for  in /u/all/ngo_b/cu/rendu/projetTek2/cpp/bomber/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Fri May 13 20:44:13 2011 benoit ngo
// Last update Sun Jun  5 18:02:25 2011 benoit ngo
//
#ifndef		__ALL_WALL_H__
# define	__ALL_WALL_H__
# include	"empty.hh"
# include	"Wall.hh"
# include	"lineWall.hh"
# include	"coord.h"
# include	<map>
# include	<stack>

class				AllWall
{
private:

  std::map<int, lineWall>	_wall;

  int				_max_x;
  int				_max_y;

  void				build_dest();
  bool				false_in_range(const int, const int);
  s_coord	       		get_first_pos();

public:
  AllWall();

  //void				addWall(const int, const int);

  void				set_sizeX(const int);
  void				set_sizeY(const int);
  int				get_sizeX() const;
  int				get_sizeY() const;
  void				parseFile(std::string const &);
  int				add_object(Obj *, const int, const int);
  void				build_random(const int, const int);
  Obj *				getWall(const int, const int);
  ~AllWall();
  AllWall &			operator=(AllWall const &);
  Obj *				find_the_type(char c, int x, int y);
  Obj *				alloc_wall(const int, const int);
  Obj *				alloc_dwall(const int, const int);
  Obj *				alloc_empty(const int, const int);
  void				deleteWall(const int, const int);
};

#include	"choose_wall.hh"


#endif		/*__ALL_WALL_H__*/
