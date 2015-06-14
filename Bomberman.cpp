//
// Bomberman.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Mon May  2 11:13:03 2011 romain capot
// Last update Sun Jun  5 17:50:19 2011 antoine basset
//

#include	"Bomberman.hh"

Bomberman::Bomberman()
  : exit(false)
{
  // dimensions de la fenetre
  this->_winWidth = 800;
  this->_winHeight = 600;
  window_.setWidth(this->_winWidth);
  window_.setHeight(this->_winHeight);
  window_.setTitle("Bomberman");

  //initialisation de la fenetre
  window_.create();
  if (!this->window_.isOpened())
    throw std::runtime_error("Window error");

  //initialisation de la camera
  this->_camera.initialize();
}

Bomberman::~Bomberman()
{
}
