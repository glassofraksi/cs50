/* by glassofraksi
 cs50 2020
simple implementation of Caesar cipher
key is provided through command line as ./caesar key
letters wrap around, and case is preserved
*/



#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void caesar(int key);

int main(int argc, string argv[])
{
    if (argc != 2) // checks for exacly one key
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++) // key only valid if its a number
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        caesar(atoi(argv[1])); //sends key as integer
    }
    return 0;

}

void caesar(int key) // encryption function
{
    string text = get_string("plaintext: "); // asks for text to be converted
    int n = strlen(text);
    printf("ciphertext: ");

    for (int i = 0; i < n; i++)
    {

        if (isupper(text[i]) != 0)
        {
            printf("%c", (((text[i] + key) % 65) % 26) + 65);
        }
        else if (islower(text[i]) != 0)
        {
            printf("%c", (((text[i] + key) % 97) % 26) + 97);
        }
        else
        {
            printf("%c", text[i]);
        }

    }
    printf("\n");

}