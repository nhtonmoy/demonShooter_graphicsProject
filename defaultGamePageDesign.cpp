
void highScoreShow()
{
    if(score>highScore)
    {
        highScore=score;
        isNew=true;
    }
    if(isNew && !isFirst && !isGameOver)
    {
        highScore=score;
        glColor3f(1.0f, 0.0f, 0.0f);
        char buf3[100] = {0};
        sprintf(buf3, "NEW!!");
        RenderBitMap(0.43,0.9, GLUT_BITMAP_TIMES_ROMAN_10, buf3);
    }
    glColor3f(0.0f, 0.0f, 0.0f);
    char buf[100] = {0};
    sprintf(buf, "HIGHSCORE: %d", highScore);
    RenderBitMap(0.5,0.9, GLUT_BITMAP_HELVETICA_18, buf);
}

void currentScore()
{
    glColor3f(0.0f, 0.0f, 0.0f);
    char buf[100] = {0};
    sprintf(buf, "SCORE: %d", score);
    RenderBitMap(0.59,0.8, GLUT_BITMAP_HELVETICA_18, buf);
}

void health()
{
    glColor3f(0.0f, 0.0f, 0.0f);
    char buf[100] = {0};
    sprintf(buf, "HEALTH");
    RenderBitMap(-0.95,0.94, GLUT_BITMAP_HELVETICA_18, buf);

    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(-.8,.93);
        glVertex2f(-.8,.98);
        glVertex2f(xLife,.98);
        glVertex2f(xLife,.93);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(.4,.93);
        glVertex2f(.4,.98);
        glVertex2f(xDeath,.98);
        glVertex2f(xDeath,.93);
    glEnd();
}

void startNewGame()
{
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(-.25,.3);
        glVertex2f(.25,.3);
        glVertex2f(.25,.0);
        glVertex2f(-.25,.0);
    glEnd();


    char buf[100] = {0};
    glColor3f(1.0f, 1.0f, 1.0f);
    sprintf(buf, "Start New Game");
    RenderBitMap(-.15,0.1, GLUT_BITMAP_TIMES_ROMAN_24, buf);
}

void restart()
{
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(-.25,.3);
        glVertex2f(.25,.3);
        glVertex2f(.25,.0);
        glVertex2f(-.25,.0);
    glEnd();


    char buf[100] = {0};
    glColor3f(1.0f, 1.0f, 1.0f);
    sprintf(buf, "Start New Game");
    RenderBitMap(-.15,0.1, GLUT_BITMAP_TIMES_ROMAN_24, buf);

    glColor3f(1.0f, 0.0f, 0.0f);
    char buf1[100] = {0};
    sprintf(buf1, "Game Over");
    RenderBitMap(-0.1,0.22, GLUT_BITMAP_TIMES_ROMAN_24, buf1);

    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,0.0);
        glVertex2f(-.25,.3);
        glVertex2f(.25,.3);
        glVertex2f(.25,.6);
        glVertex2f(-.25,.6);
    glEnd();

    char buf2[100] = {0};
    glColor3f(.0f, .0f, .0f);
    sprintf(buf2, "YOUR SCORE: %d",score);
    RenderBitMap(-.15,0.35, GLUT_BITMAP_HELVETICA_18, buf2);
    if(newHigh)
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        char buf3[100] = {0};
        sprintf(buf3, "NEW HIGH SCORE!!");
        printf("\nNew High Score\n");
        RenderBitMap(-0.22,0.5, GLUT_BITMAP_TIMES_ROMAN_24, buf3);


    }
}


