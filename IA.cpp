//
// IA.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Thu May 26 16:14:06 2011 romain capot
// Last update Sun Jun  5 17:28:44 2011 inan asan
//

#include	"IA.hh"
#include	"map/AObj.hh"
#include	<cstdlib>

IA::IA(APlayer::ePlayerType type, Map * map, int blockSize, gdl::GameClock * clock)
  : APlayer(0, 0, type, map, blockSize, clock)
{
  this->dir = 0;
  this->_nb = 0;
}

IA::~IA()
{
}

int		IA::check_x(const EType type)
{
  int		j;
  Obj*		x1;
  int		distance;


  (type == PERSO ? j = 1 : j = 0);
  if (type == DWALL || type == PERSO)
    distance = 2;
  else
    distance = 5;
  while (j != distance)
    {
      if (this->getX()-j >= 0)
	x1 = this->_map->getObj(this->getX()-j, this->getY());
      if ((x1 != NULL))
	{
	  if (x1->get_type() == type)
	    {
	      if (type == PERSO || type == DWALL)
		this->drop_bomb();
	      if (x1->get_type() == WALL)
		j = distance;
	      return (1);
	    }
	}
      j++;
     }
  (type == PERSO ? j = 1 : j = 0);
  while (j != distance)
    {
      if (this->getX()+j <= (this->_map->get_sizeX()-1))
	x1 = this->_map->getObj(this->getX()+j, this->getY());
      if ((x1 != NULL))
	{
	  if (x1->get_type() == type)
	    {
	      if (type == PERSO || type == DWALL)
		this->drop_bomb();
	      if (x1->get_type() == WALL)
		j = distance;
	      return (1);
	    }
	}
      j++;
     }
  return 0;
}

int		IA::check_y(const EType type)
{
  int		i;
  Obj		*x1;
  int		distance;

  (type == PERSO ? i = 1 : i = 0);
  if (type == DWALL || type == PERSO)
    distance = 2;
  else
    distance = 5;
  while (i != distance)
    {
      if (this->getY()-i >= 0)
	x1 = this->_map->getObj(this->getX(), this->getY()-i);
      if ((x1 != NULL))
	{
	  if (x1->get_type() == type)
	    {
	      if (type == PERSO || type == DWALL)
	      this->drop_bomb();
	      if (x1->get_type() == WALL)
		i = distance;
	      return (1);
	    }
	}
      i++;
    }
  (type == PERSO ? i = 1 : i = 0);
  while (i != distance)
    {
      if (this->getY()+i <= (this->_map->get_sizeY()-1))
	x1 = this->_map->getObj(this->getX(), this->getY()+i);
      if ((x1!= NULL))
	if (x1->get_type() == type)
	  {
	    if (type == PERSO || type == DWALL)
	      this->drop_bomb();
	    if (x1->get_type() == WALL)
	      i = distance;
	    return (1);
	  }
      i++;
    }
  return 0;
}

void		IA::drop_bomb()
{
  Obj*	bomb;

  if (this->_bomb->getState() == Bomb::DISPO)
    {
      bomb = this->_map->getObj(this->getX(), this->getY());
      this->_bomb->putBomb(this->getX(), this->getY());
      this->check_moves();
      bomb->setType(BOMB);
    }
}

void		IA::move_up()
{
  Obj* tmp;
  Obj	*x1;

  if (this->getY()-1 >= 0)
    x1 = this->_map->getObj(this->getX(), this->getY()-1);
  if (x1->get_type() == EMPTY)
    {
      x1->setType(PERSO);
      tmp = this->_map->getObj(this->getX(), this->getY());
      tmp->setType(EMPTY);
      this->setXY(x1->get_x(), x1->get_y());
      this->_dir = dir::BACK;
    }
}

void		IA::move_left()
{
  Obj* tmp;
  Obj	*x1;

  if (this->getX()-1 >= 0)
    x1 = this->_map->getObj(this->getX()-1, this->getY());
  if (x1->get_type() == EMPTY)
    {
      x1->setType(PERSO);
      tmp = this->_map->getObj(this->getX(), this->getY());
      tmp->setType(EMPTY);
      this->setXY(x1->get_x(), x1->get_y());
      this->_dir = dir::LEFT;
    }
  else
    this->_way = 2;
}

void		IA::move_right()
{
  Obj* tmp;
  Obj	*x1;

  if (this->getX()+1 <= (this->_map->get_sizeX()-1))
    x1 = this->_map->getObj(this->getX()+1, this->getY());
  if ((x1->get_type() == EMPTY))
    {
      x1->setType(PERSO);
      tmp = this->_map->getObj(this->getX(), this->getY());
      tmp->setType(EMPTY);
      this->setXY(x1->get_x(), x1->get_y());
      this->_dir = dir::RIGHT;
    }
  else
    this->_way = 1;
}

void		IA::move_down()
{
  Obj* tmp;
  Obj	*x1;

  if (this->getY()+1 <= (this->_map->get_sizeY()-1))
    x1 = this->_map->getObj(this->getX(), this->getY()+1);
  if (x1->get_type() == EMPTY)
    {
      x1->setType(PERSO);
      tmp = this->_map->getObj(this->getX(), this->getY());
      tmp->setType(EMPTY);
      this->setXY(x1->get_x(), x1->get_y());
      this->_dir = dir::FRONT;
    }
  else
    this->_way = 3;
  
}

void		IA::check_moves()
{
  this->_way = rand()%4;

  (this->_way == 0 ? this->move_right() :
   (this->_way == 1 ? this->move_left() :
    (this->_way == 2 ? this->move_down() :
     (this->_way == 3 ? this->move_up() : this->check_moves()))));
}

int		IA::check_dwall()
{
  if ((this->check_x(DWALL) == 1)
      || (this->check_y(DWALL) == 1))
    return (1);
  return (0);
}

int		IA::check_players()
{
  if ((this->check_x(PERSO) == 1)
      || (this->check_y(PERSO) == 1))
    {
      this->check_moves();
      return (1);
    }
  return (0);
}

int		IA::check_bombs()
{
  if ((this->check_x(BOMB) == 1)
      || (this->check_y(BOMB) == 1))
    {
      this->check_moves();
      return (1);
    }
  return (0);
}

void	IA::update(gdl::Input&)
{
  this->_bomb->update(this->_map);
  if (this->check_bombs() == 1)
    this->check_moves();
  else if ((this->check_bombs() == 0) && ((this->_bomb->getState() == Bomb::INPROGRESS) 
				     || (this->_bomb->getState() == Bomb::INPROGRESS)))
    return;
  else if (this->check_bombs() == 0 && this->_bomb->getState() != Bomb::DISPO)
    this->check_moves();
  else
    {
	if (this->check_players() == 0)
	  if (this->check_dwall() == 0)
	    this->check_moves();
    }
}
