//
// Bomb.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Wed Jun  1 15:12:12 2011 romain capot
// Last update Sun Jun  5 17:49:00 2011 antoine basset
//

#include	"Bomb.hh"

explodeColision	coli[] = {
   {WALL, &Bomb::explodeWall, true},
   {DWALL, &Bomb::blocExplosion, true},
   {PERSO, &Bomb::killPerso, false},
   {WALL, NULL, false},
};

Bomb::Bomb(int mapX, int mapY, int blockSize, Map *map)
  : _x(0), _y(0), _dam(init_dam), _map(map), _state(Bomb::DISPO), _explode(0), _nbKill(0), _nbWallDestruct(0)
{
  this->_mod = new ModBomb(mapX, mapY, blockSize);
  this->_playSound = new PlaySound();
}

Bomb::~Bomb()
{
  delete this->_mod;
  delete this->_playSound;
}

void		Bomb::getCoord(int & x, int & y) const
{
  x = this->_x;
  y = this->_y;
}

void		Bomb::setCoord(int x, int y)
{
  this->_x = x;
  this->_y = y;
}

void		Bomb::addDam(int i)
{
  this->_dam += i;
}

int		Bomb::getNbKilled() const
{
  return this->_nbKill;
}

int		Bomb::getNbWallDestruct() const
{
  return this->_nbWallDestruct;
}

std::vector<struct s_coord> &	Bomb::getKilledPos()
{
  return this->_kill_coord;
}

void				Bomb::setKilledPos(std::vector<struct s_coord> other)
{
  this->_kill_coord = other;
}

void				Bomb::clearKilledPos()
{
  this->_kill_coord.clear();
}

int		Bomb::getDam() const
{
  return this->_dam;
}

int		Bomb::getState() const
{
  return this->_state;
}

bool		Bomb::isDispo() const
{
  if (this->_state == Bomb::DISPO)
    return true;
  else
    return false;
}

void		Bomb::draw()
{
  if (this->_state == Bomb::INPROGRESS)
    this->_mod->draw(this->_x, this->_y);
}

void		Bomb::putBomb(int x, int y)
{
  this->_x = x;
  this->_y = y;
  this->_state = Bomb::INPROGRESS;
  this->_explode = 20;
}

void		Bomb::checkExplode(Map * map)
{
  int		caseX = this->_x;
  int		caseY = this->_y;


  this->_playSound->playSounds("data/sounds/bombExplosion.wav");
  // Colision avec les murs
  // explosion ON
  this->checkObj(map, caseX, caseY);
  // explosion BOT
  for (int i = 0; i < this->_dam; ++i)
    {
      if (caseY + i > map->get_sizeY() - 1)
	break ;
      if (this->checkObj(map, caseX, caseY + i))
	break ;
    }
  // explosion TOP
  for (int i = 0; i < this->_dam; ++i)
    {
      if (caseY - i < 0)
	break ;
      if (checkObj(map, caseX, caseY - i))
	break ;
    }
  // explosion LEFT
  for (int i = 0; i < this->_dam; ++i)
    {
      if (caseX - i < 0)
	break ;
      if (checkObj(map, caseX - i, caseY))
	break ;
    }
  // explosion RIGHT
  for (int i = 0; i < this->_dam; ++i)
    {
      if (caseX + i > map->get_sizeX() - 1)
	break ;
      if (checkObj(map, caseX + i, caseY))
	break ;
    }
}

void		Bomb::update(Map * map)
{
  Obj		*curObj;

  this->clearKilledPos();
  this->_nbKill = 0;
  this->_nbWallDestruct = 0;
  if (this->_state == Bomb::EXPLODE)
    this->_state = Bomb::DISPO;
  if (this->_explode > 0)
    {
      curObj = this->_map->getObj(this->_x, this->_y);
      if (curObj->get_type() == EMPTY)
	curObj->setType(BOMB);
      --this->_explode;
      if (this->_explode == 0)
	this->_state = Bomb::EXPLODE;
    }
  if (this->_state == Bomb::EXPLODE)
    this->checkExplode(map);
}


// Explode colisions

bool		Bomb::checkObj(Map * map, int x, int y)
{
  Obj		*curObj;

  curObj = map->getObj(x, y);
  for (int i = 0; coli[i].ptrFunc; ++i)
    {
      if (coli[i].wallType == curObj->get_type())
	{
	  (this->*coli[i].ptrFunc)(map, x, y);
	  if (coli[i].isBreak == true)
	    return true;
	}
    }
  curObj->setType(EXP);
  return false;
}

void		Bomb::explodeWall(Map *map, int x, int y)
{
  (void)map;
  (void)x;
  (void)y;
}

void		Bomb::killPerso(Map *map, int x, int y)
{
  s_coord	coord;

  this->_nbKill += 1;
  coord.x = x;
  coord.y = y;
  (void)map;
   this->_kill_coord.push_back(coord);
}

void		Bomb::blocExplosion(Map *map, int x, int y)
{
  Obj           *curObj;

  curObj = map->getObj(x, y);
  curObj->setType(EXP);
  this->_nbWallDestruct += 1;
}
