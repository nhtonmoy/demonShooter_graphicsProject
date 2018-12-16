#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#pragma comment(lib, "winmm.lib")
#include<bits/stdc++.h>
#include <mmsystem.h>


bool isNew=false;
bool isGameOver=true;
void update(int i);
int restartable=0;

bool isFirst=true;
int highScore;
int score;
int shotCounter=0;
float xLife=.4;
float xDeath=.4;
float xDef=1.2/5;

void Sound(int x)
{
    if(x==1)
    {
        PlaySound(TEXT("Gun+Shot2.wav"), NULL, SND_FILENAME|SND_ASYNC);
        Sleep(200);
    }
    else if(x==2)
    {
        PlaySound(TEXT("Fishing Boat And Waves 02 _ Sound Effect (192kbit_AAC) 00_00_00-00_00_10.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    }
    else if(x==3)
    {
        PlaySound(TEXT("Epic Battle Music #1 _ No Copyright Sound Effect (192kbit_AAC).wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    }
    else if(x==4)
    {
        PlaySound(TEXT("heatVision.wav"), NULL, SND_FILENAME|SND_ASYNC);
        Sleep(200);
    }

}


#include "Environment.cpp"
#include "Demons.cpp"
#include "heatVisions.cpp"
#include "BoatTranslation.cpp"

void initiateRestart()
{
    isNew=false;
    _angle1 = 90.0f;
    _angle2 = 90.0f;
    _angle3 = 90.0f;
    _angle4 = 90.0f;

    xLife=.4;
    xDeath=.4;

    firstDemonLeftMost=false;
    secondDemonLeftMost=false;
    firstDemonRightMost=false;
    secondDemonRightMost=false;


    isShotLeft1=false;
    isShotLeft2=false;
    isShotRight1=false;
    isShotRight2=false;

    heatVisionLeft1=false;
    heatVisionRight1=false;
    heatVisionLeft2=false;
    heatVisionRight2=false;

    isInitiatedLeft1=false;
    isInitiatedLeft2=false;
    isInitiatedRight1=false;
    isInitiatedRight2=false;


    rotateCount=0;
    rotateCountLeftward1=0;
    rotateCountRightward1=0;
    rotateCountRightward2=0;


    isInitiatedBoat=false;
}

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
#include "highscoring.cpp"
#include "defaultGamePageDesign.cpp"


void mouse(int button, int state, int x, int y) {
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);

    int mx = x;
    int my = y;

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        if(!isGameOver && !isFirst)
        {
            Sound(1);
            Sound(2);
        }

        if(isFirst)
        {
            printf("%d,%d\n",mx,my);
            if(mx >= 385 && mx <= 640 && my >= 270 && my <= 385)
            {
                isFirst=false;
                isGameOver=false;
                glutPostRedisplay();
                Sound(2);
            }
        }
        if(isGameOver)
        {

            if(mx >= 385 && mx <= 640 && my >= 270 && my <= 385)
            {

                isFirst=false;
                isGameOver=false;
                isNew=false;


                _angle1 = 90.0f;
                _angle2 = 90.0f;
                _angle3 = 90.0f;
                _angle4 = 90.0f;

                xLife=.4;
                xDeath=.4;

                firstDemonLeftMost=false;
                secondDemonLeftMost=false;
                firstDemonRightMost=false;
                secondDemonRightMost=false;


                isShotLeft1=false;
                isShotLeft2=false;
                isShotRight1=false;
                isShotRight2=false;

                heatVisionLeft1=false;
                heatVisionRight1=false;
                heatVisionLeft2=false;
                heatVisionRight2=false;

                shotCounter=0;
                score=0;

                isInitiatedLeft1=false;
                isInitiatedLeft2=false;
                isInitiatedRight1=false;
                isInitiatedRight2=false;


                rotateCount=0;
                rotateCountLeftward1=0;
                rotateCountRightward1=0;
                rotateCountRightward2=0;


                isInitiatedBoat=false;
                Sound(2);

                glutPostRedisplay();

            }
        }


        if(firstDemonLeftMost) //first demon leftmost position e ase
        {
            int x1=62, y1=262,y2=334;
            for(x1=62;x1<=98;x1++)
            {

                if(x1==mx && (my<=y2 && my>=y1) && _angle2!=90 && !isGameOver && !heatVisionLeft1)
                {
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
                    _angle4=90;
                    isShotRight2=false;
                    score++;
                    break;
                }
            }
        }
    }



}



void init(void)
{
    glClearColor(0.2, 1.0, 0.3, 0.0);

}


void gameover()
{
    sky();
    paharPorbot();
    buildingLeft();
    buildingRight();
    river();
    highscore();
    restart();
    highScoreShow();

    instructions();
    about();
    developedBy();
}

void start()
{
    sky();
    paharPorbot();
    buildingLeft();
    buildingRight();
    river();
    highscore();

    startNewGame();
    highScoreShow();

    instructions();
    about();
    developedBy();
}

void gameStarted()
{

    isGameOver=false;
    sky();
    paharPorbot();
    highScoreShow();
    currentScore();
    health();
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

void display()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();

    if(isFirst)
    {
        start();
        isGameOver=false;

        Sound(3);

    }
    else if(!isFirst)
    {
        if(shotCounter < 5) //score<4
        {
            isGameOver=false;
            gameStarted();

        }
        else if(shotCounter>=5)
        {
            initiateRestart();
            isGameOver=true;
            printf("%d\n",shotCounter);

            gameover();

            Sound(3);
        }
    }

    glFlush();
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1024, 768);
    glutInitWindowPosition (100, 100);

    glutCreateWindow ("DEMON SHOOTER");

    glutDisplayFunc(display);
    init ();


    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
