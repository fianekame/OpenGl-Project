
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


void snow(){
    glBegin(GL_LINE_STRIP);
        glVertex3f(0.3,0.15,0.0);
        glVertex3f(3.0,0.15,0.0);
        glVertex3f(4.0,2.0,0.0);
        glVertex3f(4.5,2.0,0.0);
        glVertex3f(3.75,0.15,0.0);

        glVertex3f(5.0,0.15,0.0);
        glVertex3f(6.0,1.5,0.0);
        glVertex3f(6.5,1.5,0.0);
        glVertex3f(5.75,0.15,0.0);

        glVertex3f(7.0,0.15,0.0);
        glVertex3f(7.5,1.0,0.0);
        glVertex3f(8.0,1.0,0.0);
        glVertex3f(7.5,0.15,0.0);
        glVertex3f(9.0,0.05,0.0);
        glVertex3f(9.5,0.0,0.0);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);

    snow();
    glScalef(1,-1,1);
    snow();

    glRotatef(60,0,0,1);
    snow();
    glScalef(1,-1,1);
    snow();

    glRotatef(120,0,0,1);
    snow();
    glScalef(1,-1,1);
    snow();

    glRotatef(180,0,0,1);
    snow();
    glScalef(1,-1,1);
    snow();

    glRotatef(240,0,0,1);
    snow();
    glScalef(1,-1,1);
    snow();

    glRotatef(300,0,0,1);
    snow();
    glScalef(1,-1,1);
    snow();
    
    glFlush();
}


void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Snow Snow");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
