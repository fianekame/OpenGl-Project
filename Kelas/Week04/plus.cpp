
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//glPointSize(4);
  glLineWidth(2);
  //glRectf(-1.5,-0.5,1.5,0.5);
  //kiri bawah kanan atas
  glColor3f(0.8,0.1,0.8);
  glRectf(-0.3,0.6,0.3,1.2);
  glRectf(-0.3,-1.2,0.3,-0.6);

  //kirba kirtas kantas kanba
  glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f (-1.5, -0.5, 0.0);
    glColor3f(0,1,0);
    glVertex3f (-1.5, 0.5, 0.0);
    glColor3f(0,1,1);
    glVertex3f (1.5, 0.5, 0.0);
    glColor3f(1,0,1);
    glVertex3f (1.5, -0.5, 0.0);
  glEnd();

  //rumah
  /*glBegin(GL_LINE_LOOP);
    glVertex3f (1, 1.0, 0.0);
    glVertex3f (1, 5, 0.0);
    glVertex3f (3, 8, 0.0);
    glVertex3f (5, 5, 0.0);
    glVertex3f (5, 1, 0.0);
  glEnd();

  glRectf(2,1,3,4);
  glRectf(3.5,4,4.5,5);*/

	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  //kiri kanan bawah atas
	gluOrtho2D(-2.0,2.0,-2.0,2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Week 04");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
