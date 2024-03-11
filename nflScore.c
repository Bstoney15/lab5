#include <stdio.h>


void printCombinations(int score)
{
    int touchdowns8, touchdowns7, touchdowns6, fieldGoals, safeties;

    for (touchdowns8 = 0; touchdowns8 <= score / 8; touchdowns8++)
    {
        for (touchdowns7 = 0; touchdowns7 <= score / 7; touchdowns7++)
        {
            for (touchdowns6 = 0; touchdowns6 <= score / 6; touchdowns6++)
            {
                for (fieldGoals = 0; fieldGoals <= (score - (touchdowns8 * 8) - (touchdowns7 * 7) - (touchdowns6 * 6)) / 3; fieldGoals++)
                {
                    safeties = score - (touchdowns8 * 8) - (touchdowns7 * 7) - (touchdowns6 * 6) - (fieldGoals * 3);
                    if (safeties >= 0 && safeties % 2 == 0)
                    {
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d safety\n", touchdowns8, touchdowns7, touchdowns6, fieldGoals, safeties / 2);
                    }
                }
            }
        }
    }
}
    


int main()
{
    int score;


    do{
        printf("\n Enter the NFL score: ");
        printf("Enter 0 or 1 to STOP \n");
        scanf("%d", &score);

        if(score == 0 || score == 1){break;}

        printCombinations(score);
    }while(score != 0 && score != 1);


    return 0;
}