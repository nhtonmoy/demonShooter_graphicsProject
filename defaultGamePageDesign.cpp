

void highScoreShow()
{
    if(score>highScore) highScore=score;
    glColor3f(0.0f, 0.0f, 0.0f);
    char buf[100] = {0};
    sprintf(buf, "HIGHSCORE: %d", highScore);
    RenderBitMap(0.7,0.9, GLUT_BITMAP_HELVETICA_18, buf);
}

void currentScore()
{
    glColor3f(0.0f, 0.0f, 0.0f);
    char buf[100] = {0};
    sprintf(buf, "SCORE: %d", score);
    RenderBitMap(0.79,0.8, GLUT_BITMAP_HELVETICA_18, buf);
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

        printf("new high");

    }
}
