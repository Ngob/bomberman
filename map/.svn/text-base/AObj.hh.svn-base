//
// ICoord.hh for  in /u/all/ngo_b/cu/rendu/projetTek2/cpp/bomber/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 11 21:27:16 2011 benoit ngo
// Last update Wed Jun  1 16:09:44 2011 romain capot
//

#ifndef		__OBJ_HH__
# define	__OBJ_HH__

# include	<string>

// enum des type des objets dans la carte
enum		EType
  {
    WALL = 0,
    DWALL = 1,
    EMPTY = 2,
    PERSO = 3,
    BOMB = 4,
    EXP = 5,
  };

// ce que contient tout les objets present dans la map

class		Obj
{
protected:
  int			_x; // pos
  int			_y;
  EType			_type; // type de lobjet
  bool			_maze;
public:
  Obj(const int, const int,  const EType);
  ~Obj();

  bool			getMaze() const;
  int			get_x() const;
  int			get_y() const;
  void			setMaze(const bool);
  void			set_x(const int);
  void			set_y(const int);
  bool			operator==(const Obj &) const;
  EType			get_type() const;
  void			setType(EType type);
};

#endif		/*__OBJ_HH__*/
