#include <GL/glut.h>

#include "glut.h"

int main(int argc, char* argv[]){
	glutInit(&argc, argv);

	glutInitWindowSize(Pong::GLUT::window_width, Pong::GLUT::window_height);
	glutCreateWindow(Pong::GLUT::window_title);

	glutDisplayFunc(Pong::GLUT::display);
	glutSpecialFunc(Pong::GLUT::specialDown);
	glutSpecialUpFunc(Pong::GLUT::specialUp);
	glutTimerFunc(Pong::GLUT::interval, Pong::GLUT::timer, 0);

	glutMainLoop();

	return 0;
}
