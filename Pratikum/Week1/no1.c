
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
  //jawaban no 3
  //penambahan glPointSize(x); dan glLineWidth(x);
  //untuk line ubah dibawah ini dengan glLineWidth(10);
	glPointSize(5);

  //nomer 1 cuma merubah type (jawaban)
  /* glBegin(GL_POINTS);
  glBegin(GL_LINE_STRIP);
  glBegin(GL_LINE_LOOP);
  glBegin(GL_LINES);
  glBegin(GL_TRIANGLES);
  glBegin(GL_TRIANGLE_FAN);
  glBegin(GL_TRIANGLE_STRIP);
  glBegin(GL_QUADS);
  glBegin(GL_QUAD_STRIP);
  glBegin(GL_POLYGON); */

  //bagian ini yang dirubah sesuai model diatas glBegin(pilihan)
  glBegin(GL_TRIANGLE_FAN);
  //nomer2 memberi warna pada tiap vertex misal glColor3f (1.0, 0.5, 1.0);
  //jawaban nomer2 adalah penambahan glColor3f(x,x,x) pada setiap vertex

    glColor3f(1,0,0);//red
    glVertex3f (0.0, 0.0, 0.0);
    glColor3f(0,0,1);//blue
    glVertex3f (0.0, 0.8, 0.0);
    //glColor3f(0,1,1);//cyan
    glVertex3f (0.8, 0.0, 0.0);
    //glColor3f(0,1,0);//green
    glVertex3f (0.0, -0.8, 0.0);
    //glColor3f(1,0,1);//magenta
    glVertex3f (-0.8, 0.0, 0.0);
  glEnd();

	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,2.0,-2.0,2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Nomer Satu");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();

	return 0;
}
