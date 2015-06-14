//
// Menu.hh for  in /home/capot_r//tek2/cpp/proj/bomberman
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Wed May  4 10:25:40 2011 romain capot
// Last update Sun Jun  5 18:00:56 2011 camille benhamou
//

#ifndef		__MENU_HH__
#define		__MENU_HH__

#include	<iostream>
#include	<string>
#include	<list>
#include	"Bomberman.hh"
#include	"Button.hh"
#include	"MenuEnum.hh"
#include	"Play.hh"
#include	"Options.hh"
#include	"Credit.hh"
#include	"Start.hh"
#include	"HighScores.hh"
#include	"AffNb.hh"
#include	"MapSize.hh"
#include	"PlaySound.hh"
#include	"NbIA.hh"
#include	"LoadGame.hh"

class	Menu : public Bomberman
{
protected:
  MenuEnum::eMenuType	_menuType;
  int		_nbPlayers;

  std::list<Button *>	_listButtons;

  // Rectangle pour le background
  Primitives::Rectangle	*_back;

  PlaySound		*_playSound;
  PlaySound		*_playSoundP;

public:
  // Textures du menu
  static gdl::Image	texBackground;

  static gdl::Image	texPressEnter;
  static gdl::Image	texNewGame;
  static gdl::Image	texLoadGame;
  static gdl::Image	texOptions;
  static gdl::Image	texCredits;
  static gdl::Image	texHighScores;
  static gdl::Image	texExitGame;
  static gdl::Image	texOnePlayer;
  static gdl::Image	texTwoPlayer;
  static gdl::Image	texOneMap;
  static gdl::Image	texTwoMap;
  static gdl::Image	texRandMap;
  static gdl::Image	texBack;

  static gdl::Image	texPressEnterOver;
  static gdl::Image	texNewGameOver;
  static gdl::Image	texLoadGameOver;
  static gdl::Image	texOptionsOver;
  static gdl::Image	texCreditsOver;
  static gdl::Image	texHighScoresOver;
  static gdl::Image	texExitGameOver;
  static gdl::Image	texOnePlayerOver;
  static gdl::Image	texTwoPlayerOver;
  static gdl::Image	texOneMapOver;
  static gdl::Image	texTwoMapOver;
  static gdl::Image	texRandMapOver;
  static gdl::Image	texBackOver;

public:
  Menu();
  ~Menu();

  void		launchMenu();

  void	initialize(void);
  void	update(void);
  void	draw(void);
  void	unload(void);

  // Fonction associer aux input
  void		actUp();
  void		actDown();
  void		actEnter();
  void		actEscape();

  // Fonction associer au boutons speciaux

  bool		checkSpecial(MenuEnum::eMenuType);
  void		doSpecial(MenuEnum::eMenuType);
  void		doExit();
  void		doPlayOne();
  void		doPlayTwo();
  void		doMapOne();
  void		doMapTwo();
  void		doMapRand();
  void		doBack();
  void		doLoadGame();
  void		doOptions();
  void		doCredit();
  void		doHighScores();

private:
  void		initBack(MenuEnum::eMenuType);
  void		updateMenu();
  void		drawMenu();
};

typedef struct	s_keys
{
  gdl::Keys::Key	key;
  void		(Menu::*ptr_func)(void);
}		t_keys;

typedef struct	s_menuInfos
{
  MenuEnum::eMenuType	curMenu;
  MenuEnum::eMenuType	prevMenu;
  gdl::Image		background;
}		t_menuInfos;

typedef struct	s_buttons
{
  MenuEnum::eMenuType	menu;
  MenuEnum::eMenuType	menuNext;
  std::string		buttonName;
  gdl::Image		tex;
  gdl::Image		texOver;
  float			posX;
  float			posY;
}		t_buttons;

typedef struct	s_buttonSpec
{
  MenuEnum::eMenuType	but;
  void		(Menu::*ptr_func)(void);
}		t_buttonSpec;

#endif
