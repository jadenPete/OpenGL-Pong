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

	// Float values are weird and sometimes simply comparing doesn't
	// work here. So, I put this instead. Even though it goes over at
	// 7 decimal places in, I only included five, which should take care
	// of any screen combination less than 100,000 pixels tall.
	if(GLUT::key_states[1] && -1.0f + height - (y - y_delta) < 0.00001f){
		y -= y_delta;
	}

	last_move = GLUT::exec_time;
}
