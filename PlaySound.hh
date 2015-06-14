//
// PlaySound.hh for  in /home/benham_a//Desktop/rendu/bomberman/bomberman-2014-capot_r
//
// Made by camille benhamou
// Login   <benham_a@epitech.net>
//
// Started on  Sat Jun  4 11:02:52 2011 camille benhamou
// Last update Sun Jun  5 14:53:02 2011 camille benhamou
//

#ifndef		__PLAYSOUND_HH__
#define		__PLAYSOUND_HH__

#include	<iostream>
#include	<string>
#include	<SFML/Audio.hpp>

class	PlaySound
{
public:
  sf::Music Music;
  sf::Sound Sound;

public:
  PlaySound();
  ~PlaySound();

  void	playMusic(std::string Sample);
  void	playSounds(std::string Sample);
  void	stopMusic();
};

#endif
