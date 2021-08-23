#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    int count = 0;
    
    // TODO: Prompt for start size
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);
    // TODO: The entered dollar transform to cents
    int cents = round(dollars * 100);
    // TODO: Greedy Algorithms
    do
    {
        count++;
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else 
        {
            cents -= 1;
        }
    }
    while (cents >= 1);
    // TODO: User output
    printf("%i\n", count);
}