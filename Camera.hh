//
// Camera.hh for  in /home/capot_r//tek2/cpp/proj/bomberman
// 
// Made by romain capot
// Login   <capot_r@epitech.net>
// 
// Started on  Mon May  2 13:45:45 2011 romain capot
// Last update Sat Jun  4 13:33:27 2011 romain capot
//

#include	"GL/gl.h"
#include	"GL/glu.h"
#include	"GameClock.hpp"
#include	"Input.hpp"
#include	"Vector3.hpp"

#ifndef		__CAMERA_HH__
#define		__CAMERA_HH__

class	Camera
{
protected:
  Vector3<float>	_position;
  Vector3<float>	_rotation;
public:
  Camera(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &);
};

class		CameraGame
{
protected:
  Vector3<float>	_position;
  Vector3<float>	_rotation;
public:
  CameraGame(void);
  void		initialize(void);
  void		updateCameraGame(int, int, int, int, int);
};

#endif
