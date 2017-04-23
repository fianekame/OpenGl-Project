
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
bool color = true;
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
  for (int i = 0; i < 8 ; i++) {
    for (int j = 0; j < 8; j++) {
        if(color){
          glColor3f(1.0,1.0,0.0);
					color=!color;
				}else{
					glColor3f(0.0,0.0,1.0);
					color=!color;
				}
				glRecti(0.0, 0.0, 2.0, 2.0);
				if (j!=7) {
					if (i%2==1) {
						glTranslatef(-2.0,0.0,0.0);
					}
					else {
						glTranslatef(2.0,0.0,0.0);
					}
				}
    }
		glTranslatef(0.0,2.0,0.0);
  }
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,16.0,0.0,16.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Checker Board");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
