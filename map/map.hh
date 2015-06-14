//
// map.hh for map in /u/all/ngo_b/cu/rendu/projetTek2/cpp/bomber/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 11 20:39:02 2011 benoit ngo
// Last update Sun Jun  5 17:47:01 2011 benoit ngo
//
#ifndef		__MAP_HH__
# define	__MAP_HH__

class Map;
#include		"../APlayer.hh"

#include		<iostream>
#include	<vector>
#include	<fstream>
#include	<sstream>
#include	<iostream>
#include	<string>
#include	<vector>
#include	<list>
#include	"AObj.hh"
#include	"lineWall.hh"
#include	"AllWall.hh"

// class CheckBomb;
// class CheckQuit;
// class Score;



// je me suis permis de deplacer tes methode dans AllWall.cpp

class			Map
{
  int			_size_x;
  int			_size_y;
  int			_nb_players;
  AllWall      		_wall;
  std::vector<s_coord>	_res_p;
  bool			check_empty(const EType);
  void			get_map_size(std::ifstream &);
  int			_nbIa;

public:

  Map();
  Map(const std::string & n);
  Map(const int, const int);
  // si le n = "" alors on buld random,
  //sinon on build avec le nom du fichier
  ~Map();
  bool		DiagIsFree(const int, const int);
    bool		lineIsFree(const int, const int, int, const int, const bool);

  void		       	setObj(const int, const int, const EType);
  void				findPlayerPos(int & x, int & y);
  void				addPlayer(int & x, int & y);
  bool				CanBePlaced(int i, int j);

  void			deleteObj(const int, const int);
  void			setObj(Obj *, const int, const int);
  Obj *			getObj(const int, const int);
  int			get_sizeX() const;
  int			get_sizeY() const;
  int			getNbPlayers() const;
  int			getNbIa() const;

  void			setAllWall(AllWall const & other);
  void			getCoord(int & x, int & y) const;
  AllWall		getAllWall() const;

  std::list<APlayer *> * load_map(const std::string &, gdl::GameClock *);
  Map &		operator=(Map const & other);

};




#endif		/*__MAP_HH__*/
