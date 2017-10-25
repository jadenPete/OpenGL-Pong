#include <GL/gl.h>

#include "pong.h"

#ifndef PONG_GLUT_H
#define PONG_GLUT_H

class Pong::GLUT {
	public:
		static void display();
		static void specialDown(int key, int x, int y);
		static void specialUp(int key, int x, int y);
		static void timer(int value);

		static constexpr int window_width = 600;
		static constexpr int window_height = 600;
		static constexpr const char* window_title = "Pong by Jaden Peterson";

		static constexpr GLfloat pixel_width = 1.0f / (window_width / 2);
		static constexpr GLfloat pixel_height = 1.0f / (window_height / 2);

		static constexpr unsigned int interval = 20;
		static unsigned long int exec_time;
		static bool key_states[2];
};

#endif
