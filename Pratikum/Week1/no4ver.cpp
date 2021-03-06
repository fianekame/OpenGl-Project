
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
    glEnd();
    glColor3f (1.0, 0.0, 0.0);
    glRectf (-1, -1, -0.75, 1);
    glColor3f (1.0, 0.5, 0.0);
    glRectf (-0.75, -1, -0.45 , 1);
    glColor3f (1.0, 1.0, 0.0);
    glRectf (-0.45, -1, -0.15, 1);
    glColor3f (0.0, 1.0, 0.0);
    glRectf (-0.15, -1, 0.15, 1);
    glColor3f (0.0, 0.0, 1.0);
    glRectf (0.15, -1, 0.45, 1);
    glColor3f (1.0, 0.0, 0.5);
    glRectf (0.45, -1, 0.75, 1);
    glColor3f (1.0, 0.0, 1.0);
    glRectf (0.75, -1, 1, 1);
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Glrect Vertikal");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
