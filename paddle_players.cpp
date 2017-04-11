
#include "paddle_base.hpp"
#include "paddle_players.hpp"

////////////// Player 1 //////////////

PaddlePlayerOne::PaddlePlayerOne(int horiz_pos) {
  box.x = horiz_pos;
  box.y = 20;
  box.w = 10;
  box.h = 80;

  score = 0;
}

PaddlePlayerOne::~PaddlePlayerOne() {}

void PaddlePlayerOne::input(SDL_Event event) {

  if (event.type == SDL_KEYDOWN) {
    if (event.key.keysym.sym == SDLK_a)
      paddle_state = PaddleBase::PaddleState::UP;   
    else if (event.key.keysym.sym == SDLK_z)
      paddle_state = PaddleBase::PaddleState::DOWN;
  }
  else if (event.type == SDL_KEYUP) {
    if (event.key.keysym.sym == SDLK_a)
      paddle_state = PaddleBase::PaddleState::STOP;   
    else if (event.key.keysym.sym == SDLK_z)
      paddle_state = PaddleBase::PaddleState::STOP;
  }
}


////////////// Player 2 //////////////

PaddlePlayerTwo::PaddlePlayerTwo(int horiz_pos) {
  box.x = horiz_pos;
  box.y = 20;
  box.w = 10;
  box.h = 80;

  score = 0;
}

PaddlePlayerTwo::~PaddlePlayerTwo() {}

void PaddlePlayerTwo::input(SDL_Event event) {

  if (event.type == SDL_KEYDOWN) {
    if (event.key.keysym.sym == SDLK_UP)
      paddle_state = PaddleBase::PaddleState::UP;   
    else if (event.key.keysym.sym == SDLK_DOWN)
      paddle_state = PaddleBase::PaddleState::DOWN;
  }
  else if (event.type == SDL_KEYUP) {
    if (event.key.keysym.sym == SDLK_UP)
      paddle_state = PaddleBase::PaddleState::STOP;   
    else if (event.key.keysym.sym == SDLK_DOWN)
      paddle_state = PaddleBase::PaddleState::STOP;
  }
}
