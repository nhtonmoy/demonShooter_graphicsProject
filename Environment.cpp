void leftBuildingErJanala(float x,float y)
{
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
        glVertex3f(x,y,0);
        glVertex3f(x+.15,y,0);
        glVertex3f(x+.15,y+.065,0);
        glVertex3f(x,y+.065,0);
    glEnd();
}

void rightBuildingErJanala(float x, float y)
{
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
        glVertex3f(x,y,0);
        glVertex3f(x+.06,y,0);
        glVertex3f(x+.06,y+0.06,0);
        glVertex3f(x,y+0.06,0);

    glEnd();
}

void buildingLeft(void)
{
                /* clear the matrix */
           /* viewing transformation  */
    //gluLookAt (camPosX, camPosY, camPosZ, 0.0, 0.0, 0.0, 0.0,1.0, 0.0);
    //glPushMatrix();

   //glScalef (1.0, 2.0, 1.0);      /* modeling transformation */
   //float size = 1.0;
   //glutWireCube (2.0);
   //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Front
        glVertex3f(-.80,-.20,0);
        glVertex3f(-.80,.50,0);
        glVertex3f(-.60,.50,0);
        glVertex3f(-.60,-.20,0);
    glEnd();
    glColor3f (0.8, 0.8, 0.8);
    glBegin(GL_QUADS); //Roof
        glVertex3f(-.65,.6,0);
        glVertex3f(-.80,.50,0);
        glVertex3f(-.60,.5,0);
        glVertex3f(-.45,.60,0);
    glEnd();
    glColor3f (0.9, 0.9, 0.9);
    glBegin(GL_QUADS); //Side
        glVertex3f(-.60,.5,0);
        glVertex3f(-.45,.60,0);
        glVertex3f(-.45,-.10,0);
        glVertex3f(-.60,-.2,0);
    glEnd();



    leftBuildingErJanala(-0.78,0.37);
    leftBuildingErJanala(-0.78,0.25);
    leftBuildingErJanala(-0.78,0.13);
    leftBuildingErJanala(-0.78,0.01);

    glBegin(GL_QUADS); //doroja
        glVertex3f(-0.67,-0.07,0);
        glVertex3f(-0.74,-0.07,0);
        glVertex3f(-0.74,-0.20,0);
        glVertex3f(-0.67,-0.20,0);
    glEnd();

}

void buildingRight(void)
{
    //glClear (GL_COLOR_BUFFER_BIT);

            /* clear the matrix */
           /* viewing transformation  */
    //gluLookAt (camPosX, camPosY, camPosZ, 0.0, 0.0, 0.0, 0.0,1.0, 0.0);
    //glPushMatrix();

   //glScalef (1.0, 2.0, 1.0);      /* modeling transformation */
   //float size = 1.0;
   //glutWireCube (2.0);
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Front
        glVertex3f(-.2,-.20,0);
        glVertex3f(-.2,.50+.1,0);
        glVertex3f(.1,.50+.1,0);
        glVertex3f(.1,-.20,0);
    glEnd();
    glColor3f (0.8, 0.8, 0.8);
    glBegin(GL_QUADS); //Roof
        glVertex3f(-.05,.6+.1,0);
        glVertex3f(-.2,.50+.1,0);
        glVertex3f(.1,.5+.1,0);
        glVertex3f(.25,.60+.1,0);
    glEnd();
    glColor3f (0.9, 0.9, 0.9);
    glBegin(GL_QUADS); //Side
        glVertex3f(.1,.5+.1,0);
        glVertex3f(.25,.60+.1,0);
        glVertex3f(.25,-.10,0);
        glVertex3f(.1,-.2,0);
    glEnd();


    rightBuildingErJanala(-.17,.45);
    rightBuildingErJanala(-.08,.45);
    rightBuildingErJanala(0.01,.45);


    rightBuildingErJanala(-.17,.35);
    rightBuildingErJanala(-.08,.35);
    rightBuildingErJanala(0.01,.35);


    rightBuildingErJanala(-.17,.25);
    rightBuildingErJanala(-.08,.25);
    rightBuildingErJanala(0.01,.25);


    rightBuildingErJanala(-.17,.15);
    rightBuildingErJanala(-.08,.15);
    rightBuildingErJanala(0.01,.15);


    rightBuildingErJanala(-.17,.05);
    rightBuildingErJanala(-.08,.05);
    rightBuildingErJanala(0.01,.05);


    rightBuildingErJanala(-.17,-.05);
    rightBuildingErJanala(-.08,-.05);
    rightBuildingErJanala(0.01,-.05);

    glBegin(GL_QUADS); //doroja
    glColor3f(0.0,0.0,.0);
        glVertex3f(-0.0,-0.1,0);
        glVertex3f(-0.0,-0.20,0);
        glVertex3f(-0.095,-0.20,0);
        glVertex3f(-0.095,-0.1,0);
    glEnd();

}

void river(void)
{
    glColor3f (0.1, 0.4, 1.0);
    glBegin(GL_POLYGON);
        //uporer paar
        glVertex3f(-1.0,-0.4,0);
        glVertex3f(-.740,-0.39,0);
        glVertex3f(-.50,-0.42,0);
        glVertex3f(-0.0,-0.38,0);
        glVertex3f(0.4,-0.41,0);
        glVertex3f(0.8,-0.39,0);
        glVertex3f(1.0,-.4,.0);
        //nicher paar
        glVertex3f(1.0,-.8,.0);
        glVertex3f(0.6,-.82,.0);
        glVertex3f(0.35,-.79,.0);
        glVertex3f(0.1,-.81,.0);
        glVertex3f(-0.6,-.78,.0);
        glVertex3f(-1.0,-.82,.0);
    glEnd();
}

void sky()
{
    glColor3f (0.5, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0,.55,0.0);
        glVertex3f(-1.0,1.0,0.0);
        glVertex3f(1.0,1.0,0.0);
        glVertex3f(1.0,.55,0.0);
    glEnd();
}

void paharPorbot()
{
    glColor3f (1.0, 0.5, 0.25);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0,.55,0.0);
        glVertex3f(-0.8,.55,0.0);
        glVertex3f(-0.9,.65,0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f (1.0, 0.5, 0.25);
        glVertex3f(-0.3,.55,0.0);
        glVertex3f(0.1,.55,0.0);
        glVertex3f(-0.15,.7,0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex3f(-0.81,.55,0.0);
        glVertex3f(-0.51,.55,0.0);
        glVertex3f(-0.65,.75,0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f (1.0, 0.4, 0.0);
        glVertex3f(-0.7,.55,0.0);
        glVertex3f(-0.2,.55,0.0);
        glVertex3f(-0.45,.8,0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f (1.0, 0.5, 0.25);
        glVertex3f(0.36,.55,0.0);
        glVertex3f(0.8,.55,0.0);
        glVertex3f(0.63,.7,0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f (1.0, 0.4, 0.0);
        glVertex3f(0.05,.55,0.0);
        glVertex3f(0.45,.55,0.0);
        glVertex3f(0.20,.75,0.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f (1.0, 0.4, 0.0);
        glVertex3f(0.77,.55,0.0);
        glVertex3f(1.15,.55,0.0);
        glVertex3f(0.94,.75,0.0);
    glEnd();
}

