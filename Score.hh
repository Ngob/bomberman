//
// Score.hh for  in /home/basset_a//workspace/bomberman-2014-capot_r
//
// Made by antoine basset
// Login   <basset_a@epitech.net>
//
// Started on  Mon May 23 10:48:03 2011 antoine basset
// Last update Sun Jun  5 16:41:09 2011 romain capot
//

#ifndef		_SCORE_HH_
#define		_SCORE_HH_

#include	<string>
#include	<iostream>
#include	<vector>
#include	<sstream>
#include	<fstream>
#include	<algorithm>
#include	<list>
#include	"APlayer.hh"

class Score
{

private :

  std::vector<int>		_best;
  std::vector<std::string>	_string_best;
  std::list<APlayer *>		*_players;

public :

  static size_t const	limit_HS = 5;

  Score();
  Score(std::list<APlayer *> *player);
  Score(std::vector<int> & tab);
  Score(Score const & other);
  ~Score();

  int			conv_nb(std::string const & str) const;
  std::string           conv_str(int nb) const;
  void			file_to_vector(const std::string & file);
  int			find_int_in_line(std::string const & str);
  std::vector<int>	getHighScores() const;
  bool			isHighScores(int value);
  void			sortHigthScores();
  void			setHightScore(int value);
  void			writeHightScore(std::string const & str);
  void			putAllScoreToVector();
  std::vector<std::string>  getStringHighScores();

public :

  Score &		operator=(Score const & other);
};

#endif		/*_SCORE_HH_*/
