//by glassofraksi
//cs50 2020
//this program outputs the total number of coins needed to make an amount using greedy algorithm

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float money;
    int cents;
    int count = 0;

    do      //gets valid user input
    {

        money = get_float("Change Owed: ");

    }
    while (money < 0 || money == 0);

    cents = round(money * 100); //converts the amount to integer to remove precision errors
    //cents = (int) money % 100;

    while (cents > 0) //main loop to calculate total number of coins, largest first and as many as possible
    {

        if (cents >= 25)
        {
            count = count + cents / 25;
            cents = cents % 25;
        }
        else
        {
            if (cents  >= 10)
            {
                count = count + cents / 10;
                cents = cents % 10;
            }
            else
            {
                if (cents >= 5)
                {
                    count = count + cents / 5;
                    cents = cents % 5;
                }
                else
                {
                    count = count + cents / 1;
                    cents = cents % 1;
                }

            }
        }
    }
    printf("%d\n", count);
}