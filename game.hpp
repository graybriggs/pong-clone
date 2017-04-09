#ifndef GAME_HPP
#define GAME_HPP


#include <SDL/SDL.h>

#include "paddle.hpp"

class Ball;
class Paddle;
class Score;

class Game {
public:

  Game();
  ~Game();

  void run();

private:

  void init();
  void shutdown();
  void init_assets();
  void wait_until_frame_end();
  void render_game_area();

private:

  SDL_Surface* screen;
  int timer = 0;
  bool done;

  SDL_Event event;

  std::unique_ptr<Paddle> paddle1;
  std::unique_ptr<Paddle> paddle2;
  std::unique_ptr<Ball> ball;
  std::unique_ptr<Score> score;

};

#endif