#include <iostream>
//#include <unistd.h>
//#include <time.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int xPlayer=7,yPlayer=16;
int xnim;
int ynim;
int xk;
int yk;
int temp; //temporary untuk menyimpan nilai x+2nya
int walk; //8x8-1
int wall = 1; //dindding
int road = 0; //jalan
int map [17][17]; //8x8+1 0-16

void cetak()
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


}
void changeTemp()
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (map[i][j] == temp)
            {
                map[i][j] = map[xk][yk];
            }
        }
    }
}
void Nim() {
  glBegin(GL_POLYGON);
  glColor3f(1,0,0);
    glVertex3f (0.1+xnim,0.1+ynim,0.0);
    glVertex3f (0.18+xnim,0.1+ynim, 0.0);
    glVertex3f (0.18+xnim,0.9+ynim, 0.0);
    glVertex3f (0.1+xnim,0.9+ynim, 0.0);
  glEnd();

  glBegin(GL_POLYGON);
  //glColor3f(0,1,1);
    glVertex3f (0.21+xnim,0.1+ynim,0.0);
    glVertex3f (0.3+xnim,0.1+ynim, 0.0);
    glVertex3f (0.3+xnim,0.9+ynim, 0.0);
    glVertex3f (0.21+xnim,0.9+ynim, 0.0);
  glEnd();

	glBegin(GL_POLYGON);
    glVertex3f (0.3+xnim,0.1+ynim,0.0);
    glVertex3f (0.45+xnim,0.1+ynim, 0.0);
    glVertex3f (0.45+xnim,0.19+ynim, 0.0);
    glVertex3f (0.3+xnim,0.19+ynim, 0.0);
  glEnd();

	glBegin(GL_POLYGON);
    glVertex3f (0.45+xnim,0.1+ynim,0.0);
    glVertex3f (0.54+xnim,0.1+ynim, 0.0);
    glVertex3f (0.54+xnim,0.9+ynim, 0.0);
    glVertex3f (0.45+xnim,0.9+ynim, 0.0);
  glEnd();

	glBegin(GL_POLYGON);
		glVertex3f (0.3+xnim,0.81+ynim,0.0);
		glVertex3f (0.45+xnim,0.81+ynim, 0.0);
		glVertex3f (0.45+xnim,0.9+ynim, 0.0);
		glVertex3f (0.3+xnim,0.9+ynim, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
  //glColor3f(1,1,0);
		glVertex3f (0.57+xnim,0.1+ynim,0.0);
		glVertex3f (0.66+xnim,0.1+ynim, 0.0);
		glVertex3f (0.66+xnim,0.9+ynim, 0.0);
		glVertex3f (0.57+xnim,0.9+ynim, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f (0.57+xnim,0.1+ynim,0.0);
		glVertex3f (0.82+xnim,0.1+ynim, 0.0);
		glVertex3f (0.82+xnim,0.19+ynim, 0.0);
		glVertex3f (0.57+xnim,0.19+ynim, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
    glVertex3f (0.82+xnim,0.1+ynim,0.0);
    glVertex3f (0.91+xnim,0.1+ynim, 0.0);
    glVertex3f (0.91+xnim,0.9+ynim, 0.0);
    glVertex3f (0.82+xnim,0.9+ynim, 0.0);
  glEnd();

	glBegin(GL_POLYGON);
		glVertex3f (0.66+xnim,0.81+ynim,0.0);
		glVertex3f (0.91+xnim,0.81+ynim, 0.0);
		glVertex3f (0.91+xnim,0.9+ynim, 0.0);
		glVertex3f (0.66+xnim,0.9+ynim, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f (0.66+xnim,0.46+ynim,0.0);
		glVertex3f (0.91+xnim,0.46+ynim, 0.0);
		glVertex3f (0.91+xnim,0.55+ynim, 0.0);
		glVertex3f (0.66+xnim,0.55+ynim, 0.0);
	glEnd();
}

void Player()
{
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex3f (xPlayer,yPlayer,0.0);
    glVertex3f (xPlayer+1,yPlayer, 0.0);
    glVertex3f (xPlayer+1,yPlayer+1, 0.0);
    glVertex3f (xPlayer,yPlayer+1, 0.0);
    glEnd();
}

void makeWay()
{
    int arah = (rand() % 4);
    switch (arah)
    {
    case 0:
        if (xk+2 <= 15)
        {
            if (map[xk+2][yk] != map[xk][yk])
            {
                map[xk+1][yk] = road;
                temp = map[xk+2][yk];
                changeTemp();
                walk--;
            }
        }
        else
        {
            makeWay();
        }
        break;
    case 1:
        if (yk+2 <= 15)
        {
            if (map[xk][yk+2] != map[xk][yk])
            {
                map[xk][yk+1] = road;
                temp = map[xk][yk+2];
                changeTemp();
                walk--;
            }
        }
        else
        {
            makeWay();
        }
        break;
    case 2:
        if (xk-2 >= 0)
        {
            if (map[xk-2][yk] != map[xk][yk])
            {
                map[xk-1][yk] = road;
                temp = map[xk-2][yk];
                changeTemp();
                walk--;
            }
        }
        else
        {
            makeWay();
        }
        break;
    case 3:
        if (yk-2 >= 0)
        {
            if (map[xk][yk-2] != map[xk][yk])
            {
                map[xk][yk-1] = road;
                temp = map[xk][yk-2];
                changeTemp();
                walk--;
            }
        }
        else
        {
            makeWay();
        }
        break;
    }

}


void generateMaze()
{
    walk = 63;
    int x = 2;
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (i % 2 == 0 || j % 2 == 0)
            {
                map[i][j] = wall;
            }
            else
            {
                map[i][j] = x;
                x++;
            }
        }
    }
    cetak();
    while (walk != 0)
    {
        xk = (rand() % 8+1)*2-1;
        yk = (rand() % 8+1)*2-1;
        makeWay();
    }
    map[0][9] = road;
    map[16][7] = road;
    cetak();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
  for (int i = 0; i < 17; i++)
  {
      for (int j = 0; j < 17; j++)
      {
          if (map[i][j]==1)
          {
              glBegin(GL_POLYGON);
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

void input(unsigned char key, int x, int y)
{
    if (key=='c' || key=='C')
    {
        generateMaze();
        xPlayer=7;yPlayer=16;
        xnim = (rand() % 8)*2+1;ynim = (rand() % 8)*2+1;
    }
    if ((key=='s' || key=='S') && yPlayer > 0 && map[yPlayer-1][xPlayer] != wall)
    {
      yPlayer-=1;
    }
    if ((key=='a' || key=='A') && map[yPlayer][xPlayer-1] != wall)
    {
      xPlayer-=1;
    }
    if ((key=='d' || key=='D') && map[yPlayer][xPlayer+1] != wall)
    {
      xPlayer+=1;
    }
    if ((key=='w' || key=='W') && yPlayer < 16 && map[yPlayer+1][xPlayer] != wall)
    {
      yPlayer+=1;
    }
    display();
    //Kondisi Menang
    // if (xPlayer == 9 && yPlayer == 0) {
    //   sleep(3);
    //   input('c',0,0);
    //   display();
    // }

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
	glutCreateWindow("Maze 8x8 Dinamis");
	glutDisplayFunc(display);
  glutKeyboardFunc(input);
  generateMaze();
  xnim = (rand() % 8)*2+1;
  ynim = (rand() % 8)*2+1;
	myinit();
	glutMainLoop();

	return 0;
}
