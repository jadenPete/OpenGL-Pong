#include <GL/gl.h>

#include "glut.h"
#include "paddle.h"

GLfloat Bouncer::Paddle::y = 1.0f;
GLfloat Bouncer::Paddle::y_delta = GLUT::pixel_width * 10;

unsigned long int Bouncer::Paddle::last_move = 0;

void Bouncer::Paddle::draw(){
	glBegin(GL_QUADS);
		glVertex2f(-1.0f + width, y);
		glVertex2f(-1.0f, y);
		glVertex2f(-1.0f, y - height);
		glVertex2f(-1.0f + width, y - height);
	glEnd();
}

void Bouncer::Paddle::move(){
	if(GLUT::key_states[0] && y + y_delta <= 1.0f){
		y += y_delta;
	}

	if(GLUT::key_states[1] && y - y_delta >= -1.0f + height){
		y -= y_delta;
	}

	last_move = GLUT::exec_time;
}
