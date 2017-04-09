
#include "config.hpp"
#include "paddle.hpp"

Paddle::Paddle(int horiz_pos) {

  box.x = horiz_pos;
  box.y = 20;
  box.w = 10;
  box.h = 80;

  score = 0;

}

void Paddle::input(SDL_Event event) {

  if (event.type == SDL_KEYDOWN) {
    if (event.key.keysym.sym == SDLK_a)
      paddle_state = PaddleState::UP;   
    else if (event.key.keysym.sym == SDLK_z)
      paddle_state = PaddleState::DOWN;
  }
  else if (event.type == SDL_KEYUP) {
    if (event.key.keysym.sym == SDLK_a)
      paddle_state = PaddleState::STOP;   
    else if (event.key.keysym.sym == SDLK_z)
      paddle_state = PaddleState::STOP;
  }
}

void Paddle::update() {
  
  if (paddle_state == PaddleState::UP)
    box.y -= MOVE_DELTA; 
  else if (paddle_state == PaddleState::DOWN)
    box.y += MOVE_DELTA; 

  paddle_area_bounds();
}


void Paddle::render() {

  SDL_Rect temp_box = box;
  SDL_FillRect(SDL_GetVideoSurface(), &temp_box, SDL_MapRGB(SDL_GetVideoSurface()->format,0xFF,0xFF,0xFF));
 
  //SDL_FillRect(SDL_GetVideoSurface(), &paddle[0].box, SDL_MapRGB(SDL_GetVideoSurface()->format,0xFF,0xFF,0xFF));
  //SDL_FillRect(SDL_GetVideoSurface(), &paddle[1].box, SDL_MapRGB(SDL_GetVideoSurface()->format,0xFF,0xFF,0xFF));
}


void Paddle::paddle_area_bounds() {

  if (box.y <= MOVE_DELTA)
    box.y += MOVE_DELTA;
  else if (box.y >= Config::SCREEN_HEIGHT - 80 - MOVE_DELTA)
    box.y -= MOVE_DELTA;
}

void Paddle::scored() {
  ++score;
}

int Paddle::get_score() const {
  return score;
}

SDL_Rect Paddle::get_box() const {
  return box;
}