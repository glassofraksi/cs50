/* by glassofraksi
 cs50 2020
 simple program to measure the grade level of a given text using Coleman-Liau index
 the 'bug' was due to only iterating the loop upto strlen instead of strlen+1 to account for \0
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    float letter = 0, word = 0, sent = 0;
    string text = get_string("Text: ");
    int n = strlen(text);

    for (int i = 0 ; i < n + 1 ; i++) // loops through the string

    {
        if (isalpha(text[i]) != 0 && isblank(text[i]) == 0) // counts the number of letters
        {
            letter++;
        }

        if (isblank(text[i]) != 0 || text[i] == '\0') // counts the number of words
        {
            word++;
        }

        if (text[i] == '.' || text[i] == '?' || text [i] == '!') //counts the number of sentences
        {
            sent++;
        }


    }

    int index = (int) round((((letter / word) * 100) * 0.0588) - (((sent / word) * 100) * 0.296) - 15.8); // Coleman-Lieu formula

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
