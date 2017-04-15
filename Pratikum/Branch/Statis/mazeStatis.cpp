#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <time.h>
//[y][x]
bool cek = true;
int xPlayer=7,yPlayer=16;
int mazeFormat [17][17];
int mazeFormat1 [17][17] = {
                            {1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
                            {1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1},
                            {1,0,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1},
                            {1,1,1,1,0,1,1,0,0,0,1,0,0,0,0,0,1},
                            {1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1},
                            {1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1},
                            {1,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1},
                            {1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
                            {1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
                            {1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,1},
                            {1,0,0,0,0,0,1,0,1,1,0,1,1,0,1,0,1},
                            {1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1},
                            {1,0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,1},
                            {1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
                            {1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1},
                            {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                            {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1}
                          };

int mazeFormat2 [17][17] = {
                            {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                            {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                            {1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1},
                            {1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
                            {1,0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,1},
                            {1,1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1},
                            {1,0,0,0,0,0,1,0,1,1,0,1,1,0,1,0,1},
                            {1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,1},
                            {1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
                            {1,1,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1},
                            {1,0,0,0,1,0,1,1,1,0,1,1,0,1,1,0,1},
                            {1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1},
                            {1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,0,1},
                            {1,1,1,1,0,1,1,0,0,0,1,0,0,0,0,0,1},
                            {1,0,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1},
                            {1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1},
                            {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1}
                          };


void changeformat(int num){
    for (int i = 0; i < 17; i++) {
      for (int j = 0; j < 17; j++) {
        if (num == 1) {
          mazeFormat[i][j] = mazeFormat1[i][j];
        }
        else{
          mazeFormat[i][j] = mazeFormat2[i][j];
        }
      }
    }
}

void Player(){
  glBegin(GL_POLYGON);
  //x,y
  glColor3f(1,0,0);
    glVertex3f (xPlayer,yPlayer,0.0);
    glVertex3f (xPlayer+1,yPlayer, 0.0);
    glVertex3f (xPlayer+1,yPlayer+1, 0.0);
    glVertex3f (xPlayer,yPlayer+1, 0.0);
  glEnd();
}

void display(){
  fprintf(stderr, "hello"); 
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
  if (cek == true) {
    changeformat(1);
  }
  else{
    changeformat(2);
  }
  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < 17; j++) {
      if (mazeFormat[i][j]==1) {
        glBegin(GL_POLYGON);
        //x,y
          glColor3f(0,0,1);
          glVertex3f (j,i,0.0);
          glVertex3f (j+1,i, 0.0);
          glVertex3f (j+1,i+1, 0.0);
          glVertex3f (j,i+1, 0.0);
        glEnd();
      }
    }
  }
  Player();
	glFlush();
}


void input(unsigned char key, int x, int y) {
  if (key=='c' || key=='C') {
    if (cek == false) {
      cek = true;
    }
    else{
      cek=false;
    }
    xPlayer=7;
    yPlayer=16;
  }
  if (key=='s' || key=='S') {
    yPlayer-=1;
  }
  if (key=='a' || key=='A') {
    xPlayer-=1;
  }
  if (key=='d' || key=='D') {
    xPlayer+=1;
  }
  if (key=='w' || key=='W') {
    yPlayer+=1;
  }
  display();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,19.0,-2.0,19.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("STATIS MAZE DEMO");
	glutDisplayFunc(display);
  glutKeyboardFunc(input);
	myinit();
	glutMainLoop();
	return 0;
}
