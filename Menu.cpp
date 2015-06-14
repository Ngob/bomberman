//
// Menu.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Wed May  4 10:25:34 2011 romain capot
// Last update Sun Jun  5 18:27:36 2011 chris chaulvet
//

#include	"Menu.hh"

gdl::Image	Menu::texBackground = gdl::Image::load("data/backgrounds/bg_begining.png");
gdl::Image	Menu::texPressEnter = gdl::Image::load("data/buttons/btn_press_enter.png");
gdl::Image	Menu::texNewGame = gdl::Image::load("data/buttons/btn_new_game.png");
gdl::Image	Menu::texLoadGame = gdl::Image::load("data/buttons/btn_load_game.png");
gdl::Image	Menu::texOptions = gdl::Image::load("data/buttons/btn_options.png");
gdl::Image	Menu::texCredits = gdl::Image::load("data/buttons/btn_credits.png");
gdl::Image	Menu::texHighScores = gdl::Image::load("data/buttons/btn_high_scores.png");
gdl::Image	Menu::texExitGame = gdl::Image::load("data/buttons/btn_exit_game.png");
gdl::Image	Menu::texOnePlayer = gdl::Image::load("data/buttons/btn_one_player.png");
gdl::Image	Menu::texTwoPlayer = gdl::Image::load("data/buttons/btn_two_players.png");
gdl::Image	Menu::texOneMap = gdl::Image::load("data/buttons/btn_map_1.png");
gdl::Image	Menu::texTwoMap = gdl::Image::load("data/buttons/btn_map_2.png");
gdl::Image	Menu::texRandMap = gdl::Image::load("data/buttons/btn_map_r.png");
gdl::Image	Menu::texBack = gdl::Image::load("data/buttons/btn_back.png");

gdl::Image	Menu::texPressEnterOver = gdl::Image::load("data/buttons/btn_press_enter2.png");
gdl::Image	Menu::texNewGameOver = gdl::Image::load("data/buttons/btn_new_game2.png");
gdl::Image	Menu::texLoadGameOver = gdl::Image::load("data/buttons/btn_load_game2.png");
gdl::Image	Menu::texOptionsOver = gdl::Image::load("data/buttons/btn_options2.png");
gdl::Image	Menu::texCreditsOver = gdl::Image::load("data/buttons/btn_credits2.png");
gdl::Image	Menu::texHighScoresOver = gdl::Image::load("data/buttons/btn_high_scores2.png");
gdl::Image	Menu::texExitGameOver = gdl::Image::load("data/buttons/btn_exit_game2.png");
gdl::Image	Menu::texOnePlayerOver = gdl::Image::load("data/buttons/btn_one_player2.png");
gdl::Image	Menu::texTwoPlayerOver = gdl::Image::load("data/buttons/btn_two_players2.png");
gdl::Image	Menu::texOneMapOver = gdl::Image::load("data/buttons/btn_map_12.png");
gdl::Image	Menu::texTwoMapOver = gdl::Image::load("data/buttons/btn_map_22.png");
gdl::Image	Menu::texRandMapOver = gdl::Image::load("data/buttons/btn_map_r2.png");
gdl::Image	Menu::texBackOver = gdl::Image::load("data/buttons/btn_back2.png");

t_keys		listKeys[] = {
  {gdl::Keys::Up, &Menu::actUp},
  {gdl::Keys::Down, &Menu::actDown},
  {gdl::Keys::Return, &Menu::actEnter},
  {gdl::Keys::Escape, &Menu::actEscape},
  {gdl::Keys::Count, NULL},
};

t_menuInfos	menuInfos[] = {
  {MenuEnum::INTRO, MenuEnum::NONE, Menu::texBackground},
  {MenuEnum::MAIN, MenuEnum::INTRO, Menu::texBackground},
  {MenuEnum::PLAYER, MenuEnum::MAIN, Menu::texBackground},
  {MenuEnum::MAPS, MenuEnum::PLAYER, Menu::texBackground},
  {MenuEnum::OPTIONS, MenuEnum::MAIN, Menu::texBackground},
  {MenuEnum::NONE, MenuEnum::NONE, Menu::texBackground},
};

