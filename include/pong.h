#include <GL/gl.h>

#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#ifndef PONG_H
#define PONG_H

class Pong {
	public:
		class GLUT;
		class Ball;
		class Paddle;

		static constexpr GLfloat twicePi = M_PI * 2;
};

#endif
