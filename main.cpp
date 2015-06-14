//
// main.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Mon May  2 10:25:17 2011 romain capot
// Last update Sat Jun  4 14:54:09 2011 romain capot
//

#include	<cstdlib>
#include	<stdexcept>
#include	"Menu.hh"

int		main(int ac, char **av)
{
  Menu		game;

  try
  {
    game.launchMenu();
  }
  catch (std::runtime_error const & e)
    {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
    }
  (void)ac;
  (void)av;
  return EXIT_SUCCESS;
}
