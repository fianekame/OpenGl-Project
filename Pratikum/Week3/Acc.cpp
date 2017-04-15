
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

float t = 0.0;

void mouth() {
	//back
	glBegin(GL_POLYGON);
	glColor3f (1.0, 1.0, 1.0);
	for(t = -4.0; t<=4.0; t+=0.01){
		 glVertex3f (t*1.2,-0.5+t*t*+0.2-5.8, 0.0);
	}
	glEnd();

	//topred
	glBegin(GL_POLYGON);
	glColor3f (1.0, 0.0, 0.0);
	for(t = -4.0; t<=4.0; t+=0.01){
		 glVertex3f (t*1.07,-0.5+t*t*+0.2-6.4, 0.0);
	}
	glEnd();

	//topputih
	glBegin(GL_POLYGON);
	glColor3f (1.0, 1.0, 1.0);
	for(t = -4.0; t<=4.0; t+=0.01){
		 glVertex3f (t*0.7,-0.2+t*t*0.4*+0.2-6.7, 0.0);
	}
	glEnd();

}

void body(){
	glBegin(GL_POLYGON);
	glColor3f(0.1,0.9,0.0);

	//KIRI
	for(float t = 1.0; t>=-1.0; t-=0.01){
			glVertex3f (-0.7+t*t-7.8, t*8, 0.0);
	}

	//BAWAH
	for(float t = -8.5; t<=6.28;t+=0.01){
			glVertex2f(t+1,0.75*sin(2*t+0.8)-8.41);
	}
	//KANAN
	for(float t = 1.0; t>=-1.0; t-=0.01){
			glVertex3f ( -0.7+t*t*-1+8.9, t*8,0.0);
	}
	//ATAS
	for(float t = 1.0; t>=-1.0; t-=0.01){
			glVertex3f (t*7-0.9+0.9, 0.7+t*t*-2+9,0.0);
	}
	glEnd();

}
void ear(){
		glBegin(GL_POLYGON);//besarkiri
	  glColor3f(1,1,0);
	  glVertex2f(-9.0,5.0);\
	  glVertex2f(-4.0,7.0);
	  glVertex2f(-8.5,11.0);
	  glEnd();

		glBegin(GL_POLYGON);//besarkanan
		glColor3f(1,1,0);
		glVertex2f(9.0,5.0);
		glVertex2f(4,7);
		glVertex2f(8.5,11);
		glEnd();

	  glBegin(GL_POLYGON);//kecilkiri
	  glColor3f(0.9,0.3,0);
	  glVertex2f(-8.2,5.3);
	  glVertex2f(-4.9,6.6);
	  glVertex2f(-7.7,9.0);
	  glEnd();

	  glBegin(GL_POLYGON);//kecilkanan
	  glColor3f(0.9,0.3,0);
	  glVertex2f(8.2,5.3);
	  glVertex2f(4.9,6.6);
	  glVertex2f(7.7,9.0);
	  glEnd();

}
void eyes(){
	  glColor3f(1,1,1);
		glBegin(GL_POLYGON);
		for(float t=-5.0; t<=1.28; t+=0.01){
	        glVertex2f(cos(t)*2-2.5,sin(t)*2+3);
		}
		glEnd();

		glColor3f(1,1,1);
		glBegin(GL_POLYGON);
		for(float t=-5.0; t<=1.28; t+=0.01){
	        glVertex2f(cos(t)*2+2.5,sin(t)*2+3);
		}
		glEnd();

	  glColor3f(0,0,0);
		glBegin(GL_POLYGON);
		for(float t=-5.0; t<=1.28; t+=0.01){
	        glVertex2f(cos(t)-2.5,sin(t)+3);
		}
		glEnd();

	  glColor3f(0,0,0);
		glBegin(GL_POLYGON);
		for(float t=-5.0; t<=1.28; t+=0.01){
	        glVertex2f(cos(t)+2.5,sin(t)+3);
		}
		glEnd();

}
void nose(){
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	for(float t=-5.0; t<=1.28; t+=0.01){
        glVertex2f(cos(t),sin(t)*2-0.4);
	}
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	body();
	eyes();
	nose();
	mouth();
	ear();
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-13.0,13.0,-13.0,13.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("ACC-A");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
