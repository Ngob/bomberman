//
// mod.cpp for  in /home/capot_r//tek2/cpp/proj/bomberman-2014-capot_r
//
// Made by romain capot
// Login   <capot_r@epitech.net>
//
// Started on  Tue May 24 09:43:48 2011 romain capot
// Last update Sun Jun  5 18:24:15 2011 chris chaulvet
//

#include	"ModPlayer.hh"

dirChoose	chooseDir[]={
  {dir::FRONT, 0.0f},
  {dir::BACK, 180.0f},
  {dir::RIGHT, 90.0f},
  {dir::LEFT, 270.0f},
  {dir::NONE, 0.0f},
};

ModPlayer::ModPlayer(int mapX, int mapY, int cubeSize, gdl::GameClock * clock)
  : _mapX(mapX), _mapY(mapY), _cubeSize(cubeSize), clock_(clock)
{
  this->model_ = gdl::Model::load("data/models/marvin.fbx");
  this->initialize();
}

void ModPlayer::initialize()
{
  this->model_.cut_animation(this->model_, "Take 001", 25, 65, "Run");
  this->model_.cut_animation(this->model_, "Take 001", 0, 80, "Stop");
  this->model_.set_anim_speed("Walk", 0.8);
  this->model_.set_anim_speed("Run", 1.8);
}

void ModPlayer::update()
{
  this->model_.update(*clock_);
  this->playAnim();
}

void ModPlayer::playAnim()
{
  this->model_.play("Run");
}

void ModPlayer::stopAnim()
{
  this->model_.stop_animation("Run");
}

void ModPlayer::draw(int blockX, int blockY, dir::eDir dir)
{
  glPushMatrix();
  gdl::Model::Begin();
  this->setPos(blockX, blockY);
  this->setDir(dir);
  glScalef(0.07, 0.07, 0.07);
  this->model_.draw();
  gdl::Model::End();
  glPopMatrix();
}

void	ModPlayer::setPos(int blockX, int blockY)
{
  int	x, y;

  x = (this->_mapX * -1 * (this->_cubeSize / 2)) + 10;
  y = (this->_mapY * -1 * (this->_cubeSize / 2)) + 10;

  x += (blockX * this->_cubeSize);
  y += (blockY * this->_cubeSize);
  glTranslatef(x, 0, y);
}

void	ModPlayer::setDir(dir::eDir dir)
{
  float	rot;

  for (int i = 0; chooseDir[i].dirType != dir::NONE; ++i)
    {
      if (chooseDir[i].dirType == dir)
	{
	  rot = chooseDir[i].rot;
	  break ;
	}
    }
  glRotatef(rot, 0, 1, 0);
}

void ModPlayer::setColor(const int r, const int g,
			  const int b, const int a)
{
  gdl::Color		c(r, g, b, a);
  this->model_.set_default_model_color(c);
}
