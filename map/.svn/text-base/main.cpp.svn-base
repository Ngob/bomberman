//
// main.cpp for  in /home/ngo_b//rendu/proj/bomberman-2014-capot_r/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 25 20:21:39 2011 benoit ngo
// Last update Thu Jun  2 02:41:30 2011 benoit ngo
//

#include	<string>
# include	"map.hh"


int		main(void)
{
  std::string	s("map1.txt");
  Map		m(20, 30);
  int		x = 0;
  int		y = 0;

  //m.setObj(4, 4, PERSO);
  //m.findPlayerPos(x, y);
  //m.findPlayerPos(x, y);
  for (int i = 0; i < 2; ++i)
    {
      m.addPlayer(x, y);
      std::cout << "x " << x << "Y " << y << std::endl;
    }
  //m.findPlayerPos(x, y);



  for (int y = 0; y < m.get_sizeY(); ++y)
    {
      for (int x = 0; x < m.get_sizeX(); ++x)
	{
	  Obj *	o = m.getObj(x, y);
	  if (o->get_type() == EMPTY)
	    std::cout << " ";
	  else
	    std::cout << o->get_type();
	}
      std::cout << std::endl;
    }
  return (0);
}
