//
// SaveGame.cpp for  in /home/basset_a//bomberman-2014-capot_r
//
// Made by antoine basset
// Login   <basset_a@epitech.net>
//
// Started on  Sat Jun  4 16:54:17 2011 antoine basset
// Last update Sun Jun  5 17:54:08 2011 inan asan
//

#include	"SaveGame.hh"

SaveGame::SaveGame(Map *map, std::list<APlayer *> *players, gdl::Input *in)
  : _map(map), _players(players), _in(in)
{

}

SaveGame::~SaveGame()
{}

void          SaveGame::update()
{
  if (_in->isKeyDown(gdl::Keys::F5))
    {
      usleep(9000);
      this->WriteSaveInFile(this->findName());
    }
}

std::string             SaveGame::conv_str(int nb) const
{
  std::ostringstream temp;

  temp << nb;
  return temp.str();
}


std::string		SaveGame::findName() const
{
  DIR *fd;
  struct dirent *dir;
  int	i = 0;

  if ((fd = opendir("./data/save")) != NULL)
    {
      while ((dir = readdir(fd)))
	i++;
      closedir(fd);
    }
  return "./data/save/save" + conv_str(i - 2);
}

void		SaveGame::WriteMapXY(std::ofstream & fichier) const
{
  fichier << this->_map->get_sizeX() << " " << this->_map->get_sizeY() <<  std::endl;
}

void		SaveGame::WriteMap(std::ofstream & fichier) const
{
  Obj		*curObj;

  for (int j = 0; j < this->_map->get_sizeY(); ++j)
    {
      for (int i = 0; i < this->_map->get_sizeX(); ++i)
	{
	  curObj = _map->getObj(i, j);
	  if (curObj->get_type() != BOMB)
	    fichier << curObj->get_type();
	  else
	    fichier << EMPTY;
	}
      fichier << std::endl;
    }
}

void		SaveGame::WriteNbPlayer(std::ofstream & fichier) const
{
  fichier << this->_players->size() << std::endl;
}

void		SaveGame::WritePlayerInfo(std::ofstream & fichier) const
{
  for (std::list<APlayer *>::iterator it = _players->begin(); it !=  _players->end(); ++it)
    {
      fichier << (*it)->getType()
	      << " "
	      << (*it)->getX()
	      << " "
	      << (*it)->getY()
	      << " "
	      << (*it)->getScore()
	      << " "
	      << (*it)->getAlive()
	      << std::endl;
    }
}

void		SaveGame::WriteSaveInFile(std::string const & file) const
{
  std::ofstream fichier;
  std::string   contenu;

  fichier.open(file.c_str(), std::ios::in | std::ios::trunc | std::ios::out );
  if (fichier.is_open())
    {
      WriteMapXY(fichier);
      WriteMap(fichier);
      WriteNbPlayer(fichier);
      WritePlayerInfo(fichier);
      fichier.close();
    }
}
