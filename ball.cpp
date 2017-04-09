
#include <math.h>
#include <stdio.h>
#include <time.h>

#include "ball.hpp"
#include "config.hpp"
#include "paddle.hpp"

Ball::Ball() {

	box.x = Config::SCREEN_WIDTH / 2 - 5;
  box.y = Config::SCREEN_HEIGHT / 2 - 5;
	box.w = 8;
	box.h = 8;

  angle = initial_firing_angle();
  xVel = calculate_x_velocity(angle);
  yVel = calculate_y_velocity(angle);


  update();

}


int Ball::initial_firing_angle()
{
	unsigned int aperture = 40;
	signed int angle = (rand() % aperture + 1);  // firing angle is +25 to -25 degrees
	angle -= aperture / 2;
	if ((rand() % 2) == 0)
		angle += 180;  // make the angle to fire in player one or two direction by adding 180 degrees

	return angle;
}

void Ball::reset_ball()
{
	x = Config::SCREEN_WIDTH / 2 - 5;
	y = Config::SCREEN_HEIGHT / 2 - 5;
	angle = initial_firing_angle();  // calculate new angle
	xVel = calculate_x_velocity(angle);	// reset the x and y velocities corresponding to the new angle; cos, sin
	yVel = calculate_y_velocity(angle);
	update();
} 



void Ball::change_x_direction()
{
	xVel *= -1.0;
}

void Ball::change_y_direction()
{
	yVel *= -1.0;
}

int Ball::paddle_hit(const Paddle& paddle)
{
	if (!check_collision(box, paddle.get_box())) {
		return 1;
	}
	return 0;
}


bool Ball::check_collision(SDL_Rect one, SDL_Rect two)
{
	if (one.x + one.w < two.x) {
		return true;
	}
	else if(one.x > two.x + two.w) {
		return true;
	}
	else if(one.y + one.h < two.y) {
		return true;
	}
	else if(one.y > two.y + two.h) {
		return true;
	}
	else {
		return false;
	}
}


void Ball::ball_screen_collision()
{
	if (screen_y_collision()) {
		change_y_direction();
	}
}

int Ball::scored()
{	
	int playerScore = 0;

	if ((playerScore = screen_x_collision())) {
		reset_ball();
	}

	return playerScore;
}

int Ball::screen_y_collision()
{
	int hit = 0;

	if (box.y <= 0) {
		hit = 1;
	}
	else if (box.y + box.h >= Config::SCREEN_HEIGHT) {
		hit = 1;
	}
	else {
		hit = 0;
	}
	return hit;
}

int Ball::screen_x_collision()
{
	int hit = 0;

	if (box.x <= 0) {
		hit = 2;  // player 2 scored
	}
	else if (box.x + box.w >= Config::SCREEN_WIDTH) {
		hit = 1;  // player 1 scored
	}
	else {
		hit = 0;  // shouldn't happen
	}

	return hit;
}

void Ball::update()
{
	box.x += xVel * 6.0;  // magic speed number 6.0
	box.y += yVel * 6.0;
}

int Ball::calculate_hit_point(const Paddle& paddle)
{
	int hitPoint = (int)box.y - paddle.get_box().y;
	int r = 0;
	//fprintf(stderr,"Hitpoint: %d\n",hitPoint);
	
	if ((hitPoint >= -10 && hitPoint < 10) || (hitPoint <= 70 && hitPoint < 50)) {
		r = -1;
	}
	else if ((hitPoint >= 10 && hitPoint < 25) || (hitPoint <= 50 && hitPoint < 35)) {
		r = 0;
	}
	else if (hitPoint >= 25 && hitPoint <= 35) {
		r = 1;
	}
	return r;
}

void Ball::switch_ball_angle(int value)
{
	if (value < 0) {
		xVel = calculate_x_velocity(30);
		yVel = calculate_y_velocity(30);
	}
	else if (value == 0) {
		xVel = calculate_x_velocity(45);
		yVel = calculate_y_velocity(45);
	}
	else if (value > 0) {
		xVel = calculate_x_velocity(45);
		yVel = calculate_y_velocity(45);
	}
}


double Ball::calculate_x_velocity(int angle)
{
	return (double)(cos(angle * PI / 180));
}

double Ball::calculate_y_velocity(int angle)
{
	return (double)(sin(angle * PI / 180));
}

void Ball::render() {
	SDL_Rect temp_ball = box;
  SDL_FillRect(SDL_GetVideoSurface(), &temp_ball, SDL_MapRGB(SDL_GetVideoSurface()->format, 0xFF, 0xFF, 0xFF));
  
}
