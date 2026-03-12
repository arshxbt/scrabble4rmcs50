#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Text: ");

    double words = 1, letters = 0, sentences = 0;
    for (int i = 0, len = strlen(phrase); i < len; i++)
    {
        if (phrase[i] > 64 && phrase[i] < 123 && (phrase[i] < 91 || phrase[i] > 96)) // letters counter
        {
            letters++;
        }
        if (phrase[i] == 32) // words counter
        {
            words++;
        }
        if (phrase[i] == 46 || phrase[i] == 63 || phrase[i] == 33) // sentences counter
        {
            sentences++;
        }
    }
    double L = (letters / words) * 100, S = (sentences / words) * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int indexrounded = round(index);
    if (indexrounded < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (indexrounded >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", indexrounded);
    }
}
