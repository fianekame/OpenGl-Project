
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(1);
  glColor3f(0,0,1);
	glBegin(GL_LINES);
  glVertex3f(-10,0,0.0);
  glVertex3f(10,0,0.0);
  glVertex3f(0,10,0.0);
  glVertex3f(0,-10,0.0);
  glEnd();

	

  //semua x jadikan t
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_LINE_STRIP);
    // for (float t = -10.0; t <=10.0; t+=0.1) {
    //   //glVertex2f(t,2*t+1);
    //   glVertex2f(t,2*t*t-t+1);
    // }
    for (float t = 0.8; t < 3.75; t+=0.01) {
      //y = A.sin9
      //3=amplitudo = A
      //b =  frekuensi
      //glVertex2f(t,3*sin(3*t+0.6)+4);
			//ellipsterpotong
			glVertex2f(-1*cos(t),4*sin(t));
    }
  glEnd();


	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
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
