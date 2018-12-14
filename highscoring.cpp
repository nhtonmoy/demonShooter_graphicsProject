void highscore()
{
    int highScore;

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
        printf("\nNew Highscore = %d\n",score);
    }
    else
    {
        printf("\nHighscore = %d\n",highScore);
    }
}
