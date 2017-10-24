#include <GL/gl.h>

#include <math.h>

#ifndef BOUNCER_H
#define BOUNCER_H

class Bouncer {
	public:
		class GLUT;
		class Ball;
		class Paddle;

		static constexpr GLfloat twicePi = 2.0f * M_PI;
};

#endif
