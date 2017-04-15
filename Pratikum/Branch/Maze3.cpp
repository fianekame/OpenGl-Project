
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <time.h>
#include <stdlib.h>
    int m [19][19];
    int posPlayerX,posPlayerY;
    int posPintuX,moveX,moveY;
    float rotasiDisplayX,rotasiDisplayY,rotasiDisplayZ;
    float tempRotasiDisplayX,tempRotasiDisplayY;
    float rotasiNimX,rotasiNimY,rotasiNimZ,tempRotasiNimX,tempRotasiNimY ,tempRotasiNimZ,setNim;
    bool cekDisplay,cekRotasiNimX,cekRotasiNimY = true ,cekRotasiNimZ;
    void balok(float x1,float y1, float x2, float y2 , float zMin, float zPlus,float colR , float colG, float colB){
        //depan
        glColor3f(colR,colG,1);
        glBegin(GL_POLYGON);
        glVertex3f(x1,y1,zPlus);
        glVertex3f(x2,y1,zPlus);
        glVertex3f(x2,y2,zPlus);
        glVertex3f(x1,y2,zPlus);
        glEnd();
        //belakang
        glColor3f(colR,1,colB);
        glBegin(GL_POLYGON);
        glVertex3f(x1,y1,-zMin);
        glVertex3f(x1,y2,-zMin);
        glVertex3f(x2,y2,-zMin);
        glVertex3f(x2,y1,-zMin);
        glEnd();
        //kiri
        glColor3f(1,colG,colB);
        glBegin(GL_POLYGON);
        glVertex3f(x1,y1,zPlus);
        glVertex3f(x1,y2,zPlus);
        glVertex3f(x1,y2,-zMin);
        glVertex3f(x1,y1,-zMin);
        glEnd();
        //kanan
        glColor3f(1,colR,1);
        glBegin(GL_POLYGON);
        glVertex3f(x2,y1,zPlus);
        glVertex3f(x2,y1,-zMin);
        glVertex3f(x2,y2,-zMin);
        glVertex3f(x2,y2,zPlus);
        glEnd();
        //bawah
        glColor3f(0.5,0.5,colB);
        glBegin(GL_POLYGON);
        glVertex3f(x1,y1,zPlus);
        glVertex3f(x1,y1,-zMin);
        glVertex3f(x2,y1,-zMin);
        glVertex3f(x2,y1,zPlus);
        glEnd();
        //atas
        glColor3f(colR,0.8,0.8);
        glBegin(GL_POLYGON);
        glVertex3f(x1,y2,zPlus);
        glVertex3f(x2,y2,zPlus);
        glVertex3f(x2,y2,-zMin);
        glVertex3f(x1,y2,-zMin);
        glEnd();
    }
    void randomNim(){
        srand(time(NULL));
        moveX = 2*(rand()%9)+1;
        moveY = 2*(rand()%9)+1;
    }
    void randomPintu(){
        posPintuX = rand()%5;
        if(posPintuX%2==0){
            posPintuX +=7;
        }else {
            posPintuX +=8;
        }
        //pintu bawah
        m[posPintuX] [0]= 0;
        //pintu atas
        m[posPintuX][18] = 0;
    }
    void generateMaze(){
        for(int i = 0; i < 19; i++){
            for(int j = 0; j < 19; j++){
                //mengisi matrik dengan nilai 1  mulai 0 sampai .... dan hanya  i genap dan j 0 sampai j genap
                if(i%2==0 || j %2==0){
                    m[i][j] = 1;
                }
                //memberikan nilai 0 pada kolom ke 17 dari baris 1 samapi 17
                if(j==17 ){
                    if(i!=0 && i!= 18 ){
                        m[i][j] = 0;
                    }
                }
                //memberikan nilai 0 pada baris ke 17 dari kolom 1 samapi 17
                if(i==17 ){
                    if(j!=0 && j!= 18){
                        m[i][j] = 0;
                    }
                }
            }
        }
        for(int i = 1; i < 17; i+=2){
            for(int j = 1; j < 17; j+=2){
                int x = rand()%2;
                if(x%2==0){
                    m[i+1][j]=0;
                }else{
                    m[i][j+1]=0;
                }
            }
        }
        randomPintu();
        randomNim();
    }
    void rotasiDisplay(){
        //PUSH pada Display
        glPushMatrix();
        glTranslatef(9.5,9.5,0);
        glRotatef(rotasiDisplayX,1,0,0);
        glRotatef(rotasiDisplayY,0,1,0);

        glTranslatef(-9.5,-9.5,0);
    }
    void display(){
        rotasiDisplay();
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        for(int i = 0; i < 19; i++){
            for(int j = 0; j < 19; j++){
                if(m[i][j]==1){
                    balok(0+i , 0+j , 1+i , 1+j , 0.5, 0.5 , 0, 0, 0);
                }
            }
        }

        // NIM
        //PUSH NIM
        glPushMatrix();
        //Transformasi NIM
        glTranslated(0.5+moveX,0.5+moveY,0);
        glRotatef(rotasiNimZ,0,0,1);
        glRotatef(rotasiNimY,0,1,0);
        glRotatef(rotasiNimX,1,0,0);
        glRotatef(setNim,1,0,0);
        glTranslated(-0.5-moveX,-0.5-moveY,0);
        //Nomor 0
        //a
        balok(0.0+moveX,0.0+ moveY,0.3+moveX,0.1+ moveY,0.1,0.1 , 0.5,0.5,0.5);
        //b
        balok(0.2+moveX,0.0+ moveY,0.3+moveX,1.0+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //c
        balok(0.0+moveX,0.9+ moveY,0.3+moveX,1.0+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //d
        balok(0.0+moveX,0.0+ moveY,0.1+moveX,1.0+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);

        //Nomor 2
        //a
        balok(0.35+moveX,0.0+ moveY,0.65+moveX,0.1+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //b
        balok(0.35+moveX,0.0+ moveY,0.45+moveX,0.6+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //c
        balok(0.35+moveX,0.5+ moveY,0.65+moveX,0.6+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //d
        balok(0.55+moveX,0.5+ moveY,0.65+moveX,1.0+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //e
        balok(0.35+moveX,0.9+ moveY,0.65+moveX,1.0+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //Nomor 9
        //a
        balok(0.7+moveX,0.0+ moveY,1.0+moveX,0.1+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //b
        balok(0.9+moveX,0.0+ moveY,1.0+moveX,1.0+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //c
        balok(0.7+moveX,0.9+ moveY,1.0+moveX,1.0+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //d
        balok(0.7+moveX,0.5+ moveY,0.8+moveX,1.0+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //e
        balok(0.7+moveX,0.5+ moveY,1.0+moveX,0.6+ moveY, 0.1, 0.1 , 0.5, 0.5 ,0.5);
        //POP NIM
        glPopMatrix();


        // PLAYER
        balok(posPintuX+posPlayerX + 0.1, 18.0+posPlayerY+0.1, posPintuX+posPlayerX + 0.9, 19.0+posPlayerY-0.1, 0.5, 0.5 , 1 , 0.5, 0.4);
        //POP DISPLAY
        glPopMatrix();
        glFlush();
        glutSwapBuffers();
    }
    void rotasiNim(){
        if (rotasiNimX < -360.0){
            rotasiNimX = rotasiNimX + 360.0;
        }else if(rotasiNimX > 360.0){
            rotasiNimX = rotasiNimX - 360.0;
        }
        if (rotasiNimY < -360.0){
            rotasiNimY = rotasiNimY + 360.0;
        }else if(rotasiNimY > 360.0){
            rotasiNimY = rotasiNimY - 360.0;
        }
        if (rotasiNimZ < -360.0){
            rotasiNimZ = rotasiNimZ + 360.0;
        }else if(rotasiNimZ > 360.0){
            rotasiNimZ = rotasiNimZ - 360.0;
        }
        if(cekRotasiNimX == true){
            rotasiNimX -= 0.1;
            tempRotasiNimX = rotasiNimX;
        }
        else if(cekRotasiNimY == true){
            rotasiNimY -= 0.1;
            tempRotasiNimY = rotasiNimY;
        }
        else if(cekRotasiNimZ == true){
            rotasiNimZ -= 0.1;
            tempRotasiNimZ = rotasiNimZ;
        }

        glutPostRedisplay();
    }
    void input(unsigned char key, int x, int y){
        if(key=='a' || key=='A'){
            if(m[posPintuX+posPlayerX-1][18+posPlayerY]!=1){
                posPlayerX-=1;
            }
        }
        else if(key=='s' || key=='S'){
            if(m[posPintuX+posPlayerX][18+posPlayerY-1]!=1){
                posPlayerY-=1;
            }
        }
        else if(key=='d' || key=='D'){
            if(m[posPintuX+posPlayerX+1][18+posPlayerY]!=1){
                posPlayerX+=1;
            }
        }
        else if(key=='w' || key=='W'){
            if(m[posPintuX+posPlayerX][18+posPlayerY+1]!=1){
                posPlayerY+=1;
            }
        }
        else if(key=='c' || key=='C'){
            posPlayerX = 0;
            posPlayerY = 0;
            generateMaze();
        }
        else if(key=='v' || key=='V'){
            if(cekDisplay==false){
                //menyimpan rotasi nim, sehingg hasil sebelumnya bisa dilanjutakan
                rotasiNimX = tempRotasiNimX;
                rotasiNimY = tempRotasiNimY;
                rotasiNimZ = tempRotasiNimZ;
                //rotasi nim dengan  90 derajat pada sumbu x
                setNim = 90;
                //meneruskan rotasi sebelumnya
                rotasiDisplayX = tempRotasiDisplayX - 30;
                rotasiDisplayY = tempRotasiDisplayY;
                //membuat animasi NIM
                glutIdleFunc(rotasiNim);
                cekDisplay = true;
            }else{
                //mereset rotasi NIM sehingga bisa tampil seperti pertama apa yang terjadi di display 2D
                rotasiNimX = 0;
                rotasiNimY = 0;
                rotasiNimZ = 0;
                setNim = 0;
                //menyimpan rotasi display, sehingga bisa meneruskan hasil sebelumnya
                tempRotasiDisplayX = rotasiDisplayX + 30;
                tempRotasiDisplayY = rotasiDisplayY;
                //mereset rotasi Fisplay sehinng bisa tampil seperti di 2D
                rotasiDisplayX = 0;
                rotasiDisplayY = 0;
                glutIdleFunc(NULL);
                cekDisplay = false;
            }
        }
        else if((key=='i' || key=='I' ) && cekDisplay==true){
            rotasiDisplayX-=1;
            if(rotasiDisplayX < -360){
                rotasiDisplayX += 360;
            }
        }
        else if((key=='k' || key=='K' ) && cekDisplay==true){
            rotasiDisplayX+=1;
            if(rotasiDisplayX > 360){
                rotasiDisplayX -=360;
            }
        }
        else if((key=='j' || key=='J' ) && cekDisplay==true){
            rotasiDisplayY-=1;
            if(rotasiDisplayY < -360){
                rotasiDisplayY +=360;
            }
        }
        else if((key=='l' || key=='L' ) && cekDisplay==true){
            rotasiDisplayY+=1;
            if(rotasiDisplayY > 360){
                rotasiDisplayY -=360;
            }
        }
        display();
    }
    void mouse(int button, int state, int x, int y){
        switch (button){
            case GLUT_LEFT_BUTTON:
                if (state == GLUT_DOWN && cekDisplay==true){
                    cekRotasiNimX = true;
                    cekRotasiNimY = false;
                    cekRotasiNimZ = false;
                }
            break;
            case GLUT_MIDDLE_BUTTON:
                if (state == GLUT_DOWN && cekDisplay==true){
                    cekRotasiNimX = false;
                    cekRotasiNimY = false;
                    cekRotasiNimZ = true;
                }
            break;
            case GLUT_RIGHT_BUTTON:
                if (state == GLUT_DOWN && cekDisplay==true){
                    cekRotasiNimX = false;
                    cekRotasiNimY = true;
                    cekRotasiNimZ = false;
                }
            break;
            default:
                break;
        }
    }
    void myinit(){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-3.5, 22.5, -3.5, 22.5, -19.5, 19.5);
        glMatrixMode(GL_MODELVIEW);
        glShadeModel (GL_FLAT);
        glEnable(GL_DEPTH_TEST);
    }
    int main(int argc, char* argv[]){
        generateMaze();
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(500,500);
        glutCreateWindow("Binary Tree");
        myinit();
        glutDisplayFunc(display);
        glutKeyboardFunc(input);
        glutMouseFunc(mouse);
        glutMainLoop();
        return 0;
    }
