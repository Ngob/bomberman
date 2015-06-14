//
// Score.cpp for  in /home/basset_a//workspace/bomberman-2014-capot_r
//
// Made by antoine basset
// Login   <basset_a@epitech.net>
//
// Started on  Mon May 23 11:13:32 2011 antoine basset
// Last update Sun Jun  5 17:56:37 2011 inan asan
//

#include	"Score.hh"

Score::Score()
{}

Score::Score(std::list<APlayer *> *players)
  : _players(players)
{}

Score::Score(std::vector<int> & tab)
  : _best(tab)
{}

Score::Score(Score const & other)
{
  this->_best = other._best;
}

Score::~Score()
{}

int		Score::conv_nb(std::string const & str) const
{
  int			nb;
  std::stringstream     Str;

  Str << str;
  Str >> nb;
  return nb;
}

std::string             Score::conv_str(int nb) const
{
  std::ostringstream temp;

  temp << nb;
  return temp.str();
}

int		Score::find_int_in_line(std::string const & str)
{
  size_t        start;
  size_t        end;
  int		value;

  for (size_t i = 0; i < str.length(); ++i)
    {
      if (str[i] <= '9' && str[i] >= '0')
        {
          start = i;
          for (; (str[i] <= '9' && str[i] >= '0') && i < str.length(); ++i);
          end = i;
	  value = conv_nb(str.substr(start, end - start));
	  return value;
	}
    }
  return 0;
}

void            Score::file_to_vector(const std::string & file)
{
  std::ifstream fichier;
  std::string   contenu;

  fichier.open(file.c_str());
  if (fichier.is_open())
    {
      while (getline(fichier, contenu))
	this->_best.push_back(find_int_in_line(contenu));
      fichier.close();
    }
}

std::vector<int>	Score::getHighScores() const
{
  return this->_best;
}

void			Score::putAllScoreToVector()
{
  for (std::list<APlayer *>::iterator it = this->_players->begin(); it != this->_players->end(); ++it)
    this->_best.push_back((*it)->getScore());
}

std::vector<std::string>	Score::getStringHighScores()
{
  size_t		i = 0;

  for (std::vector<int>::iterator it = this->_best.begin(); it != this->_best.end() && i < limit_HS; ++it)
    {
      this->_string_best.push_back(conv_str((*it)));
      ++i;
    }
  return this->_string_best;
}

void			Score::sortHigthScores()
{
  sort(this->_best.begin(), this->_best.end());
  reverse(this->_best.begin(), this->_best.end());
}

bool			Score::isHighScores(int value)
{
  bool		check = false;

  for (std::vector<int>::iterator it = this->_best.begin(); it < this->_best.end(); ++it)
    {
      if (*it < value  || this->_best.size() < limit_HS)
	check = true;
    }
  return check;
}

void			Score::setHightScore(int value)
{
  this->sortHigthScores();
  if (this->_best.size() > limit_HS)
    this->_best.erase(this->_best.end() - 1);
  this->_best.push_back(value);
  this->sortHigthScores();
}

void			Score::writeHightScore(std::string const & file)
{
  std::ofstream fichier;
  std::string   contenu;
  size_t	i = 0;

  fichier.open(file.c_str(), std::fstream::trunc);
  if (fichier.is_open())
    {
      for (std::vector<int>::iterator it = this->_best.begin(); it < this->_best.end() && i < limit_HS; ++it)
	{
	  fichier << *it << std::endl;
	  ++i;
	}
      fichier.close();
    }
}

Score&			Score::operator=(Score const & other)
{
  if (&other != this)
    {
      this->_best = other. getHighScores();
    }
  return (*this);
}
