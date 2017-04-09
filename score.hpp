#ifndef SCORE_HPP
#define SCORE_HPP

#include <SDL/SDL.h>

class Paddle;

class Score {
public:

  Score();
  ~Score();

  void init();
  void update(int p1, int p2);
  void render();

private:
  SDL_Surface* numbers;
  SDL_Rect clip_score[10];
  int p1_score, p2_score;
};

#endif