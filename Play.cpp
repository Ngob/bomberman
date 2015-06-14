//
// Play.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Tue May 24 09:50:31 2011 romain capot
//

#include	"Play.hh"
#include	"IA.hh"

Play::Play(int nbPlayers, gdl::Window * win, gdl::GameClock * clock, gdl::Input * in, std::string const & mapPath, int mapSize, int nbIA)
  : APlay(win, clock, in), _nbPlayers(nbPlayers), _nbIA(nbIA)
{
  // init map
  if (mapPath == "")
    this->_map = new Map(mapSize, mapSize);
  else
    this->_map = new Map(mapPath);
  this->_aff = new AffMap(_map, blockSize);
  this->_affPlayer = new AffPlayer(&_players);
  this->_plate = new Plate(_map->get_sizeX(), _map->get_sizeY());
  this->_check = new CheckBomb(&_players);
  this->_checkQuit = new CheckQuit(_nbPlayers, &_players);
  this->_score = new Score(&_players);
  this->_score->file_to_vector("./data/scores/higth_score.log");
  this->_saveGame = new SaveGame(_map, &_players, _in);
  this->_playSound = new PlaySound();
  this->_pause = false;
}

Play::~Play()
{
  delete this->_map;
  if (this->getNbPlayers() != 0)
    {
      delete this->_aff;
      delete this->_affPlayer;
      delete this->_plate;
      delete this->_check;
      delete this->_checkQuit;
      delete this->_score;
      delete this->_saveGame;
      delete this->_playSound;
      for (std::list<APlayer *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	{
	  delete (*it);
	}
    }
}

Play::Play(gdl::Window * win, gdl::GameClock * clock,
	   gdl::Input * in, const int save):
  APlay(win, clock, in), _nbPlayers(0)
{
  this->_map = new Map();
  std::stringstream		ss;
  std::string			str;
  std::string			path("data/save/save");
  std::list<APlayer *> *	ptr;

  ss << save;
  ss >> str;
  path += str;
  ptr = this->_map->load_map(path, clock);
  if (ptr == NULL)
    return ;
  this->_players = *ptr;
  delete ptr;
  this->_nbPlayers = this->_map->getNbPlayers() -
    this->_map->getNbIa();
  this->_nbIA = this->_map->getNbIa();
  this->_aff = new AffMap(_map, blockSize);
  this->_affPlayer = new AffPlayer(&_players);
  this->_plate = new Plate(_map->get_sizeX(), _map->get_sizeY());
  this->_check = new CheckBomb(&_players);
  this->_checkQuit = new CheckQuit(_nbPlayers, &_players);
  this->_score = new Score(&_players);
  this->_score->file_to_vector("./data/scores/higth_score.log");
  this->_saveGame = new SaveGame(_map, &_players, _in);
  this->_playSound = new PlaySound();
  this->_pause = false;
}

void		Play::initialize(void)
{
  APlayer	*player;

  this->_clock->play();
  this->_camGame.initialize();
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  _texClear = gdl::Image::load("data/textures/W2.png");
  if (this->_players.size() != 0)
    {
      this->_playSound->playMusic("data/sounds/game/battlegame.ogg");
      return ;
    }
  player = new Human(APlayer::PLAYER1, _map, blockSize, _clock);
  this->_players.push_back(player);
  if (_nbPlayers == 2)
    {
      player = new Human(APlayer::PLAYER2, _map, blockSize, _clock);
      this->_players.push_back(player);
    }
  // Creation IA
  for (int i = 0; i < this->_nbIA; ++i)
    {
      player = new IA(APlayer::IA, _map, blockSize, _clock);
      this->_players.push_back(player);
    }
  this->initPos();
  this->_playSound->playMusic("data/sounds/game/battlegame.ogg");
}

void		Play::initPos()
{
  int		x, y;

  for (std::list<APlayer *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
    {
      this->_map->addPlayer(x, y);
      (*it)->setX(x);
      (*it)->setY(y);
    }
}

void	Play::update(void)
{
  this->_win->catchEvent();
  if (this->_in->isKeyDown(gdl::Keys::P))
    {
      usleep(9000);
      this->_pause = (_pause == false) ? true : false;
    }
  if (!this->_pause)
    {
      this->_clock->update();
      this->_check->update();
      this->_saveGame->update();
      for (std::list<APlayer *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	{
	  if ((*it)->getAlive() == true)
	    {
	      if (this->_nbPlayers == 1 && (*it)->getType() == APlayer::PLAYER1)
		{
		  this->_camGame.updateCameraGame((*it)->getX(), (*it)->getY(), this->_map->get_sizeX(), this->_map->get_sizeY(), this->blockSize);
		}
	      /* check le score */
	      Bomb      *bomb = (*it)->getBomb();
	      (*it)->addScore(bomb->getNbKilled() * addKillScore);
	      (*it)->addScore(bomb->getNbWallDestruct() * addBlocDestruct);
	      if (((*it)->getScore() / addDamage) >= bomb->getDam() + 1)
		bomb->addDam(1);
	      /*seulement si le joeur survi*/
	      (*it)->update(*this->_in);
	    }
	}
      if ((this->_exit = this->_checkQuit->checkPlayerAlive(_nbPlayers)) == true)
	{
	  this->_score->putAllScoreToVector();
	  this->_score->sortHigthScores();
	  this->_score->writeHightScore("./data/scores/higth_score.log");
	  HighScores	hightScore(this->_win, this->_clock, this->_in, NULL);
	  hightScore.setNb(this->_score->getStringHighScores());
	}
    }
}

void	Play::draw(void)
{
  // Si vous modifie ici, le background ne changera pas...
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_texClear.bind();
  this->_plate->draw();
  this->_aff->checkAff();
  this->_affPlayer->draw();
  this->_win->display();
}

void	Play::runGame(void)
{
  this->initialize();
  while (!this->_exit)
    {
      this->update();
      if (!this->_win->isOpened())
	break ;
      this->draw();
      usleep(25000);
    }
  this->_playSound->stopMusic();

  AffWinner	winner(this->_win, this->_clock, this->_in, this->_checkQuit->getWinner());
  winner.affWinner();
}

int		Play::getNbPlayers() const
{
  return (this->_nbPlayers);
}
