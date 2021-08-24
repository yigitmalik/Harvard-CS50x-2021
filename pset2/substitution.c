#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int character_num = 0;
        bool character_cheak;
        //TODO: loop that counts the same characters of the entered key
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (tolower(argv[1][i]) == tolower(argv[1][j]))
                {
                    character_num++;
                }
            }
        }
        // TODO: Checking that the entered key is a character
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                character_cheak = true;
            }
            else
            {
                character_cheak = false;
                break;
            }
        }
        
        if (character_cheak == false)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        // TODO: checking that the length of the entered key is 26
        else if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (character_num != 0)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        else
        {
            string plaintext = get_string("plaintext: ");
            int letterlen;
            printf("ciphertext: ");
            //TODO: converting characters to key
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                // TODO: check that the entered text is character and lowercase
                if (islower(plaintext[i]) && isalpha(plaintext[i]))
                {
                    letterlen = tolower(plaintext[i] - 'a');
                    printf("%c", tolower(argv[1][letterlen]));
                }
                // TODO: check that the entered text is character and uppercase
                else if (isupper(plaintext[i]) && isalpha(plaintext[i]))
                {
                    letterlen = toupper(plaintext[i] - 'A');
                    printf("%c", toupper(argv[1][letterlen]));
                }
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}