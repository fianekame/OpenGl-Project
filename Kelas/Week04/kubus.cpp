
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(5);
	//glPointSize(4);
  //glRectf(-1.5,-0.5,1.5,0.5);
  //kiri bawah kanan atas

  glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glVertex3f (0, 0, 0.0);
    glVertex3f (5, 0, 0.0);
    glVertex3f (7, 2, 0.0);
    glVertex3f (7, 7, 0.0);
    glVertex3f (2, 7, 0.0);
    glVertex3f (0, 5, 0.0);
  glEnd();

  glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f (0, 5, 0.0);
    glVertex3f (5, 5, 0.0);
    glVertex3f (7, 7, 0.0);
    glVertex3f (5, 5, 0.0);
    glVertex3f (0, 5, 0.0);
    glVertex3f (5, 5, 0.0);
  glEnd();

  glColor3f(0,0,1);
  glRectf(0,0,5,5);
  glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex3f (0, 5, 0.0);
    glVertex3f (5, 5, 0.0);
    glVertex3f (7, 7, 0.0);
    glVertex3f (2, 7, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex3f (5, 0, 0.0);
    glVertex3f (7, 2, 0.0);
    glVertex3f (7, 7, 0.0);
    glVertex3f (5, 5, 0.0);
  glEnd();
  //kirba kirtas kantas kanba
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  //kiri kanan bawah atas
	gluOrtho2D(-2.0,10.0,-2.0,10.0);
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
