//by glassofraksi
//cs50 2020

#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height, i, j;

    do
    {

        height = get_int("Enter the height of pyramid:");

   }
    while (height < 1 || height > 8);  //takes valid inputs of 1-8 only from user


    for (i = height; i>0; i--)
    {                           //loop for number of lines

        for (j = 0; j < i-1; j++)
        {                       //loop for printing whitespace
            printf(" ");
        }

        for (j = height ; j > i-1; j--)
        {                       //loop for printing hash
            printf("#");
        }

        printf("\n");
    };
}