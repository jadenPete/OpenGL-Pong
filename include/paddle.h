#include <GL/gl.h>

#include "bouncer.h"

#ifndef BOUNCER_PADDLE_H
#define BOUNCER_PADDLE_H

class Bouncer::Paddle {
	public:
		static void draw();
		static void move();

		static constexpr GLfloat width = 0.08f;
		static constexpr GLfloat height = 0.4f;

		static GLfloat y;
		static GLfloat y_delta;

		static constexpr int max_angle = 45;

		// interval must be a multiple of GLUT::interval
		static unsigned long int last_move;
		static constexpr unsigned int interval = 5;
};

#endif
