
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//glLineWidth(5);
	glPointSize(5);
	glBegin(GL_POLYGON);
		glColor3f(0,0,1);
    glVertex3f (2,7,0.0);
		glVertex3f (2,4,0.0);
		glVertex3f (3.5,3,0.0);
		glVertex3f (7,4,0.0);
		glVertex3f (7,7,0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,0,0);
    glVertex3f (1.5,6.5,0.0);
		glVertex3f (1.5,3.5,0.0);
		glVertex3f (3,2.5,0.0);
		glVertex3f (6.5,3.5,0.0);
		glVertex3f (6.5,6.5,0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0,1,0);
    glVertex3f (1,6,0.0);
		glVertex3f (1,3,0.0);
		glVertex3f (2.5,2,0.0);
		glVertex3f (6,3,0.0);
		glVertex3f (6,6,0.0);
	glEnd();

	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,10.0,-2.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Stack");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
