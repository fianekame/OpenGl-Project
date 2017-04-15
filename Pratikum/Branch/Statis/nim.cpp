
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
  glBegin(GL_POLYGON);
  glColor3f(1,0,0);
    glVertex3f (0.1,0.1,0.0);
    glVertex3f (0.19,0.1, 0.0);
    glVertex3f (0.19,0.9, 0.0);
    glVertex3f (0.1,0.9, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1,1,0);
    glVertex3f (0.23,0.1,0.0);
    glVertex3f (0.3,0.1, 0.0);
    glVertex3f (0.3,0.9, 0.0);
    glVertex3f (0.23,0.9, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1,1,0);
    glVertex3f (0.23,0.1,0.0);
    glVertex3f (0.5,0.1, 0.0);
    glVertex3f (0.5,0.17, 0.0);
    glVertex3f (0.23,0.17, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1,1,0);
    glVertex3f (0.5,0.1,0.0);
    glVertex3f (0.57,0.1, 0.0);
    glVertex3f (0.57,0.9, 0.0);
    glVertex3f (0.5,0.9, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1,1,0);
    glVertex3f (0.23,0.83,0.0);
    glVertex3f (0.5,0.83, 0.0);
    glVertex3f (0.5,0.9, 0.0);
    glVertex3f (0.23,0.9, 0.0);
  glEnd();

//delapan
glBegin(GL_POLYGON);
glColor3f(0,0,1);
  glVertex3f (0.6,0.1,0.0);
  glVertex3f (0.67,0.1, 0.0);
  glVertex3f (0.67,0.9, 0.0);
  glVertex3f (0.6,0.9, 0.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0,0,1);
  glVertex3f (0.6,0.1,0.0);
  glVertex3f (0.9,0.1, 0.0);
  glVertex3f (0.9,0.17, 0.0);
  glVertex3f (0.6,0.17, 0.0);
glEnd();
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1.0,0.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Segitiga Titik");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
