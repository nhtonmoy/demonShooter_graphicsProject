#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Windows.h>
#include<bits/stdc++.h>
#include "BoatTranslation.cpp"
#include "Environment.cpp"
#include "Demons.cpp"

void update(int i);

int score;

void mouse(int button, int state, int x, int y);

void mouse(int button, int state, int x, int y) {
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);

    int mx = x;
    int my = y;

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
//        printf("%d\n",mx);
//        printf("%d\n",my);

        if(firstDemonLeftMost) //first demon leftmost position e ase
        {
            int x1=62, y1=262,y2=334;
            for(x1=62;x1<=98;x1++)
            {

                if(x1==mx && (my<=y2 && my>=y1) && _angle2!=90)
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

                if(x1==mx && (my<=y2 && my>=y1) && _angle1!=90)
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

                if(x1==mx && (my<=y2 && my>=y1) && _angle3!=90)
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

                if(x1==mx && (my<=y2 && my>=y1) && _angle4!=90)
                {
                    _angle4=90;
                    isShotRight2=false;
                    score++;
                    break;
                }

            }
        }
        printf("Score: %d\n",score);


    }



}



void init(void)
{
    //glClearColor (1.0, 01.0, 01.0, 0.0);
    glClearColor(0.2, 1.0, 0.3, 0.0);
    glShadeModel (GL_FLAT);

}

void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          camPosY+=0.5f;
          printf("a");
          update(0);
          break;
      case GLUT_KEY_DOWN:
          camPosY-=0.5f;
          update(0);
          break;
    case GLUT_KEY_RIGHT:
          camPosX+=0.5f;
          printf("a");
          update(0);
          break;
    case GLUT_KEY_LEFT:
          camPosX-=0.5f;
          update(0);
          break;
    case GLUT_KEY_PAGE_UP:
          camPosZ+=0.5f;
          update(0);
          break;
    case GLUT_KEY_PAGE_DOWN:
          camPosZ-=0.5f;
          update(0);
          break;


}
}
void update(int i)
{
    //gluLookAt(0,camPosy,0,0.0,0.0,0.0,0.0,0.0,0.0);
    glutPostRedisplay();
}

//
//
//void reshape (int w, int h)
//{
//   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
//   glMatrixMode (GL_PROJECTION);
//   glLoadIdentity ();
//   glFrustum (-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
//   glMatrixMode (GL_MODELVIEW);
//}
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


    glFlush();
}
void display()
{


    glLoadIdentity ();
    glutDisplayFunc(Environment);
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (1024, 768);
   glutInitWindowPosition (100, 100);

   glutCreateWindow (argv[0]);
   display();
   init ();

   //Environment();
   glutMouseFunc(mouse);
   //glutReshapeFunc(reshape);
   //glutSpecialFunc(specialKeys);
   glutMainLoop();
   return 0;
}
