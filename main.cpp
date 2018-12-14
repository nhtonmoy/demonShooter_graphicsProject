#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#pragma comment(lib, "winmm.lib")
#include<bits/stdc++.h>
#include <mmsystem.h>
#include "BoatTranslation.cpp"
#include "Environment.cpp"
#include "Demons.cpp"
#include "heatVisions.cpp"


void update(int i);

int score;

#include "highscoring.cpp"



void mouse(int button, int state, int x, int y);

void RenderBitMap(float x, float y, void *font, char *string)
{
    char *c;
    glRasterPos2f(x,y);
    for(c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}


void mouse(int button, int state, int x, int y) {
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);

    int mx = x;
    int my = y;

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        if(!isGameOver)
        {
            Beep(60,50);
        }
//        printf("%d\n",mx);
//        printf("%d\n",my);

        if(firstDemonLeftMost) //first demon leftmost position e ase
        {
            int x1=62, y1=262,y2=334;
            for(x1=62;x1<=98;x1++)
            {

                if(x1==mx && (my<=y2 && my>=y1) && _angle2!=90 && !isGameOver && !heatVisionLeft1)
                {
                    Beep(500,50);
                    _angle2=90;
                    isShotLeft1=false;
                    score++;
                    break;
                }

            }
        }

        if(secondDemonLeftMost) //second demon leftmost position e ase
        {
            int x1=372, y1=170,y2=242;
            for(x1=372;x1<=408;x1++)
            {

                if(x1==mx && (my<=y2 && my>=y1) && _angle1!=90 && !isGameOver && !heatVisionLeft2)
                {
                    Beep(500,50);
                    _angle1=90;
                    isShotLeft2=false;
                    score++;
                    break;
                }

            }
        }

        if(firstDemonRightMost) //second demon leftmost position e ase
        {
            int x1=312, y1=160,y2=228;
            for(x1=312;x1>=283;x1--)
            {

                if(x1==mx && (my<=y2 && my>=y1) && _angle3!=90 && !isGameOver && !heatVisionRight1)
                {
                    Beep(500,50);
                    _angle3=90;
                    isShotRight1=false;
                    score++;
                    break;
                }

            }
        }

        if(secondDemonRightMost) //second demon leftmost position e ase
        {
            int x1=683, y1=174,y2=244;
            for(x1=683;x1>=641;x1--)
            {

                if(x1==mx && (my<=y2 && my>=y1) && _angle4!=90 && !isGameOver)
                {
                    Beep(500,50);
                    _angle4=90;
                    isShotRight2=false;
                    score++;
                    break;
                }

            }
        }
        if(!isGameOver)
        {
            printf("Score: %d\n",score);
        }
        else
        {
            printf("Game Over!\n");
        }


    }



}



void init(void)
{
    //glClearColor (1.0, 01.0, 01.0, 0.0);
    glClearColor(0.2, 1.0, 0.3, 0.0);
    //glShadeModel (GL_FLAT);

}

void update(int i)
{
    //gluLookAt(0,camPosy,0,0.0,0.0,0.0,0.0,0.0,0.0);
    glutPostRedisplay();
}
int called=0;
void Environment(void)
{

    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();


    sky();
    paharPorbot();

    drawDemons();

    buildingLeft();
    buildingRight();
    river();
    drawBoats();

//    Beep(25,25);
    //PlaySound(TEXT("nature.wav"), NULL, SND_SYNC|SND_FILENAME);
    glFlush();
}
void test()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();


    sky();
    paharPorbot();
    glFlush();

}

void gameover()
{
    sky();
    paharPorbot();
    buildingLeft();
    buildingRight();
    river();
    highscore();

    glColor3f(1.0f, 0.0f, 0.0f);
    char buf[100] = {0};
    sprintf(buf, "Game Over");
    RenderBitMap(0.1,0.3, GLUT_BITMAP_TIMES_ROMAN_24, buf);
}

void display()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();
    //PlaySound(TEXT("nature.wav"), NULL, SND_SYNC|SND_FILENAME);

    if(shotCounter < 5) //score<4
    {
        isGameOver=false;
        sky();
        paharPorbot();

        drawDemons();

        buildingLeft();
        buildingRight();
        river();
        drawBoats();

        if(heatVisionLeft1)
        {
            laserLeft1();
        }
        if(heatVisionLeft2)
        {
            laserLeft2();
        }
        if(heatVisionRight1)
        {
            laserRight1();
        }
        if(heatVisionRight2)
        {
            laserRight2();
        }
    }
    else if(shotCounter==5)
    {
        isGameOver=true;
        gameover();
    }

    glFlush();
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (1024, 768);
   glutInitWindowPosition (100, 100);

   glutCreateWindow (argv[0]);

   glutDisplayFunc(display);
   init ();
   //Environment();
   glutMouseFunc(mouse);
   //glutReshapeFunc(reshape);
   //glutSpecialFunc(specialKeys);
   glutMainLoop();
   return 0;
}
