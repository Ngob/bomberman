//
// map.cpp for  in /home/ngo_b//rendu/proj/bomberman-2014-capot_r/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Thu May 26 22:33:53 2011 benoit ngo
// Last update Sun Jun  5 11:06:09 2011 benoit ngo
//

#include	<stdlib.h>
#include       	"../Play.hh"
#include	"map.hh"

void			Map::setObj(const int x, const int y,
				    const EType t)
{
  Obj *		       o;

  if (t == PERSO)
    {
      o = this->getObj(x, y);
      if (o != NULL)
	o->setType(PERSO);
    }
  else if (t == EMPTY)
    {
      o = this->getObj(x, y);
      if (o != NULL)
	o->setType(EMPTY);
    }
  else
    {
      o = this->_wall.find_the_type(t + '0', x, y);
      if (o != NULL)
	this->_wall.add_object(o, x, y);
    }
}

bool			Map::check_empty(const EType t)
{
  if (t == EMPTY || t == PERSO)
    return (true);
  return (false);
}

bool			Map::DiagIsFree(const int x, const int y)
{
  Obj *		next;

  if (((next = this->getObj(x + 1, y))
       && this->check_empty(next->get_type()) == true
       && (next = this->getObj(x, y + 1))
       && this->check_empty(next->get_type()) == true)
      || ((next = this->getObj(x - 1, y)) &&
	  this->check_empty(next->get_type()) == true
	  && (next = this->getObj(x, y - 1)) &&
	  this->check_empty(next->get_type()) == true)
      || ((next = this->getObj(x + 1, y)) &&
	  this->check_empty(next->get_type()) == true
	  && (next = this->getObj(x, y - 1)) &&
	  this->check_empty(next->get_type()) == true)
      || ((next = this->getObj(x - 1, y)) &&
	  this->check_empty(next->get_type()) == true
	  && (next = this->getObj(x, y + 1)) &&
	  this->check_empty(next->get_type()) == true)
      )
    return (true);
  return (false);
}

bool			Map::lineIsFree(const int x, const int y, int nb_free, const int to_add, const bool modif_x)
{
  Obj *			next;
  if (nb_free >= 4)
    return (true);
  if (modif_x == true)
    {
      if ((next = this->getObj(x + to_add, y)) && (next->get_type() == EMPTY
						    || next->get_type() == PERSO))
	{
	  return (this->lineIsFree(x + to_add, y, nb_free + 1, to_add, modif_x));
	}
      return (false);
    }
  else
    {
      if ((next = this->getObj(x , y + to_add)) && (next->get_type() == EMPTY
						    || next->get_type() == PERSO))
	{
	  return (this->lineIsFree(x, y + to_add, nb_free + 1, to_add, modif_x));
	}
      return (false);
    }
  return (false);
}

bool			Map::CanBePlaced(int i, int j)
{

  Obj			*on = getObj(j, i);

  if (on->get_type() == EMPTY || on->get_type() == PERSO)
    {
      if (this->DiagIsFree(on->get_x(), on->get_y()) == true
	  || this->lineIsFree(on->get_x(), on->get_y(), 1, 1, true) == true
	  || this->lineIsFree(on->get_x(), on->get_y(), 1,  -1, true) == true
	  || this->lineIsFree(on->get_x(), on->get_y(), 1, 1, false) == true
	  || this->lineIsFree(on->get_x(), on->get_y(), 1, -1, false) == true
	  )
	return (true);
    }
  return (false);
  // if (a >= 2)
  //   check = true;
  // return check;
}

void			Map::addPlayer(int & x, int & y)
{
  x = 0;
  y = 0;
  this->findPlayerPos(x, y);
  if (this->_res_p.empty() != true)
    this->setObj(x, y, PERSO);
  std::cout << "new player in " << x << " " << y << std::endl;
    //_wall._wall[y].setWall(x, ap);
}

#include <math.h>

void		       Map::findPlayerPos(int & x, int & y)
{
  double	       	dis = 0;
  int			u = 0;

  this->_nb_players += 1;

  if (this->_res_p.empty())
    {
      srandom(time(NULL) * getpid());
      do
	{
	  x = random() % this->_size_x;
	  y = random() % this->_size_y;
	  ++u;
	} while (this->CanBePlaced(y, x) != true && u < 200);
      if (this->CanBePlaced(y, x) == true)
	{
	  s_coord	s;
	  s.x = x;
	  s.y = y;
	  this->_res_p.push_back(s);
	  return ;
	}
    }
  for (int i = 0; i < this->_size_y; ++i)
    {
      for (int j = 0; j < this->_size_x; ++j)
	{
	  //if (this->getObj(j, i)->get_type() == EMPTY)
	  if (this->CanBePlaced(i, j) == true)
	    {
	      if (this->_nb_players == 0)
		{
		  if (this->CanBePlaced(i, j) == true)
		    {
		      x = j;
		      y = i;
		      return ;
		    }
		}
	      else
		{
		  double		dis_tmp = 0;
		  int	       		v = 0;
		  for (std::vector<s_coord>::iterator it = this->_res_p.begin()
			 ; it != this->_res_p.end(); ++it)
		    {
		      dis_tmp += ( 1 / sqrt((((it->x) - j) * (it->x - j)) +
					    ((it->y - i) * (it->y - i))));
			  ++v;
		    }
		  dis_tmp = v / dis_tmp;
		  if (dis_tmp >= dis)
		    {
		      x = j;
		      y = i;
		      dis = dis_tmp;
		    }

		}
	    }

	}
    }
  s_coord s;
  if (dis == 0.0)
    {
      std::cerr << "Can't add more player, spawn are reinitializing" << std::endl;
      this->_res_p.clear();
      this->addPlayer(x, y);
      return ;
    }
  s.x = x;
  s.y = y;
  //this->setObj(x, y, PERSO);
  this->_res_p.push_back(s);
}

int			Map::get_sizeX() const
{
  return (this->_size_x);
}

int			Map::get_sizeY() const
{
  return (this->_size_y);
}

AllWall  		Map::getAllWall() const
{
  return (this->_wall);
}

void           Map::getCoord(int & x, int & y) const
{
  x = _size_x;
  y = _size_y;
}

Map &	Map::operator=(Map const & other)
{
  if (&other != this)
    {
      other.getCoord(_size_x, _size_y);
      _wall = other.getAllWall();
    }
  return (*this);
}

Obj *		Map::getObj(const int x, const int y)
{
  return (this->_wall.getWall(x, y));
}

Map::Map(const std::string & s):
  _nb_players(0)
{
  this->_wall.parseFile(s);
  this->_size_x = this->_wall.get_sizeX();
  this->_size_y = this->_wall.get_sizeY();
}

Map::Map(const int size_x, const int size_y):
  _size_x(size_x), _size_y(size_y)
{
  this->_wall.build_random(size_x, size_y);
  std::cout << "Map Is Creat" << std::endl;
}
Map::Map():
  _size_x(0), _size_y(0)
{

}

void			Map::setObj(Obj * o, const int x, const int y)
{
  if (x < this->_size_x && y < this->_size_y
      && x >= 0 && y >= 0)
    this->_wall.add_object(o, x, y);
}

void			Map::deleteObj(const int x, const int y)
{
  if (x < this->_size_x && y < this->_size_y
      && x >= 0 && y >= 0)
  this->_wall.deleteWall(x, y);
}
void			Map::setAllWall(AllWall const & other)
{
  _wall = other;
}









int			Map::getNbPlayers() const
{
  return (this->_nb_players);
}

Map::~Map()
{

}

