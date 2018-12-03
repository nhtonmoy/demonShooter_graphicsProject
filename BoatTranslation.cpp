
float camPosY = 0.0f;
float camPosX = 0.0f;
float camPosZ = 5.0f;

void update(int i);
void updateBoats(int value);

float transFactor = 0.0f;
float getXBoats(int val)
{
    int width = glutGet(GLUT_WINDOW_WIDTH);
    float frac = (float)val/((float)width/2);
    return frac;
}
float getYBoats(int val)
{
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    float frac = (float)val/((float)height/2);
    return frac;
}
bool isInitiatedBoat=false;
void boatInitialPosition()
{
    transFactor=getXBoats(-1024);
    isInitiatedBoat=true;
}
void drawBoats()
{

    glPushMatrix();
        glTranslatef(transFactor,0,0);

        glColor3ub(128,64,64);
        glBegin(GL_QUADS); //1st pillar
            glVertex2f(getXBoats(-395),getYBoats(-190-40));
            glVertex2f(getXBoats(-395),getYBoats(-190));
            glVertex2f(getXBoats(-380),getYBoats(-190));
            glVertex2f(getXBoats(-380),getYBoats(-190-40));
        glEnd();

        glBegin(GL_QUADS); //boat cabin
            glVertex2f(getXBoats(-350),getYBoats(-190-40));
            glVertex2f(getXBoats(-295),getYBoats(-190));
            glVertex2f(getXBoats(-225),getYBoats(-190));
            glVertex2f(getXBoats(-170),getYBoats(-190-40));
        glEnd();


        glColor3ub(0,0,0);
        glBegin(GL_QUADS); //1st pillar's smoke 1
            glVertex2f(getXBoats(-380),getYBoats(-150-30));
            glVertex2f(getXBoats(-380),getYBoats(-155-30));
            glVertex2f(getXBoats(-385),getYBoats(-155-30));
            glVertex2f(getXBoats(-385),getYBoats(-150-30));
        glEnd();
        glBegin(GL_QUADS); //1st pillar's smoke 2
            glVertex2f(getXBoats(-388),getYBoats(-155-25));
            glVertex2f(getXBoats(-388),getYBoats(-150-25));
            glVertex2f(getXBoats(-393),getYBoats(-150-25));
            glVertex2f(getXBoats(-393),getYBoats(-155-25));
        glEnd();
        glBegin(GL_QUADS); //1st pillar's smoke 3
            glVertex2f(getXBoats(-395),getYBoats(-155-20));
            glVertex2f(getXBoats(-395),getYBoats(-150-20));
            glVertex2f(getXBoats(-400),getYBoats(-150-20));
            glVertex2f(getXBoats(-400),getYBoats(-155-20));
        glEnd();

        glBegin(GL_QUADS);//main body
            glColor3ub(255,0,65);
            glVertex2f(getXBoats(-50),getYBoats(-190));
            glVertex2f(getXBoats(-150),getYBoats(-220-40));
            glVertex2f(getXBoats(-395),getYBoats(-220-40));
            glVertex2f(getXBoats(-400),getYBoats(-190-40));
        glEnd();

    glPopMatrix();
    if(!isInitiatedBoat){
        boatInitialPosition();
    }

    glutSwapBuffers();
    //Sleep(500);
    glutTimerFunc(100,updateBoats,0);
}

void updateBoats(int value)
{

    transFactor+=0.0005f;
    if(transFactor>getXBoats(512*2))
       transFactor = -1 * getXBoats(512 * 2);
    glutPostRedisplay();
    //glutTimerFunc(20,update,0);
}

