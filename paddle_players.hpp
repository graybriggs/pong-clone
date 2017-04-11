#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "paddle_base.hpp"

class PaddlePlayerOne : public PaddleBase {
public:
  PaddlePlayerOne(int horiz_pos);
  ~PaddlePlayerOne();

  void input(SDL_Event) override;

};

class PaddlePlayerTwo : public PaddleBase {
public:
  PaddlePlayerTwo(int horiz_pos);
  ~PaddlePlayerTwo();

  void input(SDL_Event) override;
};


#endif