t_buttons	but[] = {
  {MenuEnum::INTRO, MenuEnum::MAIN, "Press Enter", Menu::texPressEnter, Menu::texPressEnterOver, 180, 350},
  {MenuEnum::MAIN, MenuEnum::PLAYER, "New Game", Menu::texNewGame, Menu::texNewGameOver, 27, 360},
  {MenuEnum::MAIN, MenuEnum::LOADGAME, "Load Game", Menu::texLoadGame, Menu::texLoadGameOver, 27, 322},
  {MenuEnum::MAIN, MenuEnum::OPTIONS, "Options", Menu::texOptions, Menu::texOptionsOver, 27, 284},
  {MenuEnum::MAIN, MenuEnum::HIGHSCORES, "High scores", Menu::texHighScores, Menu::texHighScoresOver, 27, 246},
  {MenuEnum::MAIN, MenuEnum::CREDIT, "Credits", Menu::texCredits, Menu::texCreditsOver, 27, 208},
  {MenuEnum::MAIN, MenuEnum::EXIT, "Exit", Menu::texExitGame, Menu::texExitGameOver, 27, 170},
  {MenuEnum::PLAYER, MenuEnum::PLAYER1, "One player", Menu::texOnePlayer, Menu::texOnePlayerOver, 27, 360},
  {MenuEnum::PLAYER, MenuEnum::PLAYER2, "Two players", Menu::texTwoPlayer, Menu::texTwoPlayerOver, 27, 322},
  {MenuEnum::PLAYER, MenuEnum::BACK, "Back", Menu::texBack, Menu::texBackOver, 27, 18},
  {MenuEnum::MAPS, MenuEnum::MAP1, "Map one", Menu::texOneMap, Menu::texOneMapOver, 27, 360},
  {MenuEnum::MAPS, MenuEnum::MAP2, "Map two", Menu::texTwoMap, Menu::texTwoMapOver, 27, 322},
  {MenuEnum::MAPS, MenuEnum::MAPR, "Map rand", Menu::texRandMap, Menu::texRandMapOver, 27, 284},
  {MenuEnum::OPTIONS, MenuEnum::MAIN, "Back", Menu::texBack, Menu::texBackOver, 27, 18},
  {MenuEnum::NONE, MenuEnum::NONE, "", Menu::texPressEnter, Menu::texPressEnter, 0, 0},
};

t_buttonSpec	butSpec[] = {
  {MenuEnum::EXIT, &Menu::doExit},
  {MenuEnum::PLAYER1, &Menu::doPlayOne},
  {MenuEnum::PLAYER2, &Menu::doPlayTwo},
  {MenuEnum::MAP1, &Menu::doMapOne},
  {MenuEnum::MAP2, &Menu::doMapTwo},
  {MenuEnum::MAPR, &Menu::doMapRand},
  {MenuEnum::BACK, &Menu::doBack},
  {MenuEnum::LOADGAME, &Menu::doLoadGame},
  {MenuEnum::OPTIONS, &Menu::doOptions},
  {MenuEnum::CREDIT, &Menu::doCredit},
  {MenuEnum::HIGHSCORES, &Menu::doHighScores},
  {MenuEnum::NONE, NULL},
};

Menu::Menu()
  : Bomberman(), _menuType(MenuEnum::INTRO)
{
  this->_back = NULL;
  this->_playSound = new PlaySound();
  this->_playSoundP = new PlaySound();
}

Menu::~Menu()
{
  delete this->_playSound;
  delete this->_playSoundP;
}

void		Menu::update()
{
  this->window_.catchEvent();

  for (int i = 0; listKeys[i].ptr_func != NULL; ++i)
    {
      if (this->input_.isKeyDown(listKeys[i].key))
	{
	  (this->*(listKeys[i].ptr_func))();
	}
    }
}

