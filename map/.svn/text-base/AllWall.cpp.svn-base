//
// AllWall.cpp for  in /u/all/ngo_b/cu/rendu/projetTek2/cpp/bomber/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Fri May 13 20:46:17 2011 benoit ngo
// Last update Sun Jun  5 15:47:11 2011 benoit ngo
//

#include	"AllWall.hh"
#include	<cstdlib>
#include	<ctime>
#include	<iostream>
#include	<stack>
#include	"coord.h"
#include	<string>
#include	<fstream>

t_choose_wall	type_wall[] = {
  {WALL, &AllWall::alloc_wall},
  {DWALL, &AllWall::alloc_dwall},
  {EMPTY, &AllWall::alloc_empty},
  {EMPTY, NULL}
};

void		AllWall::deleteWall(const int x, const int y)
{
  this->_wall[y].deleteWall(x);
}

Obj *		AllWall::getWall(const int x, const int y)
{
  if (x >= this->_max_x || y >= this->_max_y
      || x < 0 || y < 0)
    return (NULL);
  if (this->_wall[y].isEmpty() == false)
    {
      return (this->_wall[y].getWall(x));
    }
  return (NULL);
}

int		AllWall::get_sizeX() const
{
  return (this->_max_x);
}

int		AllWall::get_sizeY() const
{
  return (this->_max_y);
}

int		AllWall::add_object(Obj * o, const int x, const int y)
{
  this->_wall[y].setWall(x, o);
  return (0);
}



s_coord		AllWall::get_first_pos()
{
  int		x;
  int		y;
  s_coord	f;

  f.x = 0;
  f.y = 0;
  srandom(time(NULL) * getpid());
  while (f.x == 0)
    {
      Obj * o;
      x = random() % this->_max_x;
      y = random() % this->_max_y;
      while ((o = this->getWall(x, y)) != NULL)
	{
	  if (o->get_type() == EMPTY)
	    {
	      f.x = x;
	      f.y = y;
	      return (f);
	    }
	  ++x;
	}
    }
  return (f);
}

bool		AllWall::false_in_range(const int x, const int y)
{
  Obj *		next;
  if (((next = this->getWall(x, y + 2))
	      && next->getMaze() == false)
	  || ((next = this->getWall(x, y - 2))
	      && next->getMaze() == false)
	  || ((next = this->getWall(x - 2, y))
	      && next->getMaze() == false)
	  || ((next = this->getWall(x + 2, y))
	      && next->getMaze() == false))
    {
      return (true);
    }
  return (false);
}

void		AllWall::build_dest()
{
  long			var_r = 0;
  std::stack<s_coord>	s;

  srandom(getpid() * time(NULL));
  s.push(this->get_first_pos());
  while (s.empty() == false)
    {
      Obj *	next;
      s_coord	cur_coord;
      var_r = random()  % 4;
      cur_coord = s.top();
      if ((var_r == 0 && ((next = this->getWall(cur_coord.x, cur_coord.y + 2)) != NULL)
	   && next->getMaze() == false)
	  || (var_r == 1 && ((next = this->getWall(cur_coord.x, cur_coord.y - 2)) != NULL)
	      && next->getMaze() == false)
	  || (var_r == 2 && ((next = this->getWall(cur_coord.x - 2, cur_coord.y)) != NULL)
	      && next->getMaze() == false)
	  || (var_r == 3 && ((next = this->getWall(cur_coord.x + 2, cur_coord.y)) != NULL)
	      && next->getMaze() == false)
	  || (((next = this->getWall(cur_coord.x, cur_coord.y + 2)) != NULL)
	      && next->getMaze() == false)
	  || (((next = this->getWall(cur_coord.x, cur_coord.y - 2)) != NULL)
	      && next->getMaze() == false)
	  || (((next = this->getWall(cur_coord.x - 2, cur_coord.y)) != NULL)
	      && next->getMaze() == false)
	  || (((next = this->getWall(cur_coord.x + 2, cur_coord.y))) != NULL
	      && next->getMaze() == false))
	{
	  next->setMaze(true);

	  Wall *		w;
	  int			x = cur_coord.x + ((next->get_x() - cur_coord.x) / 2);
	  int		       	y = cur_coord.y + ((next->get_y() - cur_coord.y) / 2);
	  w = reinterpret_cast<Wall *> (this->getWall(x, y));

	  if (w->get_x() + 1 != this->_max_x && w->get_y() + 1 != this->_max_y)
	  {
	      w->setdest(true);
	      w->setMaze(true);
	  }

	  if (next->get_type() == EMPTY)
	    {
	      cur_coord.x = next->get_x();
	      cur_coord.y = next->get_y();
	      s.push(cur_coord);
	    }
	}
      else
	{
	  if ((var_r == 0 && ((next = this->getWall(cur_coord.x, cur_coord.y + 2)) != NULL))
	      || (var_r == 1 && ((next = this->getWall(cur_coord.x, cur_coord.y - 2)) != NULL))
	      || (var_r == 2 && ((next = this->getWall(cur_coord.x - 2, cur_coord.y)) != NULL))
	      || (var_r == 3 && ((next = this->getWall(cur_coord.x + 2, cur_coord.y)) != NULL))
	      || ((next = this->getWall(cur_coord.x, cur_coord.y + 2)) != NULL)
	      || ((next = this->getWall(cur_coord.x, cur_coord.y - 2)) != NULL)
	      || ((next = this->getWall(cur_coord.x - 2, cur_coord.y)) != NULL)
	      || ((next = this->getWall(cur_coord.x + 2, cur_coord.y)) != NULL))
	    {
	      Wall *		w;
	      int			x = cur_coord.x + ((next->get_x() - cur_coord.x) / 2);
	      int		       	y = cur_coord.y + ((next->get_y() - cur_coord.y) / 2);
	      w = reinterpret_cast<Wall *> (this->getWall(x, y));
	      if (w->get_x() + 1 != this->_max_x && w->get_y() + 1 != this->_max_y)
	      {
		  w->setdest(true);
		  w->setMaze(true);
	      }
	    }
	  while (s.empty() == false &&
		 this->false_in_range(s.top().x, s.top().y) != true)
	    {
	      s.pop();
	    }
	}
    }

}

