/* by glassofraksi
 cs50 2020
simple implementation of substituition cipher
26 character unique key is provided through command line as ./caesar key
letters are then replaced using key, and case is preserved
*/


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void substitution(string key);

int main(int argc, string argv[])
{
    if (argc != 2) // checks for exacly one key
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int n = strlen(argv[1]);

        if (n < 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (isalpha(argv[1][i]) == 0) // checks for pure character string
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
            else
            {
                for (int j = i + 1; j < n; j++) // checks for duplicate characters, intend to improve later
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("Duplicate characters in key.\n");
                        return 1;
                    }
                }
            }

        }

        substitution(argv[1]); //sends key string
    }
    return 0;

}

void substitution(string key)
{
    string text = get_string("plaintext: "); // asks for text to be converted
    int n = strlen(text);
    printf("ciphertext: ");

    for (int i = 0; i < n; i++) // main loop
    {

        if (isupper(text[i]) != 0)
        {
            printf("%c", toupper(key[text[i] % 65]));
        }
        else if (islower(text[i]) != 0)
        {
            printf("%c", tolower(key[text[i] % 97]));
        }
        else //to preserve non characters like punctuation marks
        {
            printf("%c", text[i]);
        }

    }
    printf("\n");

}