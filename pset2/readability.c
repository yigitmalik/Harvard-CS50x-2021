#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // TODO: Get input sentences from user
    string text = get_string("TEXT: ");
    int letter = 0, words = 1, sentences = 0;
    
    // TODO: Calculate letters, words and sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letter += 1;
        }
        if (isspace(text[i]))
        {
            words += 1;
        }
        if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            sentences += 1;
        }
    }
    
    // TODO: Coleman-Liau formula
    float L = (letter / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    // TODO: Print grade level
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);  
    }
}