void		Menu::draw()
{
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->_back->draw();
  for (std::list<Button *>::iterator it = this->_listButtons.begin(); it != this->_listButtons.end(); ++it)
    (*it)->draw();
  this->window_.display();
}

void		Menu::unload()
{
  this->window_.close();
}

void		Menu::initBack(MenuEnum::eMenuType type)
{
  for (int i = 0; menuInfos[i].curMenu != MenuEnum::NONE; ++i)
    {
      if (menuInfos[i].curMenu == type)
	{
	  if (this->_back)
	    delete this->_back;
	  this->_back = new Primitives::Rectangle(0, 0, this->_winWidth, this->_winHeight, menuInfos[i].background);
	  break ;
	}
    }
}

void		Menu::initialize()
{
  bool		select = false;


  this->_listButtons.clear();
  for (int i = 0; but[i].buttonName != ""; ++i)
    {
      if (but[i].menu == this->_menuType)
	{
	  Button	*button = new Button(but[i].buttonName, but[i].menu, but[i].menuNext, but[i].tex, but[i].texOver,but[i].posX, but[i].posY);
	  initBack(but[i].menu);
	  if (!select)
	    {
	      button->switchSelect();
	      select = true;
	    }
	  this->_listButtons.push_back(button);
	}
    }
}

void		Menu::launchMenu()
{
  this->initialize();

  Start	intro(&this->window_, &this->gameClock_, &this->input_, this->_winWidth, this->_winHeight);
  this->_playSound->playMusic("data/sounds/intro/intro.ogg");
  intro.runStart();
 this->_playSound->stopMusic();
  this->_playSound->playMusic("data/sounds/menu/menu.ogg");
  while (!this->exit)
    {
      this->update();
      // affichage de la fenetre
      if (!this->window_.isOpened())
	break ;
      this->draw();
      usleep(95000);
    }
  this->_playSound->stopMusic();
  this->unload();
}

///////////////////////////////
// Fonction associees au inputs
///////////////////////////////

void		Menu::actUp()
{
  this->_playSoundP->playSounds("data/sounds/select.wav");
  for (std::list<Button *>::iterator it = this->_listButtons.begin(); it != this->_listButtons.end(); ++it)
    {
      if ((*it)->getSelect())
	{
	  (*it)->switchSelect();
	  if (it == this->_listButtons.begin())
	    this->_listButtons.back()->switchSelect();
	  else
	    {
	      --it;
	      (*it)->switchSelect();
	    }
	  break ;
	}
    }
}

void		Menu::actDown()
{
  this->_playSoundP->playSounds("data/sounds/select.wav");
  for (std::list<Button *>::iterator it = this->_listButtons.begin(); it != this->_listButtons.end(); ++it)
    {
      if ((*it)->getSelect())
	{
	  (*it)->switchSelect();
	  ++it;
	  if (it == this->_listButtons.end())
	    {
	      this->_listButtons.front()->switchSelect();
	    }
	  else
	    (*it)->switchSelect();
	  break ;
	}
    }
}

void		Menu::actEnter()
{
  MenuEnum::eMenuType	curSelect = MenuEnum::NONE;

  this->_playSoundP->playSounds("data/sounds/enter.wav");
  for (std::list<Button *>::iterator it = this->_listButtons.begin(); it != this->_listButtons.end(); ++it)
    {
      if ((*it)->getSelect())
	{
	  if ((*it)->getTypeNext() != MenuEnum::NONE)
	    curSelect = (*it)->getTypeNext();
	  break ;
	}
    }
  if (curSelect != MenuEnum::NONE)
    {
      if (checkSpecial(curSelect))
	doSpecial(curSelect);
      else
	{
	  this->_menuType = curSelect;
	  this->initialize();
	}
    }
}

