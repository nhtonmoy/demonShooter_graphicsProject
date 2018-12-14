void laserLeft1()
{
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(-.86,.225);
        glVertex2f(-.1,-1.0);
        glVertex2f(-.0,-1.0);
        glVertex2f(-.82,.225);
    glEnd();
}

void laserLeft2()
{
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(-.26,.464);
        glVertex2f(-.1,-1.0);
        glVertex2f(-.0,-1.0);
        glVertex2f(-.22,.464);
    glEnd();
}

void laserRight1()
{
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(-.45,.5);
        glVertex2f(-.1,-1.0);
        glVertex2f(-.0,-1.0);
        glVertex2f(-.41,.5);
    glEnd();
}

void laserRight2()
{
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(0.275,.46);
        glVertex2f(-.1,-1.0);
        glVertex2f(-.0,-1.0);
        glVertex2f(0.315,.46);
    glEnd();
}
