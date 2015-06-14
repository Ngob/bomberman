//
// lineWall.cpp for  in /home/ngo_b//rendu/proj/bomberman-2014-capot_r/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 25 20:47:23 2011 benoit ngo
// Last update Sun Jun  5 17:26:02 2011 benoit ngo
//

#include		"lineWall.hh"
#include		"empty.hh"

void		lineWall::deleteWall(const int x)
{
  Obj *		o = new empty(this->line[x]->get_x(), this->line[x]->get_y());

  delete this->line[x];
  this->line.erase(x);
  this->line[x] = o;
}

void		lineWall::setWall(const int x, Obj * const o)
{
  std::map<int, Obj *>::iterator it;

  it = this->line.find(x);
  if (it != this->line.end())
    {
      delete (it->second);
      this->line.erase(x);
    }
  this->line[x] = o;
}

lineWall::~lineWall()
{
  for (std::map<int, Obj*>::iterator it = this->line.begin();
       it != this->line.end() ; ++it)
    {
      delete it->second;
    }
}

void		lineWall::init(const int max_x,
			       const int y, const int size_y)
{
  this->line.clear();
  this->y = y;
  (void) size_y;
  //initialisation de la ligne (toute case remplis avec empty)
  for (int i = 0; i < max_x; ++i)
    {
      if (y % 2 != 0 && y + 1 != size_y)
	{
	  if (i % 2 != 0 && i + 1 != max_x)
	    this->line[i] = new empty(i, y);
	  else
	    this->line[i] = new Wall(i, y, false);
	}
      else
	this->line[i] = new Wall(i, y, false);
    }
}

lineWall::lineWall()
{
  this->line.clear();
}

bool		lineWall::isEmpty() const
{
  return (this->line.empty() == true);
}

Obj * 	lineWall::getWall(const int x)
{
  return (this->line[x]);
}
