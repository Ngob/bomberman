//
// Camera.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Mon May  2 13:44:52 2011 romain capot
// Last update Sun Jun  5 17:40:20 2011 camille benhamou
//

#include	<iostream>
#include	"Camera.hh"

Camera::Camera()
  : _position(400.0f, 300.0f, 427.0f), _rotation(0.0f, 0.0f, 0.0f)
{
}

void Camera::initialize()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 0.1f, 10000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(this->_position.getX(), this->_position.getY(), this->_position.getZ(),
	    400.0f, 300.0f, 0.0f,
	    0.0f, 1.0f, 0.0f);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}
void  Camera::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void)gameClock;
  (void)input;
}

CameraGame::CameraGame()
  : _position(0.0f, 350.0f, 60.0f), _rotation(0.0f, 0.0f, 0.0f)
{
}

void CameraGame::initialize()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0f, 800.0f/600.0f, 1.0f, 10000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(this->_position.getX(), this->_position.getY(), this->_position.getZ(),
	    0.0f, 0.0f, 0.0f,
	    0.0f, 10.0f, 0.0f);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void  CameraGame::updateCameraGame(int x, int y, int mapX, int mapY, int cubeSize)
{
  int		depX, depY;

  depX = (mapX * -1 * (cubeSize / 2)) + 10;
  depY = (mapY * -1 * (cubeSize / 2)) + 10;

  depX += (x * cubeSize);
  depY += (y * cubeSize);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0f, 800.0f/600.0f, 1.0f, 10000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(depX, this->_position.getY(), this->_position.getZ() + depY,
	    depX, 0.0f, depY,
	    0.0f, 1.0f, 0.0f);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}
