//
// CheckBomb.hh for  in /home/basset_a//workspace/bomberman-2014-capot_r
//
// Made by antoine basset
// Login   <basset_a@epitech.net>
//
// Started on  Wed Jun  1 11:05:08 2011 antoine basset
// Last update Sun Jun  5 15:31:58 2011 camille benhamou
//

#ifndef		_CHECKBOMB_HH_
# define	_CHECKBOMB_HH_

#include	<list>
#include	<vector>
#include	"APlayer.hh"
#include	"PlaySound.hh"

class CheckBomb
{
private :

  std::list<APlayer *>	*_players;
  std::vector<struct s_coord>  _coord;
  PlaySound		*_playSound;

public :

  CheckBomb(std::list<APlayer *> *player);
 ~CheckBomb();

  void			update();

};

#endif		/*_CHECKBOMB_HH_*/