void		Menu::actEscape()
{
  MenuEnum::eMenuType	menuPrev = MenuEnum::NONE;

  for (int i = 0; menuInfos[i].curMenu != MenuEnum::NONE; ++i)
    {
      if (menuInfos[i].curMenu == this->_menuType)
	{
	  if (menuInfos[i].prevMenu != MenuEnum::NONE)
	    menuPrev = menuInfos[i].prevMenu;
	  break ;
	}
    }
  if (menuPrev != MenuEnum::NONE)
    {
      this->_menuType = menuPrev;
      this->initialize();
    }
}

///////////////////////////////////////////
// Action associees aux boutons speciaux //
///////////////////////////////////////////

bool		Menu::checkSpecial(MenuEnum::eMenuType type)
{
  for (int i = 0; butSpec[i].but != MenuEnum::NONE; ++i)
    {
      if (type == butSpec[i].but)
	return true;
    }
  return false;
}

void		Menu::doSpecial(MenuEnum::eMenuType type)
{
  for (int i = 0; butSpec[i].but != MenuEnum::NONE; ++i)
    {
      if (type == butSpec[i].but)
	(this->*(butSpec[i].ptr_func))();
    }
}

void		Menu::doExit()
{
  this->exit = true;
}

void		Menu::doPlayOne()
{
  this->_menuType = MenuEnum::MAPS;
  this->initialize();
  this->_nbPlayers = 1;
}

void		Menu::doPlayTwo()
{
  this->_menuType = MenuEnum::MAPS;
  this->initialize();
  this->_nbPlayers = 2;
}

void		Menu::doMapOne()
{
  NbIA		nbIA(this->_nbPlayers, &this->window_, &this->gameClock_, &this->input_, "data/map/map1.map");

  this->_playSound->stopMusic();
  nbIA.runNbIA();
  this->_camera.initialize();
 this->_menuType = MenuEnum::MAIN;
 this->initialize();
  this->_playSound->playMusic("data/sounds/menu/menu.ogg");

}

void		Menu::doMapTwo()
{
  NbIA		nbIA(this->_nbPlayers, &this->window_, &this->gameClock_, &this->input_, "data/map/map2.map");

  this->_playSound->stopMusic();
  nbIA.runNbIA();
  this->_camera.initialize();
  this->_menuType = MenuEnum::MAIN;
  this->initialize();
  this->_playSound->playMusic("data/sounds/menu/menu.ogg");

}

void		Menu::doMapRand()
{
  MapSize       mapSize(this->_nbPlayers, &this->window_, &this->gameClock_, &this->input_);

  this->_playSound->stopMusic();
  mapSize.runMapSize();
  this->_camera.initialize();
  this->_menuType = MenuEnum::MAIN;
  this->initialize();
  this->_playSound->playMusic("data/sounds/menu/menu.ogg");

}

void		Menu::doBack()
{
  Menu::actEscape();
}

void		Menu::doLoadGame()
{
  LoadGame	lg(&this->window_, &this->gameClock_, &this->input_);

  this->_playSound->stopMusic();
  lg.runLoadGame();
  this->_camera.initialize();
  this->_menuType = MenuEnum::MAIN;
  this->initialize();
 this->_playSound->playMusic("data/sounds/menu/menu.ogg");
}

void		Menu::doOptions()
{
  Options	options(&this->window_, &this->gameClock_, &this->input_, this->_winWidth, this->_winHeight);

  this->_menuType = MenuEnum::MAIN;
  this->initialize();

  options.runOptions();
}

void		Menu::doCredit()
{
  Credit	credit(&this->window_, &this->gameClock_, &this->input_, this->_winWidth, this->_winHeight);

  this->_menuType = MenuEnum::MAIN;
  this->initialize();
  credit.runCredit();
}

void		Menu::doHighScores()
{
  HighScores	high(&this->window_, &this->gameClock_, &this->input_, this->_back);

   high.runHighScores();
   this->_menuType = MenuEnum::MAIN;
   this->initialize();
}
