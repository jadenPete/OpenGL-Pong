#include <GL/gl.h>

#include "pong.h"

#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

class Pong::Paddle {
	public:
		static void draw();
		static void move();

		static constexpr GLfloat width = 0.08f;
		static constexpr GLfloat height = 0.4f;

		static GLfloat y;
		static GLfloat y_delta;

		static constexpr int max_angle = 45;

		// interval must be a multiple of GLUT::interval
        // Try to make interval less than the refresh
        // rate, e.g. 1,000 / 60 = 17, which means 60fps.
		static unsigned long int last_move;
		static constexpr unsigned int interval = 20;
};

#endif
