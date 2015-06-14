//
// Bomb.hh for  in /home/basset_a//workspace/bomberman-2014-capot_r
//
// Made by antoine basset
// Login   <basset_a@epitech.net>
//
// Started on  Thu May 26 11:15:24 2011 antoine basset
//

#include	"map/map.hh"
#include	"map/AObj.hh"
#include	"map/map.hh"
#include	"map/coord.h"
#include	"ModBomb.hh"
#include	"create_cube.hh"
#include	"PlaySound.hh"

#ifndef		_BOMB_HH_
#define		_BOMB_HH_


class Bomb
{
public:
  typedef enum e_satus
    {
      DISPO,
      INPROGRESS,
      EXPLODE
    }		t_status;

protected:
  int		_x;
  int		_y;
  int		_dam;

  Map		*_map;

  ModBomb	*_mod;

  gdl::Image	_texExp;

  t_status	_state;

  int		_explode;
  int		_nbKill;
  int		_nbWallDestruct;
  PlaySound	*_playSound;
 
  std::vector<struct s_coord>	_kill_coord;

public:

  static int const init_dam = 3;

  Bomb(int, int, int, Map *);
  ~Bomb();

  void		getCoord(int &, int &) const;
  int		getDam() const;
  void		addDam(int i);
  int		getState() const;
  int		getNbKilled() const;
  int		getNbWallDestruct() const;
  void		setCoord(int x, int y);
  bool		isDispo() const;
  void		putBomb(int, int);
  void		update(Map *);
  void		checkExplode(Map *);
  bool		checkObj(Map *, int, int);

  void		draw();

  std::vector<struct s_coord> &	getKilledPos();
  void				setKilledPos(std::vector<struct s_coord> other);
  void				clearKilledPos();

  void		explodeWall(Map *map, int, int);
  void		blocExplosion(Map *map, int, int);
  void		killPerso(Map *map, int, int);
};

typedef struct	explodeColision
{
  EType		wallType;
  void		(Bomb::*ptrFunc)(Map *, int, int);
  bool		isBreak;
}		explodeColision;

#endif		/*_BOMB_HH_*/
