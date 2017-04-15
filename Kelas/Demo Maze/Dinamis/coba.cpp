#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//#include <time.h>
//[y][x]
bool cek = true;
int xPlayer=7,yPlayer=16;
int xk,yk; //variable
char kunci; //temporary untuk menyimpan nilai x+2nya
int hitung; //8x8-1
char wall = '#'; //dindding
char road = '$'; //jalan
char mazeFormat [17][17]; //8x8+1 0-16

void Player()
{
    glBegin(GL_POLYGON);
    //x,y
    glColor3f(1,0,0);
    glVertex3f (xPlayer,yPlayer,0.0);
    glVertex3f (xPlayer+1,yPlayer, 0.0);
    glVertex3f (xPlayer+1,yPlayer+1, 0.0);
    glVertex3f (xPlayer,yPlayer+1, 0.0);
    glEnd();
}

void cetak()
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            std::cout << mazeFormat[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

void rubah()
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (mazeFormat[i][j] == kunci)
            {
                mazeFormat[i][j] = mazeFormat[xk][yk];
            }
        }
    }
}

void jebol()
{
    int arah = (rand() % 4);
    switch (arah)
    {
    case 0:
        if (xk+2 <= 15)
        {
            if (mazeFormat[xk+2][yk] != mazeFormat[xk][yk])
            {
                mazeFormat[xk+1][yk] = road;
                kunci = mazeFormat[xk+2][yk];
                rubah();
                hitung--;
            }
        }
        else
        {
            jebol();
        }
        break;
    case 1:
        if (yk+2 <= 15)
        {
            if (mazeFormat[xk][yk+2] != mazeFormat[xk][yk])
            {
                mazeFormat[xk][yk+1] = road;
                kunci = mazeFormat[xk][yk+2];
                rubah();
                hitung--;
            }
        }
        else
        {
            jebol();
        }
        break;
    case 2:
        if (xk-2 >= 0)
        {
            if (mazeFormat[xk-2][yk] != mazeFormat[xk][yk])
            {
                mazeFormat[xk-1][yk] = road;
                kunci = mazeFormat[xk-2][yk];
                rubah();
                hitung--;
            }
        }
        else
        {
            jebol();
        }
        break;
    case 3:
        if (yk-2 >= 0)
        {
            if (mazeFormat[xk][yk-2] != mazeFormat[xk][yk])
            {
                mazeFormat[xk][yk-1] = road;
                kunci = mazeFormat[xk][yk-2];
                rubah();
                hitung--;
            }
        }
        else
        {
            jebol();
        }
        break;
    }

}

void generateMaze()
{
    hitung = 63;
    int rdl = 37;
    char ch = rdl;
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (i % 2 == 0 || j % 2 == 0)
            {
                mazeFormat[i][j] = wall;
            }
            else
            {
                mazeFormat[i][j] = ch;
                rdl++;
                ch = rdl;
            }
        }
    }
    cetak();
    while (hitung != 0)
    {
        //int xkor = (rand() % 8+1)*2-1;
        //int ykor = (rand() % 8+1)*2-1;
        xk = (rand() % 8+1)*2-1;
        yk = (rand() % 8+1)*2-1;
        jebol();
        //melakukan ngacak kodinat
    }
    mazeFormat[0][9] = road;
    mazeFormat[16][7] = road;
    cetak();
}

void drawMaze()
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (mazeFormat[i][j]=='#')
            {
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
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4);
    drawMaze();
    Player();
    glFlush();
}


void input(unsigned char key, int x, int y)
{
    if (key=='c' || key=='C')
    {
        generateMaze();
        xPlayer=7;
        yPlayer=16;
    }
    if (key=='s' || key=='S' && mazeFormat[16+yPlayer-1][7+xPlayer] != wall)
    {
        yPlayer-=1;

    }
    if (key=='a' || key=='A' && mazeFormat[yPlayer][xPlayer-1] != wall)
    {
        xPlayer-=1;
    }
    if (key=='d' || key=='D' && mazeFormat[yPlayer][xPlayer+1] != wall)
    {
        xPlayer+=1;
    }
    if (key=='w' || key=='W' && mazeFormat[yPlayer+1][xPlayer] != wall)
    {
        yPlayer+=1;
    }
    display();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0,19.0,-2.0,19.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[])
{
    generateMaze();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    //glutInitWindowPosition(100,100);
    glutCreateWindow("DINAMIS MAZE DEMO");
    glutDisplayFunc(display);
    glutKeyboardFunc(input);
    myinit();
    glutMainLoop();
    return 0;
}
