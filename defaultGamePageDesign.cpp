void highScoreShow()
{
glColor3f(1.0f, 0.0f, 0.0f);
    char buf[100] = {0};
    sprintf(buf, "HIGHSCORE: %d", highScore);
    RenderBitMap(0.1,0.95, GLUT_BITMAP_HELVETICA_18, buf);
}
