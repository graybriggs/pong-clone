#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SDL/SDL.h>

class Paddle {
private:
  enum class PaddleState { UP, DOWN, STOP, HIT_TOP, HIT_BOTTOM };
  const int MOVE_DELTA = 5;
public:

  Paddle(int horiz_pos);

  void input(SDL_Event event);
  void move_paddle(PaddleState pm_input);
  void update();
  void render();
  void paddle_area_bounds();
  void scored();
  int get_score() const;
  SDL_Rect get_box() const;

private:

  PaddleState paddle_state;
  SDL_Rect box;
  int score;
};


#endif