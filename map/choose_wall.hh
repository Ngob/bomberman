//
// choose_wall.hh for  in /home/ngo_b//rendu/proj/bomberman-2014-capot_r/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Tue May 31 02:17:57 2011 benoit ngo
// Last update Tue May 31 11:41:39 2011 romain capot
//

#ifndef		__CHOSE_WALL_HH__
# define	__CHOSE_WALL_HH__

typedef struct	s_choose_wall
{
  EType	type;
  Obj		*(AllWall::*ptr)(int i, int j);
}			t_choose_wall;

#endif		/*__CHOSE_WALL_HH__*/
