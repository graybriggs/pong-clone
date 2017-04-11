
#include <SDL/SDL.h>

#include "config.hpp"
#include "paddle_base.hpp"


PaddleBase::~PaddleBase() {}

void PaddleBase::update(double delta) {
  
  if (paddle_state == PaddleState::UP)
    box.y -= MOVE_DELTA; 
  else if (paddle_state == PaddleState::DOWN)
    box.y += MOVE_DELTA; 

  paddle_area_bounds();
}


void PaddleBase::render() {

  SDL_Rect temp_box = box;
  SDL_FillRect(SDL_GetVideoSurface(), &temp_box, SDL_MapRGB(SDL_GetVideoSurface()->format, 0xFF, 0xFF, 0xFF));
 
  //SDL_FillRect(SDL_GetVideoSurface(), &PaddleBase[0].box, SDL_MapRGB(SDL_GetVideoSurface()->format,0xFF,0xFF,0xFF));
  //SDL_FillRect(SDL_GetVideoSurface(), &PaddleBase[1].box, SDL_MapRGB(SDL_GetVideoSurface()->format,0xFF,0xFF,0xFF));
}


void PaddleBase::paddle_area_bounds() {

  if (box.y <= MOVE_DELTA)
    box.y += MOVE_DELTA;
  else if (box.y >= Config::SCREEN_HEIGHT - 80 - MOVE_DELTA)
    box.y -= MOVE_DELTA;
}

void PaddleBase::scored() {
  ++score;
}

int PaddleBase::get_score() const {
  return score;
}

SDL_Rect PaddleBase::get_box() const {
  return box;
}