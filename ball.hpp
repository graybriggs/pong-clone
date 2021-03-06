#ifndef BALL_HPP
#define BALL_HPP


#include "SDL/SDL.h"


constexpr double PI = 3.14159265;

class PaddleBase;

class Ball {
public:
  Ball();

  int initial_firing_angle();
  void reset_ball();
  void change_x_direction();
  void change_y_direction();
  bool paddle_hit(const PaddleBase& paddle);
  bool check_collision(SDL_Rect one, SDL_Rect two);
  void ball_screen_collision();
  int scored();
  int screen_y_collision();
  int screen_x_collision();
  void update(double delta);

  int calculate_hit_point(const PaddleBase& paddle);
  void switch_ball_angle(int value);

  double calculate_x_velocity(int angle);
  double calculate_y_velocity(int angle);

  void render();

private:

  SDL_Rect box;
  double x,y;
  double xVel;
  double yVel;
  int angle;
};

#endif