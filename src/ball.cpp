#include <cstdlib>
#include <math.h>

#include <GL/gl.h>

#include "glut.h"
#include "ball.h"
#include "paddle.h"

GLfloat Pong::Ball::x = -1.0f + Paddle::width;
GLfloat Pong::Ball::y =  1.0f;

GLfloat Pong::Ball::x_delta =  GLUT::pixel_width * 10;
GLfloat Pong::Ball::y_delta = -GLUT::pixel_width * 10;

unsigned long int Pong::Ball::last_move = 0;

void Pong::Ball::draw(){
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x + radius, y - radius);

		for(int i = 0; i <= vertices; i++) {
			glVertex2f(x + radius + (radius * cos(i * twicePi / vertices)),
					   y - radius + (radius * sin(i * twicePi / vertices)));
		}
	glEnd();
}

void Pong::Ball::move(){
	GLfloat new_x = x + x_delta;
	GLfloat new_y = y + y_delta;

	// Check if any part of the ball is touching any part of the paddle
	if(new_x < -1.0f + Paddle::width &&
	   new_y - diameter <= Paddle::y &&
	   new_y >= Paddle::y - Paddle::height){
		GLfloat half_height = Paddle::height / 2;

		x_delta *= -1;

		if(new_y >= Paddle::y - half_height){
			GLfloat collision = new_y - (new_y > Paddle::y ? diameter : 0.0f);
			GLfloat ratio = (collision - (Paddle::y - half_height)) / half_height;

			y_delta = x_delta * tan(ratio * Paddle::max_angle * (M_PI / 180));
		} else {
			GLfloat ratio = (Paddle::y - half_height - new_y) / half_height;

			y_delta = x_delta * -tan(ratio * Paddle::max_angle * (M_PI / 180));
		}
	} else {
		if(new_x < -1.0f){
			exit(0);
		} else if(new_x > 1.0f - diameter){
			x_delta *= -1;
		}

		if(new_y < -1.0f + diameter || new_y > 1.0f) y_delta *= -1;
	}

	x += x_delta;
	y += y_delta;

	last_move = GLUT::exec_time;
}
