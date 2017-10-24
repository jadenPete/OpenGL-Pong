#include <algorithm>
#include <math.h>

#include <GL/glut.h>

#include "glut.h"
#include "ball.h"
#include "paddle.h"

unsigned long int Bouncer::GLUT::exec_time = 0;
bool Bouncer::GLUT::key_states[2] = {false, false};

void Bouncer::GLUT::display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	Ball::draw();
	Paddle::draw();

	glutSwapBuffers();
}

void Bouncer::GLUT::specialDown(int key, int x, int y){
	(void) x;
	(void) y;

	switch(key){
		case GLUT_KEY_UP: key_states[0] = true; break;
		case GLUT_KEY_DOWN: key_states[1] = true;
	}
}

void Bouncer::GLUT::specialUp(int key, int x, int y){
	(void) x;
	(void) y;

	switch(key){
		case GLUT_KEY_UP: key_states[0] = false; break;
		case GLUT_KEY_DOWN: key_states[1] = false;
	}
}

void Bouncer::GLUT::timer(int value){
	(void) value;

	if(exec_time - Ball::last_move >= Ball::interval){
		Ball::move();
	}

	if(exec_time - Paddle::last_move >= Paddle::interval){
		Paddle::move();
	}

	glutPostRedisplay();

	exec_time += interval;
	glutTimerFunc(interval, timer, 0);
}
