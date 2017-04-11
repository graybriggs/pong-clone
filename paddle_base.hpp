#ifndef PADDLEBASE_HPP
#define PADDLEBASE_HPP

#include <SDL/SDL.h>

class PaddleBase {
protected:
  enum class PaddleState { UP, DOWN, STOP, HIT_TOP, HIT_BOTTOM };
  const int MOVE_DELTA = 5;

public:

  virtual ~PaddleBase();

  virtual void input(SDL_Event event) = 0;
  //virtual void move_paddle(PaddleBaseState pm_input);
  virtual void update(double delta);
  virtual void render();
  virtual void paddle_area_bounds();
  virtual void scored();
  virtual int get_score() const;
  virtual SDL_Rect get_box() const;

protected:

  PaddleState paddle_state;
  SDL_Rect box;
  int score;
};


#endif