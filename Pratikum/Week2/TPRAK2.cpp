
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
float t = 0.0;

void makeLine(float size,float increament){
  glPointSize(3);
  glColor3f(0,0,1);
  glBegin(GL_POINTS);
  for(float x= -size; x<=size; x+=increament){
      glVertex2f(x,0.0);
      glVertex2f(0.0,x);
  }
  glEnd();
}

void nomer1(){
  glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(3);
  makeLine(10.0,0.5);
  //x(t): -0.8 + 1.6t; y(t) = -1 + 2t.
  glBegin(GL_LINE_STRIP);
  glColor3f(1,0,0);
  for(t = -10.0; t<=10.0; t+=0.1){
      glVertex3f (-0.8+1.6*t, -1+2*t,0.0);
  }
  glEnd();
}

void nomer2() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(3);
  //rubah ortho menjadi 1(all) untuk lebih detail
  makeLine(1.0,0.01);
  glColor3f(1,0,0);
  glBegin(GL_POINTS);
  for(t = -1.0; t<=1.0; t+=0.01){
      /* x(t) = -1 + 2t; y(t) = 0 */
      glVertex3f (-0.5+t*t*-1+1, t, 0.0);
  }
  glEnd();
}

void nomer3(){
  glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(3);
  makeLine(10.0,0.5);
  //f(x) = (x-3)(x-2)(x-1)(x)(x+1)(x+2)(x+3).
  glBegin(GL_LINE_STRIP);
  glColor3f (1,0,0);
  for(t = -10.0; t<=10.0; t+=0.1){
      glVertex3f (t,(t-3)*(t-2)*(t-1)*t*(t+1)*(t+2)*(t+3), 0.0);
  }
  glEnd();
}

void nomer4() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLineWidth(3);
  makeLine(10.0,0.5);
  float a=4,b=5,c=0.3,d=1;
  glLineWidth(2);
  glBegin(GL_LINE_STRIP);
  glColor3f (1,0,0);
  for(t=0.0; t<=6.28; t+=0.1){
    glVertex2f(t,a*sin(b*t+c)+d);
  }
  glEnd();
}
void display(){
  /*hapus comment untuk mencoba persoal. fungsi soal ada diatas fungsi display*/
  //nomer1();
  //nomer2();
  //nomer3();
  //nomer4();
  /*Khusus nomer 2 detail dapat dilihat dengna merubah ukuran ortho2dnya*/
	glFlush();
}


void input(unsigned char key, int x, int y)
{
    if (key=='a'){
      nomer1();
    }
    if (key=='s'){
      nomer2();
    }
    if (key=='d'){
      nomer3();
    }
    if (key=='f'){
      nomer4();
    }
    display();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
  //ortho2d khusu detail nomer 2
  //gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("TUGAS PRATIKUM II");
	glutDisplayFunc(display);
  glutKeyboardFunc(input);
	myinit();
	glutMainLoop();

	return 0;
}
