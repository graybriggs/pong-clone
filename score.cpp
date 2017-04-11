
#include "config.hpp"
#include "paddle_base.hpp"
#include "score.hpp"

Score::Score() {
  init();
}

Score::~Score() {
  SDL_FreeSurface(numbers);
}

void Score::init() {

    numbers = SDL_LoadBMP("pong_numbers.bmp");

    if (numbers == nullptr)
      fprintf(stderr, "Failed to load pong_numbers.bmp in score.cpp");

    for (int i = 0; i < 10; i++) {
      clip_score[i].x = i * 64;
      clip_score[i].y = 0;
      clip_score[i].w = 64;
      clip_score[i].h = 64;
    }

    p1_score = p2_score = 0;
}

void Score::update(int p1, int p2) {
 
 p1_score = p1;
 p2_score = p2;
}

void Score::render() {

  SDL_Rect clip_p1 = clip_score[p1_score];
  SDL_Rect clip_p2 = clip_score[p2_score];
  SDL_Rect playerScorePosition[2] = {{Config::SCREEN_WIDTH / 2 - 250 - 64, 100},
                                     {Config::SCREEN_WIDTH / 2 + 250, 100}};

  SDL_BlitSurface(numbers, &clip_p1, SDL_GetVideoSurface(), &playerScorePosition[0]);
  SDL_BlitSurface(numbers, &clip_p2, SDL_GetVideoSurface(), &playerScorePosition[1]);

}