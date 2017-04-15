#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <time.h>
//[y][x]
bool cek = true;
int xnim = (rand() % 8)*2+1;
int ynim = (rand() % 8)*2+1;
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
void Nim() {
  srand((unsigned)time(0));
  glBegin(GL_POLYGON);
  glColor3f(1,0,0);
    glVertex3f (0.1+xnim,0.1+ynim,0.0);
    glVertex3f (0.19+xnim,0.1+ynim, 0.0);
    glVertex3f (0.19+xnim,0.9+ynim, 0.0);
    glVertex3f (0.1+xnim,0.9+ynim, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1,1,0);
    glVertex3f (0.23+xnim,0.1+ynim,0.0);
    glVertex3f (0.3+xnim,0.1+ynim, 0.0);
    glVertex3f (0.3+xnim,0.9+ynim, 0.0);
    glVertex3f (0.23+xnim,0.9+ynim, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1,1,0);
    glVertex3f (0.23+xnim,0.1+ynim,0.0);
    glVertex3f (0.5+xnim,0.1+ynim, 0.0);
    glVertex3f (0.5+xnim,0.17+ynim, 0.0);
    glVertex3f (0.23+xnim,0.17+ynim, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1,1,0);
    glVertex3f (0.5+xnim,0.1+ynim,0.0);
    glVertex3f (0.57+xnim,0.1+ynim, 0.0);
    glVertex3f (0.57+xnim,0.9+ynim, 0.0);
    glVertex3f (0.5+xnim,0.9+ynim, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1,1,0);
    glVertex3f (0.23+xnim,0.83+ynim,0.0);
    glVertex3f (0.5+xnim,0.83+ynim, 0.0);
    glVertex3f (0.5+xnim,0.9+ynim, 0.0);
    glVertex3f (0.23+xnim,0.9+ynim, 0.0);
  glEnd();

//delapan
glBegin(GL_POLYGON);
glColor3f(0,0,1);
  glVertex3f (0.6+xnim,0.1+ynim,0.0);
  glVertex3f (0.67+xnim,0.1+ynim, 0.0);
  glVertex3f (0.67+xnim,0.9+ynim, 0.0);
  glVertex3f (0.6+xnim,0.9+ynim, 0.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0,0,1);
  glVertex3f (0.6+xnim,0.1+ynim,0.0);
  glVertex3f (0.9+xnim,0.1+ynim, 0.0);
  glVertex3f (0.9+xnim,0.17+ynim, 0.0);
  glVertex3f (0.6+xnim,0.17+ynim, 0.0);
glEnd();

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
  Nim();
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
    xnim = (rand() % 8)*2+1;
    ynim = (rand() % 8)*2+1;
    Nim();
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
  srand(time(NULL));
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("STATIS MAZE DEMO");
	glutDisplayFunc(display);
  glutKeyboardFunc(input);
	myinit();
  xnim = (rand() % 8)*2+1;
  ynim = (rand() % 8)*2+1;
	glutMainLoop();

	return 0;
}
