
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void draw(){
    glBegin(GL_LINE_STRIP);
        glVertex3f(0.47,1.55,0.0);
        glVertex3f(0.0,3.0,0.0);
        glVertex3f(-1.08,-0.35,0.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex3f(1.12,1.55,0.0);
        glVertex3f(0.0,5.0,0.0);
        glVertex3f(-1.6,0,0.0);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);

    draw();
    for (int i = 0; i < 4; i++) {
      glRotatef(72,0,0,1);
      draw();
    }

    glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0,5.0,-5.0,6.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0,0,0,0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Star Star");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
