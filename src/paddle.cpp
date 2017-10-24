#include <GL/gl.h>

#include "glut.h"
#include "paddle.h"

GLfloat Pong::Paddle::y = 1.0f;
GLfloat Pong::Paddle::y_delta = GLUT::pixel_width * 10;

unsigned long int Pong::Paddle::last_move = 0;

void Pong::Paddle::draw(){
	glBegin(GL_QUADS);
		glVertex2f(-1.0f + width, y);
		glVertex2f(-1.0f, y);
		glVertex2f(-1.0f, y - height);
		glVertex2f(-1.0f + width, y - height);
	glEnd();
}

void Pong::Paddle::move(){
	if(GLUT::key_states[0] && y + y_delta <= 1.0f){
		y += y_delta;
	}

	if(GLUT::key_states[1] && y - y_delta >= -1.0f + height){
		y -= y_delta;
	}

	last_move = GLUT::exec_time;
}
