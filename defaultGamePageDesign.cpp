

void highScoreShow()
{
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
    RenderBitMap(-1.0,0.94, GLUT_BITMAP_HELVETICA_18, buf);

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


