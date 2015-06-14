//
// lineWall.hh for  in /home/ngo_b//rendu/proj/bomberman-2014-capot_r/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 25 20:34:10 2011 benoit ngo
// Last update Tue May 31 03:05:03 2011 benoit ngo
//

#ifndef		__LINE_WALL_HH__
# define	__LINE_WALL_HH__

# include	"Wall.hh"
# include	<map>

class		lineWall
{
  std::map<int, Obj *>	line;
  int		y;

public:
  lineWall();
  ~lineWall();
  static int	id;


  void		setWall(const int, Obj * const);
  void		deleteWall(const int);
  bool		isEmpty() const;
  Obj *		getWall(const int);
  void		init(const int, const int, const int);
};

#endif		/*__LINE_WALL_HH__*/
