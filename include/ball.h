#include <GL/gl.h>

#include "pong.h"

#ifndef PONG_BALL_H
#define PONG_BALL_H

class Pong::Ball {
	public:
		static void draw();
		static void move();

		static constexpr int vertices = 20;
		static constexpr GLfloat radius = 0.05f;
		static constexpr GLfloat diameter = 2.0f * radius;

		static GLfloat x;
		static GLfloat y;

		static GLfloat x_delta;
		static GLfloat y_delta;

		// interval must be a multiple of GLUT::interval
		static unsigned long int last_move;
		static constexpr unsigned int interval = 20;
};

#endif
