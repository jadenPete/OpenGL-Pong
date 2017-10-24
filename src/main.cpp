#include <GL/glut.h>

#include "glut.h"

int main(int argc, char* argv[]){
	glutInit(&argc, argv);

	glutInitWindowSize(Bouncer::GLUT::window_width, Bouncer::GLUT::window_height);
	glutCreateWindow(Bouncer::GLUT::window_title);

	glutDisplayFunc(Bouncer::GLUT::display);
	glutSpecialFunc(Bouncer::GLUT::specialDown);
	glutSpecialUpFunc(Bouncer::GLUT::specialUp);
	glutTimerFunc(Bouncer::GLUT::interval, Bouncer::GLUT::timer, 0);

	glutMainLoop();

	return 0;
}
