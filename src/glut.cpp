#include <algorithm>
#include <math.h>

#include <GL/glut.h>

#include "glut.h"
#include "ball.h"
#include "paddle.h"

unsigned long int Pong::GLUT::exec_time = 0;
bool Pong::GLUT::key_states[2] = {false, false};

void Pong::GLUT::display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);

	Ball::draw();
	Paddle::draw();

	glutSwapBuffers();
}

void Pong::GLUT::specialDown(int key, int x, int y){
	(void) x;
	(void) y;

	switch(key){
		case GLUT_KEY_UP: key_states[0] = true; break;
		case GLUT_KEY_DOWN: key_states[1] = true;
	}
}

void Pong::GLUT::specialUp(int key, int x, int y){
	(void) x;
	(void) y;

	switch(key){
		case GLUT_KEY_UP: key_states[0] = false; break;
		case GLUT_KEY_DOWN: key_states[1] = false;
	}
}

void Pong::GLUT::timer(int value){
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
