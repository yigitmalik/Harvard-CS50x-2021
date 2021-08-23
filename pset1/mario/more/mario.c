#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // TODO: Prompt for height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 ||  n > 8);
    //
    for (int i = 0; i < n; i++)
    {
        
        for (int j = i; j < n - 1; j++)
        {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // TODO: Space between two pyramids
        printf("  ");
        
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }    
        printf("\n"); 
    }
}