void		AllWall::build_random(const int size_x,
				      const int size_y)
{
  this->_max_x = size_x;
  this->_max_y = size_y;
  srandom(getpid() * time(NULL));
  for (int i = 0; i < size_y; ++i)
    {
      this->_wall[i].init(size_x, i, size_y);
    }
  this->build_dest();
  for (std::map<int, lineWall>::iterator it = this->_wall.begin();
       it != this->_wall.end(); ++it)
    {
      for (int i = 0; i < size_x; ++i)
  	{
  	  Obj *	u = it->second.getWall(i);
  	  if (u->get_type() == DWALL)
  	    {
  	      if (random() % 2)
  		this->add_object(new empty(u->get_x(),
  					   u->get_y()), u->get_x(), u->get_y());
  	    }
  	}
    }
}

void		AllWall::parseFile(std::string const & file)
{
  std::ifstream fichier;
  std::string   contenu;
  int		i = 0;
  int		j = 0;

  fichier.open(file.c_str());
  if (fichier.is_open())
    {
      while (getline(fichier, contenu))
	{
	  for (j = 0; j < (int)contenu.length(); ++j)
	    this->add_object(this->find_the_type(contenu[j], j, i), j, i);
	  ++i;
	}
      fichier.close();
    }

  this->_max_x = j;
  this->_max_y = i;
}

Obj		*AllWall::find_the_type(char c, int x, int y)
{
  for (int i = 0; type_wall[i].ptr != NULL ; ++i)
    {
      if (c - '0' == type_wall[i].type)
	return ((this->*type_wall[i].ptr)(x, y));
    }
  return (this->alloc_wall(x, y));
}

#include <iostream>
Obj		*AllWall::alloc_wall(const int i, const int j)
{
  Obj *ob = new Wall(i, j, false);
  return (ob);
}

Obj		*AllWall::alloc_dwall(const int i, const int j)
{
  Obj *ob = new Wall(i, j, true);
  return (ob);
}

Obj		*AllWall::alloc_empty(const int i, const int j)
{
  Obj *ob = new empty(i, j);
  return (ob);
}

AllWall &			AllWall::operator=(AllWall const &other)
{
  if (&other != this)
    {
      _wall = other._wall;
    }
  return (*this);
}

void	       	AllWall::set_sizeX(const int x)
{
  this->_max_x = x;
}

void		AllWall::set_sizeY(const int y)
{
  this->_max_y = y;
}

AllWall::AllWall():
  _max_x(0), _max_y(0)
{

}

AllWall::~AllWall()
{
  //free wall *
}
