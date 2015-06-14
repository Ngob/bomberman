//
// APlay.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Tue May 24 10:25:48 2011 romain capot
// Last update Tue May 24 11:01:15 2011 romain capot
//

#include	"APlay.hh"

APlay::APlay(gdl::Window * win, gdl::GameClock * clock, gdl::Input * in)
  : _exit(false), _win(win), _clock(clock), _in(in)
{
}

APlay::~APlay()
{
}
