bool newHigh=false;

void highscore()
{

    FILE *in_file  = fopen("score.txt", "r");
    fscanf(in_file, "%d", &highScore);
    fclose(in_file);

    /*File Read ends from here*/
    /*File Write Starts from here*/

    if(score>highScore)
    {
        FILE *file = fopen("score.txt", "w");
        fprintf(file, "%d", score);
        fclose(file);
        highScore=score;
        newHigh=true;
    }
}
