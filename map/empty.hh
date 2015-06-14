//
// empty.hh for  in /home/ngo_b//rendu/proj/bomberman-2014-capot_r/map
//
// Made by benoit ngo
// Login   <ngo_b@epitech.net>
//
// Started on  Wed May 25 20:12:53 2011 benoit ngo
// Last update Mon May 30 03:51:01 2011 benoit ngo
//

#ifndef		__EMPTY_H__
# define	__EMPTY_H__
# include	"AObj.hh"

// class representant une classe vide

class		empty : public Obj
{
private:
  bool		_isFire; // case en flamme ou pas

public:
  empty(const int, const int);
  ~empty();
  bool		getFire() const;
  void		setFire(const bool);
};

#endif		/*__EMPTY_H__*/
