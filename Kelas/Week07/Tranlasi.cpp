
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
	glPointSize(4);
  glLineWidth(1);
  glColor3f(0,0,1);
	glBegin(GL_LINES);
  glVertex3f(-10,0,0.0);
  glVertex3f(10,0,0.0);
  glVertex3f(0,10,0.0);
  glVertex3f(0,-10,0.0);
  glEnd();

  //glTranslatef(-4.0,4.0,0.0);
  //glScalef(x,y,1);
  //glRotatef(80,0,0,1);
  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(-1.0,-1.0);
  glVertex2f(1.0,-1.0);
  glVertex2f(1.0,1.0);
  glVertex2f(-1.0,1.0);
  glEnd();

  glScalef(2,2,1);
  glTranslatef(2.0,2,0.0);
  glRotatef(45,0,0,1);
  glColor3f(0,0,1);
  glBegin(GL_POLYGON);
  glVertex2f(-1.0,-1.0);
  glVertex2f(1.0,-1.0);
  glVertex2f(1.0,1.0);
  glVertex2f(-1.0,1.0);
  glEnd();

	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10,-10.0,10.0);
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
