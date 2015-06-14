//
// PlaySound.cpp for  in /home/benham_a//Desktop/rendu/bomberman/bomberman-2014-capot_r
// 
// Made by camille benhamou
// Login   <benham_a@epitech.net>
// 
// Started on  Sat Jun  4 11:02:23 2011 camille benhamou
// Last update Sun Jun  5 16:47:52 2011 romain capot
//

#include	"PlaySound.hh"

PlaySound::PlaySound()
{
}

PlaySound::~PlaySound()
{
}

void		PlaySound::playMusic(std::string Sample)
{
  if (!Music.OpenFromFile(Sample))
    std::cout << "Music fail" << std::endl;

  Music.Play();
  Music.SetVolume(100.f);
  Music.SetLoop(true);
}

void		PlaySound::playSounds(std::string Sample)
{
  if (!Music.OpenFromFile(Sample))
    std::cout << "Music fail" << std::endl;

  Music.Play();
  Music.SetVolume(100.f);
}

void		PlaySound::stopMusic()
{
  Music.Stop();
}
