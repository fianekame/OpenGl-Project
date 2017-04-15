
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

bool cek = true;
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(5);
	glBegin(GL_POLYGON);
    glVertex3f (0.0,9,0.0);
    glVertex3f (-3.0,2.5,0.0);
    glVertex3f (-9.0,2.5,0.0);
    glVertex3f (-4.5,-1,0.0);
    glVertex3f (-7.5,-8,0.0);
    glVertex3f (0.0,-3,0.0);
    glVertex3f (7.5,-8,0.0);
    glVertex3f (4.5,-1,0.0);
    glVertex3f (9.0,2.5,0.0);
    glVertex3f (3.0,2.5,0.0);
	glEnd();
	glFlush();
}

void input(unsigned char key, int x, int y) {
	if (key=='c') {
		if (cek) {
			glColor3f(0,1,0);
			cek = false;
		}
		else{
			glColor3f(0,0,1);
			cek = true;
		}
		display();
	}
}
void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0,0,1);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Segitiga Titik");
	glutDisplayFunc(display);
	glutKeyboardFunc(input);
	myinit();
	glutMainLoop();

	return 0;
}
