#include <GL/gl.h>

#include <math.h>

#ifndef PONG_H
#define PONG_H

class Pong {
	public:
		class GLUT;
		class Ball;
		class Paddle;

		static constexpr GLfloat twicePi = 2.0f * M_PI;
};

#endif
