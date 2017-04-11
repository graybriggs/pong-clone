#define WINDOWS 0

#include <memory>

#include "ball.hpp"
#include "config.hpp"
#include "game.hpp"
#include "paddle_players.hpp"
#include "score.hpp"


Game::Game() {

  init();
  init_assets();

}

Game::~Game() {}

void Game::init() {

  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Pong",NULL);

  // SDL_SetVideoMode surface is explicitly freed by SDL_Quit and as
  // per documentation a smart pointer should not be used here.
  screen = SDL_SetVideoMode(Config::SCREEN_WIDTH,
                             Config::SCREEN_HEIGHT,
                             Config::BPP,
                             SDL_SWSURFACE);

  srand((unsigned)time(NULL));

  done = false;
}

void Game::shutdown() {
  SDL_Quit();
}

void Game::init_assets() {
  
  paddle1.reset(new PaddlePlayerOne(20));
  paddle2.reset(new PaddlePlayerTwo(1180));

  ball.reset(new Ball);
  score.reset(new Score);
}

void Game::run() {

  int pScore;
  int input[2]; 
  
  while (!done) {
    timer = SDL_GetTicks();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = true;
      }
    }

    paddle1->input(event);

    /*
    if ((pScore = scored(&ball)) > 0) {
      update_scores(pScore, paddle);
    }
    
    for (int i = 0; i < 2; i++) {
      if (paddle_hit(ball,paddle[i])) {
        switch_ball_angle(&ball, calculate_hit_point(&paddle[i],&ball));
        change_x_direction(&ball);
      }
    }
    */

    ball->update(1);

    paddle1->update(1);
    paddle2->update(1);

    render_game_area();
    ball->render();

    paddle1->render();
    paddle2->render();

    score->render();
    
    SDL_Flip(SDL_GetVideoSurface());

    wait_until_frame_end();
  }
}



void Game::render_game_area() {

  // render central dividing line
  SDL_Rect dividingLine = { Config::SCREEN_WIDTH / 2 - 3, 0, 6, Config::SCREEN_HEIGHT };
  SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format,0x00,0x00,0x00));
  SDL_FillRect(SDL_GetVideoSurface(), &dividingLine, SDL_MapRGB(SDL_GetVideoSurface()->format,0xFF,0xFF,0xFF));
}


void Game::wait_until_frame_end() {

  int delayTime;

  if((SDL_GetTicks() - timer) < (1000 / 60)) {
    delayTime = (1000/60) - (SDL_GetTicks() - timer);
    SDL_Delay(delayTime);
  //fprintf(stdout,"Delay time: %d\n",delayTime);
    }
}