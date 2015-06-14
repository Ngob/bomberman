//
// SaveGame.hh for  in /home/basset_a//bomberman-2014-capot_r
//
// Made by antoine basset
// Login   <basset_a@epitech.net>
//
// Started on  Sat Jun  4 16:19:06 2011 antoine basset
// Last update Sun Jun  5 16:45:51 2011 romain capot
//

#ifndef		_SAVEGAME_HH_
#define		_SAVEGAME_HH_

#include	<sys/types.h>
#include	<dirent.h>
#include	<vector>
#include	<sstream>
#include	<fstream>
#include	<string>
#include	<list>
#include	"APlayer.hh"
#include	"map/map.hh"

class SaveGame
{

  Map			*_map;
  std::list<APlayer *>  *_players;
  gdl::Input		* _in;

public :

  SaveGame(Map *map, std::list<APlayer *> *players, gdl::Input *_in);
  ~SaveGame();

  std::string 	conv_str(int nb) const;
  std::string	findName() const;
  void		update();
  void		WriteMapXY(std::ofstream & fichier) const;
  void		WriteMap(std::ofstream & fichier) const;
  void		WriteNbPlayer(std::ofstream & fichier) const;
  void		WritePlayerInfo(std::ofstream & fichier) const;
  void		WriteSaveInFile(std::string const & file) const;
};

#endif		/*_SAVEGAME_HH_*/
