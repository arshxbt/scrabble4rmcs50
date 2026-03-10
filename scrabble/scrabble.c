#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scorecalc(string word);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = scorecalc(player1);
    int score2 = scorecalc(player2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Function to calculate the scores while the main handles display
int scorecalc(string word)
{
    int score = 0, sum = 0;
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (islower(word[i]))
        {
            score = points[word[i] - 'a'];
            sum += score;
        }
        else if (isupper(word[i]))
        {
            score = points[word[i] - 'A'];
            sum += score;
        }
        // For some reasons the code below is useless, I think its because the if and else above
        // would only work on alphabets so any thing else will be skipped. would include it here
        // for convention reasons
        else if (word[i] < 65 || word[i] > 122 || (word[i] < 97 && word[i] > 90))
        {rm credit.c
            
            score = 0;
        }
    }
    return sum;
}