void instructions()
{
    glBegin(GL_POLYGON);
        glColor3f(0,0,1);
        glVertex2f(.45,.47);
        glVertex2f(.45,.55);
        glVertex2f(.9,.55);
        glVertex2f(.9,.47);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    char buf3[100] = {0};
    sprintf(buf3, "Instructions");
    RenderBitMap(.47,0.5, GLUT_BITMAP_9_BY_15, buf3);

    glBegin(GL_POLYGON);
        glColor3f(1,1,0);
        glVertex2f(.45,.0);
        glVertex2f(.45,.47);
        glVertex2f(.9,.47);
        glVertex2f(.9,.0);
    glEnd();

    glColor3f(1.0f, .0f, .0f);
    char buf1[100] = {0};
    sprintf(buf1, "Demons will appear from");
    RenderBitMap(.47,0.44, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "behind the buildings. They");
    RenderBitMap(.47,0.41, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "will shoot heat vision to");
    RenderBitMap(.47,0.38, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "the player after some time.");
    RenderBitMap(.47,0.35, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "The player have to shoot");
    RenderBitMap(.47,0.32, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "the demons before they can");
    RenderBitMap(.47,0.29, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "shoot their heat vision.");
    RenderBitMap(.47,0.26, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "To kill them, CLICK on them");
    RenderBitMap(.47,0.21, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "when they appear.");
    RenderBitMap(.47,0.18, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "Or they will shoot you.");
    RenderBitMap(.47,0.15, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "If they can shoot you");
    RenderBitMap(.47,0.12, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "4 times,");
    RenderBitMap(.47,0.09, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "That'll be your end.");
    RenderBitMap(.47,0.06, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "So SHOW THEM NO MERCY!!!");
    RenderBitMap(.47,0.03, GLUT_BITMAP_8_BY_13, buf1);
}

void about()
{
    glBegin(GL_POLYGON);
        glColor3f(0,0,1);
        glVertex2f(-.35,.47);
        glVertex2f(-.35,.55);
        glVertex2f(-.8,.55);
        glVertex2f(-.8,.47);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    char buf3[100] = {0};
    sprintf(buf3, "About");
    RenderBitMap(-.77,0.5, GLUT_BITMAP_9_BY_15, buf3);

    glBegin(GL_POLYGON);
        glColor3f(1,1,0);
        glVertex2f(-.35,.0);
        glVertex2f(-.35,.47);
        glVertex2f(-.8,.47);
        glVertex2f(-.8,.0);
    glEnd();

    glColor3f(1.0f, .0f, .0f);
    char buf1[100] = {0};
    sprintf(buf1, "Earth has been invaded");
    RenderBitMap(-.77,0.44, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "By the Giant Alien Demons!");
    RenderBitMap(-.77,0.41, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "Save your city and its");
    RenderBitMap(-.77,0.38, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "people, along with the");
    RenderBitMap(-.77,0.35, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "rest of the humanity");
    RenderBitMap(-.77,0.32, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "from those invading demons!");
    RenderBitMap(-.77,0.29, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "You are the last hope");
    RenderBitMap(-.77,0.24, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "of humanity.");
    RenderBitMap(-.77,0.21, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "Can you stop the enemy?");
    RenderBitMap(-.77,0.18, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "Can you kill them all?");
    RenderBitMap(-.77,0.15, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "Can you save the humanity?");
    RenderBitMap(-.77,0.12, GLUT_BITMAP_8_BY_13, buf1);
    sprintf(buf1, "LET'S FIND OUT!!");
    RenderBitMap(-.77,0.06, GLUT_BITMAP_8_BY_13, buf1);
}

void developedBy()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    char buf1[100] = {0};
    sprintf(buf1, "Developed By:");
    RenderBitMap(.32,-.45, GLUT_BITMAP_9_BY_15, buf1);
    sprintf(buf1, "MOHAMMAD NAZMUL HASAN");
    RenderBitMap(.55,-.5, GLUT_BITMAP_9_BY_15, buf1);
    sprintf(buf1, "EHTESHAM AHMAD NADIM");
    RenderBitMap(.55,-.54, GLUT_BITMAP_9_BY_15, buf1);
    sprintf(buf1, "RASHEDUL ALAM");
    RenderBitMap(.55,-.58, GLUT_BITMAP_9_BY_15, buf1);
    sprintf(buf1, "GOLAM MOHAMMAD SHOVON");
    RenderBitMap(.55,-.62, GLUT_BITMAP_9_BY_15, buf1);
}
